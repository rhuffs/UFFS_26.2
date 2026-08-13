function Admult (A,B){
    let resultado = 0;
    for (let i = 0 ; i < B; i++){
        resultado += A;
    }

    return resultado;
}


let Va = parseInt(prompt("Valor de A"));
let Vb = parseInt(prompt("Valor de B"));

console.log(`Multiplicação : ${Admult(Va,Vb)}`);


