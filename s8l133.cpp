// program to change case of a string
# include <stdio.h>

int main()
{
    char s[10] = "WELCOME";
    
    for(int i = 0; s[i]!='\0'; i++)
    {
        if(s[i]>= 65  && s[i]<=90)
            s[i]+=32;
    }
    printf("%s\n", s);
}