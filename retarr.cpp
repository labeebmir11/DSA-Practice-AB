// Program to make and return an array using a function
# include <iostream>
# include <stdlib.h>

using namespace std;

int * arr (int size)
{
 //int * p = new int(size);
 int *p = (int *)malloc(sizeof(int) * size);
 for (int j = 0; j < size; j++)
  {
    p[j] = j + 2;
  }
 return p;
}


int main()
{
    int size;
    cout<<"Enter desired size of array"<< endl;
    cin>> size;

    int *Arr  = arr(size);

    for (int i =0 ; i < size; i++)
    {
        cout<< Arr[i]<< endl;
    }

}