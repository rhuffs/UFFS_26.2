const prompt = require('prompt-sync')();

const lista = [4,8,15,16,23,42];

const listaSomada = lista.reduce((acumulador,x) => acumulador + x);
console.log(`Soma dos elementos da lista: ${listaSomada}`);
