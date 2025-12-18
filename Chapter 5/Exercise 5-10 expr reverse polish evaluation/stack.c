#include "acts.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

double stack[BUFFER_SIZE] = {0};
int sPtr = 0;

void push(double n)
{
    if (sPtr < BUFFER_SIZE - 1)
    {
        stack[sPtr++] = n;
    }
    else
    {
        printf("Error: Full stack, please clear memory");
    }
}

double pop()
{

    if (sPtr > 0)
    {
        return stack[--sPtr];
    }
    else
    {
        printf("Error: Stack is empty");
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
        push(stack[sPtr - 1]);
    }
    else if (strcmp(s, "print") == 0 || strcmp(s, "p") == 0)
    {
        printf("%g\n", stack[sPtr - 1]);
        printf("%g\n", stack[sPtr - 2]);
    }
    else if (strcmp(s, "swap") == 0 || strcmp(s, "sw") == 0)
    {
        double temp;
        if (sPtr > 1)
        {
            temp = stack[sPtr - 1];
            stack[sPtr - 1] = stack[sPtr - 2];
            stack[sPtr - 2] = temp;
        }
    }
    else
    {
        printf("Unknown command: %s\n", s);
    }
}

void handle_math_function(char s[])
{
    
}

void handle_assignment()
{
}