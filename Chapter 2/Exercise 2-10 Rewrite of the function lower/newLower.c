/*Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case, with a
conditional expression instead of if-else. */

#include <stdio.h>

char toLower (char x[]);

int main(){
    int c, i;
    char s[1000] = {0};
    printf("Introduce the sentence:");
    for(i = 0;(c = getchar()) != EOF; i++){
        s[i] = c; 
    }
    s[i] = '\0';
    toLower(s);
    return 0;
}
char toLower(char x[]){
    int c;
    for (c = 0; x[c] != '\0'; c++){  
        (x[c] >= 'A' && x[c] <= 'Z') ? putchar(x[c] + 'a' - 'A'): putchar(x[c]);
    }
}