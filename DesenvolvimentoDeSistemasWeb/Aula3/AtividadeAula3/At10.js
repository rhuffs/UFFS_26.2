
const prompt = require('prompt-sync')();


// Desafio combinado: dado um array de vendas ({ produto, valor, categoria }), use filter
// para selecionar apenas vendas da categoria "Eletrônicos", map para extrair os valores, e
// reduce para somar o total vendido nessa categoria.
// Entrada:
// [
// { produto: "Notebook", valor: 3200, categoria: "Eletrônicos" },
// { produto: "Cadeira", valor: 450, categoria: "Móveis" },
// { produto: "Celular", valor: 1800, categoria: "Eletrônicos" },
// { produto: "Mesa", valor: 600, categoria: "Móveis" }
// ]
// Saída:
// Total em Eletrônicos: 5000.00


const produtos = [
 { produto: "Notebook", valor: 3200, categoria: "Eletrônicos" },
 { produto: "Cadeira", valor: 450, categoria: "Móveis" },
 { produto: "Celular", valor: 1800, categoria: "Eletrônicos" },
 { produto: "Mesa", valor: 600, categoria: "Móveis" }
 ];

const Elprod = produtos
                .filter((x) => x.categoria === "Eletrônicos")
                .map((x) => x.valor)
                .reduce((soma,x)=> soma + x);

console.log(Elprod);

