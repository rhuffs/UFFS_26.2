// =============================================================================
// GEX613 - Programação II | Express + Sequelize
// Banco: biblioteca.sql (autores, livros, leitores, emprestimos)
//
// Camadas (mesmo desenho de app-horarios-api/src):
//   src/database/models    -> models Sequelize
//   *.repository.js       -> acesso ao banco
//   *.service.js          -> regras da aplicação
//   *.controller.js       -> HTTP
//   *.routes.js           -> rotas do recurso
//
// Instalação:  npm install express sequelize pg pg-hstore
// Execução:    node index.js
// =============================================================================

const express = require("express");
const autoresRoutes = require("./src/autores/autores.routes");
const livrosRoutes = require("./src/livros/livros.routes");
const leitoresRoutes = require("./src/leitores/leitores.routes");
const emprestimosRoutes = require("./src/emprestimos/emprestimos.routes");

const app = express();
const PORT = 3000;

app.use(autoresRoutes);
app.use(livrosRoutes);
app.use(leitoresRoutes);
app.use(emprestimosRoutes);

app.listen(PORT, () => {
    console.log(`Servidor rodando em http://localhost:${PORT}`);
});
