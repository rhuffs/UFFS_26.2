function fatorial(n) {
    if (n === 0 || n === 1) {
        return 1;
    }

    return n * fatorial(n - 1);
}

let num = parseInt(prompt("Digite um número:"));

console.log(`Fatorial = ${fatorial(num)}`);