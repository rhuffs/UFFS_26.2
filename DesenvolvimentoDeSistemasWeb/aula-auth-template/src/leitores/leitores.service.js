const leitoresRepository = require("./leitores.repository");

async function listar() {
    return leitoresRepository.listar();
}

async function buscarPorId(id) {
    return leitoresRepository.buscarPorId(id);
}

async function listarHistorico(id) {
    return leitoresRepository.listarHistorico(id);
}

async function criar(dados) {
    return leitoresRepository.criar(dados);
}

async function atualizar(id, dados) {
    return leitoresRepository.atualizar(id, dados);
}

async function deletar(id) {
    return leitoresRepository.deletar(id);
}

module.exports = {
    listar,
    buscarPorId,
    listarHistorico,
    criar,
    atualizar,
    deletar,
};
