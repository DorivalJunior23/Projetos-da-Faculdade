//Faça um programa de cadastro de produtos e estoques, este programa deverá:

//a)	Cadastrar produtos;

//b)	Mostrar as descrições de todos produtos já cadastrados;

//c)	Mostrar a quantidade em estoque de um determinado produto. A consulta deverá ter como entrada o código do produto.

//Cada item (a, b, c) deverá ser implementado em sua própria função

//Utilizar uma estrutura para representar cada produto, a qual deverá conter: i) um código de produto, ii) a descrição do produto; iii) quantidade em estoque do produto.

//O arquivo será do tipo binário e seu local de armazenamento será: "C:\\UTF\\produtos"


#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

#include <locale.h>

struct produto{

   int codigo;

   char descricao[500];

   int quantidade;

};

void  cadastrar_produto(){

    FILE *arq;

    arq=fopen("C:\\UTF\\produtos", "ab");

    if(arq == NULL){

        printf("ERRO EM ABRIR ARQUIVO\n");

        exit(1);

    }

    struct produto x;

    fflush (stdin);

    printf("Informe o codigo do produto:\n");

    scanf("%d",&x.codigo);

     printf("Informe a descricao do produto:\n");

    scanf(" %[^\n]s",x.descricao);

     printf("Informe a quantidade do produto:\n");

    scanf("%d",&x.quantidade);

    fwrite (&x, sizeof (struct produto), 1, arq);

    fclose(arq);

}

void mostrar_produtos(){

    FILE *arq;

    arq=fopen("C:\\UTF\\produtos", "rb");

    if(arq == NULL){

        printf("ERRO EM ABRIR ARQUIVO\n");

        exit(2);

    }

    struct produto x;

    int f;

    f=fread(&x,sizeof(struct produto),1,arq);

    while(f!=0){

   

    printf("Codigo do produto: %d\nDescricao: %s\nQuantidade: %d\n\n", x.codigo,x.descricao,x.quantidade);

     f=fread(&x,sizeof(struct produto),1,arq);

    };

    fclose(arq);

}

void  mostrar_estoque(){

     FILE *arq;

    arq=fopen("C:\\UTF\\produtos", "rb");

    if(arq==NULL){

        printf("ERRO EM ABRIR ARQUIVO\n");

        exit(1);

    }

    struct produto x;

    int pdt,f,v=0;

    printf("Informe o codigo do produto:\n");

    scanf("%i",&pdt);

    f=fread(&x,sizeof(struct produto),1,arq);

    while(f!=0){

    if(pdt==x.codigo){

        printf("Descricao: %s\nQuantidade: %d\n\n",x.descricao,x.quantidade);

        v++;

    }

    f=fread(&x,sizeof(struct produto),1,arq);

    }

    if(v==0){

    printf("Numero nao encontrado.\n");

    }

    fclose(arq);

}

int main() {



	setlocale(LC_ALL, "portuguese");  

	

	int opcao;

	do {

    	system("cls");

		printf("MENU:\n");

    	printf("1 - Cadastrar produto\n");

    	printf("2 - Mostrar as descricões de todos produtos\n");

    	printf("3 - Mostrar a quantidade de estoque de um produto\n");

    	printf("0 - Encerrar o Programa\n");

    	printf("-----------------------------\n");

    	printf("Informe a opção desejada:\n");

    	do {

      		scanf("%d", &opcao);

      		if((opcao < 0) || (opcao > 4))

      			printf("Opcao invalida! Tente novamente.\n");

    	} while ((opcao < 0) || (opcao > 4));

    

    	switch (opcao) {

		case 1: cadastrar_produto(); break;

      		case 2: mostrar_produtos(); break;

      		case 3: mostrar_estoque(); break;

    	}

  	} while (opcao != 0);

}
