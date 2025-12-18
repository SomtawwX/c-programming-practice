#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXLINE 100
#define MAXOP 100

#define NUMBER '0'
#define COMMAND 'C'
#define MATH_FUNC 'F'

int getop(char[]);
void push(double);
void ungets();
double pop(void);
double my_atof(char s[]);
void handle_command(char s[]);
void handle_math_function(char s[]);
void handle_assignment();
int getline(int s[], int maxline);

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
            printf("Error Unknown operation: %s\n", s);
            break;
        }
    }
    return 0;
}
//---------------------Check for operators and assign numbers to array---------------------------

int getop(char s[])
{
    static int line[MAXLINE] = {0};
    static int i = 0;
    static int line_length = 0;

    int j = 0;
    if (i >= line_length)
    {
       line_length = getline(line, MAXLINE);
        i = 0;
    }
    while (line[i] != '\0' && line[i] != EOF)
    {
        for (; line[i] == ' ' || line[i] == '\t'; i++)
            ;

        if (line[i] == '$')
        {
            i++;
            while (i < MAXOP - 1 && isalpha(s[j++] = line[i++]))
                ;
            s[--j] = '\0';

            return COMMAND;
        }

        if (!isdigit(line[i]) && line[i] != '.')
        {
            if (isalpha(line[i]))
            {
                while (isalpha(s[j++] = line[i++]))
                    ;

                s[--j] = '\0';
                i = 0;
                return MATH_FUNC;
            }
            else
            {
                return line[i++];
            }
        }
        if (isdigit(line[i]))
        {

            while (isdigit(s[j++] = line[i++]))
                ;
        }
        if (line[i] == '.')
        {
            i++;
            while (isdigit(s[j++] = line[i++]))
                ;
        }

        s[--j] = '\0';

        return NUMBER;
    }
}

//------------------------Buffer to save values------------------------------

#define BUFFER_SIZE 100
char stringbuffer[BUFFER_SIZE];
int buffer[BUFFER_SIZE];
int bufp = 0; // Buffer pointer
int i = 0, c;

int getline(int s[], int lim)
{
    int i = 0, c;
    if (bufp > 0)
    {
        while (bufp > 0 && i < lim - 1)
        {
            s[i] = buffer[i];
            i++;
            --bufp;
        }
        s[i] = '\0';
        return i;
    }
    else
    {
        while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        {
            s[i++] = c;
        }
    }

    if (c == '\n')
    {
        s[i++] = c;
        if (s[0] != '$')
        {
            for (int k = 0, j = i - 1; j >= 0; k++, j--)
            {
                stringbuffer[k] = s[k];
            }
        }
    }
    if (c == EOF)
    {
        s[i++] = c;
    }
    s[i] = '\0';

    return i;
}

void ungets()
{
    int i = 0;
    bufp = 0;

    for (i; stringbuffer[i] != '\0'; i++)
    {
        if (bufp <= BUFFER_SIZE && c != EOF)
            buffer[bufp++] = stringbuffer[i];
        else
            printf("Error: Ungetch Buffer is full\n");
    }
    stringbuffer[i] = '\0';
}

//-------------------------Stack control and Commands---------------------------------

#define MAXVAL 100

double val[MAXVAL];         // Stack for pushing and poping the value
int sp = 0;                 // Current postion of the stack pointer
double alpha_var[26] = {0}; // Maps alphabetic letters to a value
char init_var[26] = {0};

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
