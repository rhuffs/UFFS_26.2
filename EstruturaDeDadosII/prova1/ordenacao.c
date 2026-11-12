#include <stdio.h>

void demonstrar_hoare_partition(int A[], int low, int high) {
    int pivot = A[low];
    int i = low - 1;
    int j = high + 1;
    int iteracao = 1;

    printf("=========================================================\n");
    printf("              DEMONSTRACAO HOARE-PARTITION              \n");
    printf("=========================================================\n");
    printf("Pivo escolhido (A[%d]): %d\n", low, pivot);
    printf("Estado Inicial do Array A: ");
    for (int k = low; k <= high; k++) {
        printf("%d ", A[k]);
    }
    printf("\n---------------------------------------------------------\n\n");

    while (1) {
        // Avança i
        do {
            i++;
        } while (A[i] < pivot);

        // Recua j
        do {
            j--;
        } while (A[j] > pivot);

        printf("[Iteracao %d]\n", iteracao);
        printf("  Ponteiro i parou em i = %d (A[%d] = %d)\n", i, i, A[i]);
        printf("  Ponteiro j parou em j = %d (A[%d] = %d)\n", j, j, A[j]);

        // Verificação de parada (i >= j)
        if (i >= j) {
            printf("  Condicao de parada atingida: i (%d) >= j (%d).\n", i, j);
            printf("  Retornando j = %d.\n", j);
            printf("  Estado final do Array A: ");
            for (int k = low; k <= high; k++) {
                printf("%d ", A[k]);
            }
            printf("\n---------------------------------------------------------\n");
            return;
        }

        // Troca dos elementos
        printf("  Troca realizada: A[%d] (%d) <-> A[%d] (%d)\n", i, A[i], j, A[j]);
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;

        printf("  Array A apos a troca:   ");
        for (int k = low; k <= high; k++) {
            printf("%d ", A[k]);
        }
        printf("\n\n");

        iteracao++;
    }
}

int main() {
    int A[] = {13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21};
    int n = sizeof(A) / sizeof(A[0]);

    demonstrar_hoare_partition(A, 0, n - 1);

    return 0;
}