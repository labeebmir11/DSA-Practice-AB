// Program to write Taylor series using recursion/
// 1 + x/2 + x*x/2! + x*x*x/3!....
# include <iostream>
using namespace std;

double taylor(int x, int n)// x is the power of e and n is the no of terms

{
    static double p = 1, f = 1;
    double r;
    if (n==0)
        return 1;
  // else
        r = taylor(x, n -1);
        p = p * x;
        r = r * n;
        return r + p/f;             
}


int main()
{
int x, n;
cout<<"Enter degree upto which Taylor series is to be printed and number of terms to be printed"<<endl;
cin>>x>>n;
cout<<taylor(x,n)<<endl;

}