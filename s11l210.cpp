// This program contains functions related to circular linked list
# include <stdio.h>
# include <stdlib.h>

struct CirNode
{
    int data;
    struct CirNode*next;
}*head = NULL;

void Create(int A[], int n)
{   
    struct CirNode *temp, *newnode;
    int i;
    head = (struct CirNode*)malloc(sizeof(struct CirNode));
    head->data = A[0];
    head->next = head;
    temp = head;

    for(i = 1; i < n; i++)
    {
        newnode = (struct CirNode *)malloc(sizeof(struct CirNode));
        newnode->data = A[i];
        newnode->next = head;
        temp->next = newnode;
        temp = newnode;
    }
}

void Display(struct CirNode *p)
{
    do
    {
        printf("%d\t",p->data);
        p = p->next;
    } while (p!=head);
    
}

int Length(struct CirNode *p)
{   
    int length = 0;
    do
    {
        length++;
        p = p->next;
    } while (p!=head);
    return length;
}

void RecursiveDisplay(struct CirNode *p)
{
    static int flag = 0;
    if(p!=head || flag == 0)
    {
        flag = 1;
        printf("%d\t",p->data);
        RecursiveDisplay(p->next);
    }
    flag = 0; // setting flag back to zero as it is a static variable. this is done for the next recursive call 
}

void Insert(struct CirNode *p, int index, int element)
{   
    int i;
    if(index < 0 || index > Length(p))return;
    struct CirNode *newnode;
    newnode = (struct CirNode *)malloc(sizeof(struct CirNode));

    if(index == 0)
    {
        newnode->data = element;
        newnode->next = head;
        while(p->next!=head)
        {
            p = p->next;
        }
        p->next = newnode;
    }
    else
    {
        for(i = 0 ; i < index -1; i++)
        {
            p = p->next;
        }
        newnode->data = element;
        newnode->next = p->next;
        p->next = newnode;
    }
    
}
/*  the following code includes the condition if head is initially pointing to null
void Insert(struct CirNode *p, int index, int element)
{   
    int i;
      if(index < 0 || index > Length(p))return;
    struct CirNode *newnode;
    newnode = (struct CirNode *)malloc(sizeof(struct CirNode));

    if (index == 0)
    {
        newnode->data = element;
        if (head == NULL)  // If the list is initially empty
        {
            head = newnode;
            newnode->next = head;  // Point the new node to itself
        }
        else
        {
            newnode->next = head;
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = newnode;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        newnode->data = element;
        newnode->next = p->next;
        p->next = newnode;
    }
}
*/

int Delete(struct CirNode *p, int index)
{
    if(index <= 0 || index > Length(head))return -1; //invalid index
    int x,i;
    if(index == 1) // deleting the head node
    {
        while(p->next!=head)
        {
            p = p->next;
        }
        x = head->data;
        if(head == p)// this will happen only if head node is the only node
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else
    {
        struct CirNode *q = NULL; //trailing pointer
        for(i = 0; i < index -1; i++)
        {
            q = p;
            p = p->next;
        }    
        q->next = p->next;
        x = p->data;
        free(p);
    }
    return x;
}
/*int Delete2(struct CirNode *p, int index)
{
    struct CirNode *q;
    int i, x;

    if (index < 0 || index > Length(head))
        return -1;

    if (index == 1)
    {
        while (p->next != head)
            p = p->next;
        x = head->data;

        if (head == p)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else
    {
        for (i = 0; i < index - 2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }

    return x;
}*/

int main()

{
    int A[] = {1,2,3,4,50};
    Create(A,5);
    printf("%d\n",Delete(head,5));
    
    RecursiveDisplay(head);
}