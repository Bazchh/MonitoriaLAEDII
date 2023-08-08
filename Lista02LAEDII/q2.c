#include <stdio.h>
#include <stdlib.h>

int diasDeAulas(int dia, int mes, int ano){
int ultDia = 29, ultMes = 10, ultAno = 2023;
ano  *= 365;
mes *= 30;
dia += mes+ano;
ultAno  *= 365;
ultMes *= 30;
ultDia += ultMes+ultAno;

int semanas = (ultDia - dia)/7;
int qntdAulas = semanas*2;

return qntdAulas;

}

int main(){
int dia, mes, ano;

printf("\nInsira o dia: ");
scanf("%i", &dia);
printf("\nInsira o mes: ");
scanf("%i", &mes);
printf("\nInsira o ano: ");
scanf("%i", &ano);
int R = diasDeAulas(dia, mes, ano);
printf("\nQuantidade de aulas entre a data atual e fim do periodo: %i", R);
}