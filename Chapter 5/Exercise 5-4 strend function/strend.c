/*Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the end of the string s, and zero otherwise. */

#include <stdio.h>

int strend(char *s, char *t);

int main()
{
    printf("%d", strend("Hi, Max","Max"));
    return 0;
}

int strend(char *s, char *t)
{
    char *p1 = s;
    char *p2 = t;
    while (*s)
        s++;
    while (*t)
        t++;
    if ((s - p1) < (t - p2))
        return 0;

    while(t > p2){
        if(*--s != *--t)
            return 0;
    }
    return 1;
    
}