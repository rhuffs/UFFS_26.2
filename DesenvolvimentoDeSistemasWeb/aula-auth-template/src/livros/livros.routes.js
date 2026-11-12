const express = require("express");
const livrosController = require("./livros.controller");

const router = express.Router();

// =============================================================================
// COMPARAÇÃO: a mesma consulta escrita de duas formas
// =============================================================================

// Versão 1 — async/await com try / catch
// GET /livros
router.get("/livros", livrosController.listar);

// Versão 2 — Promises com then / catch / finally
// GET /livros-then
router.get("/livros-then", livrosController.listarThen);

// Atenção à ORDEM: rotas fixas (/livros/disponiveis) antes de /livros/:id,
// senão o Express trata "disponiveis" como se fosse um id.

// GET /livros/disponiveis — livros sem empréstimo em aberto
router.get("/livros/disponiveis", livrosController.listarDisponiveis);

// GET /livros/mais-emprestados
router.get("/livros/mais-emprestados", livrosController.listarMaisEmprestados);

// GET /livros/:id
router.get("/livros/:id", livrosController.buscarPorId);

// POST /livros
router.post("/livros", livrosController.criar);

// PUT /livros/:id
router.put("/livros/:id", livrosController.atualizar);

// DELETE /livros/:id
router.delete("/livros/:id", livrosController.deletar);

module.exports = router;
