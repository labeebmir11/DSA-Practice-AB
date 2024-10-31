# include <stdio.h>
# include <limits.h>

# define n 5

void printParenthesis(int i, int j, int s[n][n]) {
    if (i == j) {
        printf("%c", 'A' + i - 1);
        return;
    }
    printf("(");
    printParenthesis(i, s[i][j], s);
    printParenthesis(s[i][j] + 1, j, s);
    printf(")");
}

int main()
{
    int p[5] ={5,4,6,2,7};
    int c[5][5] = {0};
    int s[5][5] = {0};

    for(int d = 0; d < n-1; d++)
    {
        
        for(int i = 1; i < n-1; i++)
        {
            int j = i+d;
            int min = INT_MAX;
            for(int k = i ; k <= j-1; k++)
            {
                if(c[i][k]+c[k+1][j] + p[i-1] * p[k] * p[j] < min)
                {
                    min = c[i][k]+c[k+1][j] + p[i-1] * p[k] * p[j];
                    s[i][j] = k;
                }
                c[i][j] = min;
            }
        }
    }
    printf("\nParenthesiation:");
    printParenthesis(1,n-1,s);
    printf("\n");
}