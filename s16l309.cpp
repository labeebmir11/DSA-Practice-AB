//Program for generating Binary Search tree from Preorder
# include <stdio.h>
# include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;

}*root = NULL;

struct Stack
{
    int size;
    int top;
    struct Node **A;
};

void Create(struct Stack *s, int size)
{
    s->size = size;
    s->top = -1;
    s->A = (struct Node**)malloc(sizeof(struct Node *) * s->size);
}

void Push(struct Stack *s, struct Node *x)
{
    if(s->top == s->size - 1)
        printf("Stack Overflow\n");
    else
    {
        s->top++;
        s->A[s->top] = x;
    }

}

struct Node* Pop(struct Stack *s)
{   
    struct Node *x = NULL;
    if(s->top == -1)
        printf("Stack Underflow, nothing to pop\n");
    else
    {
        x = s->A[s->top];
        s->top--;
    }    
    return x;
}

int isEmpty(struct Stack s)
{
    if(s.top == -1)
        return 1;  //is empty
    else
        return 0; //not empty    
}
int isFull(struct Stack s)
{
    if(s.top == s.size - 1)
        return 1; //is full
    else
        return 0;
}
struct Node* stackTop(struct Stack s)
{
    if(!isEmpty(s))
        return s.A[s.top];
    else
        return NULL;    
}
int max()
{
    return 1000;
}
int min()
{
    return -1000;
}

struct Node* CreatePre(int preorder[], int n)
{
    struct Stack s;
    Create(&s,50);
    struct Node *newnode, *p;
    int i = 0;

    root = (struct Node*)malloc(sizeof(struct Node));
    root->data = preorder[i++];
    root->lchild = root->rchild = NULL;
    p = root;

    while(i < n)
    {
        if(preorder[i] < p->data )
        {
            newnode = (struct Node*)malloc(sizeof(struct Node));
            newnode->data = preorder[i++];
            newnode->lchild = NULL;
            newnode->rchild = NULL;
            p->lchild = newnode;
            Push(&s, p);
            p = newnode;
        }
        //else if preorder[i] is greater than p->data and it lies between p->data and stacktop element
        //if stack is empty, then consider infinity
        else if(preorder[i] > p->data && preorder[i] < (isEmpty(s)?max(): stackTop(s)->data))
        {
            newnode = (struct Node*)malloc(sizeof(struct Node));
            newnode->data = preorder[i++];
            newnode->lchild = NULL;
            newnode->rchild = NULL;
            p->rchild = newnode;
            p = newnode;
        }
        else
        {
            p = Pop(&s);
        }
    }

    return root;
}

struct Node* CreatePost(int postorder[], int n)
{
    struct Stack s;
    Create(&s,50);
    struct Node *newnode, *p;
    int i = n -1;

    root = (struct Node*)malloc(sizeof(struct Node));
    root->data = postorder[i--];
    root->lchild = root->rchild = NULL;
    p = root;

    while(i >= 0)
    {
        if(postorder[i] > p->data )
        {
            newnode = (struct Node*)malloc(sizeof(struct Node));
            newnode->data = postorder[i--];
            newnode->lchild = NULL;
            newnode->rchild = NULL;
            p->rchild = newnode;
            Push(&s, p);
            p = newnode;
        }
        
        else if(postorder[i] < p->data && postorder[i] > (isEmpty(s)?min(): stackTop(s)->data))
        {
            newnode = (struct Node*)malloc(sizeof(struct Node));
            newnode->data = postorder[i--];
            newnode->lchild = NULL;
            newnode->rchild = NULL;
            p->lchild = newnode;
            p = newnode;
        }
        else
        {
            p = Pop(&s);
        }
    }

    return root;
}

void printIO(struct Node *p)
{
    if(p)
    {
        printIO(p->lchild);
        printf("%d\t", p->data);
        printIO(p->rchild);
    }
}

/*int main()
{
    int preorder[] = {30,20,10,15,25,40,50,45};
    struct Node *s = CreatePre(preorder, 8);
    printf("\n");
    printIO(root);

}*/
int main()
{
    int preorder[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int postorder[] = {15, 10, 25, 20, 45, 50, 40, 30};

    printf("BST from Preorder:\n");
    struct Node *preorderRoot = CreatePre(preorder, 8);
    printIO(preorderRoot);
    printf("\n");

    printf("BST from Postorder:\n");
    struct Node *postorderRoot = CreatePost(postorder, 8);
    printIO(postorderRoot);
    printf("\n");

    return 0;
}
