#include <stdio.h>
#include <stdlib.h>

int mdc (int a, int b){ 
    if (b == 0) {
        return a;
    } else {
        return mdc(b, a % b);
    }
}



int main(){
    int n1, n2;

    printf("\nInsira o primeiro numero: " );
    scanf("%i", &n1);

    printf("\nInsira o segundo numero: " );
    scanf("%i", &n2);

    printf("\nMDC entre %i e %i = %i", n1,n2, mdc(n1,n2));
}