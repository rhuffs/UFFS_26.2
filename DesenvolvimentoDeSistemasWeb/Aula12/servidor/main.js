const express = require("express");

const app = express();

app.use(express.json());

const PORTA = 3001;

app.get("/", (req, res) => {
    res.send("Servidor funcionando!");
});

app.listen(PORTA, () => {
    console.log(`Servidor rodando na porta ${PORTA}`);
});
