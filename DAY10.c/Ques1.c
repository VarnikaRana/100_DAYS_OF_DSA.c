//Problem: Read a string and check if it is a palindrome using two-pointer comparison.

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, j, flag = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int len = strlen(str);
    if (str[len - 1] == '\n')
        str[len - 1] = '\0';

    i = 0;
    j = strlen(str) - 1;

    while (i < j)
    {
        if (str[i] != str[j])
        {
            flag = 0;
            break;
        }
        i++;
        j--;
    }

    if (flag == 1)
        printf("The string is a Palindrome.\n");
    else
        printf("The string is NOT a Palindrome.\n");

    return 0;
}
