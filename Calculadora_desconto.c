// Crie um programa em C que calcule o valor a ser pago por uma compra.
//Se o valor for inferior a R$ 300,00, não aplica desconto.
//Para valores acima de R$ 300,00, aplica um desconto de 10% sobre o valor que exceder R$ 300,00.
//O programa deve exibir o valor da compra, o valor do desconto e o valor total a ser pago.

#include <stdio.h>

int main(){

double valorcompra, valordesconto, totalpgto;

printf("Digite o valor da compra: ");
scanf("%lf", &valorcompra);


if(valorcompra < 300){

    printf("valor da compra: %lf", valorcompra);


}else{

valordesconto= (valorcompra-300) * 0.1;
totalpgto= valorcompra- ((valorcompra - 300) * 0.1);

printf("valor compra= %lf\nvalor do desconto= %lf\nvalor a pagar= %lf", valorcompra, valordesconto, totalpgto);

}




}
