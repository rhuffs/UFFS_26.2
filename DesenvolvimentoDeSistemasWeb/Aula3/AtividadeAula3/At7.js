// Use reduce para encontrar o maior valor de um array de números, sem usar Math.max.
// Entrada:
// [12, 45, 3, 89, 22, 67]
// Saída:
// Maior valor: 89

const prompt = require('prompt-sync')();
const Num = [12, 45, 3, 89, 22, 67];
const Maior = Num.reduce((MaiorN, x) => { if (x > MaiorN) MaiorN = x; return MaiorN; });

console.log(`${Maior}`);