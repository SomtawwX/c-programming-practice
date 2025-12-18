// Exercise 5-7. Rewrite readlines to store lines in an array supplied by main, rather than calling alloc to maintain storage. How much faster is the program?

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
#define B_ZISE 5000

int readlines(char *lineptr[], char *storage, int nlines);
int getline(char *line, int LINESIZE);

char *lineptr[MAXLINE];

int main()
{

    int nline = 0;
    char s[B_ZISE];

    if ((nline = readlines(lineptr, s, MAXLINE)) >= 0)
    {
      for(int i = 0; i > nline; i++){
        printf("%s\n", s[i]);
      }
    }else{
        printf("Too many lines to store\n");
    }
    return 0;
}

int getline(char *line, int lineSize)
{
    int c;
    char *sLine = line;
    while (lineSize-- > 0 && (c = getchar()) != EOF && c != '\n')
    {
        *line++ = c;
    }
    if (c == '\n')
    {
        *line++ = '\n';
    }
    *line = '\0';
    return line - sLine;

}

int readlines(char *lineptr[], char *st, int nlines)
{
    int len, nline = 0;
    char line[MAXLINE];
    
    char *lineEnd = st + B_ZISE;

    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (nline >= MAXLINE || st + len > lineEnd)
        {
            return -1;
        }
        else
        {
            line[len - 1] = '\0';
            lineptr[nline++] = st;
            strcpy(st, line);
            st += len;
            
        }
    }
    return nline;
}
