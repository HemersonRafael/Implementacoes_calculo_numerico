
//M�TODO DE NEWTON
//Created by Hemerson Rafael on 31/03/16.
//  Copyright (c) 2016 Hemerson Rafael. All rights reserved.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float calcfuncao(float x, char letra){
	if(letra=='A'||letra=='a'){
		return(pow(x,3.0)-(6*pow(x,2.0)-x+30*x));
	}
	if(letra=='B'||letra=='b'){
		return((3*x)-cos(x));
	}
	if(letra=='C'||letra=='c'){
		return(x+(2*cos(x)));
	}
	if(letra=='D'||letra=='d'){
		return(pow(x,3.0)-pow(2.718281828,(x*2))+3);
	}
	if(letra=='E'||letra=='e'){
		return((2*pow(x,3.0))+pow(x,2.0)-2);
	}
	if(letra=='F'||letra=='f'){
		return(pow(2.718281828,cos(x))+pow(x,3.0)-3);
	}
	if(letra=='G'||letra=='g'){
		return((0.1*pow(x,3.0))-pow(2.718281828,(2*x))+2);
	}
	if(letra=='H'||letra=='h'){
		return(pow(x,3.0)-(5*pow(x,2.0))+x+3);
	}
	if(letra=='I'||letra=='i'){
		return((2*x)-sin(x)+4);
	}
	if(letra=='J'||letra=='j'){
		return(pow(10,x)+pow(x,3.0)+2);
	}
	if(letra=='l'||letra=='L'){
		return(pow(x,3.0)-(4*pow(x,2.0))+2);
	}
	
}
float calcfuncaod(float x, char letra){
	if(letra=='A'||letra=='a'){
		return((3*pow(x,2.0))-(12*x)-1+30);
	}
	if(letra=='B'||letra=='b'){
		return(3+sin(x));
	}
	if(letra=='C'||letra=='c'){
		return(1-(2*sin(x)));
	}
	if(letra=='D'||letra=='d'){
		return((3*pow(x,2.0))-(2*pow(2.718281828,(x*2)))+3);
	}
	if(letra=='E'||letra=='e'){
		return((6*pow(x,2.0))+2*x);
	}
	if(letra=='F'||letra=='f'){
		return((-sin(x)*pow(2.718281828,cos(x)))+(3*pow(x,2.0)));
	}
	if(letra=='G'||letra=='g'){
		return((0.3*pow(x,2.0))-(2*pow(2.718281828,(2*x))));
	}
	if(letra=='H'||letra=='h'){
		return((3*pow(x,2.0))-(10*x)+1);
	}
	if(letra=='I'||letra=='i'){
		return(2-cos(x));
	}
	if(letra=='J'||letra=='j'){
		return((x*pow(10,(x-1)))+(3*pow(x,2.0)));
	}
	if(letra=='l'||letra=='L'){
		return((3*pow(x,2.0))-(8*x));
	}
	
}

float calck(float ak, float bk, float ek){
	return(ceil((log10(bk-ak)-log10(ek))/log10(2)));
}

float multfuncoes(float am, float bm, char letram){
    return(calcfuncao(am,letram)*calcfuncao(bm,letram));

}
int main (){
    float x, a, b,e,test,aux;
    int cont1=0, cont, k;
    char letra;


    do{ 
		printf("******************** METODO DE NEWTON ********************\n\n");
    	
    	printf("_______________________________________________\n");
    	printf("A= pow(x,3.0)-(6*pow(x,2.0)-x+30*x)            |\n");
    	printf("_______________________________________________\n");
    	printf("B= (3*x)-cos(x)                                |\n");
    	printf("_______________________________________________\n");
    	printf("C= x+(2*cos(x))                                |\n");
    	printf("_______________________________________________\n");
    	printf("D= pow(x,3.0)-pow(2.718281828,(x*2))+3         |\n");
    	printf("_______________________________________________\n");
    	printf("E= (2*pow(x,3.0))+pow(x,2.0)-2                 |\n");
    	printf("_______________________________________________\n");
    	printf("F= pow(2.718281828,cos(x))+pow(x,3.0)-3        |\n");
    	printf("_______________________________________________\n");
    	printf("(G= 0.1*pow(x,3.0)-pow(2.718281828,(2*x))+2    |\n");
    	printf("_______________________________________________\n");
    	printf("H= pow(x,3.0)-(5*pow(x,2.0))+x+3               |\n");
    	printf("_______________________________________________\n");
    	printf("I= (2*x)-sin(x)+4                              |\n");
    	printf("_______________________________________________\n");
    	printf("J= pow(10,x)+pow(x,3.0)+2                      |\n");
    	printf("_______________________________________________\n");
    	
		printf("DIGITE A LETRA DA FUNCAO QUE DESEJA CALCULAR:\n");
    	scanf("%c",&letra);
    	
		printf("INFORME O NUMERO DA TOLERANCIA:\n");
    	scanf("%f",&e);
        
		printf("INFORMER UM INTERVALO [a,b]\n");
        printf("INFORME O NUMERO DE a:\n");
        scanf("%f",&a);
        printf("INFORME O NUMERO DE b:\n");
        scanf("%f",&b);


        if(multfuncoes(a,b,letra)<0){
            cont=1;
        }
        else if(multfuncoes(a,b,letra)>0){
            cont=2;
            printf("INFORMER UM INTERVALO [a,b] NOVO porque nesse nao existir raiz\n");
        	system("pause");
            system("cls");
        }

   }while(cont==2);
   
	k= calck(a,b,e);
	printf("NUMERO MAXIMO DE INTERACOES K: %d\n\n",k);
	printf("valor calc f'(a): %f\n",calcfuncaod(a,letra));
    printf("valor calc f'(b): %f\n",calcfuncaod(b,letra));
	
	if(sqrt(pow(calcfuncaod(a,letra),2.0))<sqrt(pow(calcfuncaod(b,letra),2.0))){
			x=b;
		}
	else{
		x=a;
	}
	
    do{
    	
    	printf("_______________________________________________\n");
    	printf("INTERACOES K: %d\n",cont1);
    	aux=x;    	        
        x= x-(calcfuncao(x,letra)/calcfuncaod(x,letra));    
        printf("O VALOR DE X: %f\n",x);
        printf("valor calc f(x): %f\n",calcfuncao(x,letra));
        printf("valor calc f'(x): %f\n",calcfuncaod(x,letra));
        test= aux-x;
        printf("O VALOR DE test: %f\n",test);
		printf("_______________________________________________\n");
		cont1=cont1+1;
		
    }while(cont1<k && test>=e);

    system("pause");
}
