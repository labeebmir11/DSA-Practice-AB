// Program to write Templates in CPP
# include <iostream>
using namespace std;

template<class T>
class Arithmetic
{
  private:  
    T a;
    T b;

  public:
    Arithmetic(T p, T q);
    T add();
    T subtract();
};
template<class T>
Arithmetic<T> :: Arithmetic(T p, T q)
{
    a = p;
    b = q;
}
template<class T>
T Arithmetic<T> :: add()
{
    return a + b;
}
template<class T>
T Arithmetic<T> :: subtract()
{
    return a - b;
}

int main()
{
    
    Arithmetic<int> a(3,2);

    cout << a.add()<<endl;
    cout<< a.subtract()<<endl;

    Arithmetic<double> b(2.4,3.5);
    cout << b.add()<<endl;
    cout<< b.subtract()<<endl;

    return 0;
}