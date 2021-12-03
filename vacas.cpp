//Um fazendeiro retira leite de suas vacas todos os dias e quer fazer algumas estatísticas da produção de uma semana.
//O programa informa: 
//O dia da sema na com mais e o dia com menos vacas ordenhadas.
//A média de leite retirada por dia.
//A média de leite por vaca.
//O dia da semana com a menor quantidade de leite retirado e quantas vacas foram ordenhadas neste dia.
//A quantidade de vacas ordenhadas e de leite tirado na sexta feira.
#include <stdlib.h>
#include <stdio.h>
void dia_mais(int *v){
    int maior=-1,diamais,menor=1000,diamenos;
    for(int i=0;i<7;i++){
        if(v[i]>maior){
            maior=v[i];
            diamais=i;
        }
        if(v[i]<menor){
            menor=v[i];
            diamenos=i;
        }
    }
    printf("Dia onde mais vacas foram ordenhadas: %i\nDia onde menos vacas foram ordenhadas: %i\n",diamais,diamenos);
    
}
void media_leite(int *l){
    float soma=0;
    float media=0;
        for(int i=0;i<7;i++){
            soma=soma+l[i];
        }
        media=soma/7;
        printf("Media de leite tirado: %.2f\n",media);
}
void media(int *l,int *v){
    float somal=0,somav=0;
    float media;
    for(int i=0;i<7;i++){
      somal+=l[i];
      somav+=v[i];
    }
    media=somal/somav;
    printf("Media de litro por vaca: %.2f\n",media);
}
void menor_leite(int *l,int *v){
    int menor=1000,dia;
    for(int i=0;i<7;i++){
        if(l[i]<menor){
            menor=l[i];
            dia=i;
        }
    }
    printf("O dia que se retirou menos leite foi no dia %i, foram ordenhadas %i vacas.\n",dia,v[dia]);
}
void sexta(int *v,int *l){
    printf("Na sexta feira foram ordenhadas %i vacas e retirados %i litros de leite.",v[5],l[5]);
}
int main(){
    int dias[7],qtd_vacas[7]={10,15,13,14,16,17,13},qtd_leite[7]={155,212,141,148,156,160,152};
    for(int i=0;i<7;i++){
        printf("Dia: %i\n",i);
        dias[i]=i;
        printf("Vacas ordenhadas: %i\n",qtd_vacas[i]);

        printf("Litros de leite: %i\n",qtd_leite[i]);
       
    }
    dia_mais(qtd_vacas);
    media_leite(qtd_leite);
    media(qtd_leite,qtd_vacas);
    menor_leite(qtd_leite,qtd_vacas);
    sexta(qtd_vacas,qtd_leite);
}
