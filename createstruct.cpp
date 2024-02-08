// Program to create a structure in heap
# include <stdio.h>
# include <stdlib.h>
# include <iostream>

using namespace std;

struct rectangle
{
    int length;
    int breadth;
};

struct rectangle *createStruct()
{
    struct rectangle *n;
    n = new rectangle;
    // n = (struct rectangle *)malloc(sizeof(struct rectangle));
    (*n).length = 10;
    (*n).breadth = 20;
    return n;
}

int main()
{
    struct rectangle *p;
    p = createStruct();
    cout<<"Length is "<<p->length<<endl<< "Breadth is "<< p->breadth<< endl;
}