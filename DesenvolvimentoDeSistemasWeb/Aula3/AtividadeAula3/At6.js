const prompt = require('prompt-sync')();


// Combine map e filter: dado um array de notas (0 a 10), retorne um novo array contendo
// apenas as notas de alunos aprovados (nota ≥ 6), convertidas para o conceito
// "APROVADO".
// Entrada:
// [5.5, 7.0, 9.2, 4.0, 6.0]
// Saída:
// ["APROVADO", "APROVADO", "APROVADO"]

const notas = [5.5,7.0,9.2,4.0,6.0];

const NotasApr = notas
    .filter((x) => x >= 6)
    .map((x) => "APROVADO");
    
console.log(`${NotasApr}`);