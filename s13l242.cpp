//Program checking parenthesis of 3 types ({[]}) matching implemented with the help of stack using array
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
int isBalance(struct Stack *s, char *e)
{
    s->size = strlen(e);
    s->top = -1;
    s->A = (char *)malloc(sizeof(char) * s->size);
    for(int i = 0; e[i]!= '\0' ; i++)
    {
        if(e[i] == '(' || e[i] =='{' || e[i] == '[')
            push(s,e[i]);
        else 
        {
            if(s->top == -1)
                return 0; /*not balanced because no closing brackets for opening brackets
            
            else if((e[i] == ')' && pop(s)== '(' )|| (e[i]=='}' && pop(s)=='{' )|| (e[i] == ']' && pop(s)=='['))
                return 1; 
             cant use the above else if because it will check once and return without checkingfurther characters of the string
            instead of this we use a condition whichg will check if the closing braket and the top element of the stack dont match, this will help us in avoiding scanning through the entire string*/    
        
            else if ((e[i] == ')' && pop(s) != '(') || (e[i] == '}' && pop(s) != '{') || (e[i] == ']' && pop(s) != '['))
                return 0;

        }
    }
    if(s->top ==-1) //if stack is empty
        return 1;
    else 
        return 0;    
}
int main()
{   
    struct Stack s;
   char exp[] = "{(([[a+b]*[c-d]])/e)}";
   printf("%d\n", isBalance(&s, exp));
}