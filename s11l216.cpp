// Program for doubly linked list
# include <stdio.h>
# include <stdlib.h>

struct DNode
{
    struct DNode *prev;
    int data;
    struct DNode *next;
}*first = NULL;

void Create(int A[], int n)
{   
    int i;
    struct DNode *newnode, *temp;
    first = (struct DNode*)malloc(sizeof(struct DNode));
    first->prev = NULL;
    first->data = A[0];
    first->next = NULL;
    temp = first;

    for(i = 1; i < n; i++)
    {
        newnode = (struct DNode*)malloc(sizeof(struct DNode));
        temp->next = newnode;
        newnode->prev = temp;
        newnode->data = A[i];
        newnode->next = NULL;
        temp = newnode;
    }

}

void Display(struct DNode *p)
{
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p = p->next;
    }
    printf("\n");
}

int Length(struct DNode *p)
{
    int length = 0;
    while(p!=NULL)
    {
        length++;
        p = p->next;
    }
    return length;
}

void Insert(struct DNode *p, int index, int element)
{   
    int i;
    if(index < 0 || index > Length(p))return;
    struct DNode *newnode = (struct DNode*)malloc(sizeof(struct DNode));
    
    if(index == 0)
    {
        p->prev = newnode;
        newnode->next = first;
        newnode->prev = NULL;
        newnode->data = element;
        first = newnode;
    }
    
    else
    {
        for(i = 1; i < index; i++) p = p->next;
        newnode->prev = p;
        newnode->data = element;
        newnode->next = p->next;
        if(p->next)p->next->prev = newnode;
        p->next = newnode;
    }
}

int Delete(struct DNode *p, int index)
{       
    struct DNode *q =   NULL;
    int x,i;
    if(index < 1 || index > Length(p))return -1;//invalid index
    if(index == 1)
    {
        first = first->next;
        if(first)first->prev = NULL;
        x = p->data;
        free(p);
        
    }
   else
    {
        for(i = 1; i < index; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        
        if(p->next)
            p->next->prev = q;    
        x = p->data;
        free (p);
        
    }
    return x;
}

void Reverse(struct DNode *p)
{
    struct DNode *current = first, *nextnode, *tail;
    // Assigning tail to last element:
    while(p->next !=NULL)
    {
        p= p->next;
    }
    tail = p;
    //Swapping next and prev of each node:
    while(current!=NULL)
    {
        nextnode = current->next;
        current->next = current->prev;
        current->prev = nextnode;
        current = nextnode;
    }
    //After swapping is done, we interchange first and tail pointer using current or nextnode pointer
    current = tail;
    tail = first;
    first = current;

}

int main()
{
    int A[] = {1,2,4,5};
    Create(A,4);
    
    Display(first);
    Reverse(first);
    Display(first);


   /* printf("%d\n",Length(first));
      Insert(first,4,3);
      Delete(first,1);*/

}