/*Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in the
string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits,
and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing -
is taken literally. */

#include <stdio.h>
#include <ctype.h>

//No estoy seguro si es exactamente lo que pedia el libro pero me estoy atrasando con esta parte.
// Así que lo dejare así pero luego puede que la rehaga.
void expand(char s1[], char s2[]);

int main()
{
    char original[1000] = {0};
    char fixedArray[1000] = {0};
    int i, c;

    for (i = 0; (c = getchar()) != EOF && i < sizeof(original) - 1; i++)
    {
        original[i] = c;
    }

    original[i] = '\0';

    expand(original, fixedArray);

    printf("%s", fixedArray);
    return 0;
}

void expand(char s1[], char s2[])
{
    int i = 0, j = 0;
    char high = 0, low = 0;
    while (s1[i] != '\0')
    {
        while (s1[i + 1] == '-' && s1[i + 2] != '\n' && s1[i + 2] != '\0')
        {
            char start = s1[i];
            char end = s1[i + 2];

            if (islower(start) && islower(end) ||
                isupper(start) && isupper(end) ||
                isdigit(start) && isdigit(end))
            {

                if (start > end && low == 0)
                {
                    low = end;
                }
                else if (start < end && low == 0)
                {
                    low = end;
                }

                if (start > high && start > end)
                {
                    high = start;
                }
                else if (start < low && start < end)
                {
                    low = start;
                }
                if (end > start && end > high)
                {
                    high = end;
                }
                else if (end < start && end < low)
                {
                    low = end;
                }

                i += 2;
            }
        }
        if (high != 0 && low != 0)
        {
            for (char c = low; c <= high; c++)
            {
                s2[j++] = c;
            }
        }

        low = high = 0;
        i++;
    }
}
