import "react";
import Titulo from "./Titulo"; 
import Conteudo from "./Conteudo";
import Replica from "./Replica";
import Clientes from "./Clientes";
//criar as proprias tags <saasasdascasc></asdasdasd> -> Componentes

export default function App (){
    //JS
    return (<div>
    
        <Titulo valor = "Hello react"/>
        <Conteudo></Conteudo>
        <Replica/>
        <Clientes/>
    
    </div>
    );
}
