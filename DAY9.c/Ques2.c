//Write a function that reverses a string. The input string is given as an array of characters s.
//You must do this by modifying the input array in-place with O(1) extra memory.

 #include <stdio.h>
#include <string.h>

void reverseString(char s[])
{
    int i = 0;
    int j = strlen(s) - 1;
    char temp;

    while (i < j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        i++;
        j--;
    }
}

int main()
{
    char s[100];

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    int len = strlen(s);
    if (s[len - 1] == '\n')
        s[len - 1] = '\0';

    reverseString(s);

    printf("Reversed string: %s\n", s);

    return 0;
}
