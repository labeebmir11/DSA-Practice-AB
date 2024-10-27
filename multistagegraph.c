# include <stdio.h>
# include <limits.h>
# define n 8
int main()
{
    
    int cost[9], d[9],path[4];
    int stages = 4;

    int c[9][9] = {{0,0,0,0,0,0,0,0,0},
                    {0,0,2,1,3,0,0,0,0},
                    {0,0,0,0,0,2,3,0,0},
                    {0,0,0,0,0,6,7,0,0},
                    {0,0,0,0,0,6,8,9,0},
                    { 0,0,0,0,0,0,0,0,6},
                    {0,0,0,0,0,0,0,0,4},
                    {0,0,0,0,0,0,0,0,5},
                    {0,0,0,0,0,0,0,0,0}};

    cost[n] = 0;
    for(int i = n-1; i>=1; i--)
    {
        int min = INT_MAX;
        for(int k = i+1; k <= n; k++)
        {
            if(c[i][k]!=0 && c[i][k] + cost[k] < min)
            {
                min =  c[i][k] + cost[k];
                d[i] = k;
            }
        }
        cost[i] = min;
    }                
    path[stages] = n;
    path[1] = 1;
    for(int i = 2; i < stages; i++)
    {
        path[i] = d[path[i-1]];
    }

    for(int i = 1; i <= stages; i++)
    {
        printf("%d\t", path[i]);
    }


}