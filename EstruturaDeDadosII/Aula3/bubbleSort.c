#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int vet[], int tam){
    int i, j, temp;
    int flag = 0;
    for (i = 0; i < tam - 1; i++){
        for (j = 0; j < tam - i - 1; j++){
           if (vet[j] > vet[j + 1]){
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
                flag++;
            }
        }
    }
   
    printf("Vetor de tamanho %d fez %d trocas.\n", tam, flag);
}

void geraPiorCaso(int vet[], int n){
    for (int i = 0; i < n; i++) {
        vet[i] = n - i; 
    }
}

void bubblePior(int vet[], int tam){
    int i, j, temp;
    int flag = 0;
    for (i = 0; i < tam - 1; i++){
        for (j = 0; j < tam - i - 1; j++){
           if (vet[j] > vet[j + 1]){
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
                flag++;
            }
        }
    }
   
    printf("Vetor de tamanho %d fez %d trocas.\n", tam, flag);
}

void geraVet(int vet[], int n, int min, int max){
    for (int i = 0; i < n; i++) {
        vet[i] = min + rand() % (max - min + 1);
    }
}

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


    printf("Caso 10\n");
    printf("Caso normal\n");
    bubbleSort(Vn, n);

    printf("Melhor caso\n");
    bubbleSort(Vn, n);

    printf("Pior caso\n");
    geraPiorCaso(Vn, n);
    bubbleSort(Vn, n);

    printf("\n");
    
    
    printf("Caso 100\n");
    printf("Caso normal\n");
    bubbleSort(Vb, b);

    printf("Melhor caso\n");
    bubbleSort(Vb, b);

    printf("Pior caso\n");
    geraPiorCaso(Vb, b);
    bubbleSort(Vb, b);

    printf("\n");

    printf("Caso 1000\n");
    printf("Caso normal\n");
    bubbleSort(Vm, m);

    printf("Melhor caso\n");
    bubbleSort(Vm, m);

    printf("Pior caso\n");
    geraPiorCaso(Vm, m);
    bubbleSort(Vm, m);

    return 0;
}
