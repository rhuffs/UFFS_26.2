# Exercício: Sistema de Autenticação

## Objetivo
Completar a implementação de um sistema de autenticação seguindo a arquitetura em camadas (Repository → Service → Controller).

## Arquivos para Completar

### 1. `auth.repository.js` (Camada de Dados)
**Tarefas:**
- [ ] Implementar `buscarPorEmail()` - buscar usuário por email
- [ ] Implementar `buscarPorId()` - buscar usuário por ID
- [ ] Implementar `criar()` - criar novo usuário no banco

**Dicas:**
- Use `Usuario.findOne({ where: { ... } })` para buscar por campo específico
- Use `Usuario.findByPk(id)` para buscar por chave primária
- Use `Usuario.create(dados)` para criar novo registro

---

### 2. `auth.service.js` (Camada de Lógica de Negócio)
**Tarefas:**
- [ ] Completar `autenticarUsuario()`:
  - Buscar usuário por email
  - Verificar se usuário existe
  - Comparar senha com hash usando bcrypt
  - Retornar resultado da autenticação

- [ ] Completar `criarNovoUsuario()`:
  - Gerar hash da senha (saltRounds = 10)
  - Criar usuário com senha hasheada
  - Retornar dados do usuário criado

- [ ] Completar `gerarToken()`:
  - Gerar token JWT com username
  - Configurar expiração de 1 hora

**Dicas:**
- `bcrypt.genSaltSync(saltRounds)` - gera o salt
- `bcrypt.hashSync(senha, salt)` - cria o hash
- `bcrypt.compare(senha, hash)` - verifica senha
- `jwt.sign(payload, secret, options)` - gera token

---

### 3. `auth.controller.js` (Camada de Controle HTTP)
**Tarefas:**
- [ ] Completar `login()`:
  - Extrair username e password de `req.body`
  - Chamar `authService.autenticarUsuario()`
  - Verificar resultado da autenticação
  - Gerar token se sucesso
  - Retornar resposta adequada

- [ ] Completar `criarUsuario()`:
  - Chamar `authService.criarNovoUsuario()` com `req.body`
  - Retornar status 201 com dados do usuário

**Dicas:**
- Use `req.body` para acessar dados da requisição
- Status 200 para sucesso
- Status 201 para criação
- Status 401 para não autorizado
- Status 500 para erro do servidor

---

## Conceitos Importantes

### Bcrypt (Hashing de Senhas)
```javascript
// Gerar hash
const salt = bcrypt.genSaltSync(10);
const hash = bcrypt.hashSync("senha123", salt);

// Verificar senha
const valida = await bcrypt.compare("senha123", hash);
```

### JWT (JSON Web Token)
```javascript
// Gerar token
const token = jwt.sign(
    { username: "user@email.com" },
    "chave-secreta",
    { expiresIn: "1h" }
);
```

### Sequelize (ORM)
```javascript
// Buscar por campo
Usuario.findOne({ where: { email: "user@email.com" } })

// Buscar por chave primária
Usuario.findByPk(id)

// Criar registro
Usuario.create({ email, nome, senha })
```

---

## Como Testar

1. **Criar usuário:**
```bash
POST /novoUsuario
{
  "username": "user@email.com",
  "passwd": "senha123",
  "nome": "Nome do Usuário"
}
```

2. **Fazer login:**
```bash
POST /login
{
  "username": "user@email.com",
  "password": "senha123"
}
```

3. **Resposta esperada:**
```json
{
  "message": "Login successful",
  "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9..."
}
```

---

## Proteção de Rotas

Após completar a implementação da autenticação, você pode proteger rotas usando middlewares JWT.

### Middlewares Disponíveis (em `auth.config.js`)

1. **`requireJWTAuth`** - Exige que o usuário esteja autenticado (tenha token válido)
2. **`requirePermissao(descricao)`** - Exige autenticação + permissão específica
3. **`verificarPermissaoMiddleware(descricao)`** - Apenas verifica permissão (use após `requireJWTAuth`)

### Exemplo 1: Proteger Rota com Autenticação JWT

Proteja rotas que exigem apenas que o usuário esteja logado:

```javascript
const { requireJWTAuth } = require("./auth/auth.config");

// Rota protegida - apenas usuários autenticados
router.get("/autores", requireJWTAuth, autoresController.listar);
```

**Teste:**
```bash
# Sem token - retorna 401 Unauthorized
GET /autores

# Com token - funciona
GET /autores
Authorization: Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9...
```

### Exemplo 2: Proteger Rota com Permissão Específica

Proteja rotas que exigem permissões específicas:

```javascript
const { requirePermissao } = require("./auth/auth.config");

// Rota protegida - requer permissão DELETAR_AUTOR
router.delete("/autores/:id", 
    requirePermissao("DELETAR_AUTOR"), 
    autoresController.deletar
);

// Rota protegida - requer permissão CRIAR_LIVRO
router.post("/livros", 
    requirePermissao("CRIAR_LIVRO"), 
    livrosController.criar
);
```

**Teste:**
```bash
# Usuário sem permissão - retorna 403 Forbidden
DELETE /autores/1
Authorization: Bearer <token-sem-permissao>

# Usuário com permissão - funciona
DELETE /autores/1
Authorization: Bearer <token-com-permissao>
```

### Exemplo 3: Verificar Permissão Manualmente

Use quando precisar verificar permissões dentro do controller:

```javascript
const { requireJWTAuth, verificarPermissaoMiddleware } = require("./auth/auth.config");

// Aplicar middlewares em sequência
router.put("/autores/:id", 
    requireJWTAuth,  // Primeiro: valida JWT
    verificarPermissaoMiddleware("EDITAR_AUTOR"),  // Depois: verifica permissão
    autoresController.atualizar
);
```

### Exemplo 4: Rotas Públicas vs Protegidas

```javascript
const express = require("express");
const autoresController = require("./autores/autores.controller");
const { requireJWTAuth, requirePermissao } = require("./auth/auth.config");

const router = express.Router();

// Rotas PÚBLICAS (sem autenticação)
router.get("/autores", autoresController.listar);
router.get("/autores/:id", autoresController.buscarPorId);

// Rotas PROTEGIDAS (requer autenticação)
router.post("/autores", 
    requireJWTAuth, 
    autoresController.criar
);

router.put("/autores/:id", 
    requireJWTAuth, 
    autoresController.atualizar
);

// Rotas PROTEGIDAS (requer permissão específica)
router.delete("/autores/:id", 
    requirePermissao("DELETAR_AUTOR"), 
    autoresController.deletar
);

module.exports = router;
```

### Fluxo de Autenticação

1. **Cliente faz login** → recebe token JWT
2. **Cliente envia requisição** → inclui token no header `Authorization: Bearer <token>`
3. **Middleware verifica token** → valida e decodifica
4. **Middleware verifica permissão** (opcional) → consulta banco de dados
5. **Rota processa requisição** → se tudo OK

### Acessando Usuário Autenticado

Após passar pelo middleware `requireJWTAuth`, o usuário fica disponível em `req.user`:

```javascript
async function criar(req, res) {
    try {
        // req.user contém os dados do usuário autenticado
        console.log("Usuário autenticado:", req.user.email);
        
        const autor = await autoresService.criar(req.body);
        return res.status(201).json(autor);
    } catch (erro) {
        return res.status(500).json({ erro: erro.message });
    }
}
```

---

## Recursos Adicionais

- [Documentação Bcrypt](https://www.npmjs.com/package/bcrypt)
- [Documentação JWT](https://www.npmjs.com/package/jsonwebtoken)
- [Documentação Sequelize](https://sequelize.org/docs/v6/)

---

## Pontos de Atenção

1. **NUNCA** armazene senhas em texto puro
2. Sempre use hash (bcrypt) para senhas
3. Valide dados antes de processar
4. Trate erros adequadamente
5. Use status HTTP corretos
6. Siga a separação em camadas (Repository → Service → Controller)
