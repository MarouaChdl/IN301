#include <stdio.h>

int main()
{	int n,m,i,s1,s2,j;
	s1=0;
	s2=0;
	
	 scanf("%d",&n);
	 scanf("%d",&m);
	 
	 for(i=1;i<n;i++){
			if(n%i==0) s1=s1 + i;//i est deviseur
		}
	 for(j=1;j<m;j++){		
			if(m%j==0) s2=s2 + j;
		}
		
		if((s1==m )&& (s2==n)) printf("C'est des nombres amis \n");
		else  printf("Ce n'est pas des nombres amis \n");
	
	return 0;
}

/*
 * int somme_dv(int a){
 * int s=0;
 * for(int i=1;i<a/2;i++){
 * if(=! (a%i)) s+=1;
 * return s
 * 
 * int estami(int a, int b)
 * return somme_div(a)==b && somme_div(b)==a;
 * }
 */ 
