// Program to implement stack using Linked List
# include <stdio.h>
# include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top = NULL;

void Push(int x)
{
    struct Node *newnode;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    if(newnode == NULL)
        return;
    else
    {
        newnode->data = x;
        newnode->next = top;
        top = newnode;
    }    
}
int pop()   //printing the topmost element of the stack
{       
    struct Node *p = top;
    int x = -1;
    if(top == NULL) //if the list is empty
        printf("Stack is empty, nothing to pop\n");
    else
    {
        top = top->next;
        x = p->data;
        free(p);
    }
    return x;
}
void Display()
{
    struct Node *p = top;
    if(top == NULL)
        printf("Empty stack, nothing to display\n");
    else
    {
        while(p!=NULL)
        {
            printf("%d\t",p->data);
            p = p->next;
        }
        printf("\n");
    }    
}
int peek(int index)
{   
    int x = -1;
    int i;
    struct Node *p = top;
   
    for(i = 1; p && i < index; i++)
    {   
        p = p->next;
    }
    if(p)
    {
        x = p->data;
        return x;
    }
     return x;   
        
}
int stackTop()
{
    if(top)
        return top->data;
    return -1;    
}
int isEmpty()
{
    if(top == NULL)
        return 1; //is empty
    return 0;    //is not empty
}
int isFull()
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    if(newnode == NULL)
        return 1; //is full
    return 0;    //is not full
}
int main()
{
    Push(1);Push(2);Push(3);Push(4);
    Display();
    //printf("Popped element is %d\n", pop());
    //printf("Popped element is %d\n", pop());
    printf("%d\n",peek(6));
   // Display();

}