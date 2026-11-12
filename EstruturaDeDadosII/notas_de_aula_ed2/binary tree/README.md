# Estrutura de Dados: Árvore Binária de Busca (BST)

Este repositório contém uma implementação base de uma **Árvore Binária de Busca (Binary Search Tree - BST)** em linguagem C, juntamente com uma especificação de exercícios práticos para fixação dos conceitos de inserção e percurso em ordem.

---

## Estrutura do Código Base

A estrutura de dados utilizada para representar cada nó da árvore é definida da seguinte forma:

```c
typedef struct node {
    struct node * left;  // Ponteiro para o filho à esquerda
    struct node * right; // Ponteiro para o filho à direita
    int data;            // Valor armazenado no nó
} node;
```

### Funções Fornecidas no Código Base

1. **`create`**: Aloca memória e inicializa um novo nó com o valor informado.
2. **`insert`**: Insere recursivamente um novo nó na árvore mantendo a propriedade da BST (valores menores ou iguais à esquerda, valores maiores à direita).
---

## Especificação dos Exercícios

Os exercícios a seguir devem ser desenvolvidos completando o arquivo principal (`main.c`).

### Exercício 1: Inserção

**Objetivo:** Construir uma árvore binária de busca a partir de uma sequência de valores inseridos informados pelo usuário.

**Especificação e Tarefas:**
1. Na função `main`, declare e inicialize o ponteiro da raiz: `node * root = NULL;`.
2. Solicite ao usuário a entrada de valores inteiros (ou defina um vetor de testes como `{53, 30, 14, 39, 72, 61, 84}`).
3. Para cada valor a ser inserido:
   - Crie o novo nó invocando `create(valor)`.
   - Atualize a raiz invocando `root = insert(root, novo_no)`.
---

### Exercício 2: Exibição dos Elementos da Árvore

**Objetivo:** Implementar funções para percorrer e exibir todos os elementos armazenados na árvore no modo In-Order.

**Protótipos das Funções:**
```c
void print_inorder(node * root);   // Percurso Em-Ordem (In-Order)
```

**Especificação das Funções:**
**`print_inorder` (Em-Ordem):**
   - Visita recursivamente a subárvore esquerda (`root->left`).
   - Imprime o valor do nó atual (`root->data`).
   - Visita recursivamente a subárvore direita (`root->right`).
   - *Nota:* Em uma BST, esta exibição mostra os elementos em ordem crescente.
---

