//Program to generate tree by traversal using inorder and preorder
# include <stdio.h>
# include <stdlib.h>

struct Node
{
    Node *lchild;
    Node *rchild;
    int data;
};
struct Node* createNode(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    return newnode;

}

int search(int inorder[], int inoStart, int inoEnd, int curr)
{
    for(int i = inoStart; i <= inoEnd; i++)
    {
        if(inorder[i] == curr)
            return i;
      
    }
    return -1;
}

void inorderPrint(struct Node *p)
{   
    if(p){
    inorderPrint(p->lchild);
    printf("%d\t", p->data);
    inorderPrint(p->rchild);
    }
}

struct Node* buildTree(int preorder[], int inorder[], int inoStart, int inoEnd)
{   
    struct Node *newnode;

    static int pidx = 0; //index of pre order array
    if(inoStart > inoEnd)return NULL;
    int curr = preorder[pidx]; //0th element of preorder array is the root and is stored in curr.
    pidx++;
    newnode = createNode(curr); //node has been formed

    //now search for the position of curr (0th element of preorder) in inorder
    if(inoStart == inoEnd)return newnode;
    int pos = search(inorder, inoStart, inoEnd, curr);
    newnode->lchild = buildTree(preorder, inorder, inoStart,pos-1);
    newnode->rchild = buildTree(preorder,inorder,pos+1, inoEnd);
return newnode;

}

int main()
{
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};

   struct Node *s =  buildTree(preorder,inorder, 0, 4);
   inorderPrint(s);
}