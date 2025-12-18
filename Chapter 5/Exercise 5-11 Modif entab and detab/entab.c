/*Exercise 5-12. Extend entab and detab to accept the shorthand "entab -m +n"
to mean tab stops every n columns, starting at column m. Choose convenient (for the user) default behavior. */
#define TABEND 8
#define MAXSIZE 1000

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void entab(char s[], int nclum, int cstart);
int get_flag_value(int *argc, char ***argv);

int main(int argc, char *argv[])
{
    int c, val, ncolum = TABEND, colStart = 0;
    int cInput;
    char string[MAXSIZE];

    while (--argc > 0) // Parses the command line arguments
    {
        argv++;

        if ((*argv)[0] == '-' || (*argv)[0] == '+')
        {

            char *p = *argv;

            while ((c = *++p))
            {
                switch (c) //-mngd 4
                {
                case 'm':
                    val = get_flag_value(&argc, &argv);

                    if (val >= 0)
                    {
                        colStart = val;
                    }
                    else
                    {
                        printf("Warning: Missing value for flag m, using default values\n");
                    }
                    break;

                case 'n':
                    val = get_flag_value(&argc, &argv);

                    if (val >= 0)
                    {
                        ncolum = val;
                    }
                    else
                    {
                        printf("Warning: Missing value for flag n, using default values\n");
                    }
                    break;

                default:
                    printf("Undefined flag: %c\n", c);
                    break;
                }
            }
        }
    }

    printf("Enter the sentence to edit(Maximun string size of 1000): \n");
    int i = 0;
    while ((cInput = getchar()) != EOF && i < MAXSIZE - 1)
    {
        string[i] = cInput;
        i++;
    }
    string[i++] = '\0';

    entab(string, ncolum, colStart);
}

void entab(char s[], int nclum, int cstart)
{
    int currentpos = 0;
    int blanks = 0;

    while (*s)
    {

        if (*s == ' ')
        {
            blanks++;
        }
        else
        {

            /* We are past cstart AND next output hits a tab stop */
            if (currentpos >= cstart &&
                (blanks % nclum) == 0)
            {

                while (blanks > 0)
                {
                    putchar(' ');
                    blanks--;
                }
                
            }

            /* Print the non-space char */
            putchar(*s);

            if (*s == '\n')
                currentpos = 0;
            else
                currentpos++;
        }

        s++;
    }

    /* Flush trailing blanks at end of input */
    while (blanks-- > 0)
        putchar(' ');
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
