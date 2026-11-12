const express = require("express");
const emprestimosController = require("./emprestimos.controller");

const router = express.Router();

// GET /emprestimos
router.get("/emprestimos", emprestimosController.listar);

// GET /emprestimos/atrasados
router.get("/emprestimos/atrasados", emprestimosController.listarAtrasados);

// POST /emprestimos
router.post("/emprestimos", emprestimosController.criar);

// PUT /emprestimos/:id/devolver — registra a data de devolução
router.put("/emprestimos/:id/devolver", emprestimosController.registrarDevolucao);

// DELETE /emprestimos/:id
router.delete("/emprestimos/:id", emprestimosController.deletar);

module.exports = router;
