// Program to write a class in C++
# include <iostream>

using namespace std;

class Rectangle
{   
    private:

    int length;
    int breadth;

    public:

    Rectangle()     // Non parameterised or default constructor
    {
        length = 0;
        breadth = 0;
    }
    Rectangle(int l, int b); //  Parameterised Constructor
    int area();             // Facilitator
    int perimeter();        // fecilitator
    int getLength()         // Accessor
    {
        return length;
    }
    void setLength(int l);  // Mutator
    ~Rectangle()   // Destructor
     {
        cout<<"Destructor"<<endl;
     }        
};

Rectangle :: Rectangle(int l,int b)
{
    length = l;
    breadth = b;
}

int Rectangle :: area()
{
    return length * breadth;
}

int Rectangle :: perimeter()
{
    return 2 * (length + breadth);
}

void Rectangle :: setLength(int l)
{
    length = l;
}




int main()
{
    Rectangle r(5, 10);
    cout<< r.area()<<endl;
    cout<<r.perimeter()<<endl;
    cout<<r.getLength()<<endl;
   

}