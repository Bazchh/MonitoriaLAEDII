#include <stdio.h>
#include <stdlib.h>
//Nessa questão, ao se tratar de um somatorio sabemos que o valor inicial é dado por i e o ultimo por n
//então podemos ter uma função que tem como argumentos um numero inicial e um final
int somatorio(int i, int n){
    //toda recursão precisa ter um caso base, um caso de parada da recursão
    //este if é nossa condição de parada, significando que chegamos ao ultimo indice do somatorio
    if(i == n){
        return n;
    }
    //em caso do if ser falso, iremos chamar novamente nossa função passando novos argumentos, no caso so somatorio
    //devemos passar o proximo termo do somatorio, neste caso, i+1 e na volta de toda a recursão devemos
    //somar o i a qual chamou a nova recursão, por isso "i+somatorio(i+1,n)"
    return i+somatorio(i+1,n);
}

int main (){

int soma = somatorio(1,10);
printf("%i", soma);
}