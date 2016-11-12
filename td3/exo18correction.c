#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLEMAX 100000

typedef struct{
  int taille;
  int tab[TAILLEMAX];
} Tableau;

Tableau initialise_rand(int taille, int val){
  Tableau T;
  T.taille = taille;
  int i;
  for(i=0; i < taille; i++){
    T.tab[i] = rand()%val;
  }
  return T;
}

void affiche_tab(Tableau T){
	int i;
  for(i=0; i < T.taille; i++){
    printf("%d ",T.tab[i]);
  }
  printf("\n \n");
}


void swap(Tableau *T, int i, int j){
  int temp = T->tab[i];
  T->tab[i] = T->tab[j];
  T->tab[j] = temp;
}


//////////////////////////////////// Tri Sélection ////////////////////////////
int tri_selection(Tableau *T){
  int pos_min;
  int min;
  int i,j;
  for(i=0; i< T->taille-1;i++){
    pos_min = i;
    min = T->tab[i];
    for( j = i+1; j < T->taille; j++){
      if(T->tab[j] < min){
	pos_min = j;
	min = T->tab[j];
      }
    }
    T->tab[pos_min] = T->tab[i];
    T->tab[i] = min;
  }
  return T->taille*(T->taille-1)/2;
}


//////////////////////////////////// Tri Insertion ////////////////////////////

int tri_insertion(Tableau *T){
  int comp = 0; int temp,i,j;
  for(i = 1; i < T->taille; i++){
    temp = T->tab[i];
    for(j=i-1; j >= 0; j--){
      if(T->tab[j] < temp){
        comp++;
        break;
      }
      else{
        T->tab[j+1] = T->tab[j];
      }
    }
    T->tab[j+1] = temp;
    comp += i-j-2;
  }
  return comp;
}


//////////////////////////////////// Tri à bulle ////////////////////////////

int bubble_sort(Tableau *T){
  int pos_swap, t = 0;
  int comp = 0;
  while(t < T->taille-1){
    pos_swap = T->taille;
    int j;
    for( j = T->taille-1; j>t; j--){
        if(T->tab[j] < T->tab[j-1]) {
        swap(T,j,j-1);
        pos_swap = j;
      }
     }
    comp += T->taille -t -2;
    t = pos_swap; 
    }
  return comp;
}
//////////////////////////////// Tri Rapide //////////////////////////


//Algo de partitionnement de tableau
int partition(Tableau *T, int g, int d){
  int pivot = T->tab[g];
  int i = g+1;
  int j = d;
  while(i < j){
    while(T->tab[i] <= pivot) i++;
    while(T->tab[j] > pivot) j--;
    if(i<j){
      swap(T,i,j);
      i++;
      j--;
    }
  }
  T->tab[g] = T->tab[j];
  T->tab[j] = pivot;
  return j;
}

//Choix de la médiane comme pivot
int mediane_pivot(Tableau *T, int g, int d){

  //find the median between g, d and m
  int m = (g+d)/2;
  if(T->tab[g] < T->tab[m]) swap(T,g,m);
  if(T->tab[d] < T->tab[g]) {swap(T,d,g);}
  else{ return 2;}
  if(T->tab[g] < T->tab[m]) swap(T,m,g);
  return 3;
}


//Choix du premier élément comme pivot
int premier_pivot(Tableau *T, int g, int d){
  return 0;
}


//Choix d'un élément aléatoire comme pivot
int alea_pivot(Tableau *T, int g, int d){
  swap(T,g,g + (rand()%(d-g)));
  return 0;
}

int tri_pivot_r(Tableau *T, int g, int d, int (*pivot)(Tableau*, int, int)){
  if(g < d){
    int piv = (*pivot)(T, g, d);//put the pivot in position g
    int p = partition(T, g, d);
    if(p < (g+d)/2){
     piv += tri_pivot_r(T,g,p-1,pivot);
     piv += tri_pivot_r(T,p+1,d,pivot);  
    }
    else{
      piv += tri_pivot_r(T,p+1,d,pivot);
      piv += tri_pivot_r(T,g,p-1,pivot);
    }
    
    return  d-g + piv;
  }
  return 0;
}

int tri_pivot_simple(Tableau *T){
  return tri_pivot_r(T, 0, T->taille,premier_pivot);
}

int tri_pivot_alea(Tableau *T){
  return tri_pivot_r(T, 0, T->taille,alea_pivot);
}

int tri_pivot_mediane(Tableau *T){
  return tri_pivot_r(T, 0, T->taille,mediane_pivot);
}


/////////////////////////  Tri Fusion /////////////////////////////////////////////////////////

int fusion(Tableau *T, int g, int m, int d){
  int i = g;
  int j = m;
  int k =0;
  int temp[TAILLEMAX];
  int comp;
  while(i < m && j <= d){
    if(T->tab[i] < T->tab[j]){
      temp[k] = T->tab[i];
      i++;
    }
    else{
     temp[k] = T->tab[j];
      j++; 
    }
    k++;
  }
  comp = k;
  while(i < m){
    temp[k] = T->tab[i];
    i++;
    k++;
  }
  while(j <= d){
    temp[k] = T->tab[j];
    j++;
    k++;
  }
  for(i = 0; i < k; i++){
    T->tab[g+i] = temp[i];
  }
  return comp;
}

int tri_fusion_rec(Tableau *T, int g, int d){
  int comp;
  if(g < d){
    int m = (g+d)/2;
    comp = tri_fusion_rec(T,g,m);
    comp+= tri_fusion_rec(T,m+1,d);
    comp+= fusion(T,g,m+1,d);
    return comp;  
  }
  return 0; 
}

int tri_fusion(Tableau *T){
  return tri_fusion_rec(T,0,T->taille-1); 
}

/////////////////////////  Test des tris ////////////////////////////////////////////////////

void stat(int lower_bound, int upper_bound, int step, int precision, int (*ptr)(Tableau*)){
  Tableau T;int moyenne;
  int j,i;
  for(i = lower_bound; i < upper_bound; i+=step){
    moyenne = 0;
    for( j = 0; j < precision; j++){
      T = initialise_rand(i,100000);
      moyenne+= (*ptr)(&T);
    }
    printf("%d %d\n",i,moyenne/precision);
  }
}

int main(){
  srand(time(NULL));
  //Tableau T = initialise_rand(100,10000);
  //affiche_tab(T);
  //tri_fusion(&T);
  //affiche_tab(T);
  printf("Tri à bulle:\n");
  stat(10,2000,200,100,bubble_sort);
  printf("Tri insertion:\n");
  stat(10,2000,200,100,tri_insertion);
   printf("Tri Fusion:\n");
  stat(10,2000,200,100,tri_fusion);
  printf("Tri Pivot Simple:\n");
  stat(10,2000,200,100,tri_pivot_simple);
  printf("Tri Pivot Aléa:\n");
  stat(10,2000,200,100,tri_pivot_alea);
  printf("Tri Pivot Mediane:\n");
  stat(10,2000,200,100,tri_pivot_mediane);
    return 0;
}
