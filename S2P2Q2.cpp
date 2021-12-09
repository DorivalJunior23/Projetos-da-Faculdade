
//Em uma fazenda produtora de leite, todos os dias é preenchida uma ficha de controle leiteiro. Nessa ficha, são anotadas informações para saber quanto cada vaca está produzindo de leite por dia. 

//Diariamente, são realizadas 2 ordenhas: manhã e tarde. No final do dia, com base nas anotações da ficha de controle, são apurados: o total produzido no dia (litros) por vaca, o total de litros produzidos no dia (soma de litros de todas as vacas) e a média de litros de leite produzido por animal.

//Para esse exercício, você deve fazer:

//a) Definir a struct vaca com os campos: nome(char), litrosManha(float) e litrosTarde(float);

//b) Escrever a função ler_leite que recebe o endereço de um vetor do tipo vaca, o tamanho do vetor do tipo int e faz a leitura dos dados;

//c) Escrever a função mostrar_producao que recebe o endereço de um vetor do tipo vaca, o tamanho do vetor do tipo int e imprime na saída padrão os nomes das vacas, os litros de leite da manhã e da tarde de cada uma delas,  o total de litros de leite produzido no dia por vaca, o total de litros de leite produzido no dia e a média de litros de leite produzidos por animal, conforme os exemplos abaixo:



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct vaca{
   char nome[200];
   float litrosmanha,litrostarde;
};
void ler_leite(struct vaca *v,int n){
    for(int i=0;i<n;i++){
    scanf(" %[^\n]s",v[i].nome);
    scanf("%f",&v[i].litrosmanha);
    scanf("%f",&v[i].litrostarde);
    }
}
void mostrar_producao(struct vaca *v,int n){
    for(int i=0;i<n;i++){
        printf("%s - litros manha: %.1f, litros tarde %.1f - total no dia: %.1f\n",v[i].nome,v[i].litrosmanha,v[i].litrostarde,v[i].litrostarde+v[i].litrosmanha);
    }
    float soma=0;
    for(int i=0;i<n;i++){
        soma=soma+v[i].litrosmanha+v[i].litrostarde;
    }
    printf("Total de leite produzido por dia(litros): %.1f\nMedia de litros de leite produzido por animal: %.1f\n",soma,soma/n);
}
int main(){
    int n;
    scanf("%d",&n);
    struct vaca vc[n];
    ler_leite(vc,n);
    mostrar_producao(vc,n);
}
