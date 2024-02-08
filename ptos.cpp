# include <iostream>
# include <stdio.h>
# include <stdlib.h>
using namespace std;
struct rectangle
{
    int l;
    int b;
};
int main()
{
    struct rectangle *p;
    p=(struct rectangle *)malloc(sizeof(struct rectangle));

    (*p).l = 10;
    (*p).b = 5;

    cout<<"Area is "<< ((*p).l) * ((*p).b)<<endl;
}