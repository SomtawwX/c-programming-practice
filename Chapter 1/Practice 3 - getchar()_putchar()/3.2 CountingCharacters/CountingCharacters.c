#include <stdio.h>

int main(){

    long c;
    c = 0;
    /*Otra forma de escribirlo es así:
    for(c = 0; getchar() != EOF, c++);
    */
    while(getchar() != EOF){
        c++;
    }
    printf("La cantidad le letras es: %ld\n", c);
    return 0;
}