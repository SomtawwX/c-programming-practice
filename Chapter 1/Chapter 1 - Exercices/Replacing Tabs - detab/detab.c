#include <stdio.h>
#define TABSTOP 8

char line[1000];

int main()
{
    int c,b = 0, i = 0;
    while ((c = getchar()) != EOF)
    {
        if(c != '\t')
        {
            line[b] = c;
            b++;
            i++;
        }else{
            for (int j = 0; j < TABSTOP - (i % TABSTOP); j++)
            {
                line[b] = ' ';
                b++;
                
            }
            i = 0; 
        } 
        
    }
    printf("%s", line);
    return 0;
}
