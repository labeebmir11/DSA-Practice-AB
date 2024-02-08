//Program to create heap and insert elements in it
# include <stdio.h>
# include <stdlib.h>
# include<math.h>

void InsertMAX(int a[], int n)
{
    int i = n;
    int temp = a[n];
    while(i > 1 && temp > a[i/2] )
    {
        a[i] = a[i/2];
        i = i/2;
    }
    a[i] = temp;

}

void InsertMIN(int a[], int n)
{
    int i = n;
    int temp = a[n];
    while(i > 1 && temp < a[i/2] )
    {
        a[i] = a[i/2];
        i = i/2;
    }
    a[i] = temp;

}

int Delete(int A[], int n)
{
    int i,j,x;
    x = A[1];
    A[1] = A[n];
    A[n] = x; //Assigning the deleted value at the end of the array
    i = 1, j = 2 * i; 
    while(j <= n-1) //-1 because size of heap reduces when we delete
    {
        //check if lchild or rchild is bigger ad assign the bigger child to j
        if(j < n-1 && A[j+1]> A[j])
            j = j+1;
        //check if newly bought parent node is less than the large child
        if(A[i] < A[j]){
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
            break;        
    }
    //store the deleted element

    return x;
}
void Heapify(int a[], int n)
{
    for(int i = n/2; i >= 1; i--)
    {
        int j = 2*i;
        while(j <= n)
        {
            if(j <=n && a[j] < a[j+1] )
                j = j+1;
            if(a[i] < a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;

                i = j;
                j = 2*j;
            }    
        }
    }
}



int main()
{
    int a[] = {0,10,20,30,25,5,40,35};
    int i;

   // Heapify(a,7);
    
    //assume that the array indexing starts from 1, so set the 0th element to 0.
    //also, assume the first element is already in the heap. So, send elements from 2

    for(i = 2; i <= 7; i++) //insert new at 10th posn initially
    {
        InsertMAX(a,i);
    }
    

    /*printf("\nDeleted value is %d\n", Delete(a,7)); //because there are 7 non zero elements 
    printf("\nDeleted value is %d\n", Delete(a,6)); //heap size is now 6*/

   
    printf("\n");
    printf("Original Heap is:\n");
    for( i = 1; i <=7; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");

    for(int i = 7; i > 1; i--)
    {
        Delete(a,i);
    }
    printf("After deleting all noddes, we get a sorted heap:\n");
    for( i = 1; i <=7; i++)
    {
        printf("%d\t", a[i]);
    }

  /* printf("\nHeap created using heapify is: \n");
   for(int i = 1; i <= 7; i++)
   {
        printf("%d\t", a[i]);
   }*/


}