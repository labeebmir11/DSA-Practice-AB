// Program to pass a structure containing an array and int using pointers
# include <iostream>
# include <stdio.h>
# include <stdlib.h>

using namespace std;

struct arrRec
{
    int length;
    int breadth;
    int A[5];
};

void changeS(struct arrRec *r1)
{
    (*r1).length = 15;
     r1->breadth = 10;
     r1->A[0] = 100;
     (*r1).A[1] = 79;
}




int main()
{
    struct arrRec a1 = {10,5,{10,20,30,40,50}};
    changeS(&a1);
    cout<<"Length is  "<< a1.length<<endl<<"Breadth is  "<< a1.breadth<< endl;
    for (int i = 0; i < 5; i++)
        cout<<a1.A[i]<<endl;
}