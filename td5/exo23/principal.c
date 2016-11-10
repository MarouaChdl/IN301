#include "circonference.h"
#include "surface.h"
#include <stdio.h>

int main()
{	double c,s;
	int r;
	printf("entrer valeur rayon \n");
	scanf("%d",&r);
	
	c=circonference(r);
	printf("circonference  %f \n",c);
	
	s=surface(r);
	printf("surface  %f \n",s);
	return 0;
}

