#include <stdio.h>
#include <string.h>
#include <limits.h>

/*Exercise 3-4. In a two's complement number representation, our version of itoa does not handle the
largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why not. Modify it to print
that value correctly, regardless of the machine on which it runs. */

void newItoa(int n, char s[]);
void reverse(char s[]);

int main()
{
    int i = 0;
    char string[1000] = {0};

    newItoa(INT_MIN, string);
    printf("%s", string);
    return 0;
}

// The reason why the previous version of ITOA couldn't handle the biggest Negative number possible was that 
// being a signed number the max positive value it could hold is 1 number less than the negative (INT_MAX is the max value positive it can hold)
// and previously we were using a n = -n to reverse negative numbers but if the number was INT_MIN then it would cause an overflow
// this would give us the wrong answer, so instead I saved the values first into unsinged int by casting n into a unsinged value

void newItoa(int n, char s[])
{
    int i = 0; 
    unsigned int negNum = (n < 0) ? -(unsigned int)n : (unsigned int)n;

    do{
        s[i++] = negNum % 10 + '0';
        
    }while ((negNum /= 10) > 0);

    if(n < 0){
        s[i++] = '-';
    }
    reverse(s);
    s[i++] = '\0';

}

void reverse(char s[]){
    int j = 0;
   
    for (int i = strlen(s) - 1; i > j; i--, j++){
        char temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
}