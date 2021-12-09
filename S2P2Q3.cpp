//A struct abaixo define um funcionário de uma empresa de vendas de produtos diversos. 

//typedef struct func{
//char id;
  //      float vendas;
    //    int filial;
//} func;

//Os campos da struct têm o seguinte significado:

//id: identificador do usuário, por exemplo, 'A', 'B', etc.
//vendas: valor total de vendas realizadas.
//filial: código identificador da filial, com os seguintes valores possíveis: 1, 2 ou 3 (apenas três filiais).
//Com base na struct func, você deve implementar três funções no programa em ANEXO, de acordo com o que se pede:

//Função alocar_ler

//Esta função deve alocar memória dinamicamente para um vetor de N funcionários e ler da entrada padrão os dados para cada funcionário.

//Função imprimir

//Esta função deve receber o vetor de funcionários e imprimir os dados na saída padrão.

//Função imprimir_maior_salario_filial

//Esta função deve receber o vetor de funcionários e imprimir os maiores salários de cada filial (1, 2 e 3).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct func {
	char id;
	float vendas;
	int filial;
} func;

struct func* alocar_ler(int n){
    struct func*v=NULL;
    v=(struct func*)malloc(n * sizeof(struct func));
    if(v==NULL){
        printf("erro de alocar memoria");
        exit(1);
    }
    for(int i=0;i<n;i++){
        scanf("%s",&v[i].id);
        scanf("%f",&v[i].vendas);
        scanf("%d",&v[i].filial);
    }
    return v;
}

void imprimir(int n,struct func *v){
    printf("Funcionarios:\n");
    for(int i=0;i<n;i++){
        printf("%c %.2f %d\n",v[i].id,v[i].vendas,v[i].filial);
    }
}

void imprimir_maior_salario_filial(int n,struct func *v){
   int i;
   float maiorf1=0,maiorf2=0,maiorf3=0;
   printf("Maiores salarios:\n");
   for(i=0;i<n;i++){
   if(v[i].filial==1){
        if(v[i].vendas>maiorf1){
            maiorf1=v[i].vendas;
    }
   }
    
   if(v[i].filial==2){
    
        if(v[i].vendas>maiorf2){
            maiorf2=v[i].vendas;
        
    }
    
   }
   if(v[i].filial==3){
        if(v[i].vendas>maiorf3){
            maiorf3=v[i].vendas;
    }
    
   }
   }
   printf("Filial 1 = %.2f\n", maiorf1);
   printf("Filial 2 = %.2f\n", maiorf2);
   printf("Filial 3 = %.2f\n", maiorf3);
}
int main(void){
	int n;
	func *funcionarios = NULL;
	
	scanf("%d", &n);
	
	funcionarios = alocar_ler(n);
	
	imprimir(n,funcionarios);
	
	imprimir_maior_salario_filial(n, funcionarios);
}
