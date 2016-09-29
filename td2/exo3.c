#include <stdio.h>

int main()
{
	int x,y,z,s;
	scanf("%d %d" ,&x,&y); //
	
	//x=23;y=87; 
	z=0; //reste

	
	printf("=%d * %d\n",x,y); //esthétique
	while(x!=1){
	if (x%2 == 0){ 
		x=(x/2); y=2*y;
		} //si pair 
 
	else{
		x=x-1; y=y;
		z=z+y; //reste
		}//si impair

		printf("=%d * %d+ %d  \n",x,y,z);		
	}
	s=y+z;
	printf("= %d  \n",s); //esthétique
	return 0;
}

