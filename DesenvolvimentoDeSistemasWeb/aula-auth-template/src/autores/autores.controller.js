const autoresService = require("./autores.service");

async function listar(req, res) {
    try {
        const autores = await autoresService.listar();
        return res.status(200).json(autores);
    } catch (erro) {
        console.log("Erro ao buscar autores:", erro);
        return res.status(500).json({ erro: erro.message });
    }
}

async function buscarPorId(req, res) {
    try {
        const autor = await autoresService.buscarPorId(req.params.id);
        return res.status(200).json(autor);
    } catch (erro) {
        console.log("Erro ao buscar autor:", erro);
        return res.status(500).json({ erro: erro.message });
    }
}

async function listarLivros(req, res) {
    try {
        const livros = await autoresService.listarLivros(req.params.id);
        return res.status(200).json(livros);
    } catch (erro) {
        console.log("Erro ao buscar livros do autor:", erro);
        return res.status(500).json({ erro: erro.message });
    }
}

async function criar(req, res) {
    try {
        const autor = await autoresService.criar(req.body);
        return res.status(201).json(autor);
    } catch (erro) {
        console.log("Erro ao criar autor:", erro);
        return res.status(500).json({ erro: erro.message });
    }
}

async function atualizar(req, res) {
    try {
        const autor = await autoresService.atualizar(req.params.id, req.body);
        if (!autor) return res.status(404).json({ erro: "Autor não encontrado" });
        return res.status(200).json(autor);
    } catch (erro) {
        console.log("Erro ao atualizar autor:", erro);
        return res.status(500).json({ erro: erro.message });
    }
}

async function deletar(req, res) {
    try {
        const autor = await autoresService.deletar(req.params.id);
        if (!autor) return res.status(404).json({ erro: "Autor não encontrado" });
        return res.status(204).send();
    } catch (erro) {
        console.log("Erro ao deletar autor:", erro);
        return res.status(500).json({ erro: erro.message });
    }
}

module.exports = {
    listar,
    buscarPorId,
    listarLivros,
    criar,
    atualizar,
    deletar,
};
