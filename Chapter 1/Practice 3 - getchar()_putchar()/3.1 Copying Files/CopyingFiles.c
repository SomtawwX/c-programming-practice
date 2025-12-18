#include <stdio.h>

int main() {
    int c;
    /*Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1*/

    while ((c = getchar()) != EOF) {
        putchar(c);
        printf(" El resultado de el Ejercicio 1-6 es: %d\n", c != EOF);
    }
    
    /*Repuesta al ejercicio*/
    printf("Salimos del bucle\n");
    printf(" El resultado de el Ejercicio 1-6_1 es: %d\n", c != EOF);
 
    
    return 0;
}