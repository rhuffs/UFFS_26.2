#include <stdio.h>
#include <stdlib.h>

/*
 * v e o vetor a ser ordenado
 * b e o resultado
 * len e o tamanho do vetor
 * base e a base a ser utilizada
 * pow representada o digito [1, 10, 100, ...]
*/
 
void counting_sort(int * v, int * b, int len, int base, int pow){
    int * C = (int*)malloc((base+1)*sizeof(int));
    int t;
    
    for(int i = 0; i <= base; i++) C[i] = 0;
    
    for(int j = 0; j < len; j++){ 
        t = (v[j]/pow) % base;
        C[t]++;        
    }
    
    for(int j = 1; j <= base; j++) C[j] = C[j] + C[j-1];
    
    for(int i = len-1; i >= 0; i--){
        t = (v[i]/pow) % base;
        C[t]--;
        b[C[t]] = v[i];
    }   
}


/*escreva a funcao radix_sort fazendo chamadas para a funcao counting sort apresentada previamente*/
