// Finding multiple missing elements in a sorted array
# include <stdio.h>

int main()
{
    int A[11] = {6,7,8,9,11,12,15,16,17,18,19};
    int diff = A[0]-0;

    for(int i = 0; i < 11; i++)
    {
        if(diff != A[i] - i)
        {
            while(diff < A[i] - i)// while the origial difference is less than the new difference
            {
                printf("%d\n", diff + i);
                diff++;
            }
        }
    }
}