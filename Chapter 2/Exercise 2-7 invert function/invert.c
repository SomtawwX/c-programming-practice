/*Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at position p
inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged. */
#include <stdio.h>
int invert(int x, int p, int n);

int main(){           //128 64 32 16 8 4 2 1
    int value = 110;  //0 1 1 0 1 1 1 0 --->  //1 0 0 1 0 0 0 1
                                              //0 0 1 1 1 0 0 0
    int position = 5;
    int nbits = 3;
    printf("The function returned the result of %d", invert(value, position, nbits));
    return 0;
}

int invert(int x, int p, int n){
    int x2; 
    x2 = ((1 << n) -1) << (p - n + 1); // 0 0 1 1 1 0 0 0
    return x = x ^ x2;                 // 0 1 1 0 1 1 1 0 ---> 0 1 0 1 0 1 1 0
                                                             
}

