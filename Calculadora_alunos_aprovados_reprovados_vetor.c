#include <stdio.h>
#include <string.h>

int main() {
    // Dado um conjunto de nome de aluno e outro conjunto de média dos alunos:
    // Desenvolva um programa que armazene em um vetor resultante os nomes dos alunos que não conseguiram atingir a média 6.0.
    // No final, exibir os nomes destes alunos, incluindo suas medias.

    int n;
    printf("Digite o numero de alunos: ");
    scanf("%d", &n);
    getchar();  // Para consumir o caractere de nova linha após a leitura do inteiro

    char nome[n][50];
    float media[n];
    char reprovados[n][50];
    char aprovados [n][50];
    float media_aprovados[n], media_reprovados[n];
    int contar_reprovados = 0, contar_aprovados = 0;


    for (int i = 0; i < n; i++) {
        printf("\n\nDigite o nome do aluno %d: ", i + 1);
        fgets(nome[i], 50, stdin);
        nome[i][strcspn(nome[i], "\n")] = '\0';  // Remover o caractere de nova linha do nome

        printf("Digite a media do aluno %d: ", i + 1);
        scanf("%f", &media[i]);
        getchar();  // Consumir o caractere de nova linha após a leitura do float
    }

    // Verificando alunos reprovados
    for (int i = 0; i < n; i++) {
        if (media[i] < 6.0) {
            // Armazenando os nomes dos alunos reprovados no vetor reprovados
            strcpy(reprovados[contar_reprovados], nome[i]);
            media_reprovados[contar_reprovados] = media[i];
            contar_reprovados++;
        }else{
        // Armazenando os nomes dos alunos aprovados
            strcpy(aprovados[contar_aprovados], nome[i]);
            media_aprovados[contar_aprovados] = media[i];
            contar_aprovados++;

        }
    }

    // Exibindo o resultado

     printf("\n==========RESULTADOS==========\n");

    if (contar_reprovados > 0) {
        printf("\nA quantidade de alunos reprovados eh de: %d\n", contar_reprovados);
        for (int i = 0; i < contar_reprovados; i++) {
            printf("%s - media = %.2f\n", reprovados[i], media_reprovados[i]);
        }
    } else {
        printf("\nNenhum aluno reprovado.\n");
    }

    if (contar_aprovados > 0) {
     printf("\nA quantidade de alunos aprovados eh de: %d\n", contar_aprovados);
        for (int i = 0; i < contar_aprovados; i++) {
            printf("%s - media = %.2f\n", aprovados[i], media_aprovados[i]);
        }
    } else {
        printf("\nNenhum aluno aprovado.\n");
    }

    return 0;
}
