// Program containing create, display, length, insert,delete and reverse functions for circular doubly linked lists
# include <stdio.h>
# include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*head = NULL;

void Create(int A[], int n)
{   
    int i;
    struct Node*newnode, *temp;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = A[0];
    head->prev = head;
    head->next = head;
    temp = head;

    for(i = 1; i < n; i++)
    {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = A[i];
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = head;
        temp = newnode;
    }
        head->prev = temp; // if this line is missing, entire program crashes
}

int Length(struct Node *p)
{
    int length = 0;
    do
    {
        length++;
        p = p->next;
    } while (p!=head);
    return length;
}
void Display(struct Node *p)
{   
    
    do
    {
        printf("%d\t",p->data);
        p = p->next;
    } while (p!=head);
    printf("\n");
}
void Insert(struct Node *p, int index, int element)
{       
    p=head;
    struct Node *q = NULL;
    int i;
    if(index < 0 || index > Length(p))return;
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = element;
    if(index == 0)
    {
        if(!head)
        {
            newnode->next = newnode;
            newnode->prev = newnode;
            head = newnode;
        }
        else
        {
            newnode->next = head;
            newnode->prev = head->prev;
            head->prev->next = newnode;
            head->prev = newnode;
            head = newnode;
        }
    }
    else
    {
        
        for(i = 1; i <= index; i++)
        {
            q = p;
            p = p->next;
        }
        
        newnode->next = p;
        newnode->prev = q;
        q->next = newnode;
        p->prev = newnode;
    }
}
int Delete(struct Node *p, int index)
{   
    struct Node*q = NULL;
    int x,i;
    if(index < 1 || index > Length(p))return -1;
    if(index == 1)
    {
        x = p->data;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        head = p->next;
        free(p);
        
        
    }
    else
    {
        for(i = 1; i < index; i++)
        {
            q = p;
            p= p->next;
        }
        q->next = p->next;
        p->next->prev = q;
        x = p->data;
        free(p);
        
    }
    return x;
}
void Reverse(struct Node *p)
{
    struct Node*current = head, *nextnode, *tail;

    while(p->next!=head)p = p->next;
        tail = p;
    do
    {
        nextnode = current->next;
        current->next = current->prev;
        current->prev = nextnode;
        current = nextnode;
    } while (current!=head);
    
    current = head;
    head = tail;
    tail = current;
}
int main()
{
    int A[] = {1,2,3,4};
    Create(A,4);
    Display(head);
    printf("Length of the list is %d\n", Length(head));
    Insert(head,4,11);
    Display(head);
    printf("%d\n",Delete(head,1));
    Display(head);
    Reverse(head);
    Display(head);
    
}