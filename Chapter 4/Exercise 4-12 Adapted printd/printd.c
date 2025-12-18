/*Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string by calling a recursive
routine.*/

#include <stdio.h>

void printd(int n, char s[]);
void printd_wrapper(int n, char s[]);

int main()
{

    char array[100];

    printd(-1543, array);
    printf("%s\n",array);
    printd(1543, array);
    printf("%s", array);

    return 0;
}

int i = 0;

void printd(int n, char s[])
{
 
    unsigned int num;

    if (n < 0)
    {
        s[i++] = '-';
        num = -((unsigned int)n);
    }
    else
    {
        num = n;
    }
    printd_wrapper(num, s);
    i = 0;
}

void printd_wrapper(int n, char s[])
{
    if (n / 10)
        printd_wrapper(n / 10, s);

    s[i++] = (n % 10 + '0');
    s[i] = '\0';
}