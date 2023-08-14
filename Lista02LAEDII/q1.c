#include <stdio.h>

int main (){
    char c; //variavel para armazenar
    int i = 0;
    int count = 0;
    do{
    c = i;   
    printf(" %c", c);
    count++;
    if(count == 9){
        printf("\n");
        count = 0;
    }
    i++;
    }while(i <= 127);

}