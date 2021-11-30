#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct jogo{
    int numero;
    int dezenas[6];
};
void gravar_jogo(){
     FILE *arq;
    arq=fopen("C:\\jogo\\loteria.bin","ab");
    if(arq==NULL){
        printf("Erro");
        exit(1);
    }
    struct jogo ptr;
    printf("Numero do cartão de aposta:\n");
    scanf("%i",&ptr.numero);
    for(int i=0;i<6;i++){
        do{
         printf("Insira o %iº numero:\n",i+1);
         scanf("%i",&ptr.dezenas[i]);
         if((ptr.dezenas[i]<1)||(ptr.dezenas[i]>60)){
             printf("Numero Invalido. Tente Novamente;\n");
         }
         }while((ptr.dezenas[i]>60)||(ptr.dezenas[i]<1));
    }
     fwrite(&ptr,sizeof(struct jogo),1,arq);
     fclose(arq);
    
}
void ler_jogos(){
     FILE *arq;
    arq=fopen("C:\\jogo\\loteria.bin","rb");
    if(arq==NULL){
        printf("Erro");
        exit(1);
    }
    struct jogo x;
    int f; 
    f=fread(&x,sizeof(struct jogo),1,arq);
    while(f!=0){
        printf("Numero do cartão de aposta:\n%i\n",x.numero);
        for(int i=0;i<6;i++){
            printf("%iº Dezena:\n%i\n",i+1, x.dezenas[i]);
        }
    f=fread(&x,sizeof(struct jogo),1,arq);
    }
}
void limpar_jogos(){
    FILE *arq;
    arq=fopen("C:\\jogo\\loteria.bin","wb");
    if(arq==NULL){
        printf("Erro");
        exit(1);
    }
    fclose(arq);
}
void procurar_jogo(){
     FILE *arq;
    arq=fopen("C:\\jogo\\loteria.bin","rb");
    if(arq==NULL){
        printf("Erro");
        exit(1);
    }
    struct jogo x;
    int n,f,v=0; 
    printf("Imprima o numero do jogo que deseja encontrar:\n");
    scanf("%i",&n);
    f=fread(&x,sizeof(struct jogo),1,arq);
    while(f!=0){
       if(n == x.numero){
           v++;
        for(int i=0;i<6;i++){
            printf("%iº Dezena:\n%i\n",i+1, x.dezenas[i]);
        }
       }
    f=fread(&x,sizeof(struct jogo),1,arq);
    }
    if(v==0){
        printf("Numero de jogo não encontado.\n");
    }
    fclose(arq);
}

int main()
{
    int n;
    do{
  printf("Loteria;\n1-Gravar um jogo\n2-Ler os jogos\n3-Limpar os jogos\n4-Procurar um jogo\n0-Fechar programa;\n");
  scanf("%i",&n);
  switch(n){
      case 0: break;
      case 1: gravar_jogo(); break;
      case 2: ler_jogos(); break;
      case 3: limpar_jogos(); break;
      case 4: procurar_jogo(); break;
      default: printf("Numero invalido.\n");
  }
     }while(n!=0);

    return 0;
}
