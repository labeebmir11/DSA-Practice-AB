// Program to return an array, print first n positive integers
/*Write a C program that defines a function generateArray that takes an integer n as an argument and returns an array of the first n positive integers. In the main function, take user input for the value of n, call the generateArray function, and then print the elements of the generated array.
*/

# include <stdio.h>
# include <stdlib.h>
int* generateArray(int n)
{
    int *p;
    p = (int*)malloc(n * sizeof(int));
    for(int i = 0; i< n; i++)
    {
        p[i] = i + 1;
    }
    return p;
}

int main()
{
    int n;
    printf("Enter the value of n\n");
    scanf("%d",&n);

 int *r = generateArray(n);
 for(int i = 0; i < n; i++)
 {
    printf("%d\t", r[i]);
 }

 free(r);

}