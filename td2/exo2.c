#include <stdio.h>

int main()
{ 	int s;
	int m;
	int h;
	
	scanf("%d",&s); 
	// ne pas mettre de s=scanf car met le nombre d'argument
	//l'adresse &s modifie la valeur de l'adresse de s
	
	m = s/60;
	printf(" fait %d minutes \n",m);
	h=s/3600;
	printf(" fait %d heures \n",h);
	s=s%60;
	printf(" et il reste  %d seconde \n",s);
	
	return 0;
}

