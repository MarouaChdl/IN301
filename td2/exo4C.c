#include <stdio.h>

int main()
{
	float precision = 0.01;
	float s=0;
	int i=0;

	while((1.0/(i*i))>precision){
		s += 1.0/(i*i); // pour faire 1 flottant 1.O
		i=i+1;
	}
	printf("%f \n",s);
	return 0;
}

