// Program to test arrays
# include <stdio.h>
int main()
{
    int arr[] = {10,20,30,40,50,60,70};
    int *j, *k;
    j = &arr[4];
    k = (arr + 4);

if(j == k)
    printf("Both pointers point to the same location\n");
else
printf("The two pointers are different\n");        
    
    
}