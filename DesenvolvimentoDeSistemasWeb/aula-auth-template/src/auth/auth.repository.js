const { Usuario, Permissao, UsuarioPermissao } = require("../database/models");

async function buscarPorEmail(email) {
    // TODO: Buscar usuário por email no banco de dados
    // Dica: use Usuario.findOne() com where
    const usuario = 
    
    return usuario;
}

async function buscarPorId(email) {
    // TODO: Buscar usuário por ID (chave primária)
    // Dica: use Usuario.findByPk()
    return 
}

async function criar(dados) {
    // TODO: Criar um novo usuário no banco de dados
    // Dica: use Usuario.create() passando os dados
    return 
}

async function buscarPermissaoPorDescricao(descricao) {
    return Permissao.findOne({
        where: { descricao: descricao },
    });
}

async function buscarUsuarioPermissao(email, idPermissao) {
    return UsuarioPermissao.findOne({
        where: {
            email: email,
            id_permissao: idPermissao,
        },
    });
}

async function listarPermissoesUsuario(email) {
    const permissoes = await UsuarioPermissao.findAll({
        where: {
            email: email,
        },
        include: [
            {
                model: Permissao,
                as: "Permissao",
            },
        ],
    });

    return permissoes.map((up) => up.Permissao);
}

module.exports = {
    buscarPorEmail,
    buscarPorId,
    criar,
    buscarPermissaoPorDescricao,
    buscarUsuarioPermissao,
    listarPermissoesUsuario,
};
