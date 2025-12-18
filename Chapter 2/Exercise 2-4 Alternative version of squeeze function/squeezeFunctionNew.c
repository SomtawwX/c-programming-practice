// Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in s1 that
// matches any character in the string s2.

#include <stdio.h>
#include <stdbool.h>

void squeeze(char s1[], char s2[]);

int main()
{
    int c, i;
    char string[1000] = {0};
    char string2[1000] = {0};
    printf("Introduce the first string: \n");
    for (i = 0; (c = getchar()) != EOF; i++)
        string[i] = c;
    string[i] = '\0';
    printf("Introduce the sencond string: \n");
    for (i = 0; (c = getchar()) != EOF; i++)
        string2[i] = c;
    string2[i] = '\0';

    squeeze(string, string2);

    return 1;
}

void squeeze(char s1[], char s2[])
{
    int i, j;
    i = j = 0;
    bool enablePrint;
    while (s1[i] != '\0')
    {
        enablePrint = true;
        for (j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
            {
                enablePrint = false;
                break;
            }
        }
        if (enablePrint)
            putchar(s1[i]);
        i++;
    }
}