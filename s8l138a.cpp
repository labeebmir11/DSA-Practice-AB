// program to find duplicates in a string
# include <stdio.h>
# include <string.h>

int main()
{   
    int i,j,count;
    char s[] = "Finding";

    for(i = 0; i < strlen(s)-1; i++)
    {
        count = 1;

        if(s[i]!='@')
            for(j = i+1; j < strlen(s);j++)
            {
                if(s[i]==s[j])
                {
                    count++;
                    s[j] = '@';
                }
            }
            if(count > 1)
            printf("%c appears %d times\n",s[i],count);
    }
}