import "react";
import { useState } from "react";
import Replica from "./Replica";
//criar as proprias tags <saasasdascasc></asdasdasd> -> Componentes

export default function Conteudo (){
    //JS - comportamento é JS
    const [contador, setContador] = useState(0);
    const [nome, setNome] = useState("");
    function incrementa(){
        setContador(contador+1);
    };

    
    
    return (
    //comportamneto é HTML
    <div>
        <input value = {contador}></input>
        <button onClick={incrementa}>Incrementar</button>
        <br/>
        <input value={nome}onChange={(event) => setNome(event.target.value)}></input>
        {nome.length > 3 && <Replica valor = {nome}/>}

    </div>


    );
}
