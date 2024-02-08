// Sum of first n natural numbers using recursion
# include <iostream>
using namespace std;


int sumrec(int n)
{
 if (n==0)
    return n;

 else
    return sumrec(n-1) + n;    
}

int main()
{
    int n;
    cout<<"Enter value of n"<<endl;
    cin>> n;

    cout<<sumrec(n)<<endl;;
}