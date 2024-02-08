# include <stdio.h>

int fun(int n)
{
    int x = 0;
    if(n > 0 )
    {
        x++;
        return fun(n-1) + x;
    }
    return 0;
}
int main()
{
    int a = 5;
    int p = fun(a);
    printf("%d\n", p);
}