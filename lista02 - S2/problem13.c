#include <stdio.h>
#include <stdlib.h>
//Para esta questão utilizamos a formula da congruencia de Zeller

// ds = (d + ((mes + 1)*13/5) + a%100 + (a%100/4) + (a/400) + 5 * (a/100)) % 7 
int main(){
int ds,d,mes,a;

printf("\nInsira o dia para a data: ");
scanf("%i", &d);

printf("\nInsira o mes para a data: ");
scanf("%i", &mes);

printf("\nInsira o ano para a data: ");
scanf("%i", &a);

ds = (d + ((mes + 1)*13/5) + a%100 + (a%100/4) + (a/400) + 5 * (a/100)) % 7;

switch (ds)
{
case 0:
printf("\nSabado");    
break;
case 1:
printf("\nDomingo");    
break;
case 2:
printf("\nSegunda");
break;
case 3:
printf("\nTerça");    
break;
case 4:
printf("\nQuarta");    
break;
case 5:
printf("\nQuinta");
break;
case 6:
printf("\nSexta");    
break;
default:
    break;
}

}