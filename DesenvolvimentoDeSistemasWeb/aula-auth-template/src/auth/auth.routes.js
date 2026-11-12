const express = require("express");
const authController = require("./auth.controller");

const router = express.Router();

// POST /login - Autenticação de usuário
router.post("/login", authController.login);

// POST /logout - Logout de usuário
router.post("/logout", authController.logout);

// POST /novoUsuario - Criar novo usuário
router.post("/novoUsuario", authController.criarUsuario);

module.exports = router;
