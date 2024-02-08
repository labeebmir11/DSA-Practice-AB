// program to check anagram using hashing
# include <stdio.h>
# include <string.h>

int main()
{   
    int i;
    char a[] = "listen";
    char b[] = "silent";

    char H[26]={0};
    
    for(i = 0; a[i]!='\0'; i++)
    {
        H[a[i]-97]++;
    }
    for(i = 0; b[i]!='\0'; i++)
    {
        H[b[i]-97]--;
        if(H[b[i]-97] == -1)
        {
            printf("Not anagram\n");
            break;
        }
    }
    if(b[i] == '\0')
    printf("Anagram\n");



}



 