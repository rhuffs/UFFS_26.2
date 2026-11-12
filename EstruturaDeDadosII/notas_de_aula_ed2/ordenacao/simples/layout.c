#include <stdio.h>

void swap(int * v, int i, int n){
    int aux = v[i];
    
    v[i] = v[n];
    v[n] = aux;
}


int main ( void ) {

    int size, n;
    
    scanf("%d", &size);
    n = size;
    
    int v[size];
    
    while(size)
        scanf("%d", &v[--size]);
    
    //chame sua funcao de ordenacao aqui
    
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);


    return 0;
}
