const prompt = require('prompt-sync')();

// Dado um array de objetos representando funcionários ({ nome, salario }), use map para
// gerar um novo array apenas com os nomes, e filter para retornar apenas os funcionários
// com salário acima de R$ 3000,00.
// Entrada:
// [
// { nome: "Ana", salario: 2500 },
// { nome: "Bruno", salario: 4200 },
// { nome: "Carla", salario: 3800 }
// ]
// Saída:
// Nomes: ["Ana", "Bruno", "Carla"]
// Salário > 3000:
// [{ nome: "Bruno", salario: 4200 },
// { nome: "Carla", salario: 3800 }]

const funcs = [{ nome: "Ana", salario: 2500 },{ nome: "Bruno", salario: 4200 },{ nome: "Carla", salario: 3800 }];


const funcsNomes = funcs.map((x) => x.nome);
const M3000 = funcs.filter((x) => x.salario > 3000);
console.log(`${funcsNomes}`);
console.log(`Salário > 3000`);
console.log(M3000);
