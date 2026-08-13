#include <stdio.h>
#include <stdlib.h>

typedef struct node{
   struct node * left; 
   struct node * right;
   int data;
} node;


node * create( int data ) {
    node * new_node = (node *)malloc(sizeof(node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = data;
    return new_node; 
}

//insere new em uma arvore enraizada por root. Retorna o ponteiro para a raiz. 
node * insert( node * root, node * new_node){
    if( root == NULL ) {
        return new_node;
    }else{
        if( root->data >= new_node->data ){
            root->left = insert(root->left, new_node);
        } else {
            root->right = insert(root->right, new_node);
        }
    }
    return root;
}


void print_inorder(node * root){

    if (root == NULL){
        return;
    }
    print_inorder(root->left);
    printf("%d ",root->data);
    print_inorder(root->right);
}  

int main ( void ) {

    node * root = NULL;

    int vetorTeste[7] = {53,30,14,39,72,61,84};
    for(int i = 0; i <= 7; i++){
        root = insert(root, create(vetorTeste[i]));
    }
    


    print_inorder(root);
    return 0;
}
