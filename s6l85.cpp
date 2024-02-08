// Program to ynamically create array in heap and then increase its size
# include <stdio.h>
# include <stdlib.h>
# include <iostream>

using namespace std;

int main()
{
    int *p;
    //p = (int *)malloc(5 * sizeof(int));
    p = new int[5];

   for (int i = 0; i <5; i++)
   {
    p[i] = i + 2;    // assigning even numbers
   } 
    int *q;
    q = new int[10];

    //copy all elements of array p to array q
    for (int i = 0; i <5; i++)
    {
        q[i] = p[i];
    }
    //delete array p
    delete []p;

    //let pointer p point to array q
    p = q;

    //delete q
    q = NULL;

    //assign 6th element to p
    p[5] = 85;

    //print array p to check
    for (int i = 0; i <6; i++)
    {
        cout<<p[i]<<"  ";
    }

    

}