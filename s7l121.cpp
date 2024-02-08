// Finding missing elements in a sorted array
# include <stdio.h>

int main()
{
    int A[11] = {6,7,8,9,10,11,13,14,15,16,17};
    int difference = A[0]- 0;

    for(int i = 0; i < 11; i++)
    {
        if(A[i] - i!= difference)
        {
            printf("Missing element is %d\n",difference + i );
            break;
        }
    }

}