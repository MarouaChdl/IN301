#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Tableau{
	int taille ;
	int tab[100]; //les premiers entiers sont significatif
};

typedef struct Tableau tableau;

int alea(int n){return rand() %n;} //fonction aléatoire

tableau rand_init(){ /**question d**/
	tableau T;
	T.taille=10;
	int i;
	for(i=0;i<10;i++){
	T.tab[i]=alea(20);
	}
	return T;
}

void affiche_element(tableau T,int j){ /**question e**/
	int i;
	for(i=0;i<10+j;i++){
	printf("%d \t",T.tab[i]);}
	printf("\n");
	
}

int produit_element(tableau T){ /**question f**/
	int i,s;
	s=1;
	for(i=0;i<10;i++){
		s=s*T.tab[i];}
	//ne pas mettre de printf sinon affiche 0	
	
	return s;
	}

int minimum(int n, int m){ /**question d compare deux valeur pour donner minimum**/
	if(n>m) return m;
	else return n;
	
}

int minimum_retourner(tableau T){ /**question g**/
	int i,min;
	min=T.tab[0];
	for (i=0;i<10;i++){
		min=minimum(T.tab[i],min);}
		return min;
}


tableau decalage(tableau T){ /**question h**/
	int i;
	tableau T2;
	T2.taille=T.taille+1; //new tableau T2 avec une case de plus que tableau T
	
	for(i=0;i<11;i++){ 
		T2.tab[i+1]=T.tab[i];//on met dans la case 2 de T2 la case 1 de T
	}
	T2.tab[0]= -1;
	
	return T2;
	}
	


int main()
{										/**----------QUESTION A ---------------**/
	
	int a;
	printf("------QUESTION A --------- \n");
	tableau T;
	
	
	a=sizeof(tableau);
	printf("Taille de la structure tableau est de %d \n",a);
	
										/**----------QUESTION B ---------------**/
	printf("------QUESTION B ---------  \n");
	printf("la taille mémoire est de 404 \n");
	
	
										/**----------QUESTION C ---------------**/
	printf("------QUESTION C --------- \n");
	
	srand(time(NULL)); //initialisée les valeurs aléatoires changante grace aux temps
	tableau montab=rand_init();     	/**----------QUESTION D ---------------**/
	
	printf(" %d valeur aléatoire \n",T.taille);
	
										/**----------QUESTION E ---------------**/
	printf("------QUESTION E --------- \n");
	affiche_element(montab,0);
	
										/**----------QUESTION F ---------------**/
	printf("------QUESTION F --------- \n");
	int s;
	s=produit_element(montab);
	printf("%d \n ",s);
	
										/**----------QUESTION C ---------------**/
	printf("------QUESTION G --------- \n");
	int m;
	m=minimum_retourner(montab);
	printf("%d \n",m);
	
										/**----------QUESTION C ---------------**/
	printf("------QUESTION H --------- \n");
	tableau T2;
	T2=decalage(montab);
	affiche_element(T2,1);
	
	//faire trie
	
	
	return 0;
}





