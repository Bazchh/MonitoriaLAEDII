#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    for(i = 1; i <= 100; i++){
        if(i % 7 == 0){
            printf("%i", i);
        }
    }
}