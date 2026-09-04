
#include <stdio.h>
#include <stdlib.h>


void leitura(int *vetor, int tam){
    for (int i = 0; i < tam; i++){
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

void exibicao(int *vetor, int tam){
    printf("\nvetor ordenado:\n");

    for (int i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
void merge(int *vetor, int inicio, int meio, int fim){
    int tamEsquerda = meio - inicio + 1;
    int tamDireita = fim - meio;

    int *esquerda = malloc(tamEsquerda * sizeof(int));
    int *direita = malloc(tamDireita * sizeof(int));

    if (esquerda == NULL || direita == NULL){
        printf("Erro ao alocar memoria.\n");
        free(esquerda);
        free(direita);
        exit(1);

    }


    for (int i = 0; i < tamEsquerda; i++){
        esquerda[i] = vetor[inicio + i];
    }

    for (int i = 0; i < tamDireita; i++){
        direita[i] = vetor[meio + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = inicio;

    while (i < tamEsquerda && j < tamDireita){
        if (esquerda[i] <= direita[j]){
            vetor[k] = esquerda[i];
            i++;
        }
        else{
            vetor[k] = direita[j];
            j++;
        }

        k++;
    }
    while (i < tamEsquerda){
        vetor[k] = esquerda[i];
        i++;
        k++;
    }
    while (j < tamDireita){
        vetor[k] = direita[j];
        j++;
        k++;
    }
    free(esquerda);
    free(direita);
}


void mergeSort(int *vetor, int inicio, int fim){

    if (inicio < fim){
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}



int main(){
    int tam;
    printf("Digite o tam do vetor: ");
    scanf("%d", &tam);

    
    if (tam <= 0){
        printf("o tam tem que ser maior que zero.\n");
        return 1;
    }

    int *vetor = malloc(tam * sizeof(int));

    if (vetor == NULL){
        printf("erro ao alocar memoria.\n");
        return 1;
    }
    leitura(vetor, tam);
    mergeSort(vetor, 0, tam - 1);
    exibicao(vetor, tam);
    free(vetor);

    return 0;
}