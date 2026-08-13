function Salario (horas,valorHoras){
  if (horas > 200){
    return (horas * valorHoras) * 1.05;  
  } else {
    return horas * valorHoras;
  }
}

let horas  = Number(prompt("Horas Trabalhadas"));
let valorHoras = Number(prompt("Valor da Horas"));

console.log(`Salario = ${Salario(horas, valorHoras)}`);