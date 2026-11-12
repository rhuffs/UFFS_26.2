const autoresRepository = require("./autores.repository");

async function listar() {
    return autoresRepository.listar();
}

async function buscarPorId(id) {
    return autoresRepository.buscarPorId(id);
}

async function listarLivros(id) {
    return autoresRepository.listarLivros(id);
}

async function criar(dados) {
    return autoresRepository.criar(dados);
}

async function atualizar(id, dados) {
    return autoresRepository.atualizar(id, dados);
}

async function deletar(id) {
    return autoresRepository.deletar(id);
}

module.exports = {
    listar,
    buscarPorId,
    listarLivros,
    criar,
    atualizar,
    deletar,
};
