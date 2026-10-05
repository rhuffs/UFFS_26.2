#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comp = 0; //muito grande
long long trocas = 0;

int gera_rand(){
    return rand() % 1000;
}

void resetContadores(){
    comp = 0;
    trocas = 0;
}

void bubbleSort(int vet[], int tam){
    int i, j, temp;
    
    for (i = 0; i < tam - 1; i++){
        int trocou = 0; 

        for (j = 0; j < tam - i - 1; j++){
            comp++;
            if (vet[j] > vet[j + 1]){
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
                trocas++; 
                trocou = 1;
            }
        }

        if (trocou == 0){
            break; 
        }
    }
}


void insertionSort(int vet[], int n)
{
    for (int i = 1; i < n; i++){
        int chave = vet[i];
        int j = i - 1;

        while (j >= 0){
            comp++;
            if (vet[j] > chave){
                vet[j + 1] = vet[j];
                trocas++;
                j--;
            }
            else{
                break;
            }
        }
        vet[j + 1] = chave;
    }
}

void selectionSort(int vet[], int n){
    for (int i = 0; i < n - 1; i++){
        int menor = i;
        for (int j = i + 1; j < n; j++){
            comp++;
            if (vet[j] < vet[menor]){
                menor = j;
            }
        }

        if (menor != i){
            int temp = vet[i];
            vet[i] = vet[menor];
            vet[menor] = temp;
            trocas++;
        }
    }
}

void quickSort(int vet[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int pivo = vet[inicio];
        int i = inicio;

        for (int j = inicio + 1; j <= fim; j++)
        {
            comp++;
            if (vet[j] < pivo)
            {
                i++;
                int temp = vet[i];
                vet[i] = vet[j];
                vet[j] = temp;
                trocas++;
            }
        }

        int temp = vet[inicio];
        vet[inicio] = vet[i];
        vet[i] = temp;
        trocas++;

        quickSort(vet, inicio, i - 1);
        quickSort(vet, i + 1, fim);
    }
}

void merge(int vet[], int inicio, int meio, int fim)
{
    int tamanhoEsquerda = meio - inicio + 1;
    int tamanhoDireita = fim - meio;

    int *esquerda = malloc(tamanhoEsquerda * sizeof(int));
    int *direita = malloc(tamanhoDireita * sizeof(int));

    for (int i = 0; i < tamanhoEsquerda; i++)
    {
        esquerda[i] = vet[inicio + i];
    }

    for (int i = 0; i < tamanhoDireita; i++)
    {
        direita[i] = vet[meio + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = inicio;

    while (i < tamanhoEsquerda && j < tamanhoDireita)
    {
        comp++;

        if (esquerda[i] <= direita[j])
        {
            vet[k] = esquerda[i];

            i++;
        }
        else
        {
            vet[k] = direita[j];

            j++;
        }

        k++;
        trocas++;
    }

    while (i < tamanhoEsquerda)
    {
        vet[k] = esquerda[i];

        i++;
        k++;

        trocas++;
    }

    while (j < tamanhoDireita)
    {
        vet[k] = direita[j];

        j++;
        k++;

        trocas++;
    }

    free(esquerda);
    free(direita);
}

void mergeSort(int vet[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(vet, inicio, meio);

        mergeSort(vet, meio + 1, fim);

        merge(vet, inicio, meio, fim);
    }
}

void copiaVetor(int original[], int vetor[], int n)
{
    for (int i = 0; i < n; i++)
    {
        vetor[i] = original[i];
    }
}

void geraAleatorio(int vetor[], int n)
{
    for (int i = 0; i < n; i++)
    {
        vetor[i] = gera_rand();
    }
}

void geraOrdenado(int vetor[], int n)
{
    for (int i = 0; i < n; i++)
    {
        vetor[i] = i;
    }
}

void geraInvertido(int vetor[], int n)
{
    for (int i = 0; i < n; i++)
    {
        vetor[i] = n - i;
    }
}

void rodarTestes(int original[], int vetor[], int n, char caso[])
{
    clock_t inicio;
    clock_t fim;
    double tempo;

    printf("\nTAMANHO N = %d | CASO: %s ---\n", n, caso);

    copiaVetor(original, vetor, n);
    resetContadores();

    inicio = clock();

    bubbleSort(vetor, n);

    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Bubble Sort-> Tempo: %f s | Comp: %lld | Trocas: %lld\n",
           tempo, comp, trocas);

    copiaVetor(original, vetor, n);
    resetContadores();
    inicio = clock();
    insertionSort(vetor, n);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Insertion Sort-> Tempo: %f s | Comp: %lld | Trocas: %lld\n",
           tempo, comp, trocas);

    copiaVetor(original, vetor, n);
    resetContadores();

    inicio = clock();

    selectionSort(vetor, n);

    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Selection Sort-> Tempo: %f s | Comp: %lld | Trocas: %lld\n",
           tempo, comp, trocas);

    copiaVetor(original, vetor, n);
    resetContadores();

    inicio = clock();

    quickSort(vetor, 0, n - 1);

    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Quick Sort-> Tempo: %f s | Comp: %lld | Trocas: %lld\n",
           tempo, comp, trocas);

    copiaVetor(original, vetor, n);
    resetContadores();

    inicio = clock();

    mergeSort(vetor, 0, n - 1);

    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Merge Sort-> Tempo: %f s | Comp: %lld | Trocas: %lld\n",
           tempo, comp, trocas);
}

int main()
{
    srand(time(NULL));

    int tamanhos[] = {100, 1000, 10000};

    for (int i = 0; i < 3; i++)
    {
        int n = tamanhos[i];

        int *original = malloc(n * sizeof(int));
        int *vetor = malloc(n * sizeof(int));

        geraAleatorio(original, n);

        rodarTestes(original, vetor, n, "ALEATORIO");

        geraOrdenado(original, n);

        rodarTestes(original, vetor, n, "ORDENADO");

        geraInvertido(original, n);

        rodarTestes(original, vetor, n, "INVERTIDO");

        free(original);
        free(vetor);
    }

    return 0;
}