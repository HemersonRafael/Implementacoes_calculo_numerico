#include<math.h>
#include<stdio.h>
#include <stdlib.h>
#include<conio.h>

float fa(float x){
	return exp(x);    // 2A
}
float fb(float x){
	return (1/(x*x)); 	// 2B

}
float fc(float x){
	return (1/(pow((1+x),2)));	// 2C

}
float fd(float x){
	return (x*x/pow((x-1),2));	// 2D

}
float fe(float x){
    return (pow(x,3)+pow(x,2)+x+1);	// 2E

}
float ft(float x){
	return (1/x);

}
void fcalc(float a,float b,int n, char letra){
    int i;
    float  h,soma,I;

    float y[n], x[n];
    h=(b-a)/n;
    printf("\n____________________________________\n");
    printf("DADOS: \n");
    printf("\nA= %f\n", a);
    printf("B= %f\n", b);
    printf("N= %d\n", n);
    printf("H= %f\n", h);

    x[0]=a;

	for(i=0; i<=n; i++){
        x[i+1]=x[i]+h;
        if(letra== 'A'||letra== 'a'){
         y[i]=fa(x[i]);
        }
        else if(letra== 'B'||letra== 'b'){
         y[i]=fb(x[i]);
        }
        else if(letra== 'C'||letra== 'c'){
         y[i]=fc(x[i]);
        }
        else if(letra== 'D'||letra== 'd'){
         y[i]=fd(x[i]);
        }
        else if(letra== 'E'||letra== 'e'){
         y[i]=fe(x[i]);
        }
        else if(letra== 'T'||letra== 't'){
         y[i]=ft(x[i]);
        }

        printf("X[%d]: %f\t",i,x[i]);
        printf("Y[%d]: %f\n",i,y[i]);

    }
    soma=0;

    for(i=0; i<=n; i++){

		if(i==0||i==n){
            soma=soma+y[i];
        }
        else {
            soma=soma+2*y[i];
        }
    }

    I= (h/2)*soma;
    printf("\n I=%f\n",I);

}

int main(){

         printf("CALCULOS DA LETRA 'A'\n");
            fcalc(0,1,1,'a');
            fcalc(0,1,3,'a');
            fcalc(0,1,6,'a');

         printf("CALCULOS DA LETRA 'B'\n");
            fcalc(4,4.5,1,'b');
            fcalc(4,4.5,3,'b');
            fcalc(4,4.5,6,'b');

         printf("CALCULOS DA LETRA 'C'\n");
            fcalc(0,1,1,'c');
            fcalc(0,1,3,'c');
            fcalc(0,1,6,'c');

         printf("CALCULOS DA LETRA 'D'\n");
            fcalc(-2,-1,1,'d');
            fcalc(-2,-1,3,'d');
            fcalc(-2,-1,6,'d');

         printf("CALCULOS DA LETRA 'E'\n");
            fcalc(3,3.3,1,'e');
            fcalc(3,3.3,3,'e');
            fcalc(3,3.3,6,'e');

         printf("CALCULOS DA LETRA 'T'\n");
         fcalc(3,3.6,6,'t');

}
