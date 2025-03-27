//Crie um programa em C para cadastrar informações de candidatos a uma vaga de emprego, considerando idade, gênero e experiência. O programa deve:
//1. Exibir o número total de candidatos do gênero feminino e masculino.
//2. Calcular a idade média dos homens com experiência.
//3. Calcular a porcentagem de homens com mais de 45 anos.
//4. Exibir o número de mulheres com menos de 35 anos e com experiência.
//5. Exibir a menor idade entre as mulheres com experiência.


#include <stdio.h>

int main(){

int n, contarF = 0, contarM = 0;
int homenscomexp = 0, somaidadehomenscomexp = 0;
int homensmais45 = 0;
int mulheresmenos35comexp = 0;
int menoridademulherexp = -1;

printf("Digite a quantidade de candidatos: ");
scanf("%d", &n);

int idades[n];
char generos[n];
char experiencias[n];


for (int i = 0; i < n; i++){
    printf("\n\n======Candidato %d:======\n", i + 1);

    printf("idade: ");
    scanf("%d", &idades[i]);

    do {
        printf("Genero (M ou F): ");
        scanf(" %c", &generos[i]);

        if (generos[i] != 'M' && generos[i] != 'F' && generos[i] != 'm' && generos[i] != 'f'){
            printf("entrada invalida, digite M ou F para informar o genero.\n");
        }

    }while (generos[i] != 'M' && generos[i] != 'F' && generos[i] != 'm' && generos[i] != 'f');

      if (generos[i] == 'm') generos[i] = 'M';
        if (generos[i] == 'f') generos[i] = 'F';

    if (generos[i] == 'M'){
        contarM ++;

    }else{
    contarF ++;
    }


    do {
        printf("Experiencia (S ou N): ");
        scanf(" %c", &experiencias[i]);

        if (experiencias[i] != 'S' && experiencias[i] != 'N' && experiencias[i] != 's' && experiencias[i] != 'n'){
            printf("entrada invalida, digite S ou N para informar a experiencia.\n");
        }

    }while (experiencias[i] != 'S' && experiencias[i] != 'N' && experiencias[i] != 's' && experiencias[i] != 'n');

    if (experiencias[i] == 's') experiencias[i] = 'S';
    if (experiencias[i] == 'n') experiencias[i] = 'N';

    if (generos[i] == 'M'){
            if (experiencias[i] == 'S'){
        homenscomexp++;
        somaidadehomenscomexp += idades[i];
        }

    if (idades[i] > 45){
        homensmais45 ++;

    }
}

if (generos[i]== 'F'){
    if (idades[i] < 35 && experiencias[i]== 'S'){
        mulheresmenos35comexp ++;
    }
    if (experiencias[i] == 'S'){
        if (menoridademulherexp == -1 || idades[i] < menoridademulherexp){
            menoridademulherexp = idades[i];
        }
    }
}
}

for (int i = 0; i < n; i++){
printf("\n\nDados dos candidatos cadastrados: \n");
printf("======Candidato %d: ======\n", i + 1);
printf("Idade: %d\n", idades[i]);
printf("Genero: %c\n", generos[i]);
printf("Experiencia: %c\n", experiencias[i]);

}
printf("\n Numero de candidatos masculinos: %d", contarM);
printf("\n Numero de candidatos femininos: %d\n", contarF);

if (homenscomexp > 0){
    float idademediadoshomenscomexp = (float)somaidadehomenscomexp / homenscomexp;
    printf("A idade media dos homens com experiencia eh de %.2f\n", idademediadoshomenscomexp);

}else{
printf("Nao ha homens com experiencia cadastrados.\n");

}

printf ("\nnumero de mulheres com menos de 35 anos e com experiencia: %d", mulheresmenos35comexp);

if(menoridademulherexp != -1){
    printf("\nmenor idade entre mulheres com experiencia: %d\n", menoridademulherexp);

}else{
printf("\nnao ha mulheres com experiencia cadastradas.\n");
}

}
