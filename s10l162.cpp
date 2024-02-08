// Program to create a sparse matix
# include <stdio.h>
# include <stdlib.h>

struct Element 
{
    int i;
    int j;
    int x;
};

struct sparse
{
    int m; //rows of matrix
    int n; //col of matrix
    int num; //for number of non zero elements
    struct Element *e;  //array of structures to hold different elements
};

void create(struct sparse *s)
{
    int m,n,i,num,x;
    printf("Enter the dimension of the matrix m*n\n");
    scanf("%d%d", &s->m, &s->n);
    printf("Enter the number of non zero elements in the matrix\n");
    scanf("%d",&s->num);
    // Now we create an array to hold the elements
    s->e = (struct Element *)malloc(num * sizeof(struct Element));

    printf("Enter all non zero elements (row, col, element)\n");
    for(i =1; i<= s->num; i++)
    {
        scanf("%d%d%d",&s->e[i].i, &s->e[i].j, &s->e[i].x);
    }

}

void Display(struct sparse s)
{   
    int k = 1;
    printf("The sparse matrix is: \n");
    for(int i = 1; i <= s.m; i++ )
    {
        for(int j = 1; j <= s.n; j++)
        {
            // if i, j match with the i, j of the element array, then we print the number stored in the element array. if not, then we print zero
            if(i == s.e[k].i && j == s.e[k].j )
               { 
                printf("%d\t", s.e[k].x);
                k++;
               }
            else
                printf("0\t");   
        }
        printf("\n");
    }
}

int main()
{
    struct sparse s1;
    create(&s1);
    Display(s1);
}