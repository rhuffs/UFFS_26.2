Quicksort


- Particiona o array em dois sub-arrays cujos elementos do array à esquerda são menores e os da direita, maiores do que um pivot
- Ordena recursivamente cada um dos subarrays

#Exemplo: 
      [7, 1, 5, 6, 2, 4, 9, 3] - [1, 2, _3_, 6, 7, 4, 9, 5] 
      [1, 2, 3, 4, _5_, 6, 9, 7] - [1, 2, 3, 4, 5, 6, _7_, 9]   


# Analise da particao 

-- Proporcional ao número de comparações

# Analise de QuickSort

-- Pode ser escrito com a seguinte recorrência $T(n) = 2 T\left(\frac{n}{2}\right) + O(n)$

- Arvore de recorrência: a árvore de recursão é expandida até o caso base $O(1)$
- expansão ocorre até que $n/2^i = 1$. Ou seja, altura da arvore é $log_2(n)$. 
- Todos os nodos sao visitados pela recorrência: cada nivel $i$ tem $2^i$ nodos. 
- Custo de cada nodo é $O(n/2^i)$. 

$$\sum_{i=0}^{\log_2(n)} \left(2^i \cdot \frac{n}{2^i}\right) = \sum_{i=0}^{\log_2(n)} n = O(n \log n)$$

# Exercício

-- Escreva uma função de particionamento do QuickSort
