// Program to insert an element at a given array index
# include <stdio.h>

struct Array
{
    int a[20];
    int length;
    int size;
};

int main()
{
    struct Array a1;
    a1 = {{1,2,3,4,5}, 5, 20};

    //insert element at index 3
    int index = 3;

    for(int i = a1.length; i > index; i--)
    {
        a1.a[i] = a1.a[i- 1];
    }
    a1.length++;
    a1.a[index] = 11;

    printf("Updated array after insertion of new element is :\n");
    for (int i = 0; i < a1.length; i++)
    {
        printf("%d\t", a1.a[i]);
    }
}    