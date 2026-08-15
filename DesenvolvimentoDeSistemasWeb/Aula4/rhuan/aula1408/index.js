const express = require('express');

const app = express();
app.use(express.json());

const PORTA = 3001;

app.listen(PORTA, () => {
    console.log(`Servidor rodando :) na porta ${PORTA}`);
});


app.get("/helloworld", (req,res) => {
    res.status(200).json({mensagem : "Hello World!!" }); //200..299 OK //400.499 erro do cliente // 500...599 erro de servidor
                                                        //https://httpstatusdogs.com/ kkkkkkkk
});

app.post("/helloworld", (req,res) => {
    const nome = req.body.nome;
    res.status(200).json({mensagem : `Hello ${nome}` });
});

app.post("/at1", (req,res) => {
    function Salario (horas,valorHoras){
    if (horas > 200){
        return (horas * valorHoras) * 1.05;  
        } else {
            return horas * valorHoras;
        }
    }

    
    let {horas, valorHoras} = req.body;
    let resultado = Salario(horas,valorHoras);
    res.status(200).json({Salario : resultado});
});

app.post ("/at2", (req,res) => {
    const Preco = (precoPro, fdp ) => {
        switch (fdp) {
            case 1:
                return precoPro * 0.95;
            
            
            case 2:

                return precoPro * 1.10;
        
            
            default:
                return "Forma de pagamento Inválida";

        }
    }

    let {PrecoProduto, formaDePag} = req.body;
    let resultado = Preco(PrecoProduto, formaDePag);

    if (formaDePag === 1){
        res.status(200).json({"Valor a vista" : resultado });
    } else if (formaDePag === 2){
        res.status(200).json({"Valor a Prazo" : resultado });
    } else {
        res.status(200).json({"Forma de pagamento inválida" : true});
    }

});

app.post ("/at3", (req,res) => {
    function DurEvento(inicio, fim){
        if (inicio < fim){
            return fim - inicio;
        } else if (inicio > fim){
            return (24 - inicio) + fim;
        } else {
            return "Digite um valor válido"
        }
    }

    let {Dinicio, Dfim} = req.body;
    let evento = DurEvento(Dinicio, Dfim);
    res.status(200).json({"A duracao do evento foi de " : evento});
});

app.post("/at4", (req,res ) => {
    function Admult (A,B){
        let resultado = 0;
        for (let i = 0 ; i < B; i++){
            resultado += A;
        }

        return resultado;
    }

    let {Va, Vb} = req.body;
    let resultado = Admult (Va,Vb);
    res.status(200).json({"Multiplicação " : resultado});
});

app.post("/at5", (req,res) => {
    const Somasec = (Value) => {
        let resultado = 0;
        for(let i = 0; i <= Value; i++){
            resultado += i;
        }

        return resultado;
    }

    let Valor = req.body.Valor;
    resultado = Somasec(Valor);
    res.status(200).json({"Soma sequencial" : resultado });
});

app.post("/at6", (req,res) => {
    let num;
    let numeros = req.body.numeros;
    let certo = 0;
    let total = 0;

    for (let num of numeros) {
        if (num !== 0) {
            if (num >= 10 && num <= 20) {
                certo++;
            }

            total++;
        }
    }

    let resultado = (certo / total) * 100;
    res.status(200).json({Resultado : resultado.toFixed(2) })

});

app.post("/at7", (req,res) => {
    function fatorial(n) {
        if (n === 0 || n === 1) {
            return 1;
        }

        return n * fatorial(n - 1);
    }

    let num = req.body.num;
    fat = fatorial(num);
    res.status(200).json({Fatorial : fat });
});

app.post("/at8", (req,res) => {
    function Posneg(){
        let numeros = req.body.numeros;
        let Num;
        let pos = 0;
        let neg = 0;

        for (let Num of numeros){
            if (Num >= 0){
                pos++;
            } else {
                neg++
            }
        }

        return `${pos}(+) e ${neg}(-)`
    }
    let PN = Posneg();
    res.status(200).json(PN)
})

