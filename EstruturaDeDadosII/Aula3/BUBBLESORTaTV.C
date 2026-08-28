#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int vet[], int tam) {
    int i, j, temp;
    int total_trocas = 0; // Variável que vai contar cada troca realizada

    for (i = 0; i < tam - 1; i++) {
        for (j = 0; j < tam - i - 1; j++) {
            if (vet[j] > vet[j + 1]) {
                // Realiza a troca (swap)
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
                
                total_trocas++; // Soma 1 toda vez que entra aqui dentro
            }
        }
    }
    // IMPRIME O RESULTADO: O segredo é usar o "%d" para indicar que vai exibir um inteiro
    printf("Vetor de tamanho %d fez um total de %d trocas.\n", tam, total_trocas);
}

int main() {
    int n = 10, b = 100, m = 1000;
    int Vn[10], Vb[100], Vm[1000];

    srand(time(NULL));

    // Preenche e testa o vetor de 10 elementos
    for (int i = 0; i < n; i++) Vn[i] = rand() % 100;
    bubbleSort(Vn, n);

    // Preenche e testa o vetor de 100 elementos
    for (int i = 0; i < b; i++) Vb[i] = rand() % 500;
    bubbleSort(Vb, b);

    // Preenche e testa o vetor de 1000 elementos
    for (int i = 0; i < m; i++) Vm[i] = rand() % 5000;
    bubbleSort(Vm, m);

    return 0;
}
