// program to merge two arrays
# include <stdio.h>
# include <stdlib.h>


int * merge(int a[], int b[])
{
    int *c;
    c = (int *)malloc(sizeof(int) * 10);
    int i = 0,j=0,k=0;
    while(i < 5 && j < 5)
    {
        if(a[i] < b[j])
          {  c[k] = a[i];
            k++; i++;}
        else 
        {
            c[k] = b[j];
            k++; j++;
        }

    }
    // Now write two for loops to copy 1 or more remaining elements.
    for( ; i <5; i++)
       {
             c[k] = a[i];
             k++;
       }
    for( ; j <5; j++)
    {
            c[k] = b[j];
            k++;
    }  
    return c; 
}

int main()
{
    int a[5] = {3,8,16,20,25};
    int b[5] = {4,10,12,22,23};
    

    int *c = merge(a,b);
    printf("Merged array is: \n");
    for(int i = 0; i < 10; i++)
        printf("%d\t", c[i]);
}