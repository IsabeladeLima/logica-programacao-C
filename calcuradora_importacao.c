// Crie um programa em C para calcular o custo total de um produto com base no valor do produto, país de origem, meio de transporte, tipo de carga e custos adicionais (impostos, frete e seguro).
//O programa deve:
// 1.Solicitar o valor do produto, país de origem (1, 2 ou 3), meio de transporte (T para terrestre, A para aéreo, F para fluvial) e tipo de carga (S para carga especial, N para carga normal).
//2. Calcular:
// Imposto: 5% para produtos abaixo de R$ 100,00 e 10% para os demais.
//Frete: Dependente do tipo de carga e do país.
//Seguro: Metade do valor do produto se o transporte for aéreo e o país for 2, caso contrário, R$ 30.
//Exibir um resumo com o valor do produto, imposto, frete, seguro e o valor total.
//Permitir o cadastro de múltiplos produtos até que o usuário escolha encerrar.
//O programa deve validar todas as entradas e exibir os resultados de cada produto antes de permitir a inserção de outro produto.

#include <stdio.h>
#include <ctype.h>  // Para usar toupper()

int main() {
    char carga, transporte, op;
    float valor, imposto, frete, totalprod, seguro;
    int pais, i = 0;

    do {
        i++;
        printf("Informe o valor do Produto: ");
        scanf("%f", &valor);

        printf("Informe o pais de origem (1, 2 ou 3): ");
        scanf("%d", &pais);

        while (pais < 1 || pais > 3) {
            printf("\nPais invalido, tente novamente: ");
            scanf("%d", &pais);
        }

        printf("Informe o meio de transporte (T= terrestre, A= aereo ou F= fluviaç): ");
        scanf(" %c", &transporte);
        transporte = toupper(transporte);

        while (transporte != 'T' && transporte != 'A' && transporte != 'F') {
            printf("\nMeio de transporte invalido. Tente novamente: ");
            scanf(" %c", &transporte);
            transporte = toupper(transporte);
        }

        printf("Informe sobre a carga (S= especial ou N= normal): ");
        scanf(" %c", &carga);
        carga = toupper(carga);

        while (carga != 'S' && carga != 'N') {
            printf("\nCarga invalida, tente novamente: ");
            scanf(" %c", &carga);
            carga = toupper(carga);
        }

     // Calculando imposto
    if (valor < 100) {
        imposto = valor * 0.05;
    } else {
        imposto = valor * 0.1;
    }

    // Calculando custo de transporte
    if (carga == 'S') {
        if (pais == 1) {
            frete = 50;
        } else if (pais == 2) {
            frete = 35;
        } else {
            frete = 24;
        }
    } else if (carga == 'N') {
        if (pais == 1) {
            frete = 12;
        } else if (pais == 2) {
            frete = 35;
        } else {
            frete = 60;
        }
    }

    //calculo do seguro
    if (pais == 2 && transporte == 'A'){
        seguro = valor / 2;
    }else{
    seguro = 30;
    }

    //total produto

    totalprod= valor + seguro + frete + imposto;

    //exibindo resultados
    printf("\n\n=====Resumo do produto=====");
    printf("\nValor do produto: %.2f", valor);
    printf("\nImposto: %.2f", imposto);
    printf("\nFrete: %.2f", frete);
    printf("\nSeguro: %.2f", seguro);
    printf("\nValor total: %.2f", totalprod);


       printf("\n\nDeseja continuar a entrada de dados? [S/N]: ");
        scanf(" %c", &op);
        op = toupper(op);

    } while (op != 'N');

    printf("\nFinalizando o programa...");

    return 0;
}
