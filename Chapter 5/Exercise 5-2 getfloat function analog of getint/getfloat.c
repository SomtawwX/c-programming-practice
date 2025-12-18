/*Exercise 5-2. Write getfloat, the floating-point analog of getint. What type does getfloat return as its function value? */

#include <stdio.h>
#include <ctype.h>
#include <limits.h>

#define SIZE 100

int getch(void);
void ungetch(int c);

int main()
{
    float array[SIZE];
    int n, getfloat(float *);
  
    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
        ;

    for (int i = 0; i < n; i++)
    {
        printf("%f\n", array[i]);
    }
    
    return 0;
}

int getfloat(float *px)
{
    int c , sign;
    double power;
    while (isspace(c = getch()))
        ;

    sign = (c == '-') ? -1 : 1;

    if (c == '-' || c == '+')
    {
        c = getch();
        if (!isdigit(c))
        {
            ungetch(c);
            ungetch((sign < 0) ? '-' : '+');

            printf("Character isn't a number: %c", c);
            return 0;
        }
    }

    for (*px = 0; isdigit(c); c = getch())
    {
        *px = *px * 10.0 + (c - '0');
    }

    if (c == '.')
    {
        c = getch();
        for (power = 1.0; isdigit(c); c = getch())
        {
            *px = 10.0 * *px + (c - '0');
            power *= 10;
        }
        *px /= power;
    }
    *px *= sign;

    if (c != EOF)
    {
        ungetch(c);
    }
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