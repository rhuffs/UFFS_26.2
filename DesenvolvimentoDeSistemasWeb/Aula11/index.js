const database = require("./database");
const express = require('express');
const cors = require('cors');
const app = express();
app.use(express.json());
app.use(cors());
const PORTA = 3001;
app.listen(PORTA, () => {
    console.log(`Servidor rodando :) na porta ${PORTA}`);
});


app.get('/fornecedor/:id', (req, res) => {

    const id = Number(req.params.id);

    const fornecedor = database.fornecedores.find(
        fornecedor => fornecedor.id === id
    );

    if (!fornecedor) {
        return res.status(404).send("Fornecedor não encontrado");
    }

    res.send(fornecedor);
});
