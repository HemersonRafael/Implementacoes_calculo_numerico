#include <stdio.h>
#include <stdlib.h>

float calcfuncao(float x, float y){
	return (0.04*y);
}

void calck1(float a,float b,float h,float x0,float y0){
	
	int k,m1;
	float m;
	
		
	m = (b-a)/h;
	m1=m;
	printf("m= %d\n",m1);
	float x[m1]; float y[m1];
	x[0]=x0;
	y[0]=y0;
				
	for(k=0;k<m1;k++){
		
		x[k+1]= x[k]+h;
		y[k+1]= y[k]+(h*calcfuncao(x[k],y[k]));
		printf("calcf= %f\n",calcfuncao(x[k],y[k]));
		printf("x [%d]= %f\n",k+1,x[k+1]);
		printf("y [%d]= %f\n",k+1,y[k+1]);
		
	}
	
}
void calck2(float a,float b,float h,float x0,float y0){
	
	int k,m1;
	float m,K1,K2;
	
	m = (b-a)/h;
	m1=m;
	printf("m= %d\n",m1);
	float x[m1], y[m1];
	
			x[0]=x0;
			y[0]=y0;
		
	for(k=0;k<m1;k++){
		
		x[k+1]= x[k]+h;
		
		K1=calcfuncao(x[k],y[k]);
		K2=calcfuncao((x[k]+h),y[k]+(h*K1));
		y[k+1]= y[k]+((h/2)*(K1+K2));
		printf("calcf= %f\n",calcfuncao(x[k],y[k]));
		printf("x [%d]= %f\n",k+1,x[k+1]);
		printf("y [%d]= %f\n",k+1,y[k+1]);
		
	}
	
}
void calck3(float a,float b,float h,float x0,float y0){
	
	int k,m1;
	float m,K1,K2,K3;
	
	m = (b-a)/h;
	m1=m;
	printf("m= %d\n",m1);
	float x[m1], y[m1];
	
			x[0]=x0;
			y[0]=y0;
		
	for(k=0;k<m1;k++){
		
		x[k+1]= x[k]+h;
		
		K1=calcfuncao(x[k],y[k]);
		K2=calcfuncao(x[k]+(h/3),y[k]+((h/3)*K1));
		K3=calcfuncao(x[k]+((2*h)/3),y[k]+(((2*h)/3)*K2));
		y[k+1]= y[k]+((h/4)*(K1+(3*K3)));
		printf("calcf= %f\n",calcfuncao(x[k],y[k]));
		printf("x [%d]= %f\n",k+1,x[k+1]);
		printf("y [%d]= %f\n",k+1,y[k+1]);
		
	}
	
}
void calck4(float a,float b,float h,float x0,float y0){
	
	int k;
	float m;
	int m1;
	float K1,K2,K3,K4;
	
	m = (b-a)/h;
	m1=m;
	printf("m= %d\n",m1);
	
	float x[m1], y[m1];
	x[0]=x0;
	y[0]=y0;
			
		
	for(k=0;k<m1;k++){
		
		x[k+1]= x[k]+h;
		
		K1=calcfuncao(x[k],y[k]);
		K2=calcfuncao(x[k]+(h/2),y[k]+((h/2)*K1));
		K3=calcfuncao(x[k]+(h/2),y[k]+((h/2)*K2));
		K4=calcfuncao(x[k]+h,y[k]+(h*K3));
		y[k+1]= y[k]+((h/6)*(K1+(2*(K2+K3))+K4));
		printf("calcf= %f\n",calcfuncao(x[k],y[k]));
		printf("x [%d]= %f\n",k+1,x[k+1]);
		printf("y [%d]= %f\n",k+1,y[k+1]);
		
	}
	
}
int main (){
	float a,b,h1,h2,x0,y0;
	
	printf("METODO DE RUNGER KUTTA\n");
	printf("DADOS:\n");
	a=0;
	b=1;
	h1=0.1;
	h2=0.2;
	x0=0;
	y0=1000;
	printf("a= %f\n",a);
	printf("b= %f\n",b);
	printf("h1= %f\n",h1);
	printf("x0= %f\n",x0);
	printf("y0= %f\n\n",y0);
	printf("RK1:\n");
	calck1(a,b,h1,x0,y0);
	printf("\n_______________________________________________\n");
	printf("RK2:\n");
	calck2(a,b,h1,x0,y0);
	printf("\n_______________________________________________\n");
	printf("RK3:\n");
	calck3(a,b,h1,x0,y0);
	printf("\n_______________________________________________\n");
	printf("RK4:\n");
	calck4(a,b,h1,x0,y0);
	printf("\n_______________________________________________\n");
	printf("DADOS:\n");
	printf("a= %f\n",a);
	printf("b= %f\n",b);
	printf("h2= %f\n",h2);
	printf("x0= %f\n",x0);
	printf("y0= %f\n\n",y0);
	printf("RK1:\n");
	calck1(a,b,h2,x0,y0);
	printf("\n_______________________________________________\n");
	printf("RK2:\n");
	calck2(a,b,h2,x0,y0);
	printf("\n_______________________________________________\n");
	printf("RK3:\n");
	calck3(a,b,h2,x0,y0);
	printf("\n_______________________________________________\n");
	printf("RK4:\n");
	calck4(a,b,h2,x0,y0);
	printf("\n_______________________________________________\n");
	system("pause");
	
}
