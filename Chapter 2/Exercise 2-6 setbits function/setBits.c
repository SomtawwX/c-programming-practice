/*Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position
p set to the rightmost n bits of y, leaving the other bits unchanged*/

#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main(){        //128 64 32 16 8 4 2 1
    int numX = 50; //0 0 1 1 0 0 1 0
    int numY = 100;//0 1 1 0 0 1 0 0 ---> 1 0 0 0 0 0 0 0
                   //1 0 0 1 0 0 1 0
    printf("The function returned the next result: %d", setbits(numX, 7, 3, numY));
   
    return 0;
}

int setbits (int x, int p, int n, int y){
    y = (y & ~(~0 << n)) << (p-n+1);
    x = (x & ~(~0 << (p-n+1))) | y;
   return x;
    
}