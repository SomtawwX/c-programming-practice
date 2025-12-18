/*Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid representation of zero. Fix it to push such a character back on the input. */

#include <stdio.h>
#include <ctype.h>

#define SIZE 100

void ungetch(int cha);
int getch();

int main()
{
    int n, getint(int *), array[SIZE];
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}

int getint(int *px)
{
    int c, sign;
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != '-' && c != '+' && c != EOF)
    {
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        if (!isdigit(c = getch()))
        {
            ungetch(c);
            ungetch((sign < 0) ? '-' : '+');
        }
    }

    for (*px = 0; isdigit(c); c = getch())
        *px = *px * 10 + (c - '0');
    *px *= sign;

    if (c != EOF)
        ungetch(c);
    return c;
}

int buffer[SIZE];
int bufp = 0;

int getch()
{

    return (bufp > 0) ? buffer[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp < SIZE - 1)
    {
        buffer[bufp++] = c;
    }
    else
    {
        printf("Error: Buffer is full");
    }
}