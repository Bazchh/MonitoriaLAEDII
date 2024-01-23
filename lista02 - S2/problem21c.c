#include <stdio.h>
#include <stdlib.h>

int fib(int n){

if(n <= 1){
    return 1;
} else {
    return fib(n-1) + fib(n - 2);   
}

}

int main(){
int i;
for(i = 1; i < 10; i++){
printf(" %i ",fib(i));
}


}

