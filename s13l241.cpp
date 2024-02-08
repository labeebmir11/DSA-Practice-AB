//Program checking parenthesis matching implemented with the help of stack using array
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct Stack
{
    int size;
    int top;
    char *A;
};
void push(struct Stack *s, char ch)
{   
    if(s->top == s->size - 1){
        printf("Stack overflow, element can't be pushed\n");
        return;}

    s->top++;
    s->A[s->top] = ch;

}
char pop(struct Stack *s)
{   
    char ch = '\0';
    if(s->top == -1)
    {
        printf("Stack is empty, nothing to pop!\n");
            return ch;
    }
    else{
        ch = s->A[s->top];
        s->top--;
        return ch;
    }
    return ch;
}
int isBalance(char *exp, struct Stack *s)
{   
    int i;
    s->size = strlen(exp);
    s->top = -1;
    s->A = (char *)malloc(sizeof(char) * s->size );
    for(i = 0; exp[i]!='\0';i++)
    {
        if(exp[i] == '(')
            push(s, exp[i]);
        else if(exp[i] == ')')
        {
            if(s->top!=-1)
                pop(s);
            else //stack is empty
                return 0; //not balanced    
        }    
    }
    return (s->top != -1)?0:1;
}
int main()
{   
    struct Stack s;
   char exp[] = "(((a + b) * (c + d)))";
   printf("%d\n", isBalance(exp,&s));
}