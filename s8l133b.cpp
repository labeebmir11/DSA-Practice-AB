// program to toggle case of a string
# include <stdio.h>

int main()
{
    char s[10] = "WeLComE";
    
    for(int i = 0; s[i]!='\0'; i++)
    {
        if(s[i]>= 65  && s[i]<=90)
            s[i]+=32;
        else if(s[i]>= 97  && s[i]<=122)    
            s[i]-=32;
    }
    printf("%s\n", s);
}