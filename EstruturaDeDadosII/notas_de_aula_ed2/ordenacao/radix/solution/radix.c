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


int v_max(int * v, int len){
    int i = 0;
    int max = v[i];
    
    
    for (i = 1; i< len; i++)
        if(v[i] > max) max = v[i]; 

    return max;
}


void copy(int * v, int * u, int len){
    for(int i = 0; i < len; i++)
       u[i] = v[i];
}

void radix_sort(int * v, int * b, int len, int base){
    int max = v_max(v, len);
    int digits = 0;
    
    
    do{
        max = max / 10;
        digits++;
    }while(max);
    
    
    
    int pow = 1;
    for(int i = 0; i < digits; i++) {
        counting_sort(v, b, len, base, pow);
        copy(b, v, len);        
        pow *=10;
    }
    
}



int main ( void ) {

    int size, n;
    
    scanf("%d", &size);
    n = size;
    
    int v[size];
    int b[size];
    
    while(size)
        scanf("%d", &v[--size]);
    
    
    radix_sort(v, b, n, 10);
    
    for (int i = 0; i < n; i++)
        printf("%d ", b[i]);


    return 0;
}
