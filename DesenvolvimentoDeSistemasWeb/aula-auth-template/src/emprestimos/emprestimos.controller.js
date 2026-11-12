const emprestimosService = require("./emprestimos.service");

async function listar(req, res) {
    try {
        const emprestimos = await emprestimosService.listar();
        return res.status(200).json(emprestimos);
    } catch (erro) {
        console.log("Erro ao buscar empréstimos:", erro);
        return res.status(500).json({ erro: erro.message });
    }
}

async function listarAtrasados(req, res) {
    try {
        const atrasados = await emprestimosService.listarAtrasados();
        return res.status(200).json(atrasados);
    } catch (erro) {
        console.log("Erro ao buscar empréstimos atrasados:", erro);
        return res.status(500).json({ erro: erro.message });
    }
}

async function criar(req, res) {
    try {
        const emprestimo = await emprestimosService.criar(req.body);
        return res.status(201).json(emprestimo);
    } catch (erro) {
        console.log("Erro ao criar empréstimo:", erro);
        return res.status(erro.status || 500).json({ erro: erro.message });
    }
}

async function registrarDevolucao(req, res) {
    try {
        const emprestimo = await emprestimosService.registrarDevolucao(req.params.id);
        if (!emprestimo) return res.status(404).json({ erro: "Empréstimo não encontrado" });
        return res.status(200).json(emprestimo);
    } catch (erro) {
        console.log("Erro ao registrar devolução:", erro);
        return res.status(erro.status || 500).json({ erro: erro.message });
    }
}

async function deletar(req, res) {
    try {
        const emprestimo = await emprestimosService.deletar(req.params.id);
        if (!emprestimo) return res.status(404).json({ erro: "Empréstimo não encontrado" });
        return res.status(204).send();
    } catch (erro) {
        console.log("Erro ao deletar empréstimo:", erro);
        return res.status(500).json({ erro: erro.message });
    }
}

module.exports = {
    listar,
    listarAtrasados,
    criar,
    registrarDevolucao,
    deletar,
};
