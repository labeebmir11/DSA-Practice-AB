// Program to find missing elements of array using hashing
# include <stdio.h>
# include <stdlib.h>

int main()
{
    int A[10] = {3,7,4,9,12,6,1,11,2,10};
    int *B;
    B = (int *)malloc(sizeof(int) * 13);
    for (int i = 0; i < 13; i++) {
        B[i] = 0;
    }
    for(int i = 0;  i < 10; i++)
    {
        B[A[i]]++;
    }
    for (int j = 1; j < 12; j++)
    {
        if(B[j]==0)
            printf("%d\n", j);
    }
}