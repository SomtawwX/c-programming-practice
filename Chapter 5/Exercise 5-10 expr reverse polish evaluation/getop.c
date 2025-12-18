#include <stdio.h>
#include <ctype.h>
#include "acts.h"

int getop(char s[]){
    
    if (s[0] == '$'){
        for (int i = 0; s[i] != '\0'; i++){
           
            s[i] = s[i + 1];
            
        }
        return COMMAND;
    }

    if(!isdigit(s[0]) && s[0] != '.'){
        if(isalpha(s[0])){
            return MATH_FUNC;
        }else{
            return s[0];
        }
    }
   return NUMBER;

}
