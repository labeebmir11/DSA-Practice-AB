//Program to implement Binary Tree using a circular array based queue
# include <stdio.h>
# include <stdlib.h>

struct Node
{
    struct Node *lchild;
    struct Node *rchild;
    int data;
}*root = NULL;

struct Stack
{
    int size;
    int top;
    struct Node **S; // the stack is an array which will store the address of nodes.
};

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q; //Queue is going to store address of nodes, so struct Node *Q 
    //Queue is an array of addresses of nodes and we create queue dynaically so struct Node **Q
};

void create(struct Queue *p)
{
    p->size = 100;
    p->rear = p->front = 0;
    p->Q = (struct Node **)malloc(sizeof(struct Node *) * p->size);
}

void enqueue(struct Queue *p, struct Node *x)
{
    if((p->rear + 1)%p->size == p->front) printf("Queue is full\n");
    p ->rear = (p->rear + 1)%p->size;
    p->Q[p->rear] = x;
}

struct Node* dequeue(struct Queue *p) // we are removing address of a node from the queue, so we return the adress
{   
    struct Node *x = NULL;
    if(p->front == p->rear)printf("Queue is Empty,nothing to delete\n");
    p->front = (p->front + 1)% p->size;
    x = p->Q[p->front];

    return x;
}

int isEmpty(struct Queue *p)
{
    if(p->front == p->rear)return 1;

    return 0;
}

void CreateStack(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
     st->S = (struct Node **)malloc(sizeof(struct Node*) * st->size );
}
   // st->S // the array will be storing address of nodes i.e: pointer to nodes :: new Node*
   

void PushStack(struct Stack *st, struct Node *x)
{
    if(st->top == st->size - 1)
        printf("Stack overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;}    
}
struct Node* PopStack(struct Stack *st)
{   
    struct Node *temp = NULL;
    if(st->top == -1)
        printf("Stack underflow, nothing to pop\n");
    else
    {
        temp = st->S[st->top];
        st->top--;
    }    
    return  temp;
}

void createTree()
{
    struct Node *newnode, *p;
    int x;
    struct Queue q;
    create(&q);

    printf("Enter root value\n");
    scanf("%d",&x);

    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;
    enqueue(&q,root);

    while(!isEmpty(&q)) //while the queue doesnt become empty
    {   
        p =  dequeue(&q);
        printf("Enter the value of lchild (-1 for no node) of %d\n",p->data);
        scanf("%d",&x);

        if(x!=-1)
        {
            newnode = (struct Node*)malloc(sizeof(struct Node));
            newnode->data = x;
            newnode->lchild = NULL;
            newnode->rchild = NULL;
            
            enqueue(&q,newnode);
            p->lchild = newnode;
        }
        printf("Enter the value of rchild (-1 for no node) of %d\n",p->data);
        scanf("%d",&x);

        if(x!=-1)
        {
            newnode = (struct Node*)malloc(sizeof(struct Node));
            newnode->data = x;
            newnode->lchild = NULL;
            newnode->rchild = NULL;
            
            enqueue(&q,newnode);
            p->rchild = newnode;
        }
    }
}

void Preorder(struct Node *p)
{
    //Node,left,right
    if(p)
    {
    printf("%d\t",p->data);
    Preorder(p->lchild);
    Preorder(p->rchild);
    }
}

void Postorder(struct Node *p) // Left, Right, Node
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d\n",p->data);
    }
}

void Inorder(struct Node *p)
{
    //left,node,right
    if(p){
    Inorder(p->lchild);
    printf("%d\n",p->data);
    Inorder(p->rchild);}

}
void Ipreorder(struct Node *p) // Node,lchild,rchild
{
    struct Stack *st;
    CreateStack(st, 100);
    struct Node *t = p, *temp;
    while(t!=NULL || st->top!=-1)
    {
        if(t!=NULL)
        {
            printf("%d\t", t->data);
            PushStack(st, t);
            t = t->lchild;

        }
        else
        {
            t = PopStack(st);
            t = t->rchild;

        }
    }
}



void Iinorder(struct Node *p) // lchild, node, rchild
{
    struct Stack *st;
     CreateStack(st,100);

    struct Node *t = p, *temp;
    while(t!=NULL || st->top!=-1)
    {
        if(t!=NULL)
        {   
            PushStack(st, t);
            t = t->lchild;

        }
        else
        {
            t = PopStack(st);
            printf("%d\t", t->data);
            t = t->rchild;

        }
    }
}
void Ipostorder(struct Node *p) //lchild,rchild,node
{
    struct Stack *st;
    CreateStack(st,100);
    long int temp;
    struct Node *t = p;
    while(t!=NULL || st->top!=-1)
    {   
        if(t!=NULL){
        PushStack(st,t);
        t = t->lchild;
        }
        else
        {
            temp =(long int) PopStack(st);
            if(temp > 0) //then push the negative adress into stack and make t point to temp's r child
            {
                PushStack(st,(struct Node *)(-temp));
                t = ((struct Node*)temp)->rchild;
            }
            else //if less than 0, then print temps data and put t to NULL
            {
                printf("%d\t",((struct Node *)(-temp))->data);
                t = NULL;
            }// when performing operations about address, typecast by struct Node * and when storing in long int, typecast by long int
        }
    }
}             



int main()
{
    createTree();
    printf("Postorder:\n");
    Postorder(root);
    printf("\n");
    printf("Iterative postorder: \n");
    Ipostorder(root);
//     printf("\nPost Order ");
//     Postorder(root);
}