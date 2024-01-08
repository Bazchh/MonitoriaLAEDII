#include <stdio.h>
#include <stdlib.h>

int inverterNumeroRecursivo(int n, int invertido){
    if(n == 0){
        return invertido;
    }
    
    int ultimoN = n % 10;
    invertido = invertido * 10 + ultimoN;
    return inverterNumeroRecursivo(n / 10, invertido);
}

//essa questão segue a mesma logica da questão 20, a diferença é que armazenamos um a um os numeros em uma variavel que inverte o numero    

int main() {
   int n = 4321, invertido;
  invertido =  inverterNumeroRecursivo(n , 0);
  printf("\nInvertido recursivo: %i", invertido);
  invertido = inverterNumero(n);
  printf("\nInvertido iterativo: %i", invertido);
}