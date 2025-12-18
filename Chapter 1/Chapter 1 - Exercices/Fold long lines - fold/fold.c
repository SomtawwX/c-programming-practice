#include <stdio.h>
#define FOLDLIMIT 5
void fold();

int main()
{
    fold();
    return 0;
}

void fold()
{
    int c, i = 0;
    int lastSpace = 0;
    int lastChar = 0;
    int count = 0;
    char line[1000] = {0};

    while((c = getchar()) != EOF)
    {
        if (count < FOLDLIMIT-1)
        {
            line[i] = c;
            i++;
            count++;
            if (c == ' ' || c == '\t')
            {
                lastSpace = i;
                printf("SPACE: %d\n", lastSpace);
                
            }
        }
        else
        {
            
            if(line[i-1] != ' ' && line[i-1] != '\t'){
                line[i] = '-';
                line[i++] = '\n';
                
                
            }else{
                line[i] = c;
                line[lastSpace + 1] = '\n';
                
                
            }
            
            count = 0;
        }
    }
    line[i+1] = '\0';
    printf("%s", line);
}
