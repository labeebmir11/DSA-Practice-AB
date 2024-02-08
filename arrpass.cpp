// Passing array to a function
# include <stdio.h>

void display1(int*p, int n)
{   
    for(int i = 0; i < 6; i++)
    {
        printf("%d\t", *p);
        p++;
    }
}

void display2(int a[], int n)
{
    for(int i = 0; i < 6; i++)
    {
        printf("%d\t", a[i]);
        
    }
}

int main()
{
    int a[] = {0,1,2,3,4,5};
    printf("\n");
     display1(a,6);
     printf("\n");
     display2(a,6);
}