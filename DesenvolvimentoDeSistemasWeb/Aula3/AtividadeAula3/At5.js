const prompt = require('prompt-sync')();

const Astring = ["Maria","João","Marcos","Ana","Miguel"];
const M = Astring.filter((x)=> {if (x[0] === 'M')return x} );
console.log(`Nomes : ${Astring}`);
console.log(`Nomes com M: ${M}`);