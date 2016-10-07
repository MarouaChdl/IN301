#include <stdio.h>
//correction

int somme_dv(int a){
	int s=0;
	int i;
	for(i=1;i<=(a/2);i++){
		if(! (a%i) ) s+=i;
		}
			return s;
}

int main()
{  
	
	
	int n,i,sommede;
	//scanf("%d",&n);
	n=10000;
	
	for(i=1;i<n;i++){
	sommede=somme_dv(i);
		if((i <= sommede) && (sommede <n)){
			if(i == somme_dv(sommede)){
			printf("%d et %d sont amis \n",i,sommede);
			}
		}
	}
	
	return 0;
}

