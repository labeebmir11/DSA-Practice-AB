// program to write get, set and display functions for a diagonal matrix
# include <stdio.h>

struct Matrix
{
    int A[10]; //array to store diagonal elements
    int n;     // size of square matrix n*n
};
// Indexing of matrix  in mathematics starts from 1 while those of arrrays starts from 0

void Set(struct Matrix *m, int i, int j, int x)
{
    if(i == j)
    {
        m->A[i-1] = x;
    }
}

int Get(struct Matrix m, int i, int j)
{
    if(i == j)
        return m.A[i - 1];
    else
        return 0;    
}
void Display(struct Matrix m)
{
    for(int i = 1; i <= m.n; i++)
    {
        for(int j = 1; j <= m.n; j++)
        {
            if(i == j)
                printf("%d\t", m.A[i-1]);
            else
                printf("0\t");    
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    m.n = 4;
    Set(&m, 1,1,3); Set(&m,2,2,6); Set(&m,3,3,9); Set(&m,4,4,12);
    printf("%d\n",Get(m,3,3));
    Display(m);


}