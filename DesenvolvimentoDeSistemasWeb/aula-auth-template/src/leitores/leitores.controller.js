const leitoresService = require("./leitores.service");

async function listar(req, res) {
    try {
        const leitores = await leitoresService.listar();
        return res.status(200).json(leitores);
    } catch (erro) {
        console.log("Erro ao buscar leitores:", erro);
        return res.status(500).json({ erro: erro.message });
    }
}

async function buscarPorId(req, res) {
    try {
        const leitor = await leitoresService.buscarPorId(req.params.id);
        return res.status(200).json(leitor);
    } catch (erro) {
        console.log("Erro ao buscar leitor:", erro);
        return res.status(500).json({ erro: erro.message });
    }
}

async function listarHistorico(req, res) {
    try {
        const historico = await leitoresService.listarHistorico(req.params.id);
        return res.status(200).json(historico);
    } catch (erro) {
        console.log("Erro ao buscar histórico do leitor:", erro);
        return res.status(500).json({ erro: erro.message });
    }
}

async function criar(req, res) {
    try {
        const leitor = await leitoresService.criar(req.body);
        return res.status(201).json(leitor);
    } catch (erro) {
        console.log("Erro ao criar leitor:", erro);
        return res.status(500).json({ erro: erro.message });
    }
}

async function atualizar(req, res) {
    try {
        const leitor = await leitoresService.atualizar(req.params.id, req.body);
        if (!leitor) return res.status(404).json({ erro: "Leitor não encontrado" });
        return res.status(200).json(leitor);
    } catch (erro) {
        console.log("Erro ao atualizar leitor:", erro);
        return res.status(500).json({ erro: erro.message });
    }
}

async function deletar(req, res) {
    try {
        const leitor = await leitoresService.deletar(req.params.id);
        if (!leitor) return res.status(404).json({ erro: "Leitor não encontrado" });
        return res.status(204).send();
    } catch (erro) {
        console.log("Erro ao deletar leitor:", erro);
        return res.status(500).json({ erro: erro.message });
    }
}

module.exports = {
    listar,
    buscarPorId,
    listarHistorico,
    criar,
    atualizar,
    deletar,
};
