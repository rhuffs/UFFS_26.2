let num;
let certo = 0;
let total = 0;

do {
    num = parseInt(prompt("Número:"));

    if (num !== 0) {
        if (num >= 10 && num <= 20) {
            certo++;
        }

        total++;
    }

} while (num !== 0);

let resultado = (certo / total) * 100;

console.log(`Resultado: ${resultado}`);


