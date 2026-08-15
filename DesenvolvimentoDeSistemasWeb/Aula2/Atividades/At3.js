function DurEvento(inicio, fim){
    if (inicio < fim){
        return fim - inicio;
    } else if (inicio > fim){
        return (24 - inicio) + fim;
    } else {
        return "Digite um valor válido"
    }
}

let Dinicio = parseInt(prompt("Incio do evento"));
let Dfim = parseInt(prompt("fim do evento"));
console.log(`Duração : ${DurEvento(Dinicio,Dfim)}`);


