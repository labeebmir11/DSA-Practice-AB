// Program to find a pair of elements with sum k in an unsorted array using hashing
# include <stdio.h>
# include <stdlib.h>
int main()
{   
    int k = 10; //sum
    int A[10] = {6,3,8,10,16,7,5,2,9,14};

    int *B;
    B = (int *)malloc(sizeof(int) * 17);
    for(int i = 0; i < 17; i++)
    {
        B[i] = 0;
    }
    for(int i = 0; i < 10; i++)
    {   
        
        if ( k-A[i]>=0 && B[k - A[i]] !=0)
            printf("%d+%d=%d\n",A[i], k-A[i],k);
        B[A[i]]++;    
    }

}