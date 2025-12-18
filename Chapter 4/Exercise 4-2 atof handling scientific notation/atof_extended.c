/*Exercise 4-2. Extend atof to handle scientific notation of the form 123.45e-6 where a floating-point number may be followed by e or E and an optionally signed exponent.*/
#include <stdio.h>
#include <ctype.h>

double atof(char s[]);
double Mypow(double base, int exponent);

int main()
{

    char input1[] = "123.45e-6";
    char input2[] = "1.2E3";
    char input3[] = "-4.5e+2";
    int suma = 1+2;
    printf("%s => %g\n", input1, atof(input1));  // Debería ser 0.00012345
    printf("%s => %g\n", input2, atof(input2));  // Debería ser 1200
    printf("%s => %g\n", input3, atof(input3));  // Debería ser -450

    return 0;
}

double atof(char s[])
{
    double val, power, pow_result;
    int i, sign, exp_sign, exponent;

    for (i = 0; s[i] == ' '; i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
        exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;

        for (exponent = 0; isdigit(s[i]); i++)
        {
            exponent = 10 * exponent + (s[i] - '0');
        }
        val *= Mypow(10, (exp_sign * exponent));
    }

    return sign * val / power;
}

double Mypow(double b, int exponent)
{
    double result = 1.0;
    int exp = (exponent < 0) ? -exponent : exponent;

    for (int i = 0; i < exp; i++)
    {
        result *= b;
    }

    return (exponent < 0) ? 1.0 / result : result;
}
