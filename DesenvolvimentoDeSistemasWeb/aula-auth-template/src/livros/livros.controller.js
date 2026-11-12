const livrosService = require("./livros.service");

// Versão 1 — async/await com try / catch
async function listar(req, res) {
    try {
        const livros = await livrosService.listar();
        return res.status(200).json(livros);
    } catch (erro) {
        console.log("Erro ao buscar livros:", erro);
        return res.status(500).json({ erro: erro.message });
    }
}

// Versão 2 — Promises com then / catch / finally
function listarThen(req, res) {
    const inicio = Date.now();

    livrosService
        .listar()
        .then((livros) => {
            res.status(200).json(livros);
        })
        .catch((erro) => {
            console.log("Erro ao buscar livros:", erro);
            res.status(500).json({ erro: erro.message });
        })
        .finally(() => {
            // executa sempre, com sucesso ou erro
            console.log(`GET /livros-then (${Date.now() - inicio} ms)`);
        });
}

async function listarDisponiveis(req, res) {
    try {
        const livros = await livrosService.listarDisponiveis();
        return res.status(200).json(livros);
    } catch (erro) {
        console.log("Erro ao buscar livros disponíveis:", erro);
        return res.status(500).json({ erro: erro.message });
    }
}

async function listarMaisEmprestados(req, res) {
    try {
        const livros = await livrosService.listarMaisEmprestados();
        return res.status(200).json(livros);
    } catch (erro) {
        console.log("Erro ao buscar livros mais emprestados:", erro);
        return res.status(500).json({ erro: erro.message });
    }
}

async function buscarPorId(req, res) {
    try {
        const livro = await livrosService.buscarPorId(req.params.id);
        return res.status(200).json(livro);
    } catch (erro) {
        console.log("Erro ao buscar livro:", erro);
        return res.status(500).json({ erro: erro.message });
    }
}

async function criar(req, res) {
    try {
        const livro = await livrosService.criar(req.body);
        return res.status(201).json(livro);
    } catch (erro) {
        console.log("Erro ao criar livro:", erro);
        return res.status(500).json({ erro: erro.message });
    }
}

async function atualizar(req, res) {
    try {
        const livro = await livrosService.atualizar(req.params.id, req.body);
        if (!livro) return res.status(404).json({ erro: "Livro não encontrado" });
        return res.status(200).json(livro);
    } catch (erro) {
        console.log("Erro ao atualizar livro:", erro);
        return res.status(500).json({ erro: erro.message });
    }
}

async function deletar(req, res) {
    try {
        const livro = await livrosService.deletar(req.params.id);
        if (!livro) return res.status(404).json({ erro: "Livro não encontrado" });
        return res.status(204).send();
    } catch (erro) {
        console.log("Erro ao deletar livro:", erro);
        return res.status(500).json({ erro: erro.message });
    }
}

module.exports = {
    listar,
    listarThen,
    listarDisponiveis,
    listarMaisEmprestados,
    buscarPorId,
    criar,
    atualizar,
    deletar,
};
