#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    int valor;
    struct No * dir;
    struct No * esq;
    int altura;
} No;

No * criarNo(int valor){
    No * novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    novo->altura = 0;

    return novo;

}


int altura(No * no){
    if (no == NULL){
        return -1;

    }

    return no->altura;
}

int maior(int a, int b){
    if (a>b){
        return a;
    } else {
        return b;
    }
}

void atualizarAltura(No *no){
    no->altura = 1 + maior(altura(no->esq), altura(no->dir));
}

No * rotacaoDir(No *z){
    No * y = z->esq;
    No * t2 = y->dir;

    y->dir = z;
    z->esq = t2;

    atualizarAltura(z);
    atualizarAltura(y);

    return y;


}

int fatorBalanceamento(No * no){
    if (no == NULL){
        return 0;
    }

    return altura(no->esq) - altura(no->dir );

}

No *rotacaoEsq(No * z){
    No * y = z->dir;
    No * t2 = y->esq;

    y->esq = z;
    z->dir = t2;

    atualizarAltura(z);
    atualizarAltura(y);

    return y;
}
No * inserirValor(No * raiz, int valor){

    if (raiz == NULL){
        return criarNo(valor); 
    }

    if (valor < raiz->valor){
        raiz->esq = inserirValor(raiz->esq,valor);
    }

    else if (valor > raiz->valor){
        raiz->dir = inserirValor(raiz->dir,valor);
    }

    else{
        return raiz;
    }
    
    atualizarAltura(raiz);


    int fb = fatorBalanceamento(raiz);
    //if (fb == 2  && fatorBalanceamento(raiz->esq) >= 0)  // LL
    //if (fb == -2 && fatorBalanceamento(raiz->dir) <= 0)  // RR
    //if (fb == 2  && fatorBalanceamento(raiz->esq) < 0)   // LR
    //if (fb == -2 && fatorBalanceamento(raiz->dir) > 0)   // RL
    if (fb == 2 && fatorBalanceamento(raiz->esq) >= 0 ){
        return rotacaoDir(raiz);
    }

    if (fb == -2 && fatorBalanceamento(raiz->dir) <=0){
        return rotacaoEsq(raiz);
    }

    if (fb == 2 && fatorBalanceamento(raiz->esq) < 0){
        rotacaoEsq(raiz->esq);
        return rotacaoDir(raiz);
    }

    if (fb == -2 && fatorBalanceamento(raiz->dir) > 0){
        rotacaoDir(raiz->dir);
        return rotacaoEsq(raiz);
    }

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

	raiz = inserirValor(raiz, 50);
    raiz = inserirValor(raiz, 30);
    raiz = inserirValor(raiz, 70);
    raiz = inserirValor(raiz, 20);
    raiz = inserirValor(raiz, 40);
    raiz = inserirValor(raiz, 60);
    raiz = inserirValor(raiz, 80);
    raiz = inserirValor(raiz, 35);
    raiz = inserirValor(raiz, 45);
    raiz = inserirValor(raiz, 65);
 

   imprimir(raiz, 0);
    
   

    imprimir(raiz,0);
    return 0;
}
