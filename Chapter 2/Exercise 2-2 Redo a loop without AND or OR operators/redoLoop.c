
//Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||. 
//The loop should be equivalent to the following for loop:
// for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) s[i] = c;

#include <stdio.h>

int main(){
    int i = 0;
    int lim = 1000; // Assuming a limit for the string length
    char s[lim]; // Assuming s is a character array to store the input
    int c;

    while (i <lim -1){
        c = getchar();

        if(c != EOF){
            if (c != '\n'){
                s[i] = c;
                i++;
            }

        }else{
            break; // Exit the loop if EOF is encountered
        }
        
    }
}