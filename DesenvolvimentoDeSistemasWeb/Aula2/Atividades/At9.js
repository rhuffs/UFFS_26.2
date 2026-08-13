//a cada intervalo de 100 m = pico
//extamente n a metade de dois picos há um vale
//a cada 50 m há um vale ou  um pico
//nao existe pico -> pico nem vale -> vale


let N = parseInt(prompt("Digite o Numero de medidas:"));
let Atual = 0;
let Anterior = 0;
let Move_ant = 0;
for (let i = 0; i < N; i ++){
    let Alt = parseInt(prompt("Medidas"));
    if (i === 0){
        Anterior = Alt;
        continue;
    }
    Atual = Alt;
    if (Atual > Anterior){
        if(Move_ant === 1){
            certo = false;
            break
        }

        movimentoAnterior = 1;
    } else if (Atual < Anterior) {
        if(Move_ant === -1){
            certo = false;
            break
        }

        movimentoAnterior = -1;

    } else {
        certo = false;
        break;
    }

    Anterior =  Atual;
}


console.log(certo ? 1 : 0);
