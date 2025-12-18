#include <stdio.h>
#define OUT 0
#define IN 1

/*
    ***Exercise 1-12. Write a program that prints its input one word per line.*** 
        Esta solucion es mala y creo que se puede solcionar de manera más eficiente pero la dejare
        así para en un futuro volver y ver como he mejorado.
  */

int main(){

    int c, STATE;

    STATE = OUT;

    while ((c = getchar()) != EOF){
        
       if(STATE == OUT){
            STATE = IN;

        }
        while (STATE == IN){

             putchar(c);
             c = getchar();

             if (c == ' ' || c == '\n' || c == '\t'){
                STATE = OUT;
           
             } 
        }
        printf("\n");


       
    }
}