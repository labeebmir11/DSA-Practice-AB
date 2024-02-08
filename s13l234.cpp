// Program to implement stack using Array
# include <stdio.h>
# include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *A;
};
void Create(struct Stack *s)
{
    printf("Enter the required size of the stack\n");
    scanf("%d", &s->size);
    s->top = -1;
    s->A = (int *)malloc(sizeof(int) * s->size);
}
void Display(struct Stack s)
{
    int i;
    for(i = s.top; i >= 0; i--)
    {
        printf("%d\n", s.A[i]);
    }
    printf("\n");
}
void Push(struct Stack *s, int x)
{
    if(s->top == s->size - 1)
        printf("Stack Overflow\n");
    else
    {
        s->top++;
        s->A[s->top] = x;
    }

}
int Pop(struct Stack *s)
{   
    int x = -1; //return -1 even if nothing is popped in case of underflow
    if(s->top == -1)
        printf("Stack Underflow, nothing to pop\n");
    else
    {
        x = s->A[s->top];
        s->top--;
    }    
    return x;
}
int peek(struct Stack *s, int position)
{   
    int x = -1;
    int index = s->top - position + 1;
    if(index < 0)
        printf("Invalid position\n");
    else
    {
       x = ("%d\t", s->A[index]);
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
int stackTop(struct Stack s)
{
    if(!isEmpty(s))
        return s.A[s.top];
    else
        return -1;    
}
int main()
{   
    struct Stack s;
    Create(&s);

    Push(&s, 1);Push(&s, 2);Push(&s, 3);Push(&s, 4);Push(&s, 5);
    Display(s);
    
    printf("%d\n",peek(&s,4));

    
   
    
}
