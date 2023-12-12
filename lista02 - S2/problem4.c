#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, count;

    for(i = 1; i < 100; i++){
        count = 1;
        for(j = 1; j <= i / 2; j++){
            if(i % j == 0){
                count = 0;
            }

        }

    if(count == 1){
        printf("\t%i", i);
    }
        
    }
}