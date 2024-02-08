# include <stdio.h>
# include <stdlib.h>

int* createArray(int* size)
{
   static int a[] = {1,2,3,4,5};
    *size = sizeof(a)/sizeof(a[0]);
    return a;
}

int main()
{
    int size;
    int *p;
    p = createArray(&size);

    for(int i = 0; i < size; i++)
    {
        printf("%d\t", p[i]);
    }
}