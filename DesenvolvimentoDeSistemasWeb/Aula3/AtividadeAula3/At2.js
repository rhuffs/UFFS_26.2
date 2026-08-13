const prompt = require('prompt-sync')();



const lista = [10,15,22,33,40,7];
const pares = lista.filter((x) => {if (x % 2 === 0) return x} );
console.log(`Pares da lista : ${pares}`);

