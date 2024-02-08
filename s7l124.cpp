// Program to find duplicates in a sorted array
# include <stdio.h>

int main()
{       
    int j;
    int duplicate = -1;
    int A[10] = {3,6,8,8,10,12,15,15,15,20};
    for(int i = 0; i <10; i++)
    {
        if(A[i]==A[i+1] && A[i]!=duplicate)
        {
            printf("%d\t", A[i]);
            duplicate = A[i];
        }

    }
    printf("\n");
    // to count number of dupliocates
    for(int i = 0; i < 10; i++)
    {
        if(A[i] == A[i+1])
        {
             j = i+1;
            while(A[i]== A[j])
            {
                j++;
            }
            printf("%d appears %d times\n", A[i], j-i);
            i=j-1;
        }
    }

 



}