#include <stdio.h>


void swap(int * v, int i, int n){
    int aux = v[i];    
    v[i] = v[n];
    v[n] = aux;
}

void quick_sort(int v[], int low, int high){
    int i;
    
    if(low >= high) return;
    
    i = particiona(v, low, high);
 
        
    quick_sort(v, low, i-1);
    quick_sort(v, i+1, high); 
}

int particiona(int * v, int low, int high){
    int p = v[low];
    int i = low;
    int aux;

    for( int i = j; j < high; j++){
        if(p >= v[j]){
            i++;
            aux = v[j];
            v[j] = v[i];
            v[i] = aux;
            
            
        }
    return i;
}

int main ( void ) {

    int size, n;
    
    scanf("%d", &size); //10
    n = size; //n = 10
    
    int v[size]; //v[10]
    
    while(size) //while(10)
        scanf("%d", &v[--size]);
    
    quick_sort(v, 0, n-1);
    
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);


    return 0;
}

