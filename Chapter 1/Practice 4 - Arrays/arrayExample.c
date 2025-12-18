#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    /* Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the
       histogram with the bars horizontal; a vertical orientation is more challenging.  
       */
       
    int c, i, fcounter, cCounter, state;
    int ndigit[10] = {0};
    int char_num[28] = {0};
    fcounter = 0;
    cCounter = 0;
    
    state = OUT;

    while ((c = getchar()) != EOF)
    {
        
        if (c == ' ' || c == '\n' || c == '\t'){
        
            state = OUT;
            ++ndigit[fcounter];
            fcounter = 0;

        }else 
        {
            state = IN;
            ++fcounter;   
        }
      
        if(c > 96 && c <= 122){
            ++char_num[c - 'a'];
        } else if (c >= 65 && c < 90){
            ++char_num[c - 'A'];
        }
         
    }
   
    printf("Histograma de conteo de letras en palabra:\n");
    for (i = 0; i < 10; i++)
    {
        printf("[%d], ", i);
        for(fcounter = 0; fcounter < ndigit[i]; fcounter++){
            printf("*");
        }
        printf("\n");
        //printf("%d", ndigit[i]);
        
    }
        printf("-----------------------------------------------\n");
    printf("Histograma de repeticion de caracteres:\n");
    for (i = 0; i <= 28; i++){
        printf("[%d] ", i);
        for (cCounter = 0; cCounter < char_num[i]; cCounter++){
            printf("*");
        }
        printf("\n");
    }
        

}
    