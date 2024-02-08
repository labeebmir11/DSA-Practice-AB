//This program contains all sorting techniques except radix sort
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int findmax(int A[], int n)
{
    int max = A[0];
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Insert(struct Node **p, int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *q = NULL;
    newnode->data = value;
    newnode->next = NULL;

    if (p[value] == NULL)
        p[value] = newnode;
    else
        q = p[value];
    while (q->next != NULL)
        q = q->next;
    q->next = newnode;
    q = newnode;
}

int Delete(struct Node **p, int i)
{
    struct Node *q;
    q = p[i];
    p[i] = p[i]->next;
    int x = q->data;
    free(q);
    return x;
}

void BinSort(int A[], int n)
{
    int max, i, j;
    max = findmax(A, n);
    struct Node **bin = (struct Node **)malloc(sizeof(struct Node *) * (max + 1)); //creating array of linked lists
    for (i = 0; i < max + 1; i++)
    {
        bin[i] = NULL;
    }
    for (i = 0; i < n; i++)
    {
        Insert(bin, A[i]);
    }
    i = 0;
    j = 0;
    while (i < max + 1)
    {
        while (bin[i] != NULL)
        {
            A[j++] = Delete(bin, i);
        }
        i++;
    }

    // Free memory
    for (i = 0; i < max + 1; i++)
    {
        while (bin[i] != NULL)
        {
            struct Node *temp = bin[i];
            bin[i] = bin[i]->next;
            free(temp);
        }
    }
    free(bin);
}

void Insertion(int A[], int n)
{
    int i, j, x;
    for (int i = 1; i < n; i++)
    {
        x = A[i];
        j = i - 1;

        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

void Bubble(int A[], int n)
{
    int i, j, flag;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                flag = 1; //if swap happens any time in the pass, flag is set to 1
            }
        }
        if (flag == 0)
            break; //in any pass, if no swaps happen, it implies the array is sorted and we break from the function
    }
}

void Selection(int A[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        j = k = i;
        while (j < n)
        {
            if (A[j] < A[k])
                k = j;
            j++;
        }
        swap(&A[k], &A[i]);
    }
}

int Partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l;
    int j = h;
    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot); //i stops incrementing when an element greater than pivot is encountered
        do
        {
            j--;
        } while (A[j] > pivot); // j stops decrementing when an element lesser than pivot is encountered
        if (i < j)
            swap(&A[i], &A[j]);
    } while (i < j);
    swap(&A[j], &A[l]);

    int x = j;
    return x; //returning index where partition is done
}

void QuickSort(int A[], int l, int h)
{
    if (l < h)
    {
        int x = Partition(A, l, h);
        QuickSort(A, l, x);
        QuickSort(A, x + 1, h);
    }
}

void merge(int A[], int l, int mid, int h)
{
    int i, j, k;
    int B[100];
    i = l;
    j = mid + 1;
    k = l;
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    for (; i <= mid; i++)
        B[k++] = A[i];
    for (; j <= h; j++)
        B[k++] = A[j];

    for (i = l; i <= h; i++)
    {
        A[i] = B[i];
    }
}

void MergeSort(int A[], int n)
{
    int l, mid, h, p, i;
    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, h);
        }
    }
    //printf("p = %d\ni = %d\nn=%d\n", p,i,n);
    if (n - i > p / 2)
    {
        l = i;
        h = i + p - 1;
        mid = (l + h) / 2;
        merge(A, l, mid, n - 1);
    }
    if (p / 2 < n)
    {
        merge(A, 0, p / 2 - 1, n - 1);
    }
}

void RMergeSort(int A[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        RMergeSort(A, l, mid);
        RMergeSort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}

void CountSort(int A[], int n)
{
    int i, j = 0;
    int max = findmax(A, n);
    printf("%d\n", max);
    int *c = (int *)malloc(sizeof(int) * (max + 1));

    for (i = 0; i < max + 1; i++)
    {
        c[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        c[A[i]]++;
    }
    i = 0;
    while (i < max + 1)
    {
        if (c[i] > 0)
        {
            A[j++] = i;
            c[i]--;
        }
        else
            i++;
    }
}

void ShellSort(int A[], int n)
{
    int gap, i, j, temp;
    for (gap = n / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = A[i];
            j = i - gap;
            while (j >= 0 && A[j] > temp)
            {
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = temp;
        }
    }
}


int main()
{
    int A[] = {6, 3, 9, 10, 15, 6, 8, 12, 3, 6};

  ShellSort(A, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
       
    return 0;
}
