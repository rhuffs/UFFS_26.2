# Exercício: Radix Sort a partir do Counting Sort

## Objetivo

Implementar o `radix_sort` **apenas fazendo chamadas** à função `counting_sort` deste repositório, que já foi adaptada para ordenar por um único dígito.


Inspire-se no pseudocódigo discutido em aula: 


<details>
<summary>Pseudocódigo</summary>

```text
função radixSort(A[], B[], n, base)
início
    max     = maior(A, n)
    digitos = numDigitos(max, base)
    pow     = 1

    para i = 0 até digitos - 1 faça
        countingSort(A, B, n, base, pow)
        copiar(B, A, n)          // B vira entrada do próximo passo
        pow = pow * base
    fim para
fim
```

</details>
