#include <stdio.h>
#include <stdlib.h>

int main(){

int numero, qntd, dia = 1; //A variavel dia está definida para ser nosso "limite" do laço do while
//Dado que a semana tem 7 dias, vamos supor que fazemos uma venda por dia, assim a cada venda incrementamos
//a variavel dia até ser igual a 7 e a cada venda, armazenamos o valor vendido até ali 
//na variavel total
float total;
do {

printf("\nInsira a quantidade do produto: ");
scanf("%i", &qntd);

printf("\nInsira o numero do produto: ");
scanf("%i", &numero);

switch (numero)
{
case 1:
total += 3.00*qntd;
dia++;
break;
case 2:
total += 4.00*qntd;
dia++;
break;
case 3:
total += 2.80*qntd;
dia++;
break;
case 4:
total += 1.95*qntd;
dia++;
break;
case 5:
total += 5.00*qntd;
dia++;
break;
default:
dia++;
break;
}
    

}while (dia<= 7);

printf("\nTotal vendido: %.2f", total);

}