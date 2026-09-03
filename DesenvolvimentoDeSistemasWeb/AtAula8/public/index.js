const database = require('./database');
console.log("Pacientes do banco local:", database.pacientes);
const tabela = document.createElement('table');
const tab = document.createElement('tread');
tabela.appendChild(tab);
const cow = document.createElement('tr');
tab.appendChild(cow)


const col1 = document.createElement('td');
const col2= document.createElement('td')
const col3 = document.createElement('td')
const col4 = document.createElement('td')
tabela.appendChild(tab);
tabela.appendChild(row);
row.appendChild(col);
tab.innerText = "Pacientes"


//     <table border="1">
//     <tr>
//         <td>Id</td>
//         <td>Nome</td>
//         <td>Email</td>
//         <td>Telefone</td>
//         <td>Procedimento</td>
//     </tr>
//     <tr>
//         <td>id</td>
//         <td>linha1</td>
//         <td>linha2</td>
//         <td>linha3</td>
//         <td>linha4</td>
//     </tr>
//     <tr>
//         <td>id</td>
//         <td>linha1</td>
//         <td>linha2</td>
//         <td>linha3</td>
//         <td>linha4</td>
//     </tr>





// async function buscarDados() {
    try {
   const resposta = await fetch('http://localhost:3001/entidade');
  
   // Verifica se a requisição deu certo
   if (!resposta.ok) {
     // Mensagem de erro
   }
  
   // Converte a resposta para um objeto JSON
   const dados = await resposta.json();
   // processa os dados - exemplo abaixo apenas loga no console
   console.log(dados);
 } catch (erro) {
   console.error('Erro ao buscar dados:', erro);
 }

// chama a função
buscarDados();


