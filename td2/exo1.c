 #include <stdio.h>

int main()
{
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<10-i;j++){ //j enfonction de -i pour décrementer 
		printf(" ");
					}		
	printf("*\n");
	}
	
	return 0;
}
