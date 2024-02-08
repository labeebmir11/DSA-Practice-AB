# include <stdio.h>
# include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void displayArr(struct Array b)
{
    printf("Elements of the array are: \n");
    for(int i = 0; i < b.length; i++)
    {
        printf("%d\t", b.A[i]);
    } 
}


int main()
{
    int n;
    struct Array a1;
    printf("Enter size of te array\n");
    scanf("%d",&a1.size);

    a1.A = (int*)malloc(a1.size * sizeof(int));

    printf("Enter number of elements you want to enter\n");
    scanf("%d", &n);

    printf("Enter the elements of the array\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a1.A[i]);
    }   
    a1.length = n;

    displayArr(a1);  


}