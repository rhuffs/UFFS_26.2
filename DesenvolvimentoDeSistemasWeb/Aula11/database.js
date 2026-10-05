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
            telefone: "489225422",
            endereco: "Endereço do Fornecedor 1",
        },
        {
            id: 2,
            nome: "Fornecedor 2",
            email: "fornecedor2@example.com",
            telefone: "22222222222",
            endereco: "Endereço do Fornecedor 2",
        },
        {
            id: 3,
            nome: "Fornecedor 3",
            email: "fornecedor3@example.com",
            telefone: "33333333333",
            endereco: "Endereço do Fornecedor 3",
        },
        {
            id: 4,
            nome: "Fornecedor 4",
            email: "fornecedor4@example.com",
            telefone:"444444444444",
            endereco: "Endereço do Fornecedor 4",
        },        

    ],
};

module.exports = database;
