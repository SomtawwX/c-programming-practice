/*Exercise 5-13. Write the program tail, which prints the last n lines of its input. By default, n is set to 10,
let us say, but it can be changed by an optional argument so that

 tail -n

prints the last n lines. The program should behave rationally no matter how unreasonable the input or the value
of n. Write the program so it makes the best use of available storage; lines should be stored as in the sorting
program of Section 5.6, not in a two-dimensional array of fixed size. */

#define MAXLINE 5000
#define MAXLEN 1000

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int readLine(char *lineptr[], int nlines);
int getLine(char *, int n);
char *alloc(int lenght);
int get_flag_value(int *argc, char ***argv);

char *lineptr[MAXLINE];

int main(int argc, char *argv[])
{
    int start, n = 10, nlines;
    while (--argc > 0)
    {
        argv++;
        if ((*argv)[0] == '-')
        {

            char *p = *argv;
            int c, val = 0;
            while (c = *++p)
            {
                switch (c)
                {
                case 'n':
                    val = get_flag_value(&argc, &argv);
                    if (val >= 0)
                    {
                        n = val;
                    }
                    else
                    {
                        printf("Warning: Undefined value n. Using defaults");
                    }
                    break;

                default:
                    printf("Error: Unrecognized flag %c\n", c);
                    break;
                }
            }
        }
    }
    nlines = readLine(lineptr, MAXLINE);
    start = nlines - n;

    if (start < 0)
    {
        start = 0;
    }
    for (int i = start; i < nlines; i++)
        printf("[%d]\t%s\n", i, lineptr[i]);
}

int readLine(char *lineptr[], int maxlines)
{

    int len, nlines = 0;
    char s[MAXLINE], *p;

    //While there's still lines
    while ((len = getLine(s, MAXLEN)) > 0)   
    {
        //If the line size is bigger than the storage or bigger than the space available
        if (nlines >= MAXLINE || (p = alloc(len)) == NULL)  
        {
            return -1; 
        }
        else
        {
            s[len - 1] = '\0';
            strcpy(p, s);
            lineptr[nlines++] = p; // Store start of line address
        }
    }
    return nlines;
}

int getLine(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;

    if (c == '\n')
    {
        s[i++] = c;
    }
    return i;
}

static char allocbuff[MAXLINE];
static char *allocp = allocbuff;

char *alloc(int n)
{
    if (allocbuff + MAXLINE - allocp >= n)
    {
        allocp += n;
        return allocp - n; // Address start of line
    }
    else
    {
        return NULL;
    }
}

int get_flag_value(int *argc, char ***argv)
{
    if (*argc > 1 && isdigit((unsigned int)(*argv)[1][0]))
    {
        int val = atoi((*argv)[1]);
        (*argv)++;
        (*argc)--;
        return val;
    }
    else
    {
        return -1;
    }
}
