// Power function with reduced number of multiplications
# include <iostream>
using namespace std;

int power(int base,int exp)
{
if (exp==0)
    return 1;
if (exp%2==0) // Power is even
    return power(base*base, exp/2);
else        // Power is odd
    return (base* power(base*base, (exp-1)/2));   
}

int main()
{
    int b,e;
    cout<<"Enter values of base and power respectively"<<endl;
    cin>>b>>e;
    cout<< power(b,e)<<endl;
}