#define MAXOP 100
#define MAXVAL 100
#define BUFFER_SIZE 100
#define NUMBER '0'
#define COMMAND 'C'
#define MATH_FUNC 'F'

int getop(char s[]);
double my_atof(char s[]);
void push(double);
double pop(void);
char getch(void);
void ungetch(char);
void ungets();
void handle_command(char s[]);
void handle_math_function(char s[]);
void handle_assignment();