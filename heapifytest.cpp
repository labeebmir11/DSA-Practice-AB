# include <stdio.h>
# include <stdlib.h>
# include <math.h>

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

int Delete(int A[], int n)
{
    int i,j,x;
    x = A[1];
    A[1] = A[n];
    A[n] = x; //Assigning the deleted value at the end of the array
    i = 1, j = 2 * i; 
    while(j < n-1) //-1 because size of heap reduces when we delete
    {
        //check if lchild or rchild is bigger and assign the bigger child to j
        if(A[j+1] > A[j])
            j = j+1;
        //check if the newly bought parent node is less than the large child
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

void Heapify(int a[], int i, int n)
{
    int largest = i;
    int l = 2*i;
    int r = 2*i+1;
    if(l <= n && a[l] > a[largest])
        largest = l;
    if(r <= n && a[r] > a[largest])
        largest = r;
    if(i!=largest)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        Heapify(a,largest,n);
    }        
}



int main()
{
    int a[] = {0, 10, 20, 30, 25, 5, 40, 35}; int n = 7;
    int i;
    for(i = n/2; i >= 1; i-- )
    {
        Heapify(a, i, n);
    }

    printf("\nHeap created using heapify is: \n");
    for(int i = 1; i <= 7; i++)
    {
        printf("%d\t", a[i]);
    }

    // Add your other operations or function calls here if needed.

    return 0;
}
