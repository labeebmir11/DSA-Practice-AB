// program to find duplicates in a string using hashing
# include <stdio.h>
# include <string.h>

/*int main()
{   
    int i,j;
    char s[] = "labeeb";
    char o[125];

    for(i = 0; i < 125; i++)
    {
        o[i] = 0;
    }
    printf("String length is %d\n", strlen(s));

    for(i = 0; i < strlen(s) ; i++)
    {
        o[s[i]]++;

    }
    for(i = 0; i < 125; i++)
    {
        if(o[i] > 1)
        {
            printf("%c appears %d times\n", i,o[i]);
        }
    }


}*/
// Let us optimise the above code to reduce sze of array required for hashing

int main()
{   
    int i,j;
    char s[] = "labeeb";
    char o[26];

    for(i = 0; i < 26; i++)
    {
        o[i] = 0;
    }
    printf("String length is %d\n", strlen(s));

    for(i = 0; i < strlen(s) ; i++)
    {
        o[s[i]-97]++;

    }
    for(i = 0; i < 26; i++)
    {
        if(o[i] > 1)
        {
            printf("%c appears %d times\n", (i+97),o[i]);
        }
    }


}