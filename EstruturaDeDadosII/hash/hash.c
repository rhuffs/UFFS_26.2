#include <stdio.h>
#include <stdlib.h>


typedef struct lista_enc {
    int numero;
    int key;
    struct lista_enc * prox;

}lista_enc;

//cada posicao do vetor é uma lista encadeada


int hash_function(lista_enc c, int tam){
    int q = c.key / c.numero ;
    int m = tam ;
    int r = c.key % c.numero;

    int Hk = (q * m) + r;
}

lista_enc * lista_encadeada(lista_enc * v ,int numero, int key){
    lista_enc * novo;
    novo = (lista_enc *)malloc(sizeof( lista_enc));
    novo->numero = numero;
    novo->prox = NULL;

    if (v == NULL) {
        return novo;
    }

    
}


void main(){
    int  v[] = {} ;


}

