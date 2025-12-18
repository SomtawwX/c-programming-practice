#include <stdio.h>

void mystrcat(char *s, char *t);

int main()
{
    char s[100] = {"Hello"};
    mystrcat(s, " World");
    printf("%s\n", s);

    return 0;
}

void mystrcat(char *s, char *t)
{
    while (*s)
        s++;
    while (*s++ = *t++)
        ;
}