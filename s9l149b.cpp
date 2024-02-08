// C program for a lower triangular matrix in coloumn major form
# include <stdio.h>
# include <stdlib.h>

struct Matrix
{
    int *A;
    int n;

};

void Set(struct Matrix *m, int i, int j, int x)
{
    if(i>=j)
        m->A[(m->n*(j - 1)) + ((j-2) * (j - 1)/2) + (i-j)] = x;
}

int Get(struct Matrix m, int i, int j)
{
    if(i >= j)
        return m.A[(m.n*(j - 1)) + ((j-2) * (j - 1)/2) + (i-j)];
    else
        return 0;    

}

void Display(struct Matrix m)
{
    for(int i = 1; i <= m.n; i++)
    {
        for(int j = 1; j <= m.n; j++)
        {
            if(i >= j)
                printf("%d\t",m.A[(m.n*(j - 1)) + ((j-2) * (j - 1)/2) + (i-j)] );
            else
                printf("0\t")    ;
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    int i, j, x;
    printf("Enter the value of n\n");
    scanf("%d", &m.n);
    m.A = (int *)malloc(m.n * (m.n+1)/2 * sizeof(int));

    printf("enter all elements");
 for(i=1;i<=m.n;i++)
 {
 for(j=1;j<=m.n;j++)
 {
 scanf("%d",&x);
 Set(&m,i,j,x);
 }
 }
 printf("\n\n");

 printf("%d\n", Get(m,4,4));
 printf("\n\n");
 Display(m);

 free(m.A);
}