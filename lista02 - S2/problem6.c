#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 5, i, j, fat;

    for(i = 1; i <= n; i++){
        fat = 1;
        for(j = i; j > 1; j--){
            fat *= j;
        }
        printf("\n%i", fat);
         }
}