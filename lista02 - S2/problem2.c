#include <stdio.h>
#include <stdlib.h>


int main(){
    
    int i;
    printf("CELSIUS \tFarenheit\n");
    for(i = 30; i <= 50; i++){
        printf(" %i   \t  = \t   %i\n",i, (i+32));
    }
    
}