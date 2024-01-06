#include <stdio.h>
#include <stdlib.h>

float hipotenusa(lado1, lado2){
    return (lado1 * lado1 + lado2 * lado2);
}
//Nessa questão basta usar a formula para calculado da hipotenusa
//coloquei de modo manual os parametros, mas vocês podem criar duas variaveis e usar um scanf
//para tornar mais dinamico os valores passados
int main(){
float hipo;

hipo = hipotenusa(2, 5);
}