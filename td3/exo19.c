#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//liste chainée c'est 2 champs: valeur et element 

/**----------QUESTION A ---------------**/
	
struct ELEMENT{
	int valeur;
	struct ELEMENT* suivant;   //champs suivant est un pointeur vers un elememnt 
};
typedef struct ELEMENT element;

typedef element* LISTE; 
//une liste est un pointeur sur un premier element  des qu'il voit liste il le remplace par l'adresse de l'element

/**----------QUESTION B ---------------**/
LISTE Creelistevide(){ 
	return NULL;
	//si liste vide la liste ne pointera pas sur le prmeier element vu qu'il n'y en a pas.
	}
	
/*liste vide
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

/**----------QUESTION C ---------------**/
LISTE inseredebut(LISTE l,int x){
	LISTE new =malloc(sizeof(element)); //marche avec <stdlib.h>
	new -> valeur =x;
	new -> suivant = l;
	return new;
}
//corection itératif insere fin	
LISTE inserefin(LISTE l,int x){	
	LISTE new =malloc(sizeof(element)); //ne peut pas avoir deux malloc
	LISTE a =l;  //pointeur sur le premier element de l 
	new -> valeur =x;
	new -> suivant = NULL;
	while(l-> suivant != NULL){
	l=l-> suivant; //avancer dans la liste
	}
	
	l-> suivant =new;
	return a;
}
/*
//corection recursif insere fin
LISTE inserefin2(liste e,int n){
	LISTE a=malloc(sizeof(element));
	if(e==NULL){
		if(a==NULL) exit(1);
		a->valeur =n;
		a-> suivant = NULL;
		return a; }
	e->suivant =inserefin(e->suivant,n);
	return e;	
}
*/ 

int estlistetriee(LISTE l){
	
	if((l -> suivant) == NULL) return 1;
	
	else if ( (l-> suivant) ->valeur <= (l->valeur)) return 0;
	return estlistetriee(l->suivant);
	
	/* /a faire pour itératif
	while(l-> suivant != NULL){
	
	if (new <= new +1)printf("liste est triée"); 
	
	else printf("liste est non triée \n");
	
	l=l-> suivant; //avancer dans la liste
	}
	*/ 
}	
	
LISTE inserertrier(LISTE l,int n){
	LISTE a=malloc(sizeof(element));
	
	if((l == NULL) || (n <=(l ->valeur))){
		if(a == NULL) exit(1);
		a-> valeur=n;
		a -> suivant=l;
		return a;
	
}
	l->suivant =inserertrier(l->suivant,n);
	return l;
}
	

/**----------QUESTION D ---------------**/
int taille(LISTE l){ //pour la taille de la liste en 2 ligne
	if(l==NULL) return 0;
	return 1+taille(l->suivant);

}

int taille2(LISTE l){ //en 1 ligne
	return (l ==NULL) ? 0 : 1+taille(l-> suivant);
}


/**----------QUESTION E ---------------**/
int rechercher_element(LISTE l,int x){
	if(l == NULL) return 0;
	while(l-> suivant != NULL){
		if((l->valeur) == x) {
			printf("on a trouver l'element %d\n ",x);
			return x;
			}
	l=l-> suivant; //avancer dans la liste
	
	}
	printf("on n'a  pas trouver l'element %d \n",x);
return 0;
}

/**----------QUESTION F ---------------**/
LISTE supprimer(LISTE l){
	LISTE a;
	a=l->suivant;
	if(l== NULL) return NULL;
	if(l->suivant != NULL)free(l);
	return a;
}

	
int main()
{
	srand(time(NULL));
	LISTE l;
	int i;
	l=Creelistevide();
	
	//est_vide2(l);

	for(i=0;i<30;i++){ 
		l=inseredebut(l,i);
			//l=inserefin(l,8);	
	}
 
	afficherliste_iteratif(l);
	//estlistetriee(l);
	//taille2(l);
	//printf("La taille est de %d  \n",taille2(l));
	//afficherliste_recursif(l);
	//est_vide2(l);
	rechercher_element(l,89);
	supprimer(l);
	afficherliste_iteratif(l);
	
	liberememoire(l);
	
	return 0;
}

