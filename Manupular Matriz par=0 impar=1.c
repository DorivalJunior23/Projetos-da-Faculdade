#include <stdio.h>

int leMatriz(int n){
    int i, j,matriz[n][n];

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%i",&matriz[i][j]);
        }
    }
}
int printaMatriz(int n){
    int i,j,matriz[n][n];
    printf("Matriz:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%i    ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("-------------------\n");
}
int parImpar(int n){
    int i,j,aux=0,matriz[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(matriz[i][j]%2==0){
                matriz[i][j]=0;
            }else{
                matriz[i][j]=1;
            }
        }
    }
}

int main()
{
    int a,z;
    printf("Informe o tamanho da matriz: ");
    scanf("%i", &a);
    z=a*a;
    printf("Informe %i valores para a matriz: \n", z);
    leMatriz(a);
    printaMatriz(a);
    parImpar(a);
    printaMatriz(a);

}
