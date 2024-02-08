//Program to convert infix to postfix using a stack
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct Stack
{
    int size;
    int top;
    char *A;
};
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
int isEmpty(struct Stack s)
{
    if(s.top == -1)
        return 1;  //is empty
    else
        return 0; //not empty    
}
int stackTop(struct Stack s)
{
    if(!isEmpty(s))
        return s.A[s.top];
    else
        return -1;    
}
int isOperand(char ch)
{
    if(ch== '+' ||ch=='-' ||ch=='*' ||ch=='/') //these are operators
        return 0;
    else
        return 1;    
}
int precedence(char ch)
{
    if(ch=='+' || ch=='-')
        return 1;
    else if(ch == '*' || ch =='/')
        return 2;
    else
        return 0;        
}
char* convert(struct Stack *s, char*infix)
{
    s->size = strlen(infix);
    s->top = -1;
    s->A = (char*)malloc(sizeof(char) * strlen(infix)); //this will act as our stack
    int i = 0, j = 0;
    char* postfix = (char*)malloc(sizeof(char)* (strlen(infix) + 2));//this will be the output array displaying the postfix
    while(infix[i]!='\0')
    {
        if(isOperand(infix[i])) //operands are directly copied to the postfix array
            postfix[j++] = infix[i++];
        else //if it is an operator
        {
            if(precedence(infix[i]) > precedence(stackTop(*s)))
                Push(s,infix[i++]);
            else
            {
                postfix[j++] = Pop(s);
            }    

        }    
    }
    while(!isEmpty(*s))// if there are still elements present in the stack
    {
        postfix[j++] = Pop(s);
    }
    postfix[j] = '\0'; //terminating the postfix string

    return postfix;
}

int Evalpostfix(struct Stack *s, char *p)
{
    s->size = strlen(p);
    s->top = -1;
    s->A = (char*)malloc(sizeof(char)* s->size);
    int i = 0,first,second,result;

    for(i = 0; p[i]!='\0';i++)
    {
        if(isOperand(p[i]))
            Push(s,p[i++]);
        else   //if the element encountered is an operator
        {
            second = Pop(s); //first element popped out is made the second operand
            first =  Pop(s); // second element popped out is made the first element
            switch(p[i])
            {
                case '+': result = first + second;
                          Push(s,result);
                          break;
                case '-': result = first - second;
                          Push(s,result);
                          break;  
                case '*': result = first * second;
                          Push(s,result);
                          break;  
                case '/': result = first / second;
                          Push(s,result);
                          break;                             
            }
        }

    }
    return  Pop(s);  //last element pushed into the stack will be the final answer

    
}
int main()
{
    struct Stack s;
    char exp[] = "a+b*c-d/e";
    char *e = convert(&s, exp);
    printf("\n");
    for(int i = 0; i < strlen(exp); i++)
    {
        printf("%c ", e[i]);
    }
}