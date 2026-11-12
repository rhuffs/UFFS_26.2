# Operações de Balanceamento em Árvores Binárias (C)

Este repositório contém uma coleção de funções auxiliares em linguagem C para rotações e correções de balanceamento.

## Funções que devem ser implementadas

| Função | Assinatura | Descrição |
| :--- | :--- | :--- |
| **Rotação à Esquerda** | `node * rotate_left(node * x)` | Realiza uma rotação simples à esquerda a partir do nó `x`. |
| **Rotação à Direita** | `node * rotate_right(node * y)` | Realiza uma rotação simples à direita a partir do nó `y`. |
| **Correção à Direita** | `node * fix_right(node * tree)` | Rebalanceia a subárvore à direita quando há desbalanceamento. |
| **Correção à Esquerda** | `node * fix_left(node * tree)` | Rebalanceia a subárvore à esquerda quando há desbalanceamento. |
