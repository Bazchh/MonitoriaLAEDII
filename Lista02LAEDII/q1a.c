#include <stdio.h>

int main (){
    char c;
    int i = 0;
    int count = 0;
    do{
    
    for(count = 0; count < 10; count++, i++){
    c = i;
    printf(" %c", c);

    }
    printf("\n");
    
    }while(i < 127);
    

}