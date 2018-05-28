#include <stdio.h>
#include <stdlib.h>

float calcfuncao(float x, float y){
	return (x-y+2);
}

int main(){
	
	int k,m;
	float a,b,h,K1,K2,K3;
	
	a=0;
	b=1;
	h=0.1;
	
	
	
	m = (b-a)/h;
	printf("m= %d\n",m);
	float x[m], y[m];
	
			x[0]=0;
			y[0]=2;
		
	for(k=0;k<=m;k++){
		
		x[k+1]= x[k]+h;
		
		K1=calcfuncao(x[k],y[k]);
		K2=calcfuncao(x[k]+(h/3),y[k]+((h/3)*K1));
		K3=calcfuncao(x[k]+((2*h)/3),y[k]+(((2*h)/3)*K2));
		y[k+1]= y[k]+((h/4)*(K1+(3*K3)));
		printf("calcf= %f\n",calcfuncao(x[k],y[k]));
		printf("x [%d]= %f\n",k+1,x[k+1]);
		printf("y [%d]= %f\n",k+1,y[k+1]);
		
	}
	system("pause");
}
	
