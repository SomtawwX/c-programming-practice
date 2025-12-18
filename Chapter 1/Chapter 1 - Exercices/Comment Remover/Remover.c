#include <stdio.h>
#include <stdbool.h>
#define ENABLED 1
#define DISABLED 0

int main()
{
    int c;
    bool inComment = DISABLED;
    bool inBlockComment = DISABLED;
    bool inString = DISABLED;
    int previous = 0;
    while ((c = getchar()) != EOF)
    {
      
        if (c == '/' && previous == '/' && !inString)
        {
            inComment = ENABLED;
        }
        else if (c == '\n' && inComment == ENABLED)
        {
            inComment = DISABLED;
            previous = 0;
        }

        if (c == '*' && previous == '/' && !inString)
        {
            inBlockComment = ENABLED;
        }
        else if (c == '/' && previous == '*' && inBlockComment == ENABLED)
        {
            inBlockComment = DISABLED;
            c = 0;
            previous = 0;
        }
        {
            
            if (c == '"' && previous != '\\')
            inString = !inString;
        }

        if (!inComment && !inBlockComment && previous != 0)
        {
         putchar(previous);
        }
        previous = c;
       
    }
}