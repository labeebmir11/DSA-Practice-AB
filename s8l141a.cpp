// Permutation of a string using backtracking recursion
# include <stdio.h>

void perm(char s[], int k)
{
    int i;
    static int A[10] = {0}; //map array
    static char Res[10];
    
    if(s[k]=='\0')
    {
        Res[k] = '\0';
        for(i = 0; Res[i]!='\0' ; i++) //printing the string
        {
            printf("%c", Res[i]);
            
        }
        printf("\n");
    }

    else
    {
        for(i = 0; s[i]!='\0'; i++ )
        {
            if(A[i] == 0)
            {
                Res[k] = s[i];
                A[i] = 1;
                perm(s,k+1);
                A[i] = 0;
            }
        }
    }
}

int main()
{
    char s[] = "ABC";
    perm(s,0); 
}