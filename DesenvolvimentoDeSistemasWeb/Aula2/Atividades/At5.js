const Somasec = (Value) => {
    let resultado = 0;
    for(let i = 0; i <= Value; i++){
        resultado += i;
    }

    return resultado;
}

let Valor = parseInt(prompt("Digite o valor"));

console.log(`Soma = ${Somasec(Valor)}`);


