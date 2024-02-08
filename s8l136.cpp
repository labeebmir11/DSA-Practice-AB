// Program to reverse an a string
# include <stdio.h>

char* stringReverse(char* a)
{   
    int i,j,l=0;
    char temp;
    for( i = 0; a[i]!='\0';i++)
    {
        
    }
    printf("Length of the entered string is %d\n", i);

    for(j = 0; j < i/2; j++)
    {
        temp = a[j];
        a[j] = a[i - 1 - j];
        a[i -1 - j] = temp;
    }
    return a;


}

int main()
{   
    char *r;

    char s[20];
    printf("Enter a string\n");
    scanf("%s", s);

    printf("You entered %s\n", s);

    r = stringReverse(s);
    printf("Reveresed string is: %s\n",r);



}