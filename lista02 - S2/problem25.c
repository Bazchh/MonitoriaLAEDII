#include <stdio.h>
#include <stdlib.h>
//Basicamente deve-se se seguir a formula dada na questão
f(int m, int n){
    if (n == 1){
        return m + 1;
    } else if(m == 1){
        return n + 1;
    } else if (m > 1 && n > 1){
        return f(m, n - 1) + f(m-1, n);
    }
}


int main (){
f(5,2);
}