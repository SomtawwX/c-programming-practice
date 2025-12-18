/*Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at the price of
more tests outside.) Write a version with only one test inside the loop and measure the difference in runtime.*/

#include <stdio.h>

int binSearch(int x, int array[], int n);

int main(){
    int array[100];
    binSearch(22, array, 100);
    return 1;
}

int binSearch(int x, int array[], int n){
    int low, high, middle;

    high = n -1;
    low = 0;

    while (low <= high){
        middle = (low + high) / 2;

        if (x < array[middle]) {
            high = middle - 1;
        } else {
            low = middle + 1;
        }
        
    }
    if (array[middle] == x){
        return middle;
    }else{
        return -1;
    }
}