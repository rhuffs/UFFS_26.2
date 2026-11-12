#include <stdio.h>


void swap(int * v, int i, int n){
    int aux = v[i];    
    v[i] = v[n];
    v[n] = aux;
}

void quick_sort(int * v, int low, int high){
    int i;
    
    if(low >= high) return;
    
    i = particiona(v, low, high);
 
        
    quick_sort(v, low, i-1);
    quick_sort(v, i+1, high); 
}

int main ( void ) {

    int size, n;
    
    scanf("%d", &size);
    n = size;
    
    int v[size];
    
    while(size)
        scanf("%d", &v[--size]);
    
    quick_sort(v, 0, n-1);
    
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);


    return 0;
}
