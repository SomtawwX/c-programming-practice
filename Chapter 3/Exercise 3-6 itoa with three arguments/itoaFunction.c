/*Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third argument is
a minimum field width; the converted number must be padded with blanks on the left if necessary to
make it wide enough. */

#include <stdio.h>


void itoa (int n, char s[], int width);
void reverse(char s[], int len);

int main(){
    char array[100] = {0};
    itoa(-423, array, 6);
    printf("%s", array);
    return 0;
}

void itoa (int n, char s[], int width){
    int i = 0, sign = n;
    unsigned int num = (sign < 0) ? -(unsigned int)n : (unsigned int)n;
    do{
        s[i++] = num % 10 + '0';
        
    } while((num /= 10) > 0);

    while (i < width){
        s[i++] = ' ';
    }

    if (sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s, i);
    
    
}

void reverse(char s[], int len){
    char temp;
    for (int i = len - 1, j = 0; i > j; i--, j++){
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
}