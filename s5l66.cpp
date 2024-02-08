//Power function using recursion
# include <iostream>

using namespace std;

int pow(int base, int exp)
{
if(exp ==0)
    return 1;
else
    return base * pow(base, exp - 1);    

}

int main()
{
    int b, e;
    cout<<"Enter the values of base and exponent respectively"<<endl;
    cin>>b>>e;

    cout<<pow(b,e)<<endl;
}