const { Op } = require("sequelize");
const sequelize = require("../database/connection");
const { Emprestimo, Leitor, Livro } = require("../database/models");

async function listar() {
    return Emprestimo.findAll({
        attributes: ["id", "dataEmprestimo", "dataPrevista", "dataDevolucao"],
        include: [
            { model: Leitor, as: "leitor", attributes: ["nome"] },
            { model: Livro, as: "livro", attributes: ["titulo"] },
        ],
        order: [["dataEmprestimo", "DESC"]],
    });
}

async function listarAtrasados() {
    return Emprestimo.findAll({
        attributes: [
            "id",
            "dataPrevista",
            [sequelize.literal("CURRENT_DATE - data_prevista"), "diasAtraso"],
        ],
        where: {
            dataDevolucao: null,
            dataPrevista: { [Op.lt]: sequelize.literal("CURRENT_DATE") },
        },
        include: [
            { model: Leitor, as: "leitor", attributes: ["nome", "email"] },
            { model: Livro, as: "livro", attributes: ["titulo"] },
        ],
        order: [["dataPrevista", "ASC"]],
    });
}

async function buscarPorId(id) {
    return Emprestimo.findByPk(id);
}

// Verifica se o livro já tem empréstimo em aberto (sem devolução)
async function buscarEmAbertoPorLivro(livroId) {
    return Emprestimo.findOne({
        where: { livroId, dataDevolucao: null },
    });
}

async function criar(dados) {
    return Emprestimo.create(dados);
}

async function registrarDevolucao(id) {
    const emprestimo = await Emprestimo.findByPk(id);
    if (!emprestimo) return null;
    return emprestimo.update({ dataDevolucao: new Date() });
}

async function deletar(id) {
    const emprestimo = await Emprestimo.findByPk(id);
    if (!emprestimo) return null;
    await emprestimo.destroy();
    return emprestimo;
}

module.exports = {
    listar,
    listarAtrasados,
    buscarPorId,
    buscarEmAbertoPorLivro,
    criar,
    registrarDevolucao,
    deletar,
};
