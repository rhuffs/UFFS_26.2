#include<stdio.h>
#include <stdlib.h>
// O que é uma função hash
/*Tabelas Hash (Tabelas de Dispersão)
Uma tabela Hash utiliza uma função chamada função Hash para transformar uma chave em uma posição de um vetor.*/

//hash(chave) = chave mod (tamanho da tabela)
//hash(chave "k") = chave % (tamanh 'm')
//hash(k) = k % m
//================================================================================================================

// conflitos :

//Sondagem Linear
//hi(K) = (h(k) + i) % m
//Onde :
//K: chave para inserir
//h(k): posicao original calculada
//i: numero de tentativas
//m: tamanho da tabela

//Procura pela proxima posição livre

//================================================================================================================
//Encadeamento 
//valores de mesmas posicoes na tabela são armazenado em uma lista encadeada
//vetor = (NULL)(NULL)(NULL)(NULL)(NULL)(NULL)(NULL)(NULL)(NULL)(NULL)
//hash(14) = 14 % TAM == 4
//vetor = (NULL)(NULL)(NULL)(NULL)(24)(NULL)(NULL)(NULL)(NULL)
//                                 |
//                                 14
//                                 |
//                                 4
//                                 |
//                                NULL
//fator de carga

//alpha = n/m
//n: quantidade de elementos armazenados
//m: tamanho da tabela
//================================================================================================================
#define TAM 10

typedef struct No {
    int chave;
    struct No *prox;
} No;

No *tabela[TAM]; //Vetor de Nós[10]

int hash(int chave) {
    return chave % TAM;
}

void inicializar() { //serve para incializar todas a posições como NULL
    for (int i = 0; i < TAM; i++) {
        tabela[i] = NULL;
    }
}

void inserir(int chave) {
    int indice = hash(chave); //salva a posicao em uma variavel chamada indice

    No *novo = malloc(sizeof(No)); //aloca novo nó

    if (novo == NULL) { // deu errado
        return;
    }

    novo->chave = chave; // novo nó recebe chave
    novo->prox = tabela[indice]; //o proximo do novo nó, é o nó que ja exitia na posição indice, para nao perder o que existia alí

    tabela[indice] = novo; // o novo nó é salvo no vetor 
}

No *buscar(int chave) { // pecorre a lista encadeada, e para cada nó percorrido antes de chegar em NULL, verifica se sao iguais
    int indice = hash(chave);

    No *atual = tabela[indice];

    while (atual != NULL) {
        if (atual->chave == chave) {
            return atual;
        }

        atual = atual->prox; // metodo de andar na lista
    }

    return NULL;
}

void remover(int chave) {
    int indice = hash(chave);

    No *atual = tabela[indice];// ponteiro auxiliar que percorre a lista em bsuaca do valor a remover
    No *anterior = NULL; // no auxiliar que sempre esta um nó atras de atual

    while (atual != NULL) {
        if (atual->chave == chave) { // se chave de atual == a chave buscada

            if (anterior == NULL) {              //se o anterior a chave encontrada é nulo, significa que é o primeiro nó da lista,
                tabela[indice] = atual->prox;    //logo a primeira posição é assumida pelo  proximo do atual,e podemos remover como free atual 
            } else {
                    anterior->prox = atual->prox;    // se não, o proximo do anterior recebe o o proximo do atual ex: chave :4  24->(14 anterior)->(4 atual)   
                }                                    //ex: chave 4 -> atual = 4 // 24->(14 anterior)->(4 atual)->NULL // 24->14->NULL //free(4)

            free(atual);
            return;
        }

        anterior = atual; //anterior anda uma
        atual = atual->prox; // atual anda uma
    }
}

//4    vetor(4) = 24
// atual = 24
// anterior = NULL
// 24 == 4
// anterior = atual// ou seja anterior = 24
//atual = atual proximo // ou seja atual = 14
//24->14->4->NULL

// 14 == 4
// anterior = atual// ou seja anterior = 14
//atual = atual proximo // ou seja atual = 4

// 4 ==4
// se anterior == NULL // 14 == NULL //falso
// senão o proximo do anterior recebe proximo do atual


void imprimir() {
    for (int i = 0; i < TAM; i++) { // percorre todos os nós da lista
        No *atual = tabela[i];

        printf("%d: ", i);

        while (atual != NULL) { // imprime lista encadeada
            printf("%d -> ", atual->chave);
            atual = atual->prox;
        }

        printf("NULL\n");
    }
}

void liberar() { // limpa a lista dando free em todas as posições
    for (int i = 0; i < TAM; i++) {
        No *atual = tabela[i];

        while (atual != NULL) {
            No *temp = atual;
            atual = atual->prox;
            free(temp);
        }

        tabela[i] = NULL;
    }
}

void printaBusca(No * buscado){
    if (buscado != NULL) {
        printf("Chave encontrada!\n");
    } else {
        printf("Chave nao encontrada!\n");
    }


}

int main() {
    inicializar();

    inserir(10); // índice 0
    inserir(21); // índice 1
    inserir(32); // índice 2
    inserir(43); // índice 3
    inserir(54); // índice 4
    inserir(65); // índice 5
    inserir(76); // índice 6
    inserir(87); // índice 7
    inserir(98); // índice 8
    inserir(19); // índice 9
    inserir(20);
    inserir(30);
    inserir(40);
    inserir(11);
    inserir(22);
    imprimir();

    printf("\nbuscar 10\n");
    printaBusca(buscar(10));

    printf("\nRemover 10\n");
    remover(10);

    printf("\nDepois da remocao:\n");
    imprimir();
    
    printf("\nbuscar 10\n");
    printaBusca(buscar(10));

    printf("\nliberando lista...");
    liberar();

    return 0;
}

