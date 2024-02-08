// program to count the number of words in a string
// Logic: Number of words in a string is equal to the number of spaces + 1
// in case of multiple spaces used between two words, we check that we consider only one space at a time
# include <stdio.h>

int main()
{
    char a[] = "How are   you doing";
    int space = 0;

    for(int i = 0; a[i] !='\0'; i++)
    {
        if(a[i]== ' ' && a[i-1] != ' ')//if there is a space and ensure that the previous character was not a space
            space++;
    }
    // Number of words is space + 1
    printf("Number of words in the given string is %d\n", space+1);       
}