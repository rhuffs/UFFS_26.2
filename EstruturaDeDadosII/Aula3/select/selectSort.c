#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void sortSelect(int vetor[], int tam) {
    int flag = 0;

    for (int i = 0; i < tam - 1; i++) {

        int menor = i;

        for (int j = i + 1; j < tam; j++) {

            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }

        if (menor != i) {
            int temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;

            flag++;
        }
    }

    printf("Vetor de tamanho %d fez %d trocas.\n", tam, flag);
}
void geraPiorCaso(int vet[], int n){
    for (int i = 0; i < n; i++) {
        vet[i] = n - i; 
    }
}


void geraVet(int vet[], int n, int min, int max){
    for (int i = 0; i < n; i++) {
        vet[i] = min + rand() % (max - min + 1);
    }
}

void imprimeVet(int vet[], int tam){
    for (int i = 0; i < tam; i++){
       printf("%d ", vet[i]); 
    }
}

//[43,5,2,23,5,]

int main(){
    int n = 10;
    int b = 100;
    int m = 1000;

    int Vn[10];
    int Vb[100];
    int Vm[1000];

    srand(time(NULL));
    geraVet(Vn, n, 1, 10);
    geraVet(Vb, b, 1, 100);
    geraVet(Vm, m, 1, 1000);


    printf("\nCaso 10\n");
    imprimeVet(Vn, n);
    
    printf("\nCaso normal \n");
    sortSelect(Vn, n);
    imprimeVet(Vn, n);
    

    printf("\nMelhor caso\n");
    sortSelect(Vn, n);
    imprimeVet(Vn, n);

    printf("\nPior caso\n");
    geraPiorCaso(Vn, n);
    sortSelect(Vn, n);
    imprimeVet(Vn, n);

    printf("\n/////////////\n");
    
    
    printf("\nCaso 100\n");
    imprimeVet(Vb, b);
    printf("\nCaso normal\n");
    sortSelect(Vb, b);
    imprimeVet(Vb, b);

    printf("\nMelhor caso\n");
    sortSelect(Vb, b);
    imprimeVet(Vb, b);

    printf("\nPior caso\n");
    geraPiorCaso(Vb, b);
    sortSelect(Vb, b);
    imprimeVet(Vb, b);

    printf("\n//////////////\n");

    printf("\nCaso 1000\n");
    imprimeVet(Vm, m);
    printf("\nCaso normal\n");
    sortSelect(Vm, m);
    imprimeVet(Vm, m);

    printf("\nMelhor caso\n");
    sortSelect(Vm, m);
    imprimeVet(Vm, m);

    printf("\nPior caso\n");
    geraPiorCaso(Vm, m);
    sortSelect(Vm, m);
    imprimeVet(Vm, m);

    return 0;
}