/*Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated to the
right by n positions. */

#include <stdio.h>

int rightrot(int x, int n);

int main(){

    printf("The return value is: %d", rightrot(150, 3));
    return 0;
}

int rightrot(int x, int n){
    //150 = 1 0 0 1 0 1 1 0 ---> 1 1 0 1 0 0 1 0
    //mask= 0 0 0 0 0 1 1 1
    int mask = ((1 << n) - 1) ;
    int bits = mask & x;

    x = (x >> n) | (bits << 8 - n); 
    
    return x; 

}