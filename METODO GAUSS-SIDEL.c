//Created by Hemerson Rafael on 26/03/16.
//  Copyright (c) 2016 Hemerson Rafael. All rights reserved.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){
    int n, cont=0,cont1=0, ni, k, j;
    float e=0.0, COV=0.0, soma=0.0, soma1=0.0, test=0.0;

    do{
        if(cont==1){
            cont=0;
        }
        if(cont==0){
            printf("******************** METODO DE GAUSS-SEIDEL ********************\n\n");
            printf("INFORME A ORDEM DA MATRIZ 'A':\n");
            scanf("%d",&n);
            printf("INFORME O NUMERO MAXIMO DE INTERACOES:\n");
            scanf("%d",&ni);
            printf("INFORME O NUMERO DA TOLERANCIA:\n");
            scanf("%f",&e);
        }
        float A[n][n], X[n],x[n], B[n],aux[n];

        if(cont==0){
            for(k=0;k<n;k++){
                for(j=0;j<n;j++){
                    printf("INFORME O VALOR DA POSICAO a[%d] [%d] DA MATRIZ 'A':\n",k+1,j+1);
                    scanf("%f",&A[k][j]);
                }
            }
            for(k=0;k<n;k++){
                printf("INFORME O VALOR DA POSICAO b[%d] DO VETOR 'B':\n",k+1);
                scanf("%f",&B[k]);
            }
            for(k=0;k<n;k++){
                printf("INFORME O VALOR DA POSICAO x[%d] DO VETOR 'X':\n",k+1);
                scanf("%f",&x[k]);
            }
            for(k=0;k<n;k++){
                soma=0;
                for(j=0;j<n;j++){
                    if(k!=j){
                        soma=soma+A[k][j];
                    }
                }
                COV = (soma)/A[k][k];

                printf("___________________________\n");
                printf("cov%d =  %f\n",k,COV);

                if(COV>1){
                    cont=1;
                }


            }
            if(cont==1){
                printf("O SISTEMA PROPOSTO NAO SATISFAZ O CRITERIO DE CONVERGENCIA\n");
                printf("CONFIRA OS DADOS E TENTE NOVAMENTE!");
                system("pause");
                system("cls");

            }

        }


        while(cont==0||cont==4){

            printf("___________________________\n");
            for(k=0;k<n;k++){
                soma=0.0;
                for(j=0;j<n;j++){
                    if(k != j){
                        soma= soma+(A[k][j]*x[j]);
                    }
                }

            X[k] = (B[k]-soma)/(A[k][k]);
            aux[k]=x[k];
            x[k]=X[k];
            printf("X%d = %f\n",k+1,x[k]);


            }
            soma1=0.0;
            for(k=0;k<n;k++){
                soma1=soma1+pow((X[k]-aux[k]),2.0);
            }
            test = sqrt(soma1);
            printf("test = %f\n",test);



            if(test<=e){
                cont=5;
            }
            if(test>e){
                cont=4;
                if(cont1==ni){
                    cont=6;
                }
            }
            cont1=cont1+1;


        }
        if(cont=5){
            printf("___________________________\n");
            printf("A SOLUCAO APROXIMADA:\n");

                for(k=0;k<n;k++){
                    printf("X%d = %f\n",k+1,X[k]);

                }

                system("pause");
                system("cls");
        }


    }while(cont==1);
}
