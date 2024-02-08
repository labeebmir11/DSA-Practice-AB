#include<stdio.h>
# include <stdlib.h>
struct Array
{
 int A[10];
 int size;
 int length;
}; 

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Display(struct Array a1)
{
    printf("Elements of the array are: \n");
    for(int i = 0; i < a1.length; i++)
    {
        printf("%d\t", a1.A[i]);
    }
}

void Append(struct Array *a1, int x)
{   
    if(a1->length < a1->size)
    {
    (*a1).A[(*a1).length] = x;
    // a1->A[a1->length] = x;
    (*a1).length++;
    // a1->length++; 
    }
}

void Insert(struct Array *a1, int x, int index)
{
    if(index >= 0 && index<=(*a1).length && ((*a1).length < (*a1).size))
    {
        for(int i = a1->length ; i > index; i--)
        {
            (*a1).A[i] = (*a1).A[i - 1];
        }
        a1->A[index] = x;
        a1->length++;
    }
}   
int Delete(struct Array *a1, int index)
{   
    int x= 0;
    if(index>=0 && index<(*a1).length)
    {   
        x = a1->A[index];
        for(int i = index; i < (*a1).length-1 ;i++)
        {
            a1->A[i] = a1->A[i+1];
        }
        a1->length--;
        return x;
    }
}
int LinearSearch(struct Array a1, int key) //Normal Linear search
{
    for(int i =0; i < a1.length; i++)
    {
        if(a1.A[i]== key)
        {
            return 1;   //search succesful, returns index at which key is found
        }
        
    }
    return -1; //unsuccessful, key not found
}

int LinearSearch_tpt(struct Array *a1, int key)// optimised lonear search through transporatation
{
    for(int i = 0; i < a1->length; i++)
    {
        if(a1->A[i] == key)
        {
            swap(&a1->A[i],&a1->A[i-1]);
            return i;
        }
    }
    return -1;

}

int LinearSearch_mtof(struct Array *a1, int key) //optimised linear search by swapping the most recently searched element with the 0th element

{
    for(int i = 0; i < a1->length; i++)
    {
        if(key == a1->A[i])
        {
            swap(&a1->A[i], &a1->A[0]);
            return i;
        }
    }
    return -1;
}

int BinarySearch (struct Array a1, int key)
{
    int l, h, mid;
    l = 0;   h = a1.length - 1;
    while(l <= h)
    {
        mid = (l + h)/2;
        if(key == a1.A[mid])
        {
            return mid;
        }
        else if (key < a1.A[mid])
            h = mid - 1;
        else if (key > a1.A[mid])
            l = mid + 1;    
    }
    return -1;  // Search unsuccesful
 }

int RecBinarySearch (struct Array a1, int key, int l, int h)    // Tail recusrsion, so loops are better
{
    
    while(l <= h)
    {
        int mid = (l + h)/2;
        if(key == a1.A[mid])
            return mid;
        else if (key < a1.A[mid])
          return RecBinarySearch(a1,key,l, mid-1);
        else if(key > a1.A[mid])
           return RecBinarySearch(a1,key,mid + 1,h);      
    }
    return -1;    //unsucessful search
}
int Get(struct Array arr,int index)
{
 if(index>=0 && index<arr.length)
    return arr.A[index];
 return -1;
}

void Set(struct Array *arr,int index,int x)
{
 if(index>=0 && index<arr->length)
    arr->A[index]=x;
}

int Max(struct Array arr)
{
 int max=arr.A[0];
 int i;
 for(i=1;i<arr.length;i++)
 {
    if(arr.A[i]>max)
    max=arr.A[i];
 }
 return max;
}

int Min(struct Array arr)
{
 int min=arr.A[0];
 int i;
 for(i=1;i<arr.length;i++)
 {
     if(arr.A[i]<min)
     min=arr.A[i];
 }
 return min;
}

int RecSumArr(struct Array a1, int n) // n is the index of the last element i.e; length -1
{
    if(n <0)
        return 0;  //because array starts from index 0
    else
        return a1.A[n] + RecSumArr(a1, n -1);    
}

float Average(struct Array a1)
{
    return (RecSumArr(a1, a1.length - 1))/ a1.length;
}

void ReverseArray(struct Array *a1)
{
    int *B;
    B = (int *)malloc((*a1).length * sizeof(int));

    for(int i = a1->length - 1, j = 0; i>=0; i--,j++) 
    {
        B[j] = a1->A[i]; // for copying elements in reverse order to a different array

    }
    for(int i = 0; i< a1->length ; i++)
    {
        a1->A[i] = B[i]; 
    }
}

void Reverse2(struct Array *a1)
{
    int i,j;
    for(i = 0, j=a1->length - 1; i < j; i++,j-- )
    {
        swap(&a1->A[i], &a1->A[j]);
    }
}

void RightShift(struct Array *a1)
{
    int x = a1->A[a1->length - 1];
    for(int i = a1->length; i > 0; i-- )
    {
        a1->A[i] = a1->A[i-1];
    }
    a1->A[0] = x;
}

void InsertElement(struct Array *a1, int element)
{   
    int i = a1->length - 1;
    while(i>=0 && element < a1->A[i])
    {
        a1->A[i+1] = a1->A[i];
        i--;
    }
    a1->A[i+1] = element;
    a1->length++;
}

int checkSortedArray(struct Array a1)
{
    for(int i = 0;  i < a1.length - 1; i++)
    {
        if(a1.A[i] > a1.A[i+1])
            return -1; // Array is not sorted
    }
    return 1;   // Array is sorted
}

void adjustSign(struct Array *a1) // Arranging negative elements on one side
{
    int i = 0;
    int j = a1->length - 1;
    while(i < j)
    {
        while((a1->A[i])< 0) i++; // Move one step right if the element is negative till you encounter a positive element
        while((a1->A[j])>= 0)j--; //Move one step towrds left if the element is positive and keep moving to left till you encounter a negative element
   // the two while loops give us a pair to be swapped
        if(i < j)  //the swapping is done ony if i < j
            swap(&a1->A[i], &a1->A[j]);
    }
}







int main()
{
    struct Array a1 = {{2,4,-5,-6,7},10,5};
    
    // Append(&a1,33);
    // Insert(&a1, 11, 3);
    // Delete(&a1,1);
    // printf("%d\n", LinearSearch_mtof(&a1, 5));
    //ReverseArray(&a1);
    //RightShift(&a1);
   // InsertElement(&a1,3);
   adjustSign(&a1);
    Display(a1); 
    // printf("\n"); 
    // printf("%d\n", checkSortedArray(a1));
    // printf("%d\n", BinarySearch(a1,10));
    // printf("%d\n", RecBinarySearch(a1,10,0,a1.length));
    // printf("%d\n", RecSumArr(a1,a1.length - 1));
    // printf("%f\n", Average(a1));

}