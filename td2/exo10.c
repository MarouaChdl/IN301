#include <stdio.h>

int main()
{	float g=0;
	float d=0;
	float epsilon=0.001;
	float m;
	g=0;
	
	//scanf("%d",&d);
	d=23;
	
	
	
	while(d-g >epsilon  ){
	m=(d+g)/2;
		if(m*m > d) d=m;
			else g=m;
		}
	
	printf("%f  %f \n",g,d);
	
	}
	
	
//teste de précision 
//modificationde lintervalle



