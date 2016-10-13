#include <stdio.h>

void permutation(int* aa,int* bb){
		int temp; //ne pas faire celui ci en adresse sinon bug
		temp=*aa;
		*aa=*bb;
		*bb=temp;
		
	}
	
void reinitpointeur(int *(*p)){ //pointeur d'un pointeur 
		//p=NULL;
		*p=NULL; 
		//le pointeur p est null mais c'est une copie d'une pointeur donc il ne passera rien
	}

int main(int argc, char **argv)
{
	
	/*------QUESTION A ---------
	printf("------QUESTION A --------- \n");

	 * int c;
	c=sizeof(char); //sizeof renvoie un entier
	printf("La taille d'un caractére est de %d \n",c);
	
	int i;
	i=sizeof(int);
	printf("La taille d'un entier est de %d \n",i);
	
	int d;
	d=sizeof(double);
	printf("La taille d'un double est de %d \n",d);
	
	int e;
	e=sizeof(char*);
	printf("La taille de l'adresse d'un caractère est de %d \n",e);
	
	int v;
	v=sizeof(void*);
	printf("La taille d'un void est de %d \n",v);
	
	int ai;
	ai=sizeof(int*);
	printf("La taille de l'adresse d'un entier est de %d \n",ai);
	
	int d2;
	d2=sizeof(double*);
	printf("La taille de l'adresse d'un double est de %d \n",d2);
	
	int ii;
	ii=sizeof(int**);
	printf("La taille de l'adresse de l'adresse d'un entier est de %d \n",ii);
	
	int ij;
	ij=sizeof(int[10]);
	printf("La taille d'un tableau d'entier de 9 élément est de %d \n",ij);
	
	//int i2; //ne marche pas normal
	//i2=sizeof(int[]);
	//printf("La taille d'un tableau  d'élément est de %d \n",i2);
	 
	
	int c2;
	c2=sizeof(char[7][3]);
	printf("La taille  d'un tableau de caractère est de %d \n",c2);
	
	
	char tab[10]; //déclaration d'un tableau de 10 caratère
	int i3;
	i3=sizeof(tab);
	printf("La taille  d'un tableau de caractère avec 10 éléments est est de %d \n",i3);
	int i4;
	i4=sizeof(tab[0]);
	printf("La taille  tab[0]  %d \n",i4);
	int i5;
	i5=sizeof(&tab[0]);
	printf("La taille  &tab %d \n",i5);
	int i6;
	i6=sizeof(*&tab);
	printf("La taille  &tab %d \n",i6);
	int i7;
	i7=sizeof(*&tab[0]);
	printf("La taille  *&tab[0] %d \n",i7);
	
	int i8;
	i8=sizeof(long int);
	printf("La taille est de long int %d \n",i8);
	int i9;
	i9=sizeof(long long int);
	printf("La taille est de longlong int %d \n",i9);
	
	char (*p)[10] = &tab;
	int i10;
	i10=sizeof(p);
	printf("p est %d \n",i10);
	
	int a;
	a=sizeof(*p);
	printf(" *p est %d \n" ,a);
	
	int b;
	b=sizeof(*p[2]);
	printf(" *p[2] est %d \n ",b);
	
	int cc;
	cc=sizeof(&(*p[2]));
	printf("&(*p[2]) est %d \n",cc);
	
		
	
	//------QUESTION B ---------
	printf("------QUESTION B --------- \n");
	
	int aa,bb;
	scanf("%d",&aa);
	scanf("%d",&bb);
	
	printf(" valeur de a %d de b %d \n",aa,bb);
	permutation(&aa,&bb); //echanger des valeurs 
	printf(" valeur de a %d de b %d \n",aa,bb);
	*/ 
	
	//------QUESTION C ---------
	printf("------QUESTION C --------- \n");
	
	int a=1;
	int* p=&a; //stock dans l'adress de p l'adress de a
	reinitpointeur(&p);
	printf("%p \n",p); //marche pas il faut mettre *p pour voir l'adress de p
	

	
	
	return 0;
}

