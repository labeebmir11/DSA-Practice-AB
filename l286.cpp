//Program to implement tree using recursion
# include <stdio.h>
# include <stdlib.h>

struct Node 
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* create()
{
    int x;
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data(-1 for no node)\n");
    scanf("%d",&x);
    if(x == -1)
        return 0;
    newnode->data = x;
    printf("Enter the left child of %d(-1 for no left child)\n",x);
    newnode->left = create(); 
    printf("Enter the right child of %d(-1 for no right child)\n",x);
    newnode->right = create();

    return newnode;   
}
int main()
{
    struct Node *root;
    root = create();
}