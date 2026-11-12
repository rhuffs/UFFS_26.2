const express = require("express");
const leitoresController = require("./leitores.controller");

const router = express.Router();

// GET /leitores
router.get("/leitores", leitoresController.listar);

// GET /leitores/:id
router.get("/leitores/:id", leitoresController.buscarPorId);

// GET /leitores/:id/historico
router.get("/leitores/:id/historico", leitoresController.listarHistorico);

// POST /leitores
router.post("/leitores", leitoresController.criar);

// PUT /leitores/:id
router.put("/leitores/:id", leitoresController.atualizar);

// DELETE /leitores/:id
router.delete("/leitores/:id", leitoresController.deletar);

module.exports = router;
