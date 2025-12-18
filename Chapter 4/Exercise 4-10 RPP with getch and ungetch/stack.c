#include "calc.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

static double val[MAXVAL];         // Stack for pushing and poping the value
static int sp = 0;                 // Current postion of the stack pointer
static char alpha_var[26] = {0}; // Maps alphabetic letters to a value
static char init_var[26] = {0};

void push(double c)
{
    if (sp <= MAXVAL)
    {

        val[sp++] = c;
    }
    else
    {
        printf("Error: Stack is full\n");
    }
}

double pop(void)
{
    if (sp > 0)
    {

        return val[--sp];
    }
    else
    {
        printf("Error: No value found \n");
        return 0.0;
    }
}

void handle_command(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        s[i] = tolower(s[i]);
    }
    if (strcmp(s, "duplicate") == 0 || strcmp(s, "d") == 0)
    {
        push(val[sp - 1]);
    }
    else if (strcmp(s, "print") == 0 || strcmp(s, "p") == 0)
    {
        printf("%g\n", val[sp - 1]);
        printf("%g\n", val[sp - 2]);
    }
    else if (strcmp(s, "swap") == 0 || strcmp(s, "sw") == 0)
    {
        double temp;
        if (sp > 1)
        {
            temp = val[sp - 1];
            val[sp - 1] = val[sp - 2];
            val[sp - 2] = temp;
        }
    }
    else if (strcmp(s, "unread") == 0 || strcmp(s, "unr") == 0)
    {
        ungets();
    }
    else
    {
        printf("Unknown command: %s\n", s);
    }
}

void handle_math_function(char s[])
{
    int index;
    for (int i = 0; s[i] != '\0'; i++)
    {
        s[i] = tolower(s[i]);
    }

    if (strcmp(s, "sin") == 0)
    {
        push(sin(pop()));
    }
    else if (strcmp(s, "pow") == 0)
    {
        double exponent = pop();
        double base = pop();
        push(pow(base, exponent));
    }
    else if (strcmp(s, "exp") == 0)
    {
        push(exp(pop()));
    }

    else
    {
        index = s[0] - 'a';
        if (init_var[index] == 1)
        {
            push(alpha_var[index]);
            return;
        }
        else
        {
            printf("Error: Variable not initialized\n");
            return;
        }
        printf("Error: incorrect command\n");
    }
    if (strlen(s) == 1)
    {
        push(s[0]);
        return;
    }
}

void handle_assignment()
{
    char variable = (char)pop();
    if (isalpha(variable))
    {
        alpha_var[variable - 'a'] = pop();
        init_var[variable - 'a'] = 1;
    }
    else
    {
        printf("Invalid variable name:%s\n", variable);
    }
}