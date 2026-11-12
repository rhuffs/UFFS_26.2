const livrosRepository = require("./livros.repository");

async function listar() {
    return livrosRepository.listar();
}

async function listarDisponiveis() {
    return livrosRepository.listarDisponiveis();
}

async function listarMaisEmprestados() {
    return livrosRepository.listarMaisEmprestados();
}

async function buscarPorId(id) {
    return livrosRepository.buscarPorId(id);
}

async function criar(dados) {
    return livrosRepository.criar(dados);
}

async function atualizar(id, dados) {
    return livrosRepository.atualizar(id, dados);
}

async function deletar(id) {
    return livrosRepository.deletar(id);
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
