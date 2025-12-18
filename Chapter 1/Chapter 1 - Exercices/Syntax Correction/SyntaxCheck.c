#include <stdio.h>
#include <stdbool.h>
#define YES 1
#define NO 0

/*
    Programa para verificar errores sintácticos básicos en un código C.
    Detecta paréntesis, corchetes y llaves desbalanceadas,
    así como comillas dobles y simples sin cerrar y comentarios sin finalizar.
*/

int main()
{
    // Variables de estado para verificar si estamos dentro de una cadena, un carácter o un comentario
    bool inString = NO;        // Dentro de una cadena "..."
    bool inQuote = NO;         // Dentro de un carácter '...'
    bool inComment = NO;       // Dentro de un comentario de línea //
    bool inBlockComment = NO;  // Dentro de un comentario de bloque /* ... */
    
    int prev = 0;              // Guarda el carácter anterior para detectar combinaciones como // y /*
    int c = 0;                 // Carácter actual
    int paren = 0;             // Contador de paréntesis "()"
    int bracket = 0;           // Contador de corchetes "[]"
    int brace = 0;             // Contador de llaves "{}"

    while ((c = getchar()) != EOF)
    {
        // Detección de comentarios
        if (c == '/' && prev == '/'){
            inComment = YES;  // Detecta inicio de comentario de línea "//"
        }else if (c == '\n' && inComment == YES){
            inComment = NO;   // Fin de comentario de línea
        }
        
        if (c == '*' && prev == '/'){
            inBlockComment = YES;  // Detecta inicio de comentario de bloque "/*"
        }else if (c == '/' && prev == '*' && inBlockComment == YES){
            inBlockComment = NO;   // Fin de comentario de bloque "*/"
        }
        
        // Verificación de paréntesis, llaves y corchetes (solo si no estamos en un comentario)
        if (c == '(' && inComment == NO && inBlockComment == NO)
        {
            paren++;
        }
        else if (c == ')' && inComment == NO && inBlockComment == NO)
        {
            paren--;
        }
        
        if (c == '{' && inComment == NO && inBlockComment == NO )
        {
            brace++;
        }
        else if (c == '}' && inComment == NO && inBlockComment == NO)
        {
            brace--;
        }
        
        if (c == '[' && inComment == NO && inBlockComment == NO )
        {
           bracket++;
        }
        else if (c == ']' && inComment == NO && inBlockComment == NO)
        {
            bracket--;
        }
        
        // Manejo de comillas dobles " y simples '
        if (c == '"' && inComment == NO && inBlockComment == NO && prev != '\\')
        {
            inString = !inString; // Alterna entre estar dentro y fuera de una cadena
        }
        if(c == '\'' && inComment == NO && inBlockComment == NO  && prev != '\\'){
            inQuote = !inQuote;   // Alterna entre estar dentro y fuera de un carácter
        }
        
        prev = c;  // Guarda el carácter actual como "prev" para la siguiente iteración
    }

    // Verificación final de errores sintácticos
    if(paren < 0)
    {
        printf("Error: Falta un '('\n");
    }else if(paren > 0)
    {
        printf("Error: Falta un ')'\n");
    }
    if(bracket < 0)
    {
        printf("Error: Falta una '{'\n");
    }else if(bracket > 0)
    {
        printf("Error: Falta una '}'\n");
    }
    if(brace < 0)
    {
        printf("Error: Falta un '['\n");
    }else if(brace > 0)
    {
        printf("Error: Falta un ']'\n");
    }
    if(inString == YES)
    {
        printf("Error: Falta cerrar comillas dobles\n");
    }
    if(inQuote == YES)
    {
        printf("Error: Falta un '\''\n");
    }
    if(inBlockComment == YES)
    {
        printf("Error: Falta cerrar el comentario de bloque '*/'\n");
    }


    return 0;
}


