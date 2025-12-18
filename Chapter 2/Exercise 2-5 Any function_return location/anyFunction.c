/*Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1 where any
character from the string s2 occurs, or -1 if s1 contains no characters from s2. (The standard library
function strpbrk does the same job but returns a pointer to the location.) */

#include <stdio.h>


int any(char s1[], char s2[]);

int main()
{
    int c, i, matchIndex = 0;
    char string[1000] = {0};
    char string2[1000] = {0};

    printf("Introduce the first string: \n");
    for (i = 0; (c = getchar()) != EOF; i++)
        string[i] = c;
    string[i] = '\0';
    printf("Introduce the second string: \n");
    for (int i = 0; (c = getchar()) != EOF; i++)
        string2[i] = c;
    string2[i] = '\0';

    matchIndex = any(string, string2);

    if (matchIndex == -1)
    printf("There is no matches between characters");
    else
    printf("Found matched characters from String2 in index, %d, of String1.", matchIndex);
    
    return 0;
}

int any(char s1[], char s2[])
{
    for (int i = 0; s1[i] != '\0'; i++)
    {
        for (int j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
            {
                return i;
            }
        }
    }
    return -1;
}
