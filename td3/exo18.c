#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Tableau{
	int taille ;
	int tab[100]; //les premiers entiers sont significatif
};

typedef struct Tableau tableau;

int alea(int n){return rand() %n;} //fonction aléatoire

tableau rand_init(){
	tableau T;
	T.taille=10;
	int i;
	for(i=0;i<10;i++){
	T.tab[i]=alea(20);
	}
}



int main()
{										//----------QUESTION A ---------------//
	
	int a;
	printf("------QUESTION A --------- \n");
	tableau T;
	
	a=sizeof(tableau);
	printf("Taille de la structure tableau est de %d /n",a);
	
											//----------QUESTION B ---------------//
	printf("------QUESTION B --------- la taille mémoire est de 404 \n");
	
	
												//----------QUESTION C ---------------//
	printf("------QUESTION C --------- \n");
	int s;
	srand(time(NULL)); //initialisée les valeurs aléatoires changante grace aux temps
	tableau montab=rand_init();
	
	printf(" %d valeur aléatoire \n",T.taille);
	
	return 0;
}





