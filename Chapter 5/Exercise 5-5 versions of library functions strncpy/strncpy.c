/*Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp, which operate on at most the first n characters of their argument strings. For
example, strncpy(s,t,n) copies at most n characters of t to s.*/

#include <stdio.h>

void strncpy(char *s, char *t, int n);
void strncat(char *s, char *t, int n);
void strncmp(char *s, char *t, int n);

int main()
{

    return 0;
}

void strncpy(char *s, char *t, int n)
{
    int len = 0;

    while (len < n && (*s++ = *t++))
        len++;
    while (len++ < n)
        *s++ = '\0';
}

void strncat(char *s, char *t, int n)
{
    int len = 0;
    while(*s)
    s++;

    while (len < n && (*s = *t++)){
        len++;
        s++;
    }

   *s = '\0';
}

void strncmp(char *s, char *t, int n){

    for(int i = 0; i < n && *s == *t; s++, t++, i++)
        if(*s == '\0')
            return 0;
    return *s - *t; 
}