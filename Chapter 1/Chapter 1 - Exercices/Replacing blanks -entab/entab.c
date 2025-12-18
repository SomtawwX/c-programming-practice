#include <stdio.h>
#define TABSTOP 8

void entab();

int main()
{
  
    entab();
    
    return 0;
}

void entab(){

    int c, spaces, i;
    int currentPosition = 0;
    spaces = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            spaces++;
            if ((currentPosition + spaces) % TABSTOP == 0) // if the current index plus the number of spaces is a multiple of the tabstop
            {
                putchar('\t');
                spaces = 0;
            }
        }
        else
        {

            while (spaces > 0)
            { // print the remaining spaces before printing the character

                putchar(' ');
                spaces--;
            }
            
            if (c == '\n')
            {
                currentPosition = 0;
            }
            else
            {
                currentPosition++;
            }
            
            putchar(c);
        }
    }
}