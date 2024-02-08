// Finding duplicates in a string using bitwise operations

# include <stdio.h>
# include <string.h>

int main()
{   
    int i;
    char A[] = "labeeb";
    long int H = 0,x=0;   //long to ensure we have 4 bytes(32 bits) irrespective of compiler

    for(i = 0; A[i]!='\0'; i++)
    {   
        //set each bit on using x through merging
        x = 1;
        x = x<<(A[i]-97); 
        // check if the corresponding bit in H is already on using masking. If it is, then it is a duplicate element
        if((x & H)> 0)
            printf("%c is Duplicate\n",A[i]);
        else
          H =  (x | H); 

    }
}