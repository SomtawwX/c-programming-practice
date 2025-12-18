#define MAXOP 100
#define MAXVAL 100
#define BUFFER_SIZE 100
#define NUMBER '0'
#define COMMAND 'C'
#define MATH_FUNC 'F'

int getop(char s[]);
void push(double);
char getch(void);
void ungetch(char);
void ungets();
double pop(void);
double my_atof(char s[]);
void handle_command(char s[]);
void handle_math_function(char s[]);
void handle_assignment();
