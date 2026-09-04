
#include <stdio.h>
#include <stdlib.h>

/*
 * Função responsável pela leitura dos elementos
 * do vetor.
 */
void leitura(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

/*
 * Função responsável por exibir os elementos
 * do vetor.
 */
void exibicao(int *vetor, int tamanho)
{
    printf("\nVetor ordenado:\n");

    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }

    printf("\n");
}

/*
 * Função responsável por intercalar duas partes
 * já ordenadas do vetor.
 *
 * inicio -> primeira posição da parte esquerda
 * meio   -> última posição da parte esquerda
 * fim    -> última posição da parte direita
 */
void merge(int *vetor, int inicio, int meio, int fim)
{
    int tamanhoEsquerda = meio - inicio + 1;
    int tamanhoDireita = fim - meio;

    /*
     * Alocação dinâmica dos vetores auxiliares.
     */
    int *esquerda = malloc(tamanhoEsquerda * sizeof(int));
    int *direita = malloc(tamanhoDireita * sizeof(int));

    if (esquerda == NULL || direita == NULL)
    {
        printf("Erro ao alocar memoria.\n");

        free(esquerda);
        free(direita);

        exit(1);
    }

    /*
     * Copia a parte esquerda do vetor
     * para o vetor auxiliar.
     */
    for (int i = 0; i < tamanhoEsquerda; i++)
    {
        esquerda[i] = vetor[inicio + i];
    }

    /*
     * Copia a parte direita do vetor
     * para o vetor auxiliar.
     */
    for (int i = 0; i < tamanhoDireita; i++)
    {
        direita[i] = vetor[meio + 1 + i];
    }

    /*
     * Índices utilizados para percorrer
     * os vetores auxiliares.
     */
    int i = 0;
    int j = 0;

    /*
     * k representa a posição que será
     * preenchida no vetor original.
     */
    int k = inicio;

    /*
     * Compara os elementos das duas partes
     * e coloca o menor no vetor original.
     */
    while (i < tamanhoEsquerda && j < tamanhoDireita)
    {
        if (esquerda[i] <= direita[j])
        {
            vetor[k] = esquerda[i];
            i++;
        }
        else
        {
            vetor[k] = direita[j];
            j++;
        }

        k++;
    }

    /*
     * Caso ainda existam elementos na
     * parte esquerda, copia para o vetor.
     */
    while (i < tamanhoEsquerda)
    {
        vetor[k] = esquerda[i];

        i++;
        k++;
    }

    /*
     * Caso ainda existam elementos na
     * parte direita, copia para o vetor.
     */
    while (j < tamanhoDireita)
    {
        vetor[k] = direita[j];

        j++;
        k++;
    }

    /*
     * Libera a memória auxiliar.
     */
    free(esquerda);
    free(direita);
}

/*
 * Função recursiva do Merge Sort.
 */
void mergeSort(int *vetor, int inicio, int fim)
{
    /*
     * Continua dividindo enquanto houver
     * pelo menos dois elementos.
     */
    if (inicio < fim)
    {
        /*
         * Calcula o ponto médio.
         *
         * Essa forma evita possíveis problemas
         * de overflow de inteiros.
         */
        int meio = inicio + (fim - inicio) / 2;

        /*
         * Ordena recursivamente a metade esquerda.
         */
        mergeSort(vetor, inicio, meio);

        /*
         * Ordena recursivamente a metade direita.
         */
        mergeSort(vetor, meio + 1, fim);

        /*
         * Intercala as duas partes ordenadas.
         */
        merge(vetor, inicio, meio, fim);
    }
}

int main()
{
    int tamanho;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    /*
     * Verificação para evitar tamanho inválido.
     */
    if (tamanho <= 0)
    {
        printf("O tamanho deve ser maior que zero.\n");
        return 1;
    }

    /*
     * Alocação dinâmica do vetor principal.
     */
    int *vetor = malloc(tamanho * sizeof(int));

    if (vetor == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    /*
     * Leitura dos elementos.
     */
    leitura(vetor, tamanho);

    /*
     * Ordenação utilizando Merge Sort.
     *
     * O vetor começa na posição 0
     * e termina em tamanho - 1.
     */
    mergeSort(vetor, 0, tamanho - 1);

    /*
     * Exibição do resultado.
     */
    exibicao(vetor, tamanho);

    /*
     * Liberação da memória do vetor principal.
     */
    free(vetor);

    return 0;
}