const database = require("./database");
const express = require('express');

console.log(database.produtos);
const app = express();
app.use(express.json());
const PORTA = 3001;
app.listen(PORTA, () => {
    console.log(`Servidor rodando :) na porta ${PORTA}`);
});

let prox_id_prod = 2;
let prox_id_forn = 2; 

const router = database.Router();
// Criar um CRUD para o ítem Fornecedor na rota /api/fornecedor. A estrutura do Fornecedor é:
// id (numérico): este ID é composto por um número inteiro, iniciando de 1.
// nome (alfanumérico): nome do Fornecedor.
// email (alfanumérico): e-mail do Fornecedor.
// telefone (alfanumérico): telefone do Fornecedor
// endereco (alfanumérico): endereço do fornecedor

app.post.database("/api/fornecedor/crudFornecedor", (req,res) => {
    let  {id,nome,email,telefone,endereco} = req.body;
    
});

router.get('/api/produto',(req,res) => {

})

router.post('api/produtos', (req,res) => {
    let  {id,nome,email,telefone,endereco} = req.body;
})

// Criar um CRUD para o ítem Produto na rota /api/produto. A estrutura do Produto é:
// id (numérico): este ID é composto por um número inteiro, iniciando de 1.
// nome (alfanumérico): nome do produto.
// descricao (alfanumérico): descrição do produto
// preco (numérico): valor do produto
// estoque (numérico): quantidade em estoque
// id_fornecedor (numérico): id do fornecedor ao qual o produto está vinculado.


router.post("/api/produto/", (req,res) => {
    let  {nome,descricao,preco,estoque,id_fornecedor} = req.body;
    if (!nome || !descricao || !preco || !estoque || !id_fornecedor ){
        return res.status(400).json({
            erro : "Dados invalídos"
        })
        
    }
    const existe = database.produtos.find(a => a.id === id);
    if (existe) {
        return res.status(400).json({erro : "id  ja cadastrado" });
    }
    const novoProduto = {id : prox_id_prod++, nome, descricao,preco,estoque, id_fornecedor};
    database.produtos.push(novoProduto);
    res.status(201)
        .set('Location', '/api/produto' + novoProduto.id)
        .json(novoProduto)
});