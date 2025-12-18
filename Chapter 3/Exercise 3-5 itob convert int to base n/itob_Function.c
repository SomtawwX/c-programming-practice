/*Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b character
representation in the string s. In particular, itob(n,s,16) formats s as a hexadecimal integer in s*/
#include <stdio.h>
#include <string.h>

void itob(int n, int b, char s[]);
void reverse(char s[]);

int main()
{
    char numsys [100] = {0};
    itob(133344, 2, numsys);
    printf("%s", numsys);
    return 0;
}

void itob(int n, int b, char s[])
{
    int i = 0;
    int result = 0;
    const char digits[] = "0123456789ABCDEF";
    do{
        result = n % b; 
        
             s[i++] = digits[result];

    } while ((n /= b) > 0); 

    reverse(s);

}

void reverse(char s[]){
    char temp;
    for(int i = strlen(s) - 1, j = 0; i > j; i--, j++){
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
}