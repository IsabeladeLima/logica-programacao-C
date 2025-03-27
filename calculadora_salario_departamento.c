
//uma empresa possui 3 departamentos contendo N funcionarios, defina:
//o total de salario por departamento
//total geral de salarios de todos departamentos
//o maior salario e o departamento pertencente
// o menor salario e o departamento pertencente

#include <stdio.h>
#define DEPARTAMENTOS 3

int main(){

int num_funcionarios[DEPARTAMENTOS];
float salario, total_departamentos[DEPARTAMENTOS]= {0};
float total_geral = 0;
float maior_salario = 0, menor_salario = 0;
int depto_maior = -1, depto_menor = -1;
int primeiro_salario = 1;


for (int i = 0; i < DEPARTAMENTOS; i++){
    printf("Digite a quantidade de funcionarios do departamento %d: ", i + 1);
    scanf("%d", &num_funcionarios[i]);
}

for (int i = 0; i < DEPARTAMENTOS; i++){
    printf("\n\nDepartamento %d: \n", i + 1);
        for (int j = 0; j < num_funcionarios[i]; j++){
            printf("Salario do funcionario %d: ", j + 1);
            scanf("%f", &salario);

            total_departamentos[i] += salario;
            total_geral +=salario;

         if(salario > maior_salario || depto_maior == -1){
            maior_salario= salario;
            depto_maior= i + 1;

         }
         if (salario< menor_salario || primeiro_salario){
            menor_salario = salario;
            depto_menor = i + 1;
            primeiro_salario = 0;
         }
    }

}

printf("\nTotal de salario por departamento: \n");

for (int i = 0; i > DEPARTAMENTOS; i++){
    printf("Departamento %d: R$ %.2f\n", i + 1, total_departamentos[i]);
}

printf("\nTotal de Salarios: R$ %.2f", total_geral);
printf("\nMaior salario (depto %d): R$ %.2f", depto_maior, maior_salario);
printf("\nMenor salario (depto %d): R$ %.2f", depto_menor, menor_salario);
}
