// Add/ Append and insert element in an array
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
  a1 = {{1,2,3,4,5},5,20};

  int x = 11;
  a1.a[5] =x;
  a1.length++;

  printf("Updated length after adding element is %d\n", a1.length);

  printf("Updated array is: \n");

  for(int i = 0; i < a1.length; i++)
  {
    printf("%d\t", a1.a[i]);
  }

}