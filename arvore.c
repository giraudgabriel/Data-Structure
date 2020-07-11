
// C program to demonstrate delete operation in binary search tree 
#include<stdio.h> 
#include<stdlib.h> 
  
typedef struct no 
{ 
    int chave; 
    struct no *esq, *dir; 
}no; 
  
no *novoNo(int item) 
{ 
    no *temp =  (no *)malloc(sizeof(no)); 
    temp->chave = item; 
    temp->esq = temp->dir = NULL; 
    return temp; 
} 
  
void erd(no *root) 
{ 
    if (root != NULL) 
    { 
        erd(root->esq); 
        printf("%d ", root->chave); 
        erd(root->dir); 
    } 
} 
  
no* inserir(no* no, int chave) 
{ 
    if (no == NULL) return novoNo(chave); 
    if (chave < no->chave) 
        no->esq  = inserir(no->esq, chave); 
    else
        no->dir = inserir(no->dir, chave); 
    return no; 
} 
  
no * menorValorNo(no* no) 
{ 
    if(no && no->esq != NULL) menorValorNo(no->esq);
    return no; 
} 
  
no* removerNo(no* root, int chave) 
{ 
    // base case 
    if (root == NULL) return root; 
    // If the chave to be deleted is smaller than the root's chave, 
    // then it lies in esq subtree 
    if (chave < root->chave) 
        root->esq = removerNo(root->esq, chave); 
    // If the chave to be deleted is greater than the root's chave, 
    // then it lies in dir subtree 
    else if (chave > root->chave) 
        root->dir = removerNo(root->dir, chave); 
    // if chave is same as root's chave, then This is the no 
    // to be deleted 
    else
    { 
        // no with only one child or no child 
        if (root->esq == NULL) 
        { 
            no *temp = root->dir; 
            free(root); 
            return temp; 
        } 
        else if (root->dir == NULL) 
        { 
            no *temp = root->esq; 
            free(root); 
            return temp; 
        } 
        // no with two children: Get the erd successor (smallest 
        // in the dir subtree) 
        no* temp = menorValorNo(root->dir); 
        // Copy the erd successor's content to this no 
        root->chave = temp->chave; 
        // Delete the erd successor 
        root->dir = removerNo(root->dir, temp->chave); 
    } 
    return root; 
} 
  
// Driver Program to test above functions 
int main() 
{ 
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    no *root = NULL; 
    root = inserir(root, 50); 
    root = inserir(root, 30); 
    root = inserir(root, 20); 
    root = inserir(root, 40); 
    root = inserir(root, 70); 
    root = inserir(root, 60); 
    root = inserir(root, 80); 
  
    return 0; 
} 