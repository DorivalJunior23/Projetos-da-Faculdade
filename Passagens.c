#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct passagem{
    int nmr_passagem;
    int poltrona;
    char origem[30];
    char destino[30];
};
void criar_passagem(){
    struct passagem ptr;
    FILE *arq;
    arq=fopen("c:\\passagen\\nova", "ab");
    if(arq==NULL){
        printf("Erro");
        exit(1);
    }
    printf("Digite o numero da passagem:\n");
    scanf("%i",&ptr.nmr_passagem);
    printf("Digite o numero da poltrona:\n");
    scanf("%i",&ptr.poltrona);
    fflush(stdin);
    printf("Origem:\n");
    scanf(" %[^\n]s", ptr.origem);
    printf("destino:\n");
    scanf(" %[^\n]s", ptr.destino);
    fwrite(&ptr,sizeof(struct passagem),1,arq);
    fclose(arq);
}
void limpar_passagens(){
    FILE *arq;
    arq=fopen("c:\\passagen\\nova", "wb");
    if(arq==NULL){
        printf("Erro");
        exit(1);
    }
    printf("Todas as passagens foram limpas\n");
}
void ler_passagens(){
    FILE *arq;
    arq=fopen("c:\\passagen\\nova", "rb");
    if(arq==NULL){
        printf("Erro");
        exit(1);
    }
    struct passagem x;
    int f;
    f=fread(&x,sizeof(struct passagem),1,arq);
    while(f!=NULL){
   
    printf("Passagem: %i\nPoltrona: %i\nOrigem: %s\nDestino: %s\n\n", x.nmr_passagem,x.poltrona,x.origem,x.destino);
     f=fread(&x,sizeof(struct passagem),1,arq);
    };
    fclose(arq);
}
void procurar_passagem(){
    FILE *arq;
    arq=fopen("c:\\passagen\\nova", "rb");
    if(arq==NULL){
        printf("Erro");
        exit(1);
    }
    struct passagem x;
    int psg,f,v=0;
    printf("Informe o numero da passagem:\n");
    scanf("%i",&psg);
    f=fread(&x,sizeof(struct passagem),1,arq);
    while(f!=NULL){
    if(psg==x.nmr_passagem){
        printf("\nPoltrona: %i\nOrigem: %s\nDestino: %s\n\n",x.poltrona,x.origem,x.destino);
        v++;
    }
    f=fread(&x,sizeof(struct passagem),1,arq);
    }
    if(v==0){
    printf("Numero não encontrado.\n");
    }
    fclose(arq);
}
int main()
{
    int n;
    do{
    printf("Escolha uma ação:\n1-criar passagem\n2-ler passagens\n3-limpar passagens\n4-procurar passagem\n0-encerrar programa\n");
    scanf("%i",&n);
    switch(n){
        case 0: break;
        case 1: criar_passagem();break;
        case 2: ler_passagens();break;
        case 3: limpar_passagens();break;
        case 4: procurar_passagem();break;
        default: printf("Numero invalido!\n");break;
    }
    }while(n!=0);
    return 0;
}
