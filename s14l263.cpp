//Program to implement queue using linked list
# include <stdio.h>
# include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*front = NULL , *rear = NULL;

void enqueue(struct Node *s, int x)
{   
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->next = NULL;
    if(front == NULL)//if we are inserting the first element of the queue
         front = rear = newnode;
    else
    {
        rear->next = newnode;
        rear = newnode;
    }     
}

int dequeue(struct Node *s)
{   
    int x = -1;
    struct Node *p = front;
    //First we check if the list is empty
    if(front==NULL)
        printf("List is empty, no element to delete!\n");
    else
    {
        front =front->next;
        x = p->data;
        free(p);
    }   
    return x; 
}
void Display(struct Node s)
{
    struct Node *p = front;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int A[] = {1,3,5,7,9};
    int size = sizeof(A)/sizeof(A[0]);

    for(int i = 0; i < size; i++)
    {
        enqueue(front,A[i]);
    }
    Display(*front);
    printf("Deleted element is: %d\n",dequeue(front));
    Display(*front);
}