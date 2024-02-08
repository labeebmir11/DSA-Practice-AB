//Program to insert elements in a heap
# include <stdio.h>
# include <stdlib.h>

void print(int a[], int n)
{
    for(int i = 1; i <= n; i++)
    {
        printf("%d\t", a[i]);
    }
}

void InsertMax(int a[], int index, int key)
{   
    a[index] = key;
    int temp  = a[index];
    int i = index;

    while(i > 1 && temp > a[i/2])
    {
        a[i] = a[i/2];
        i = i/2;
    }
    a[i] = temp;

}

int main()
{
    int a[] = {0,70,50,40,45,35,39,16,10,9};

    InsertMax(a, 10, 60); //10 is the size of the array as well as the index in which the new element is added

    print(a,10);

}