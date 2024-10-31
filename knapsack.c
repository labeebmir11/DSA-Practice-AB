# include <stdio.h>

int max(int a, int b)
{
    return a>b?a:b;
}
int main()
{
    int p[5] = {0,1,2,5,6};
    int wt[5] = {0,2,3,4,5};
    int m = 8, n = 4;
    int k[5][9];

    for(int i = 0; i < 5; i++)//rows
    {
        for(int w = 0;  w < 9; w++) //cols
        {
            if(w == 0 || i == 0)
            {
                k[i][w] = 0;
            }
            else if(wt[i] > w)
            {
                k[i][w] = k[i-1][w]; //fill with entry of previous row
            }
            else
            {
                k[i][w] = max(k[i-1][w], p[i]+k[i-1][w-wt[i]]);
            }
        }
    }

    int i = n, j = m;
    while(i > 0 && j>=0)
    {
        if(k[i][j] == k[i-1][j])
        {
            printf("%d = 0\n",i);
            i--;
        }
        else
        {
            printf("%d = 1\n",i);
            j = j - wt[i];
            i--;
        }
    }
}
