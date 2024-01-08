#include <stdio.h>
#include <stdlib.h>
//Nessa questão, passamos dois numeros e fazemos o produto de um pelo outro, que é basicamente somar 
//o primeiro numero um numero de vezes igual ao segundo numero
int produtoRecursivo(int x1, int x2){
    if (x2 == 0){
        return 0;
    }

    if(x2 == 1){
        return x1;
    }
   
    return x1 + produtoRecursivo(x1, x2 - 1);
}


int main(){
    int produto, x1 = 5, x2 = 5;
    produto = produtoRecursivo(x1,x2);
    
    printf("\nproduto: %i", produto);
    
}