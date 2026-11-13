#include<stdio.h>
#include<stdlib.h>

// para ser uma avl, a diferença entre as alturas das subarvores esquerda e direita em qualquer
//nó  deve ser de no maximo 1.

//Fator de balanciamento -> FB(n) = altura(esquerda) - altura(direita)
//FB(n) pertence {-1,0,+1}

//Formula para calcular a altura -> h(no) = 1 + max(h(esq),h(dir)) 
// h == altura
// max == escolhe o maior entre as duas alturas // porque a altura de um nó é o caminho mais longo ate uma folha, não o mais curto.

//Caso	                  | Tipo de rotação
//LL (esquerda-esquerda)  | Rotação à direita
//RR (direita-direita)	  | Rotação à esquerda
//LR (esquerda-direita)	  | Rotação à esquerda + direita
//RL (direita-esquerda)	  | Rotação à direita + esquerda

//==========================================================
// No *rotacaoDireita(No *z) {
//     No *y = z->esq;
//     No *t2 = y->dir;

//     y->dir = z;
//     z->esq = t2;

//     atualizarAltura(z);
//     atualizarAltura(y);

//     return y;
// }


//     (30 z)fb = 2 - 0 = 2 fb(30) nao pertece {-1,0,1}
//    /
//   (20 y)
//   /
// (10)


    

//   (20y)
//  /     \
// (10)    (30 z)
// //==================================================

//     No *rotacaoEsquerda(No *z) {
//     No *y = z->dir;
//     No *t2 = y->esq;

//     y->esq = z;
//     z->dir = t2;

//     atualizarAltura(z);
//     atualizarAltura(y);

//     return y;
// }


//    (10z) =! FB RR
//       \
//       (20y)
//           \
//           (30)



//     (20y)
//    /   \
// (10z)   (30)

//========================================

//     if (fb > 1 && valor > raiz->esq->valor) {
//         raiz->esq = rotacaoEsquerda(raiz->esq);
//         return rotacaoDireita(raiz);
//     }

//      (10z) 2 - 0 = fb = 2 ----- 2 e! a FB  LR
//     /
//   (5y)-1 H(subarvore esquerda do 5 == 0) e H(subarvore direita == 1) == FB(5) sub esquerda - sub direita == 0 - 1 = -1 AURA+REGO 
//     \
//      (7)0

//       7 fb = 0
//     /   \
//   5 FB=0 10 fb = 0



// //============================================
// L

//     Q(0)      Q (-1)           Q(0)             Q(-1)         Q(0)                      Q(-1)                    Q(0)                       Q(0)          
//                     \         / \             /   \          /   \                     /   \                   /      \                   /      \
//                    u(0)     E(0) U(0)       E(0)  U(1)     E(0)  U(2z) --LR          E(0)  T(0)              E(1)     T(0)             E(-1)       T(0)  
//                                                   /              /                        /    \             /        /  \            /   \        /  \            
//                                                  S(0)           S(-1y)                  S(0)  U(0)          A(0)    S(0)  U(0)       A(0)  O(1)  S(0)  U(0)
//                                                                    \                                                                       /
//                                                                   T(0)                                                                    F(0)
//             Q(1)
//           /       \
//          /         \
//        E(0)        T(0)
//     /       \       /   \
//   A(-1)      O(1) S(0) U(0) 
//     \       /
//     C(0)  F(0) 
// //------------------------------------------
//              Q(1)
//            /     \
//           /       \
//          /         \
//        E(0)        T(0)
//     /       \       /   \
//   A(-1)      O(2z) S(0) U(0)   LR   
//     \       /
//     C(0)  F(-1y) 
//             \
//             i(0)
// //------------------------------------------
//              Q(1)
//             /    \
//            /      \
//           /        \
//          /          \
//        E(0)         T(0)
//     /       \       /   \
//   A(-1)      I(0)  S(0) U(0)    
//     \       /   \
//     C(0)  F(0) O(0)

// //------------------------------------------
//              Q(2z)
//             /    \
//            /      \
//           /        \
//          /          \
//       E(-1y)         T(0)
//     /       \       /   \
//   A(-1)      I(-1)  S(0) U(0)    
//     \       /   \
//     C(0)  F(0) O(1)
//                /
//               L(0)


// //------------------------------------------
//              Q(2z)
//             /    \
//            /      \
//           /        \
//          /          \
//       E(-1y)         T(0)
//     /       \       /   \
//   A(-1)      I(-1)  S(0) U(0)    
//     \       /   \
//     C(0)  F(0) O(1)
//                /
//               L(0)

//            Q
//           /
//          I
//        /   \
//       E     O
//      / \    /
//     A   F  L
//      \
//       C


//          I
//        /  \
//       E    Q
//     /  \   /  \
//   A     F O    T
//    \     /    /  \
//     C    L    S  U

//---------------------------------------------------------------------------------------------------------//

//if (fb == 2  && fatorBalanceamento(raiz->esq) >= 0)  // LL
//if (fb == -2 && fatorBalanceamento(raiz->dir) <= 0)  // RR
//if (fb == 2  && fatorBalanceamento(raiz->esq) < 0)   // LR
//if (fb == -2 && fatorBalanceamento(raiz->dir) > 0)   // RL

//Ela não olha para o valor inserido. Olha para o estado da árvore: o sinal do fator de balanceamento do filho indica para que lado a subárvore está pesada.

//1.Filho com FB ≥ 0 → pesado para o mesmo lado → rotação simples
//2.Filho com FB < 0 (no caso esquerdo) → pesado para o lado oposto → rotação dupla

typedef struct No {
    int valor;
    int altura;

    struct No *esq;
    struct No *dir;
} No;

No* criarNo(int valor){
    No *novo = malloc(sizeof(No));

    novo ->valor = valor;
    novo -> altura = 0;
    novo -> esq = NULL;
    novo -> dir = NULL;

    return novo;
}

int altura(No *no) {
    if (no == NULL)
        return -1;

    return no->altura;
}

int fatorBalanceamento(No *no){
    if (no == NULL){
        return 0;    
    }

    return altura(no->esq) - altura(no->dir);
}

int maior(int a, int b) {
    return (a > b) ? a : b;
}

void atualizarAltura(No *no) {
    no->altura = 1 + maior(altura(no->esq),altura(no->dir));
}
No *rotacaoDireita(No *z) {
    No *y = z->esq;
    No *t2 = y->dir;

    y->dir = z;
    z->esq = t2;

    atualizarAltura(z);
    atualizarAltura(y);

    return y;
}

No *rotacaoEsquerda(No *z) {
    No *y = z->dir;
    No *t2 = y->esq;

    y->esq = z;
    z->dir = t2;

    atualizarAltura(z);
    atualizarAltura(y);

    return y;
}



No *inserirAVL(No *raiz, int valor) {

    // 1. Inserção normal em uma árvore binária de busca
    if (raiz == NULL)
        return criarNo(valor);

    if (valor < raiz->valor)
        raiz->esq = inserirAVL(raiz->esq, valor);

    else if (valor > raiz->valor)
        raiz->dir = inserirAVL(raiz->dir, valor);

    else
        return raiz; // Não permite valores duplicados


    // 2. Atualiza a altura do nó
    atualizarAltura(raiz);


    // 3. Calcula o fator de balanceamento
    int fb = fatorBalanceamento(raiz);


    // 4. LL - Esquerda-Esquerda
    if (fb == 2 && fatorBalanceamento(raiz->esq) >= 0) {
        return rotacaoDireita(raiz);
    }


    // 5. RR - Direita-Direita
    if (fb == -2 && fatorBalanceamento(raiz->dir) <= 0) {
        return rotacaoEsquerda(raiz);
    }


    // 6. LR - Esquerda-Direita
    if (fb == 2 && fatorBalanceamento(raiz->esq) < 0) {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }


    // 7. RL - Direita-Esquerda
    if (fb == -2 && fatorBalanceamento(raiz->dir) > 0) {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }


    // 8. Retorna a raiz sem alterações
    return raiz;
}


No *menorValor(No *raiz) {

    while (raiz->esq != NULL)
        raiz = raiz->esq;

    return raiz;
}

No *removerAVL(No *raiz, int valor) {

    // 1. Procura o nó na árvore
    if (raiz == NULL)
        return NULL;

    if (valor < raiz->valor)
        raiz->esq = removerAVL(raiz->esq, valor);

    else if (valor > raiz->valor)
        raiz->dir = removerAVL(raiz->dir, valor);


    // 2. Nó encontrado: realiza a remoção
    else {

        // Caso 1: nó sem filhos
        if (raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            return NULL;
        }

        // Caso 2: nó com apenas um filho
        else if (raiz->esq == NULL || raiz->dir == NULL) {

            No *temp;

            if (raiz->esq != NULL)
                temp = raiz->esq;
            else
                temp = raiz->dir;

            free(raiz);
            return temp;
        }

        // Caso 3: nó com dois filhos
        else {

            // Encontra o sucessor (menor valor da direita)
            No *temp = menorValor(raiz->dir);

            // Copia o valor do sucessor
            raiz->valor = temp->valor;

            // Remove o sucessor da posição original
            raiz->dir = removerAVL(raiz->dir, temp->valor);
        }
    }
         A
        /
       20
      /  \   
    10    30
          /\  
        14  31

        temp->valor = 14
        20 = 14
        30 = null
    // 3. Atualiza a altura do nó
    atualizarAltura(raiz);


    // 4. Calcula o fator de balanceamento
    int fb = fatorBalanceamento(raiz);


    // 5. LL - Esquerda-Esquerda
    if (fb == 2 && fatorBalanceamento(raiz->esq) >= 0) {
        return rotacaoDireita(raiz);
    }


    // 6. RR - Direita-Direita
    if (fb == -2 && fatorBalanceamento(raiz->dir) <= 0) {
        return rotacaoEsquerda(raiz);
    }


    // 7. LR - Esquerda-Direita
    if (fb == 2 && fatorBalanceamento(raiz->esq) < 0) {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }


    // 8. RL - Direita-Esquerda
    if (fb == -2 && fatorBalanceamento(raiz->dir) > 0) {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }


    // 9. Retorna a raiz sem alterações
    return raiz;
}
void imprimir(No *raiz, int nivel) {
    if (raiz == NULL)
        return;

    imprimir(raiz->dir, nivel + 1);

    for (int i = 0; i < nivel; i++)
        printf("    ");

    printf("%d (h=%d)\n", raiz->valor, raiz->altura);

    imprimir(raiz->esq, nivel + 1);
}
int main(){
    No *raiz = NULL;

	raiz = inserirAVL(raiz, 50);
    raiz = inserirAVL(raiz, 30);
    raiz = inserirAVL(raiz, 70);
    raiz = inserirAVL(raiz, 20);
    raiz = inserirAVL(raiz, 40);
    raiz = inserirAVL(raiz, 60);
    raiz = inserirAVL(raiz, 80);
    raiz = inserirAVL(raiz, 35);
    raiz = inserirAVL(raiz, 45);
    raiz = inserirAVL(raiz, 65);
 

   imprimir(raiz, 0);
    
   raiz = removerAVL(raiz,50);

    imprimir(raiz,0);
    return 0;
}

