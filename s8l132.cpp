// Program to find length of string
# include <stdio.h>

int main()
{
    char name[] = "Welcome";
    int i = 0;
    int length = 0;
    while(name[i] != '\0')
    {
        length++;
        i++;
    }
    printf("Length of string is %d\n",length);

    for(i = 0; name[i]!='\0'; i++)
    {

    }
    printf("Length of the string is %d\n ", i);
}
