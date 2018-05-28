#include <stdio.h>
#include <stdlib.h>

float calcfuncao(float x, float y){
	return (y-((2*x)/y));
}

int main(){
	
	int k,m;
	float a,b,h;
	
	a=0;
	b=1;
	h=0.1;
	
	
	
	m = (b-a)/h;
	printf("m= %d\n",m);
	float x[m]; float y[m];
	
			x[0]=0;
			y[0]=1;
		
	for(k=0;k<=m;k++){
		
		x[k+1]= x[k]+h;
		y[k+1]= y[k]+(h*calcfuncao(x[k],y[k]));
		printf("calcf= %f\n",calcfuncao(x[k],y[k]));
		printf("x [%d]= %f\n",k+1,x[k+1]);
		printf("y [%d]= %f\n",k+1,y[k+1]);
		
	}
	system("pause");
}
	
