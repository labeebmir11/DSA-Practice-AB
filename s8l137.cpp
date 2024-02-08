//Program to compare strings and check for palindrome
# include <stdio.h>

int main()
{   
    int i,j;
    
    char a[] = "madam";
    char b[20];
    //Reversing array a and storing the reverse in array b
    for(i = 0; a[i]!='\0';i++)
    {

    }
    i = i-1;
    for(j = 0; i >=0; i--,j++)
    {
        b[j] = a[i];
    }
    b[j]='\0';
    printf("reverse is: %s\n",b);
    // Now we compare the original array and its reverse
    for(i=0,j=0; a[i]!='\0' && b[j]!='\0'; i++,j++)
    {
        if(a[i] != b[j])
        {
            printf("Not a palindrome\n");
            break;
        }
    }
    if(a[i]==b[j])
        printf("The entered string is a palindrome\n");
}