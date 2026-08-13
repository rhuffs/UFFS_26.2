const prompt = require('prompt-sync')();

const precos = [100.00,250.00,80.00];

const desconto = precos.map((x) => x.toFixed(2) * 0.90);
console.log(`[${desconto.map((x) => x.toFixed(2))}]`);