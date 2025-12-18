#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 1000

int getline(char *line, int maxSize);
int myatoi(char *s);
char *myitoa(int num, char *buffer);
void reverse(char *s);
int strindex(char *s, char *t);
int main()
{
}

int getline(char *s, int lim)
{
    int c;
    char *s1 = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';

    return s - s1;
}

int myatoi(char *s)
{
    int result = 0;

    while (isspace(*s))
        s++;
    for (; isdigit(*s); s++)
    {
        result = result * 10 + (*s - '0');
    }
    return result;
}

char *myitoa(int num, char *s)
{

    unsigned int n = (num < 0) ? -(unsigned int)num : (unsigned int)num;
    char *s1 = s;

    do
    {
        *s++ = n % 10 + '0';

    } while ((n /= 10) > 0);
    if (num < 0)
    {
        *s++ = '-';
    }

     *s = '\0';
    reverse(s1);

   

    return s1;
}

void reverse(char *s)
{
   char *end = s;

   while (*end++);
   end--;
   while (s < end){
    char temp = *s;
    *s++ = *end;
    *end-- = temp;
   }
}

int strindex(char *s, char *t){
    int i;
    for(i = 0; *s ; s++, i++){
        char *p = s;
        char *q = t;

        for (; *q && *p == *q; p++, q++);
        if (*q == '\0')
        return i;
    }
    return -1;
}