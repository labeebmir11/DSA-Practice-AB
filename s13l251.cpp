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


int Evalpostfix(struct Stack *s, char *p)
{
    s->size = strlen(p)+1;
    s->top = -1;
    s->A = (char*)malloc(sizeof(char)* s->size);
    int i,first,second,result;

    for(i = 0; p[i]!='\0';i++)
    {
        if(isOperand(p[i]))
            Push(s,p[i]-'0'); //note the -'0'. If the number we want o push is char 3, if we dont subtract char 0, then the asci value of char 3 will be pushed into the code. by subtracting char 0, we essentially do: char 3(51) -char 0(48). This ensures that 3 is pushed into the stack.
        else   //if the element encountered is an operator
        {
            second = Pop(s); //first element popped out is made the second operand
            first =  Pop(s); // second element popped out is made the first element
            switch(p[i])
            {
                case '+': result = first + second;break;
                case '-': result = first - second;break;
                case '*': result = first * second;break;
                case '/': result = first / second;break;
                                                    
            }
            Push(s,result);
        }

    }
    return  Pop(s);  //last element pushed into the stack will be the final answer

    
}
int main()
{
    struct Stack s;
    char postfix[] = "35*62/+4-";
    
    printf("\n");
    int r = Evalpostfix(&s,postfix);
    printf("%d\n",r);
   
}