import { useState } from "react";
import axios from "axios";

export default function Fornecedores() {

    const [fornecedor, setFornecedor] = useState(null);
    const [entrada, setEntrada] = useState("");
    const [exibirErro, setExibirErro] = useState(false);

    async function buscarFornecedor() {

        try {

            const response = await axios.get(
                `http://localhost:3001/fornecedor/${entrada}`
            );

            console.log(response.data);

            setFornecedor(response.data);
            setExibirErro(false);

        } catch (error) {

            console.log(error);

            setFornecedor(null);
            setExibirErro(true);
        }
    }

    function voltar(){
        setFornecedor(null);
        setEntrada("");
        setExibirErro(false);
    }

    return (
        <div>

            <input
                type="number"
                value={entrada}
                onChange={(e) => setEntrada(e.target.value)}
                placeholder="Digite o ID"
            />

            <button onClick={buscarFornecedor}>
                Buscar Fornecedor
            </button>

            {exibirErro && (
                <p>Fornecedor não encontrado.</p>
            )}

            {fornecedor && (
                <div>
                    <p>ID: {fornecedor.id}</p>
                    <p>Nome: {fornecedor.nome}</p>
                    <p>Email:{fornecedor.email}</p>
                    <p>Telefone:{fornecedor.telefone}</p>
                    <p>Endereço:{fornecedor.endereco} </p>
                </div>
            )}

        </div>
    );
}
