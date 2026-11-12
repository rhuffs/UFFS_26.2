const passport = require("passport");
const LocalStrategy = require("passport-local");
const JwtStrategy = require("passport-jwt").Strategy;
const ExtractJwt = require("passport-jwt").ExtractJwt;
const authService = require("./auth.service");
const authRepository = require("./auth.repository");

// Configuração da estratégia local (username/password)
const configureLocalStrategy = () => {
    passport.use(
        new LocalStrategy(
            {
                usernameField: "username",
                passwordField: "password",
            },
            async (username, password, done) => {
                try {
                    const resultado = await authService.autenticarUsuario(username, password);

                    if (resultado.sucesso) {
                        return done(null, resultado.usuario);
                    } else {
                        return done(null, false, { message: resultado.mensagem });
                    }
                } catch (error) {
                    return done(error);
                }
            },
        ),
    );
};

// Configuração da estratégia JWT
const configureJwtStrategy = () => {
    passport.use(
        new JwtStrategy(
            {
                jwtFromRequest: ExtractJwt.fromAuthHeaderAsBearerToken(),
                secretOrKey: "your-secret-key",
            },
            async (payload, done) => {
                try {
                    const user = await authRepository.buscarPorId(payload.username);

                    if (user) {
                        done(null, user);
                    } else {
                        done(null, false);
                    }
                } catch (error) {
                    done(error, false);
                }
            },
        ),
    );
};

// Configuração de serialização do usuário
const configureSerialization = () => {
    passport.serializeUser(function (user, cb) {
        process.nextTick(function () {
            return cb(null, {
                email: user.email,
                username: user.email,
            });
        });
    });

    passport.deserializeUser(function (user, cb) {
        process.nextTick(function () {
            return cb(null, user);
        });
    });
};

// Middleware para autenticação JWT
const requireJWTAuth = passport.authenticate("jwt", { session: false });

// Middleware reutilizável para verificar permissão específica
// Deve ser usado APÓS o requireJWTAuth
const verificarPermissaoMiddleware = (descricaoPermissao) => {
    return async (req, res, next) => {
        try {
            // Verifica se o usuário está autenticado (req.user deve ser definido pelo requireJWTAuth)
            if (!req.user) {
                return res.status(401).json({ message: "Usuário não autenticado." });
            }

            const email = req.user.email;
            const temPermissao = await authService.verificarPermissaoPorDescricao(
                email,
                descricaoPermissao,
            );

            if (!temPermissao) {
                return res.status(403).json({
                    message: `Acesso negado. Permissão necessária: ${descricaoPermissao}`,
                });
            }

            // Se passou na verificação, continua para o próximo middleware
            next();
        } catch (error) {
            console.error("Erro ao verificar permissão:", error);
            return res.status(500).json({ message: "Erro interno do servidor." });
        }
    };
};

// Middleware para verificar JWT e permissão específica
const requirePermissao = (descricaoPermissao) => {
    return [
        requireJWTAuth,
        async (req, res, next) => {
            try {
                // req.user é definido pelo requireJWTAuth
                if (!req.user) {
                    return res.status(401).json({ message: "Usuário não autenticado." });
                }

                const email = req.user.email;
                const temPermissao = await authService.verificarPermissaoPorDescricao(
                    email,
                    descricaoPermissao,
                );

                if (!temPermissao) {
                    return res.status(403).json({
                        message: `Acesso negado. Permissão necessária: ${descricaoPermissao}`,
                    });
                }

                next();
            } catch (error) {
                console.error("Erro ao verificar permissão:", error);
                return res.status(500).json({ message: "Erro interno do servidor." });
            }
        },
    ];
};

module.exports = {
    configureLocalStrategy,
    configureJwtStrategy,
    configureSerialization,
    requireJWTAuth,
    verificarPermissaoMiddleware,
    requirePermissao,
};
