// Program to reduce the time complexity of fibonacci series using recursion using memoziation
# include <iostream>

using namespace std;

int s[10];

int mfibo(int n)
{
    if(n <= 1)
    {
        s[n] = n;
        return n;
    }
    else
    {
        if (s[n - 2] == -1)
        s[n-2] = mfibo(n-2);

        if (s[n-1] == -1)
        s[n-1] = mfibo(n-1);
    
    s[n] = s[n-2] + s[n-1];
    return s[n-2] + s[n-1];
    }
}

int main()
{
 int n;
 cout<<"Enter which term you want to be printed"<<endl;
 cin>>n;

 for (int i = 0; i <10; i++) //initializing the static array with -1
 {
    s[i] = -1;
 }

cout<< mfibo(n)<< "  ";
    
}