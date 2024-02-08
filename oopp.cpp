// Write an object oriented program to initialise a rectangle structure, calculate its area and perimeter.
# include <stdio.h>
# include <stdlib.h>
# include <iostream>

using namespace std;

class Rectangle
{   
    public:
    int l;
    int b;

    void initialise(int p, int q)
    {
        l = p;
        b = q;
    }
    
    int area()
    {
        return l * b;
    }

    int perimeter()
    {
        return 2 * (l + b);
    }
};
int main()
{
    int a,b;
    cout<<"Enter length of rectangle and breadth of rectangle"<<endl;
    cin>> a >> b;
    Rectangle r;

    r.initialise(a,b);

    cout<<"Area of the rectangle is "<< r.area();

    cout<<"Perimeter of the rectangle is " << r.perimeter();

    return 0;
}