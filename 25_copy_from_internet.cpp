#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild; 
}Node,*Tree;
void CreateBinTree(Tree *tree)
{
    int ch;
    scanf("%d",&ch);

    if(ch == -1)
    {
        (*tree) = NULL;
    }
    else
    {
        *tree = (Tree)malloc(sizeof(Node));
        (*tree)->data = ch;
        CreateBinTree(&((*tree)->lchild));
        CreateBinTree(&((*tree)->rchild));
    }
}
void Search(Tree T,int m,int n)
{
    if(T)
    {
        Search(T->lchild,m,n);
        if(T->data > m&& T->data < n)printf("%d ",T->data);
        Search(T->rchild,m,n);
    }
}
void Inorder(Tree T)
{
    if(T)
    {
        Inorder(T->lchild);
        printf("%d ",T->data);
        Inorder(T->rchild);
    }
}
void Insert(Tree *T,int key)
{
    if(!(*T))
    {
        (*T) = (Tree)malloc(sizeof(Node));
        (*T)->data = key;
        (*T)->lchild = (*T)->rchild = NULL;
        return;
    }
    if(key == (*T)->data )
        return;
    if(key > (*T)->data )
        Insert( &((*T)->rchild), key );
    else
        Insert( &((*T)->lchild), key );
}
bool Delete(Tree *T)
{
    Tree L;
    if (!(*T)->lchild && !(*T)->rchild)
        *T = NULL;
    else if (!(*T)->lchild)
        *T = (*T)->rchild;
    else if (!(*T)->rchild)
        *T = (*T)->lchild;
    else
    {
        L = (*T)->lchild;
        while (L->rchild)
            L = L->rchild;
        L->rchild = (*T)->rchild;
        *T = (*T)->lchild;
    }
    return true;
}
bool DeleteBST(Tree *T, int key)
{
    if (!*T)
        return false;
    else if (key == (*T)->data)
    {
        Delete(T);
        return true;
    }
    else if (key < (*T)->data)
    {
        return DeleteBST(&((*T)->lchild), key);
    }
    else
    {
        return DeleteBST(&((*T)->rchild), key);
    }
}
int main(){
    Tree T = NULL;
    CreateBinTree(&T);
    int x,y,a,b;
    scanf("%d %d",&x,&y);
    scanf("%d",&a);
    scanf("%d",&b);
    Search(T,x,y);
    printf("\n");
    Insert(&T,a);
    Inorder(T);
    printf("\n");
    DeleteBST(&T,a);
    DeleteBST(&T,b);
    Inorder(T);
    printf("\n");
    return 0;
}
