// Program to initialize 2 dimensional array in 3 different ways

# include <iostream>
# include <stdio.h>
# include <stdlib.h>

using namespace std;

int main()
{
    // 1. Array entirely in stack:
    int A[3][4] = {{1,2,3,4},{5,6,7,8},{2,5,8,7}};

    //2. Using pointer to array in stack and the actual arrays in heap:
    int *B[3];
    
    B[0] = new int[4]; // B[0] = (int *)malloc(4 * sizeof(int));
    B[1] = new int[4];
    B[2] = new int[4];

    B[2][3] = 15;

    //3. Creating 2D Array entirely in heap using double pointer in stack
    int **C;
    C = new int*[3]; // Creates pointer to arrays in heap
    // C = (int **)malloc(3 * sizeof(int *));
    C[0] = new int[4]; 
    C[1] = new int[4];
    C[2] = new int[4];

    C[2][3] = 15;

    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            cout<<C[r][c]<<"  ";
        }
    }

}