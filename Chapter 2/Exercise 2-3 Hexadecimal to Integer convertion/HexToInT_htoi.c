#include <stdio.h>
#include <math.h>

int htoi(char s[]);
int power(int power, int base);



int main()
{
    char hexString[1000] = {0};
    int c = 0;
    int i;

    printf("Enter a hexadecimal string: ");
    for (i = 0; (c = getchar()) != '\n' && c != EOF; i++){
        hexString[i] = c;
        
    }
        hexString[i] = '\0'; // Null-terminate the string


    printf("The decimal value is: %d\n", htoi(hexString));
    return 0;
}

int htoi(char s[])
{
    int n = 0;
    int i = 0; 
    int len;

    for(len = 0; s[len] != '\0'; len++);

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')){
        i = 2;
        len -= 2;
    } 

    for (; s[i] != '\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            n += power(--len, 16) * (s[i] - '0');
            
        }
        if (s[i] >= 'a' && s[i] <= 'f')
        {
            n += (10 + s[i] - 'a') * power(--len, 16);                
        }
        if (s[i] >= 'A' && s[i] <= 'F')
        {
            n += (10 + s[i] - 'A') * power(--len, 16);                
        }
      
    }
    return n;
}

int power (int power, int base){
    int r = 1;

    while (power > 0){
        power--;
        r *= base;
    }
    
    return r; 
}