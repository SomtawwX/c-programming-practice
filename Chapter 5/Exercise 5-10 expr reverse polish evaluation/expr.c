/*Exercise 5-10. Write the program expr, which evaluates a reverse Polish expression from the command line, where each operator or operand is a separate argument. For
example, expr 2 3 4 + *, evaluates 2 * (3+4). */

#include "acts.h"
#include <stdio.h>
#include <ctype.h>
int getop(char s[]);

int main(int argc, char *argv[])
{
    int type;
    double op2;
    if(argc == 1){
        printf("Usage: Input operands and then operators");
        return 0; 
    }
    while(*++argv){
        type = getop(argv[0]);

       switch (type)
        {
        case NUMBER:
            push(my_atof(*argv));
            break;
        case COMMAND:
            handle_command(*argv);
            break;
        case MATH_FUNC:
            handle_math_function(*argv);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("Error: can't divide by 0");
            break;
        case '%':
            op2 = pop();
            push((int)pop() % (int)op2);
            break;
        case '=':
            handle_assignment();
            break;
        case '\n':
            // printf("=\t%.8g\n", pop());
            break;
        default:
            printf("Error Unknown operation: %s\n");
            break;
        }
    }
}

double my_atof(char s[]){
    double val, power;
    int sign, i;

    for(i = 0; isspace(s[i]); i++);

    sign = (s[i] == '-')? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;
    
    for (val = 0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
       
    }

    if(s[i] == '.')
        i++;
    
    for(power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val +(s[i] - '0');
        power *= 10.0; 
    }
    return sign * val / power;
}