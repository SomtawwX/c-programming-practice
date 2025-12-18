#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
int reverse(char line[], int linezise);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;

    while ((len = getline(line, MAXLINE)) > 0)
    {
        int i;
        int count = 0;
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
        /* if(len > 80){                                                    //Ejercicio 1-17 
             printf("this has more than 80 characters: %s", line);
         }*/

        /*for (i = len - 1; i > 0; i--)                                     //Ejercicio 1-18
        {

            if (line[i] == '\t' || line[i] == ' ') {
                count++;  // Cuenta los espacios/tabs eliminados
            } else {
                break;  // Detente cuando encuentres un carácter válido
            }
       
        }
        line[i + 1] = '\0';
        printf("Tralling white space removed: %d\n", count);
        printf("%s", line);*/

        reverse(line, len);                                                 //Ejercicio 1-19

        /*if (max > 0)
        {
            printf("%s", longest);
        }*/
    }
}

int getline(char line[], int maxline)
{
    int c;
    int i;
    int count = 0;
    // Since the array starts at 0, we need to subtract 1 from maxline
    for (i = 0; (c = getchar()) != EOF && c != '\n'; count++)
    {

        if (i < maxline - 1)
        {
            line[i++] = c;
        }
    }

    if (c == '\n')
    {

        if (i < maxline - 1)
        {
            line[i++] = c;
        }
        count++;
    }
    line[i] = '\0';
    // printf("The length of the line is %d\n", count);
    return count;
}

void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        i++;
    }
}

int reverse(char line[], int linezise)
{
    while(linezise - 1 >= 0){
        printf("%c", line[linezise]);
        linezise--;
    }
}