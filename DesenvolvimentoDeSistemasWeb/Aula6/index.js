const express = require('express');
const app = express();

app.use(express.json());

const PORTA = 3001;

worldRouter = require ("./hello-world");
app.listen(PORTA, ()=>{
    console.log(`Serividor rodando na porta 3001`);
});

app.use('/api/helloworld', helloworldRouter);

app.use()