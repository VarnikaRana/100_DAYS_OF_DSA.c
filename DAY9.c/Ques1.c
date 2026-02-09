//Problem: A secret system stores code names in forward order. To display them in mirror format, 
// you must transform the given code name so that its characters appear in the opposite order.

#include <stdio.h>
#include <string.h>

int main()
{
    char code[100];
    int i;

    printf("Enter the code name: ");
    gets(code);   

    printf("Mirror format: ");
    for (i = strlen(code) - 1; i >= 0; i--)
    {
        printf("%c", code[i]);
    }

    return 0;
}

