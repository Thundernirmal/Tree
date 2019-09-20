#include<stdio.h>
#include<stdlib.h>
#define Enter() printf("\n");
typedef struct node{
    int key,height;
    struct node * left, *right;
}Tree;

Tree* newNode(int key)
{
    Tree* node = (Tree*)malloc(sizeof(Tree));
    node->key   = key;
    node->left  = node->right  = NULL;
    node->height = 1;
    return (node);
}

int max(int a,int b){
    return a > b ? a : b;
}

int height(Tree *T){
    if(T==NULL) return 0;
    return T->height;
}

Tree *rightRotate(Tree *x)
{
    Tree *y = x->left;
    x->left = y->right;
    y->right = x;

    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;

    return y;
}

Tree *leftRotate(Tree *x)
{
    Tree *y = x->right;
    x->right = y->left;
    y->left = x;

    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;

    return y;
}

int getBalance(Tree *t){
    if(t==NULL) return 0;
    return height(t->left)-height(t->right);
}

Tree *AVLinsert(Tree *T,int key){
    //STEP 1
    if(T==NULL){
         return newNode(key);
    }
    if(T->key > key){
        T->left = AVLinsert(T->left,key);
    }
    else if(T->key < key){
        T->right = AVLinsert(T->right,key);
    }
    else
    {
        return T;
    }
    //STEP 2
    T->height = max(height(T->left),height(T->right)) + 1;
    //STEP 3
    int balance = getBalance(T);
    if(balance > 1 && key < T->left->key) return rightRotate(T);
    if(balance <-1 && key > T->right->key) return leftRotate(T);

    // Left Right Case 
	if (balance > 1 && key > T->left->key) 
	{ 
		T->left = leftRotate(T->left); 
		return rightRotate(T); 
	} 

	// Right Left Case 
	if (balance < -1 && key < T->right->key) 
	{ 
		T->right = rightRotate(T->right); 
		return leftRotate(T); 
	} 
    return T;
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
Tree * minValueNode(Tree* node) 
{ 
    Tree* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
Tree* deleteNode(Tree* root, int key) 
{ 
    // STEP 1: PERFORM STANDARD BST DELETE 
  
    if (root == NULL) 
        return root; 
  
    // If the key to be deleted is smaller than the 
    // root's key, then it lies in left subtree 
    if ( key < root->key ) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the 
    // root's key, then it lies in right subtree 
    else if( key > root->key ) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is 
    // the node to be deleted 
    else
    { 
        // node with only one child or no child 
        if( (root->left == NULL) || (root->right == NULL) ) 
        { 
            Tree *temp = root->left ? root->left : 
                                             root->right; 
  
            // No child case 
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else // One child case 
             *root = *temp; // Copy the contents of 
                            // the non-empty child 
            free(temp); 
        } 
        else
        { 
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
            Tree* temp = minValueNode(root->right); 
  
            // Copy the inorder successor's data to this node 
            root->key = temp->key; 
  
            // Delete the inorder successor 
            root->right = deleteNode(root->right, temp->key); 
        } 
    } 
  
    // If the tree had only one node then return 
    if (root == NULL) 
      return root; 
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
    root->height = 1 + max(height(root->left), 
                           height(root->right)); 
  
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to 
    // check whether this node became unbalanced) 
    int balance = getBalance(root); 
  
    // If this node becomes unbalanced, then there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && getBalance(root->left) >= 0) 
        return rightRotate(root); 
  
    // Left Right Case 
    if (balance > 1 && getBalance(root->left) < 0) 
    { 
        root->left =  leftRotate(root->left); 
        return rightRotate(root); 
    } 
  
    // Right Right Case 
    if (balance < -1 && getBalance(root->right) <= 0) 
        return leftRotate(root); 
  
    // Right Left Case 
    if (balance < -1 && getBalance(root->right) > 0) 
    { 
        root->right = rightRotate(root->right); 
        return leftRotate(root); 
    } 
  
    return root; 
} 
int main() 
{ 
    Tree *t=NULL;
    int i;
   /* t=AVLinsert(t,5);preOrder(t); Enter();
    t=AVLinsert(t,3);preOrder(t); Enter();
    t=AVLinsert(t,2);preOrder(t); Enter();
    t=AVLinsert(t,6);preOrder(t); Enter();
    t=AVLinsert(t,7);preOrder(t); Enter();
    t=AVLinsert(t,10);preOrder(t); Enter();*/
    for(i=1;i<10;i++){
        t=AVLinsert(t,i);
        preOrder(t);
        Enter();
    }
    printf("Preorder traversal of the modified Splay tree is \n");
    t=deleteNode(t,5); 
    preOrder(t); 
    return 0; 
} 