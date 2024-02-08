//Program to implement double hashing
# include <stdio.h>
# define SIZE 10

int hash1(int key)
{
    return key % SIZE;
}

int hash2(int key)
{
    return 7-(key % 7);
}

int doublehash(int H[], int key)
{
    int index = hash1(key);
    int i = 0;
    while(H[(hash1(key)+ i * hash2(key)) % SIZE] !=0)
        i++;
    return (hash1(key) + i * hash2(key)) % SIZE;

}

void Insert(int H[], int key)
{
    int index = hash1(key);

    if(H[index]!= 0)  //already occupied
        index = doublehash(H, key);

     H[index] = key;   
}

int Search(int H[], int key)
{
    int index = hash1(key);
    
    int i = 0;
    while(H[(hash1(key)+ i * hash2(key)) % SIZE]!=key)
        i++;
    return (hash1(key)+ i * hash2(key)) % SIZE;
}

int main()
{
    int HT[10] = {0};

    Insert(HT,5);
    Insert(HT,25);
    Insert(HT,15);
    Insert(HT,35);
    Insert(HT,95);

    printf("\nKey found at %d\n", Search(HT, 5));
    printf("\nKey found at %d\n", Search(HT, 25));
    printf("\nKey found at %d\n", Search(HT, 15));
    printf("\nKey found at %d\n", Search(HT, 35));
    printf("\nKey found at %d\n", Search(HT, 95));
}