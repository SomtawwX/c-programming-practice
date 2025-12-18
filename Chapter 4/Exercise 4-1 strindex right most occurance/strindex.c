// Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost occurrence of t in s, or -1 if there is none.

#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int lim);
int strindex(char s[], char t[]);

char pattern[] = "ould";

int main()
{
    int position ;
    char string[MAXLINE] = {0};

    while (getline(string, MAXLINE) > 0)
    {
        if((position = strindex(string, pattern)) >= 0){
            printf("The last known match index is: %d", position);

        }else{
            printf("No matches found.\n");
        }
    }

    return 0;
}

int getline(char s[], int lim)
{
    int i = 0, c;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n'){
        s[i++] = c;
    }
    s[i] = '\0';

    return i; 
}

int strindex(char s[], char t[]){
    int i , k,  j, result = 0;
    for (i = 0; s[i] != '\0'; i++){
        for (k = 0, j = i; t[k] == s[j]; k++, j++);
        if (k > 0 && t[k] == '\0' ){
            result = i;
        }
    }
    if (result > 0){
       return result;
    }else{
        return -1; 
    }
    
}