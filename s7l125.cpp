// Finding duplicates in a sorted array using hashing
# include <stdio.h>
int main()
{
    int A[10] = {3,6,8,8,10,12,15,15,15,20};
    int B[21];

    for(int i = 0; i < 21; i++)
    {
        B[i] = 0;
    }
    for(int i = 0; i < 10;i++)
    {
        B[A[i]]++;
    }

    for(int i = 0; i < 21; i++)
    {
        if(B[i]> 1)
        printf("%d appears %d times\n", i, B[i]);
    }

}