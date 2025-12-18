#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(my_atof(s));
            break;
        case COMMAND:
            handle_command(s);
            break;
        case MATH_FUNC:
            handle_math_function(s);
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
    return 0;
}

//-----------------------Transform string numbers to integers-----------------------
double my_atof(char s[])
{
    double val, power;
    int sign, i;
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    return sign * val / power;
}