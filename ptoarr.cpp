# include <iostream>
# include <stdlib.h>


using namespace std;

int main()
{
    int *p;
    p = (int *)malloc(sizeof(int) * 4);
    p[0] = 1; p[1] = 2; p[2] = 3; p[3] = 4;
    for (int i = 0; i < 4 ; i++)
    {
        cout<<p[i]<<endl;
    }
}