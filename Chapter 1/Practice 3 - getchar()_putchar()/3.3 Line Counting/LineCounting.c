#include <stdio.h>

int main(){
/*  
    Exercise 1-8. Write a program to count blanks, tabs, and newlines
    Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a
    single blank. 
*/
    int c, previus, cha;
    int lineCount, blankCount, tabCount;
    lineCount = 0;
    blankCount = 0;
    tabCount = 0;

    while((c = getchar()) != EOF){
        if (c == '\n')
        {
           lineCount++;
        }
        if(c == ' '){
            blankCount++;
        }
        if(c == '\t'){
            tabCount++;
            putchar(' ');
            printf("\\t");

        }else if (c == '\b')
        {
            printf("\\b");
        }else if(c == '\\'){
            printf("\\");
            
        }
   
       
        if (c != ' ' || (c == ' ' && previus != ' ')){

            putchar(c);
        }
          previus = c;
    }
    printf("El numero de espacios es: %d\n", blankCount);
    printf("El numero de tabulaciones es: %d\n", tabCount);
    printf("El numero de lineas en el programa es de: %d\n", lineCount);




    return 0;
}