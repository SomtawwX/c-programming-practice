#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
    static char lastchar;
    int i, c, j;
   /* if(lastchar == 0){
        c = getch();
    }else{
        c = lastchar;
        lastchar = 0;
    }*/
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (c == '$')
    {
        i = 0;
        while (isalpha(c = getch()) && i < MAXOP - 1)
            s[i++] = c;

        s[i] = '\0';

        if (c != EOF)
        {
            ungetch(c);
        }
        return COMMAND;
    }

    if (!isdigit(c) && c != '.')
    {
        if (isalpha(c))
        {
            i = 1;
            while (isalpha(c = getch()))
                s[i++] = c;

            s[i] = '\0';

            if (c != EOF)
            {
                ungetch(c);
            }
            return MATH_FUNC;
        }
        else
        {
            return c;
        }
    }

    i = 1;
    if (isdigit(c))
    {
        while (isdigit(s[i++] = c = getch()))
            ;
    }
    if (c == '.')
    {
        s[i++] = c;
        while (isdigit(s[i++] = c = getch()))
            ;
    }

    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}