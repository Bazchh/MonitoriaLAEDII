#include <stdio.h>
#include <stdlib.h>

int fat(int n){

 if(n == 1){
    return n;
 }   

 return n*fat(n-1);

}

int main(){
printf("%i",fat(5));
}

