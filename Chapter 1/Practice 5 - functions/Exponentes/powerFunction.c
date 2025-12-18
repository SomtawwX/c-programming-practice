#include <stdio.h>
int power(int a, int b);

int main(){
    
    

    for(int i = 0; i < 10; i++){
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    }
    
    return 0;
}

int power(int a, int b){
    int p = 1;
    for(int i = 0; i < b; i++){
        p = p * a;
    }
    return p;
}