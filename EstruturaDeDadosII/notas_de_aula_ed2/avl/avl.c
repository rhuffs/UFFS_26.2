
#include <stdio.h>
#include <stdlib.h>


typedef struct node{
   struct node * left; 
   struct node * right;
   struct node * parent;
   int height;
   int data; 
} node;


node * create( int data ) {
    node * new = (node*)malloc(sizeof(node));
    new->left = NULL;
    new->right = NULL;
    new->parent = NULL;
    new->data = data;
    new->height = 1;
    return new; 
}


node * minimum(node * n){
   if(n->left) return minimum(n->left);
   return n; 
}

node * sucessor(node * n){
    if(n->right){
        return minimum(n->right);
    }    
    node * x = n->parent;
    while(x != NULL && x->right == n){
        n = x;
        x = n->parent;
    }
    return x;
}

//caso esteja vazio, a altura e 0
int height(node * tree){
    if(tree == NULL) return 0;
    return tree->height;
}

//atualiza a altura de uma arvore baseada nos filhos
void fix_height(node * tree){
     int hl = height(tree->left);
     int hr = height(tree->right);
     
     tree->height = (hl > hr ? hl+1: hr+1); //altura do maior filho mais um 
}

node * search(node * tree, int d){
    if(tree->data ==d || tree==NULL) return tree;    
    if(tree->data >= d) return search(tree->left, d);
    else return search(tree->right, d);
}


/******
Tenha em mente que a altura das subarvores a direita e a esquerda podem ser diferir apenas em um antes de insercaoo.
Uma vez que inserimos um elemento, eles podem ter apenas 2 de diferenca. 

insere new em uma arvore enraizada por root. Retorna o ponteiro para a raiz.   
*/

node * rotate_left(node * x){
    node * aux = x->right;
    x->right = aux->left;
    if(aux->left) aux->left->parent=x;
    if(x->parent){
        if(x==x->)
    }
}

node * rotate_right(node * y);


node * fix_right(node * tree);

node * fix_left(node * tree);

node * insert( node * root, node * new ){
    if( root == NULL ) {
        return new;
    }else{
        if( root->data >= new->data ){
            if(!root->left) { //caso nao tenha nada abaixo
                root->left = new;
                new->parent = root;
            } else { 
                insert(root->left, new);
            }
            //root = fix_left(root);   //isso aqui e novo na AVL.
        } else {
            if(!root->right) { //caso nao tenha nada abaixo
                root->right = new;
                new->parent = root;
            }
            else {
               insert(root->right, new);
            }
            //root = fix_right(root);   //isso aqui e novo na AVL.
        }
    }
    return root;
}



//busca em profundidade. Primeiro, abre nodos a esquerda ate o possivel
void dfs( node * tree ){
    if(tree->left) dfs(tree->left);
    printf("%d ", tree->data); 
    if(tree->right) dfs(tree->right);
}



int main ( void ) {

    struct node * root = NULL;
    
    node * new = create(10);
    node * new1 = create(11);
    node * new2 = create(19);
    node * new3 = create(18);
    node * new4 = create(18);
    node * new5 = create(16);
    
    root = insert(root, new);
    root = insert(root, new1);
    root = insert(root, new2);
    root = insert(root, new3);
    root = insert(root, new4);
    root = insert(root, new5);
    printf("\n%d\n",height(root));
    dfs(root);


    return 0;
}
