//Program to implement Kruskal's algorithm
# include <stdio.h>
# include <limits.h>

#define I INT_MAX

int edges[3][9] = {{ 1, 1,  2,  2, 3,  4,  4,  5,  5},
                   { 2, 6,  3,  7, 4,  5,  7,  6,  7},
                   {25, 5, 12, 10, 8, 16, 14, 20, 18}};

int included[9] = {0};   //checks which edge has been included

int set[8] = {-1,-1,-1,-1,-1,-1,-1,-1};

int t[2][6];    //6 edges for 7 vertices

void Union(int u, int v)
{
    if(set[u] < set[v])
    {
        set[u] = set[u]+set[v];
        set[v] = u;
    }
    else
    {
        set[v] = set[u]+set[v];
        set[u] = v;
    }
}

int find(int u)
{
    int x = u, v= 0;
    while(set[x] > 0)
    {
        x = set[x];
    }
    while(u!=x)
    {
        v = set[u];
        set[u] = x;
        u = v;
    }
    return x;
}

int main()
{
    int i=0, j,k,u,v,n = 7,e = 9, min = I;

    while(i < n-1)
    {   
        min = I;
        for(j = 0; j < e; j++)
        {
            if(included[j]==0 &&  min > edges[2][j])
            {
                min = edges[2][j];
                k = j;
                u = edges[0][j];
                v = edges[1][j];
            }
        }
        if(find(u)!=find(v))
        {
            t[0][i] = u;
            t[1][i] = v;

            Union(find(u), find(v));  //Union is done for parents
            i++;
        }
        included[k] = 1;

    }

    for(i = 0; i < 2 ; i++)
    {
        for(j = 0; j < n-1 ; j++)
        {
            printf("%d\t",t[i][j]);
        }
        printf("\n");
    }
}


 