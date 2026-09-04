import "react";
import { useState } from "react";

//criar as proprias tags <saasasdascasc></asdasdasd> -> Componentes

export default function Clientes (){
    //JS - comportamento é JS
    const [id, setId] = useState("");
    const [nome, setNome] = useState("");
    const [email, setEmail] = useState("");
    const [telefone, setTelefone] = useState("");
    const [endereco, setEndereco] = useState("");
    const [idtxt, setIdtxt] = useState("");
    const [nometxt, setNometxt] = useState("");
    const [emailtxt, setEmailtxt] = useState("");
    const [telefonetxt, setTelefonetxt] = useState("");
    const [enderecotxt, setEnderecotxt] = useState("");


    
    return (
    //comportamneto é HTML
    <div>
        <p>Id <input value={id}onChange={(event) => setId(event.target.value)}></input></p>
        <br/>
        <p>Nome <input value={nome}onChange={(event) => setNome(event.target.value)}></input></p>
        <br/>
        <p>Email <input value={email}onChange={(event) => setEmail(event.target.value)}></input></p>
        <br/>
        <p>Telefone <input value={telefone}onChange={(event) => setTelefone(event.target.value)}></input></p>
        <br/>
        <p>Endereço <input value={endereco}onChange={(event) => setEndereco(event.target.value)}></input></p>
        <button onClick={() => {
            setIdtxt(id);
            setNometxt(nome);
            setEmailtxt(email);
            setTelefonetxt(telefone);
            setEnderecotxt(endereco);
        }}>Atualizar</button>
        {idtxt.length >0 && <p>ID : {idtxt}</p>}
        {nometxt.length >0 && <p>Nome : {nometxt}</p>}
        {emailtxt.length >0 && <p>Email : {emailtxt}</p>}
        {telefonetxt.length >0 && <p>Telefone : {telefonetxt}</p>}
        {enderecotxt.length >0 && <p>Endereço : {enderecotxt}</p>}

    </div>


    );
}
