const { Op } = require("sequelize");
const sequelize = require("../database/connection");
const { Autor, Livro, Emprestimo, comAutor } = require("../database/models");

async function listar() {
    return Livro.findAll({
        include: {
            model: Autor,
            as: "autor",
            attributes: ["id", "nome"],
        },
        order: [
            [{ model: Autor, as: "autor" }, "nome", "ASC"],
            ["anoPublicacao", "ASC"],
        ],
    });
}

async function listarDisponiveis() {
    return Livro.findAll({
        attributes: ["id", "titulo"],
        include: {
            model: Autor,
            as: "autor",
            attributes: ["id", "nome"],
        },
        where: {
            id: {
                [Op.notIn]: sequelize.literal(
                    "(SELECT livro_id FROM emprestimos WHERE data_devolucao IS NULL)",
                ),
            },
        },
        order: [["titulo", "ASC"]],
    });
}

async function listarMaisEmprestados() {
    return Livro.findAll({
        attributes: [
            "id",
            "titulo",
            [
                sequelize.fn("COUNT", sequelize.col("emprestimos.id")),
                "totalEmprestimos",
            ],
        ],
        include: [
            comAutor,
            { model: Emprestimo, as: "emprestimos", attributes: [] },
        ],
        group: ["Livro.id", "autor.id"],
        order: [
            [sequelize.literal('"totalEmprestimos"'), "DESC"],
            ["titulo", "ASC"],
        ],
    });
}

async function buscarPorId(id) {
    return Livro.findByPk(id, { include: comAutor });
}

async function criar(dados) {
    return Livro.create(dados);
}

async function atualizar(id, dados) {
    const livro = await Livro.findByPk(id);
    if (!livro) return null;
    return livro.update(dados);
}

async function deletar(id) {
    const livro = await Livro.findByPk(id);
    if (!livro) return null;
    await livro.destroy();
    return livro;
}

module.exports = {
    listar,
    listarDisponiveis,
    listarMaisEmprestados,
    buscarPorId,
    criar,
    atualizar,
    deletar,
};
