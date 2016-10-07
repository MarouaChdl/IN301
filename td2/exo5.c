#include <math.h>
#include <stdio.h>

//nombre premier divisible par 1 et lui meme.

int main()
{	
	int x,i,s;
	s=0;
	 scanf("%d",&x);
	
		for(i=2;i<x;i++){
			if(x%i==0) s=s + (x%i);
			else s=s +(x%i);}
			
			if(s==0)  printf("Ce n'est pas un nombre premier \n");
			
			 else printf("le nombre %d est un nombre premier \n",x);
			 
			
	
	return 0;
}

/*
 * i=2;
 * while(i*i <x){
 * if(x%i ==0){printf(faux); return 0}
 * i++}
 * 
 */ 
