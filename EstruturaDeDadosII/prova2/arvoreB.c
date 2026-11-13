// Definições de uma arvore B
//
// 1.x.n = Quantidade de Chaves
// 2. x.key = Chaves de um nó -> sempre em ordem nao decrescente
//    ou seja, a proxima chave sempre vai ser maior que a ultima
// 3.x.leaf - inidica se é folha -> um nó sem filhos
// 4. cada nó interno possui x.n + 1 filhos
// 5. as chaves separam os valores dos filhos
// 6. todas as folhas posssuem a mesma profundidade-> altuta  = h
// 7. Quantidade minima e maxima de chaves
//    grau minimo = t // e t >=2
//
//    a) Quantidade mínima
//          Todo nó, exceto a raiz, precisa possuir pelo menos:
//              t - 1 chaves
//          Consequentemente, todo nó interno, exceto a raiz, precisa possuir pelo menos:
//              t filhos  
//          A raiz possui uma exceção: se a árvore não estiver vazia, ela precisa ter pelo menos uma chave.
//   
//   b) Quantidade máxima
//          Todo nó pode possuir no máximo:
//              2t - 1 chaves
//          Consequentemente, um nó interno pode possuir no máximo:
//              2t filhos
//          Quando um nó possui exatamente 2t-1 chaves, ele é chamado de nó cheio (full).
//
//              (20)
//               |   
//            (7|30)
//          /  |    \ 
//       (6) (10\29) (70)

#include <stdio.h>
#include <stdlib.h>

#define T 2 // defini T como 2, se eu quiser mudar T

typedef struct No {
    int n;   //quantidade de chaves
    int folha; // 1 se for folha, 0 se for nó interno
    int chaves[2 * T - 1]; // armazena até 3 chaves
    struct No *filhos[2 * T]; //armazena até 4 ponteiros
} No;

No *criarNo(int folha) {

    No *novo = malloc(sizeof(No));

    novo->n = 0; // inicialmente nao exitem chaves
    novo->folha = folha;

    for (int i = 0; i < 2 * T; i++)
        novo->filhos[i] = NULL;

    return novo;
}

void dividirFilho(No *pai, int i) { // No *pai : Nó possui o filho que vai ser dividido // int i : posição do filho que vai ser dividido 
                                    //
                                    //         (50)
                                    //       /    \
                                    //     [10]  [60|70|80]
                                    //      0        1

    No *y = pai->filhos[i]; //Y aponta para o filho que irá ser dividido

    No *z = criarNo(y->folha); // Z cria um novo nó vendo se y é uma folha ou não, porque o novo nó tem que ter o mesmo tipo do nó original.

    z->n = T - 1; //Por quê? Porque, na divisão de um nó cheio, cada lado fica com T - 1 chaves.
                  //quando dividimos um nó com 3 chaves, uma chave sobre para o pai e as outras suas ficam divididas entre nós

    // Copia a segunda metade das chaves
    for (int j = 0; j < T - 1; j++)        //for (int j = 0; j < 1; j++)
        z->chaves[j] = y->chaves[j + T];   //  z->chaves[j] = y->chaves[j + 2];
    //y->chaves:
     //Índice:  0    1    2
    //       [10] [20] [30]
    //
    //
    //z->chaves[0] = 30
    //y = [10 | 20 | 30]
    //z = [30]

    // Se não for folha, copia os filhos também
    if (!y->folha) {
        for (int j = 0; j < T; j++)
            z->filhos[j] = y->filhos[j + T];
    }

    y->n = T - 1;

    //y = [10]
    //z = [30]

    // Abre espaço para o novo filho
    for (int j = pai->n; j >= i + 1; j--)
        pai->filhos[j + 1] = pai->filhos[j];

    pai->filhos[i + 1] = z;//Agora o novo nó está imediatamente à direita do nó original.

    // Abre espaço para a chave promovida
    // Antes:   
    //pai->filhos:
    //[ A ][ B ][ C ]
    //       ↑
    //       y
    for (int j = pai->n - 1; j >= i; j--)
        pai->chaves[j + 1] = pai->chaves[j];
    //    Depois:

    //[ A ][ B ][   ][ C ]
    //            ↑
    //       espaço para z

    // Promove a chave do meio
    pai->chaves[i] = y->chaves[T - 1];

    pai->n++;
}

void inserirNaoCheio(No *x, int valor) {

    int i = x->n - 1; // i tem a posicao do ultimo nó, se o nó tem 3 chaves, i fica na posição 2

    // Caso seja uma folha
    if (x->folha) {

        while (i >= 0 && valor < x->chaves[i]) {
            x->chaves[i + 1] = x->chaves[i];
            i--;
        }

        x->chaves[i + 1] = valor;
        x->n++;
    }

    else {

        // Encontra o filho correto
        while (i >= 0 && valor < x->chaves[i])
            i--;

        i++;

        // Verifica se o filho está cheio
        if (x->filhos[i]->n == 2 * T - 1) {

            dividirFilho(x, i);

            // Decide para qual filho continuar
            if (valor > x->chaves[i])
                i++;
        }

        inserirNaoCheio(x->filhos[i], valor);
    }
}
void inserir(No **raiz, int valor) {

    // Árvore vazia
    if (*raiz == NULL) {
        *raiz = criarNo(1);
        (*raiz)->chaves[0] = valor;
        (*raiz)->n = 1;
        return;
    }

    No *r = *raiz;

    // Verifica se a raiz está cheia
    if (r->n == 2 * T - 1) {

        No *s = criarNo(0);

        s->filhos[0] = r;

        dividirFilho(s, 0);

        int i = 0;

        if (valor > s->chaves[0])
            i++;

        inserirNaoCheio(s->filhos[i], valor);

        *raiz = s;
    }

    else {
        inserirNaoCheio(r, valor);
    }
}


void imprimir(No *raiz) {

    if (raiz == NULL)
        return;

    int i;

    for (i = 0; i < raiz->n; i++) {

        if (!raiz->folha)
            imprimir(raiz->filhos[i]);

        printf("%d ", raiz->chaves[i]);
    }

    if (!raiz->folha)
        imprimir(raiz->filhos[i]);
}


int main() {

    No *raiz = NULL;

    inserir(&raiz, 10);
    inserir(&raiz, 20);
    inserir(&raiz, 30);
    inserir(&raiz, 40);
    inserir(&raiz, 50);
    inserir(&raiz, 60);
    inserir(&raiz, 70);

    printf("Elementos da arvore B:\n");

    imprimir(raiz);

    printf("\n");

    return 0;
}
