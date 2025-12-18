#include <stdio.h>
/*
En C existen elementos conocidos como macros escritos de la siguiente forma
#define UPPER 300
*/

int main()
{

    /*

    *   El programa usa la formula °C = (5/9)(°F-32) para imprimir la tablas de temperatura de
        Farenheit y celsius.
        
    *   Otra forma de hacer este programa es usando un bucle for. 

    */

    float fahr, celsius;
    float lower = 0,          /*Limite inferior de la escala de temperatura*/
        upper = 300,        /*Limite superior de la escala de temperatura*/
        steps = 20;         /*Pasos*/

        fahr = upper;

        printf("-------- Tabla de Convercion de Farenheit | Celcius -------- \n \n");
        printf("Celcisus \t Fahr \n");
        while (fahr >= lower){
            celsius = (5.0 / 9.0)  * (fahr-32.0);
            printf("%3.0f \t \t %6.1f\n", fahr, celsius);
            fahr = fahr - steps;
        }

    return 0;
}