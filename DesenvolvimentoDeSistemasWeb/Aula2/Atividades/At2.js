const Preco = (precoPro, fdp ) => {
    switch (fdp) {
        case 1:
            return precoPro * 0.95;
            break;
        
        case 2:

            return precoPro * 1.10;
            break;
        
        default:
            return "Forma de pagamento Inválida";
            break;
    }
}

let PrecoProduto = parseInt(prompt("Informe o preço do produto"));
let formaDePag = parseInt (prompt("informe a forma de pagamento"));

if (formaDePag === 1){
    console.log(`Valor A Vista ${Preco(PrecoProduto,formaDePag)}`);
} else if (fdp === 2){
    console.log(`Valor A Prazo ${Preco(PrecoProduto,formaDePag)}`);
} else {
    console.log("Forma de pagamento inválida");
}
