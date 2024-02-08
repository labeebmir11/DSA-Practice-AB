// Program to validate a string. A string is valid if it contains no special characters
# include <stdio.h>
# include <string.h>

int validateString(char *b)
{
for(int i = 0; b[i]!='\0'; i++)
{
    //if the characters are neither capital nor small nor numbers
    if(!(b[i]>=65 && b[i]<=90) && !(b[i]>=97 && b[i]<=122) && !(b[i]>=48 && b[i]<=57))
      return 0;    
}
return 1;
}
int main()
{
    char s[20];
    printf("Enter a string\n");
    //scanf("%s", s);
    
    fgets(s,sizeof(s),stdin);      
    /*   if you have to use fgets, then ensure that the new line character because
     of enter key is replaced by string terminator*/
     int length = strlen(s);
     printf("Length = %d\n",length);   // strlen for "John" will be 5

     if(length > 0 && s[length - 1] == '\n')
     {
        s[length - 1] = '\0';
     }

 
    int a = validateString(s);
    if(a == 1)
        printf("String is valid\n");
    else if(a == 0)
        printf("String is not valid\n");    


}

