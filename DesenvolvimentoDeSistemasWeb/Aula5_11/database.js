const database = {
    produtos: [
        {
            id: 1,
            nome: "Produto 1",
            descricao: "Descrição do Produto 1",
            preco: 100,
            estoque: 10,
            fornecedor_id: 1,
        },
        {
            id: 2,
            nome: "Produto 2",
            preco: 200,
            estoque: 20,
            fornecedor_id: 2,
        },
    ],
    fornecedores: [
        {
            id: 1,
            nome: "Fornecedor 1",
            email: "fornecedor1@example.com",
            telefone: "11111111111",
            endereco: "Endereço do Fornecedor 1",
        },
        {
            id: 2,
            nome: "Fornecedor 2",
            email: "fornecedor2@example.com",
            telefone: "22222222222",
            endereco: "Endereço do Fornecedor 2",
        },
    ],
};

module.exports = database;
