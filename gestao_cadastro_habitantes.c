//Crie um programa em C para cadastrar dados de habitantes, incluindo gênero, idade e salário. O programa deve:
//1. Solicitar a quantidade de habitantes a serem cadastrados.
//2. Para cada habitante, registrar o gênero (M/F), idade e salário.
//3. Calcular:
// a) A média salarial dos habitantes.
// b) A maior e menor idade entre os cadastrados.
// c) A quantidade de mulheres com salário de até R$ 1518.
// d) O habitante com o menor salário, informando seu gênero e valor.
//O programa deve exibir os resultados ao final, incluindo as estatísticas calculadas.

#include <stdio.h>
#include <ctype.h> //usar toupper
int main(){

int n, idade, maior_idade=0, menor_idade=100, mulheres_baixo_salario=0;
float salario, soma_salario= 0, media_salario=0, menor_salario=100000;
char genero, genero_menor_salario;

printf("Quantos habitantes deseja cadastrar? ");
scanf("%d", &n);


for (int i = 0; i<n; i++){
        printf("\nHabitante %d", i + 1);


printf("\nDigite seu genero [M/F]: ");
scanf(" %c", &genero);
genero=toupper(genero);

while (genero!='M' && genero!= 'F'){
    printf("Genero invalido, tente novamente [M/F].");
    scanf(" %c", &genero);
    genero= toupper(genero);

}

printf("\nDigite sua idade: ");
scanf("%d", &idade);

if (idade > maior_idade){
    maior_idade=idade; //encontra maior idade
    }

if (idade< menor_idade){
    menor_idade=idade; //encontra menor idade
    }

printf("\nDigite seu salario: ");
scanf("%f", &salario);
soma_salario+= salario; //acumulador salario

if(salario <menor_salario){
    menor_salario=salario;
    genero_menor_salario= genero;
    }

//contagem mulheres com salario de ate 1518

if(genero == 'F' && salario <= 1518){
    mulheres_baixo_salario++;
    }

}

media_salario= soma_salario / n;

//exibindo os resultados

printf("\n========RESULTADOS===========");
printf("\nMedia salarial: R$: %.2f", media_salario);
printf("\nMaior idade cadastrada: %d", maior_idade);
printf("\nMenor idade cadastrada: %d", menor_idade);
printf("\nQuantidade de mulheres que possuem ate R$ 1518 de salario: %d", mulheres_baixo_salario);
printf("\nPessoa com o menor salario: \nGenero: %c - Salario : %.2f", genero_menor_salario, menor_salario);


    }
