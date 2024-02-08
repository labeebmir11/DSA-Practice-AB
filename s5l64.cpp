// Factorial using recursion
# include <iostream>

using namespace std;

int fact(int n)
{
if(n==0)
    return 1;
else
    return n * fact(n-1);    
}

int main()
{
    int n;
    cout<<"Enter the number whose factorial is to be calculated"<<endl;
    cin>> n;

    cout<<"Factorial is "<< fact(n)<<endl;
}