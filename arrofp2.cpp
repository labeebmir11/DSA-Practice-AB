# include <stdio.h>

int main()
{
    int a[10] = {1,2,3,4,5};
    int *p[] = {a,a+1,a+2,a+3,a+4}; // array of pointers

    // printf("%d\n", a); // name of array stores adress of base element
    // printf("%u\n", &a);
    printf("%u\n", p);
    printf("%u\n", p+1);

    
}