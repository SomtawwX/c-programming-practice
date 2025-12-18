#include "calc.h"
#include <string.h>

char stringbuffer[BUFFER_SIZE];
char currentstring[BUFFER_SIZE];
static int buffer[BUFFER_SIZE];
static int bufp = 0; // Buffer pointer

char getch(void)
{
    int i = 0, c;
    if (bufp > 0)
    {
        // printf("buffer: %c\n", buffer[bufp - 1]);
        return buffer[--bufp];
    }
    else
    {

        c = getchar();
        if (i <= BUFFER_SIZE - 1)
        {
            currentstring[i++] = c;
        }
        if (c == '\n')
        {
            currentstring[i - 1] = '\0';
            if (currentstring[0] != '$')
                strcpy(stringbuffer, currentstring);
            i = 0;
        }

        return c;
    }

    // return (bufp > 0) ? buffer[--bufp] : getchar();
}
void ungetch(char c)
{
    if (bufp <= BUFFER_SIZE)
        buffer[bufp++] = c;
    else
        printf("Error: Ungetch Buffer is full\n");
}

void ungets()
{
    int i = 0;
    bufp = 0;
    strrev(stringbuffer);
    for (i; stringbuffer[i] != '\0'; i++)
    {
        ungetch(stringbuffer[i]);
    }
}