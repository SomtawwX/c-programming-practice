#include <stdio.h>
#include <string.h>

#define swap(t, x ,y) do{t temp = x; x = y; y = x;}while (0)

void reverse(char s[]);
void reverse_wrapper (char s[], int left, int right);


int main()
{

    char s[] = "Hi, this is a test";
    reverse(s);
    printf("%s", s);

    return 0;
}

void reverse(char s[])
{
    reverse_wrapper(s, 0, strlen(s) - 1);
}
void reverse_wrapper (char s[], int left, int right){
    if (left >= right)
        return;
        
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

    reverse_wrapper(s, left + 1, right - 1);
}

