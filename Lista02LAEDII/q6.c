#include <stdio.h>

int inverterNumeroRecursivo(int n, int invertido){
    if(n == 0){
        return invertido;
    }
    
    int ultimoN = n % 10;
    invertido = invertido * 10 + ultimoN;
    return inverterNumeroRecursivo(n / 10, invertido);
}

int inverterNumero(int n){
    int invertido = 0;
    int ultimoN;
    while(n > 0){
        ultimoN = n % 10;
        invertido = invertido * 10 + ultimoN;
        n /= 10;
    }

    return invertido;
}


int main() {
   int n = 4321, invertido;
  invertido =  inverterNumeroRecursivo(n , 0);
  printf("\nInvertido recursivo: %i", invertido);
  invertido = inverterNumero(n);
  printf("\nInvertido iterativo: %i", invertido);
}
