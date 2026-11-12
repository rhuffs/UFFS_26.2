const emprestimosRepository = require("./emprestimos.repository");

async function listar() {
    return emprestimosRepository.listar();
}

async function listarAtrasados() {
    return emprestimosRepository.listarAtrasados();
}

async function buscarPorId(id) {
    return emprestimosRepository.buscarPorId(id);
}

async function criar(dados) {
    // Regra de negócio: livro não pode ter empréstimo em aberto
    const emAberto = await emprestimosRepository.buscarEmAbertoPorLivro(dados.livroId);
    if (emAberto) {
        const erro = new Error("Livro já está emprestado e não foi devolvido");
        erro.status = 409;
        throw erro;
    }
    return emprestimosRepository.criar(dados);
}

async function registrarDevolucao(id) {
    const emprestimo = await emprestimosRepository.buscarPorId(id);
    if (!emprestimo) return null;
    if (emprestimo.dataDevolucao) {
        const erro = new Error("Empréstimo já foi devolvido");
        erro.status = 409;
        throw erro;
    }
    return emprestimosRepository.registrarDevolucao(id);
}

async function deletar(id) {
    return emprestimosRepository.deletar(id);
}

module.exports = {
    listar,
    listarAtrasados,
    buscarPorId,
    criar,
    registrarDevolucao,
    deletar,
};
