const { Leitor, Emprestimo, Livro, comAutor } = require("../database/models");

async function listar() {
    return Leitor.findAll({ order: [["nome", "ASC"]] });
}

async function buscarPorId(id) {
    return Leitor.findByPk(id);
}

async function listarHistorico(id) {
    return Emprestimo.findAll({
        where: { leitorId: id },
        attributes: ["dataEmprestimo", "dataPrevista", "dataDevolucao"],
        include: {
            model: Livro,
            as: "livro",
            attributes: ["titulo"],
            include: comAutor,
        },
        order: [["dataEmprestimo", "DESC"]],
    });
}

async function criar(dados) {
    return Leitor.create(dados);
}

async function atualizar(id, dados) {
    const leitor = await Leitor.findByPk(id);
    if (!leitor) return null;
    return leitor.update(dados);
}

async function deletar(id) {
    const leitor = await Leitor.findByPk(id);
    if (!leitor) return null;
    await leitor.destroy();
    return leitor;
}

module.exports = {
    listar,
    buscarPorId,
    listarHistorico,
    criar,
    atualizar,
    deletar,
};
