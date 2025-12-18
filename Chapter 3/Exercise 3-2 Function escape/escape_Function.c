/*Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into visible
escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the
other direction as well, converting escape sequences into the real characters.*/

#include <stdio.h>

void escape(char s[], char t[]);
void entry(char s[], char t[]);

int main()
{
    char orginal[1000] = {0};
    char copy[1000] = {0};
    int c, i;

    for (i = 0; (c = getchar()) != EOF; i++)
    {
        orginal[i] = c;
    }
    orginal[i] = '\0';

    entry(copy, orginal);
    //printf("%s", copy);
    printf("Corrected string: %s", copy);
    return 1;
}

void escape(char s[], char t[])
{

    int c, e = 0;
    for (int i = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
        case '\t':
            s[e++] = '\\';
            s[e++] = 't';
            break;
        case '\n':
            s[e++] = '\\';
            s[e++] = 'n';
            break;

        default:
            s[e] = t[i];
            e++;
            break;
        }
    }
    s[e] = '\0';
}

void entry(char s[], char t[])
{
    int e = 0;
    for (int i = 0; t[i] != '\0'; i++)
    {
        if (t[i] == '\\'  && t[i + 1] != '\0' )
        {
            if (t[i + 1] == 't'){
                s[e++] = '\t';
                i++;
            }else if (t[i + 1] == 'n'){
                s[e++] = '\n';
                i++;
            }
        }else{
            s[e++] = t[i]; 
        }
        s[e] = '\0';
    }
}
