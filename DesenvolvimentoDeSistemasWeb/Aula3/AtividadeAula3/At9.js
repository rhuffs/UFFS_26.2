const prompt = require('prompt-sync')();

//  Use forEach para percorrer um array de números e imprimir no console se cada número
// é "PAR" ou "ÍMPAR", junto com seu valor.
// Entrada:
// [3, 8, 15, 20]
// Saída:
// 3 é ÍMPAR
// 8 é PAR
// 15 é ÍMPAR
// 20 é PAR

const ParOrEven = [3, 8 , 15 , 20];

function ParOuImpar (Num){
    if (Num % 2 === 0) {
        console.log(`${Num} é PAR`);
    } else {
        console.log(`${Num} é ÍMPAR`);
    }
}
   

ParOrEven.forEach(ParOuImpar);

