//em uma fabrica trabalham homens e mulheres em tres classes:
//os que produzem ate 30 peças(classe 1); os que produzem de 31 a 35 peças(classe 2) e os que produzem acim de 35 peças;
//classe 1 : recebe o salario minimo de 1420
//classe 2: recebe o salario minimo + 3% salario minimo por peça acima de 30 peças produzidas
//classe 3: recebe o salario minimo + 5% do salario minimo por peça acima de 35 peças produzidas
// faça o programa que receba o numero do prontuario, o numero de peças e o genero do operario.
//mostre: numero do operario e seu salario;
//total da folha de pgto da fabrica; total de pecas fabricadas; numero de peças fabricadas pelos homens e pelas mulheres;

#include <stdio.h>
#include <ctype.h>

#define SALARIO_MINIMO 1420.0

int main(){

int op, prontuario, n_pecas;
float total_folhapgto= 0;
float salario;
int total_pecas= 0;
int pecas_homens= 0;
int pecas_mulheres = 0;
char genero;


do{

printf("Digite o numero do seu prontuario: ");
scanf("%d", &prontuario);

do{
    printf("Digite seu genero (F para feminino ou M para masculino: ");
    scanf(" %c", &genero);
    genero= toupper(genero);

if(genero !='M' && genero != 'F'){
 printf("entrada invalida. digite novamente (F para feminino e M para masculino): ");
}

}while (genero !='M' && genero != 'F');

printf("\nDigite o numero de peças produzidas no mes: ");
scanf("%d", &n_pecas);

if(n_pecas < 0){
    printf("Numero de pecas nao pode ser negativo. \n");
    continue;

}

if(n_pecas <= 30){
salario= SALARIO_MINIMO; // classe 1

}else if (n_pecas >= 31 && n_pecas <= 35){

salario = SALARIO_MINIMO + (SALARIO_MINIMO * 0.03 *(n_pecas - 30)); // classe 2

} else{
salario = SALARIO_MINIMO + (SALARIO_MINIMO * 0.05 *(n_pecas - 35)); // classe 3
}

total_folhapgto +=salario;
total_pecas += n_pecas;

if  (genero == 'M'){
    pecas_homens += n_pecas;

}else{
pecas_mulheres+= n_pecas;
}

printf("\n\n==Detalhes do operario: ==");
printf("\nProntuario: %d", prontuario);
printf("\nGenero: %c", genero);
printf("\nNumero de pecas produzidas: %d", n_pecas);
printf("\nSalario: %.2f\n", salario);

printf("Deseja incluir outro funcionario?(digite 0 para finalizar ou 1 para continuar) ");
scanf("%d", &op);

}while (op !=0);

printf("\n\n======Resumo da Fabrica======\n\n");
printf("Total da folha de pagamento: R$ %.2f\n", total_folhapgto);
printf("Total de pecas produzidas: %d\n", total_pecas);
printf("Total de pecas produzidas pelos homens: %d\n", pecas_homens);
printf("Total de pecas produzidas pelas mulheres: %d\n", pecas_mulheres);

printf("Encerrando o programa...");

return 0;

}
