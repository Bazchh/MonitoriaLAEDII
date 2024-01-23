#include <stdio.h>
#include <stdlib.h>

int isPrime(int n, int d){
    if(d >= n/2){
        return 1;
    } else if(n % d == 0){
        return 0;    
    } else {
        return isPrime(n, d+1);
    }
}

int main(){
int n,d,r;
r = isPrime(5,2);
if(r == 1){
    printf("\nO numero eh primo");
} else {
    printf("\nO numero não eh primo");
}

}

