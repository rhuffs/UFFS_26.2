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

void print_inorder( node * tree ){
    if(!tree) return;
             
    print_inorder(tree->left);  
    printf("%d ", tree->data);   
    print_inorder(tree->right);
}


int main ( void ) {

    struct node * root = NULL;
    struct node * new;
    
    int size, n;
    
    scanf("%d", &size);
    n = size;
    
    while(size--){
        scanf("%d", &n);
        new = create(n);
        root = insert(root, new); 
    }
    
    print_inorder(root);
    
    return 0;
}
