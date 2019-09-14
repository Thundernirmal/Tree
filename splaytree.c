#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int key;
    struct node * left, *right;
}Tree;

Tree* newNode(int key)
{
    Tree* node = (Tree*)malloc(sizeof(Tree));
    node->key   = key;
    node->left  = node->right  = NULL;
    return (node);
}

Tree *rightRotate(Tree *x)
{
    Tree *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

Tree *leftRotate(Tree *x)
{
    Tree *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

Tree* splay(Tree *tree,int key){
    if((tree==NULL) || (tree->key==key))
        return tree;
    if(tree->key > key){
        if(tree->left ==NULL) return tree;

        if(tree->left->key > key){
            tree->left->left = splay(tree->left->left,key);
            tree= rightRotate(tree);
        }
        else if(tree->left->key < key){
            tree->left->right = splay(tree->left->right,key);
            if(tree->left->right!=NULL)
                tree->left = leftRotate(tree->left);
        }
        return (tree->left == NULL)? tree: rightRotate(tree);
    }
    else{
        if(tree->right==NULL) return tree;
        if(tree->right->key < key){
            tree->right->right = splay(tree->right->right,key);
            tree= leftRotate(tree);
        }
        else if(tree->left->key > key){
            tree->right->left = splay(tree->right->left,key);
            if(tree->right->left!=NULL)
                tree->right = rightRotate(tree->right);
        }
        return (tree->right == NULL)? tree: leftRotate(tree);
    }
}

Tree *search(Tree *root, int key) 
{ 
    return splay(root, key); 
} 

void preOrder(Tree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() 
{ 
    Tree *root = newNode(100); 
    root->left = newNode(50); 
    root->right = newNode(200); 
    root->left->left = newNode(40); 
    root->left->left->left = newNode(30); 
    root->left->left->left->left = newNode(20); 
  
    root = search(root, 20); 
    printf("Preorder traversal of the modified Splay tree is \n"); 
    preOrder(root); 
    return 0; 
} 