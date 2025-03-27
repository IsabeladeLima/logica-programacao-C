// em um campeonato de futebol, existem 5 times e cada time possui 5 jogadores;
//faca um programa que receba a idade, o peso e a altura de cada um dos jogadores;
//calcule e mostre: quantidade de jogadores com idade menores de 18 anos;
//a media da idade dos jogadores de cada time;
//a media da altura de todos os jogadores do campeonato;
//a porcentagem de jogadores acima de 80 kilos entre todos os jogadores;

#include <stdio.h>

#define TIMES 2
#define JOGADORES 2

int main(){

int idade;
float peso, altura;
int menor_dezoito=0;
int soma_idade=0;
float soma_altura =0;
int mais80kg = 0;
float media_idade=0;
float media_altura=0;


int idades [TIMES][JOGADORES];
float pesos [TIMES][JOGADORES];
float alturas[TIMES][JOGADORES];

for (int i = 0; i < TIMES; i++){
    printf("===Time %d: ===\n", i + 1);
    for (int j = 0; j < JOGADORES; j++){
        printf("=jogador %d: =\n", j + 1);
        printf("Digite a idade do jogador %d: ", j + 1);
        scanf("%d", &idades[i][j]);
        printf("\nDigite o peso do jogador %d: ", j + 1);
        scanf("%f", &pesos[i][j]);
        printf("\nDigite a altura do jogador %d: ", j + 1);
        scanf("%f", &alturas[i][j]);

        printf("\n\n=====Resumo Jogador %d: =====\n\n", j + 1);
        printf("Idade: %d", idades[i][j]);
        printf("\nPeso: %.2f", pesos[i][j]);
        printf("\nAltura: %.2f\n\n", alturas[i][j]);

        if (idades[i][j] < 18){
            menor_dezoito++;
        }

        soma_idade +=idades[i][j];
        soma_altura += alturas[i][j];

        if (pesos[i][j]> 80){
            mais80kg ++;
        }
    }
    printf("\n");
}
printf("\n\n ======Dados dos Jogadores: ======\n\n");

for (int i = 0; i < TIMES; i++){
    printf("========Time %d========\n", i + 1);
    for (int j = 0; j < JOGADORES; j++){
        printf("Jogador %d: - idade: %d - peso: %.2f kg - altura: %.2f m\n\n", j + 1, idades[i][j], pesos[i][j], alturas[i][j]);


    }

}

printf("quantidade de jogadores com menos de 18 anos: %d", menor_dezoito);
printf("\nQuantidade de jogadores com peso maior de 80kg: %d", mais80kg);

media_idade = (float) soma_idade / (TIMES * JOGADORES);
media_altura = (float) soma_altura / (TIMES * JOGADORES);

printf("\nA media de idade dos jogadores : %.2f anos", media_idade);
printf("\nA media de altura dos jogadores: %.2f metros", media_altura);

float porcentagem_mais80kg = (float) mais80kg / (TIMES * JOGADORES) * 100;
printf("\nPorcentagem de jogadores acima de 80kg: %.2f%%\n", porcentagem_mais80kg);





}
