// Program to implement fibonacci series using recursion
// 0 1 1 2 3 5 8
# include <iostream>

using namespace std;

int fibo(int n)
{
        if(n == 0 || n== 1)
            return n;
        else
            return fibo(n-1) +  fibo( n - 2);   
    
}

int main()
{
    int first = 0;
    int second = 1;
    int n, third;

    cout<<"Enter the no of terms you want to be printed"<<endl;
    cin>>n;

   

    for (int i = 1; i <=n; i++)
    {
        cout<< fibo(i)<< "  ";
    }
    
    
    
    /*cout<<"Fibonacci series is: "<< first <<"  " << second<<"  ";
    for (int i = 1; i <= n - 1; i++) // printing using for loop
    {
        third = first + second;
        cout<<third<< "   ";
        first  = second;
        second = third;

    }*/
}