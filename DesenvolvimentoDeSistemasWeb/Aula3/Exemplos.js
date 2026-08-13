// const prompt = require('prompt-sync')(); //obrigatorio em todo arquivo agr, serve para executar no terminal




// // let numeroHoras = parseInt(prompt("Insira o numero de horas"));
// // console.log(`numero de horas ${numeroHoras}`);


// //funcao anonima = funcao sem nome 
// //callback = funcao que recebe uma funcao como parametro
// //===========================================================================///
// //CALLBACKS

// function soma(x,y){
//     return x + y;
// }

// function subtrai(x,y){
//     return x - y;
// }

// function modificar(a,b,callback){  //c = callback usso no frontend
//     return callback(a,b);
// }

// console.log(`soma : ${modificar(1,2,soma)}`); // soma é o c"callback"
// console.log(`subtracao : ${modificar(1,2,subtrai)}`);

// //Funcao Anonima
// console.log(`soma anonima : ${modificar(1,2,(x,y) => x + y)}`);

//=================================================================================//
//Arrays:
//Map=Aplica uma funcao 

//Filter=Aplica um filtro 

//reduce= aplica uma acumulacao

const lista = [1,2,3,4,5];
const pares = lista.filter((x) => {if (x % 2 === 0) return x} );
console.log(`Pares da lista : ${pares}`);


const mapeados = lista.map((x)=> x*2); //map nao modifica lista/ ele retorna uma nova versao.
console.log(`Mapeados da lista: ${mapeados}`);
console.log(`lista origi: ${lista}`);


const listaSomada = lista.reduce((acumulador,x) => acumulador + x);
console.log(`Soma dos elementos da lista: ${listaSomada}`);
