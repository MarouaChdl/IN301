#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//liste chainée c'est 2 champs valeur et element 

						   	/**----------QUESTION A ---------------**/
	
struct ELEMENT{
	int valeur;
	struct ELEMENT* suivant;   //champs suivant est un pointeur vers un elememnt 
};
typedef struct ELEMENT element;

typedef element* LISTE; 
//une liste est un pointeur sur un premier element  des qu'il voit liste il le remplace par l'adresse de l'element


/**----------QUESTION A ---------------**/
LISTE Creelistevide(){ 
	return NULL;
	//si liste vide la liste ne pointera pas sur le prmeier element vu qu'il n'y en a pas.
	}
	
/**----------QUESTION B ---------------**/
/*
 //teste si la liste est vide
int estlistevide(LISTE l){ //teste si liste est vide
	if(l == NULL) {
		printf("La liste est vide \n"); 
		return 1;} //la liste est vide 
		
	else  { printf("La liste est non vide \n"); 
				return 0;} //la liste n'est pas vide	
}
*/  

// correction du prof 
 int est_vide(LISTE l){
	return l == NULL; // si la liste est nul alors c'est vrai alors il renvoie 1
 }
  
 int est_vide2(LISTE l){
	printf("vide");
	return l == NULL; // si la liste est nul alors c'est vrai alors il renvoie 1
 }
 
LISTE inseredebut(LISTE l,int x){
	LISTE new =malloc(sizeof(element)); //marche avec <stdlib.h>
	new -> valeur =x;
	new -> suivant = l;
	return new;
}
	
void afficherliste_recursif(LISTE l){
	if(est_vide(l)){
			printf("\n");}
		else {
			printf(" %d ",l-> valeur);
			afficherliste_recursif(l -> suivant);} 
}

void afficherliste_iteratif(LISTE l){
	LISTE temp=l;
	while(!est_vide(temp)){
		printf("%d ",temp -> valeur);
		temp= temp -> suivant; //se deplacer dans la liste
	}
	printf("\n");
}

void liberememoire(LISTE l){
		if(!est_vide (l)){
			liberememoire( l -> suivant);}
			free(l);
		}

	
int main()
{
	srand(time(NULL));
	LISTE l;
	int i;
	l=Creelistevide();
	est_vide2(l);
	
	//l=inseredebut(l,3);
	//afficherliste_iteratif(l);
	//l=inseredebut(l,4);


	for(i=0;i<300;i++){ 
		l =inseredebut(l,i);
		liberememoire(l);}
	
	afficherliste_recursif(l);
	
	est_vide2(l);
	
	
	return 0;
}

