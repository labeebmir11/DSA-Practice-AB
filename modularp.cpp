// Write a modular program to initialise a rectangle structure and calculate its area and perimeter.
# include <stdio.h>
# include <stdlib.h>
# include <iostream>

using namespace std;

struct rectangle
{
    int length;
    int breadth;
};

void initialise(struct rectangle *a, int l, int b)
{
    a->length = l;
    a->breadth = b;
}

int area(int l, int b)
{
    return l * b;
}

int peri(int l, int b)
{
    return 2*(l+b);
}

int main()
{   
    struct rectangle r1;
    int l,b;
    cout<<"Enter length and breadth of rectangle"<<endl;
    cin>>l>>b;

    initialise(&r1, l, b); // initialisation
    cout<<"Length is "<< r1.length<<endl<<"Breadth is "<<r1.breadth<<endl;

    cout<<"Area of rectangle is " <<area(l,b)<<endl;

    cout<<"Perimeter of Rectangle is "<< peri(l,b)<<endl;
}