#makefile commentaire avec #
# -c faire le fichier.o // -g pour debuger // -o renommer fichier
# -o use que pour principal par pour les .o
# ./ pour exectuer

all:principal
	./principal

principal: circonference.o surface.o principal.o
	gcc -o principal circonference.o surface.o principal.o
	
circonference.o: circonference.c  pi.h 
	gcc -Wall -c circonference.c 
	
surface.o: surface.c pi.h
	gcc -Wall -c surface.c 

	
principal.o: principal.c surface.h circonference.h
	gcc -Wall -c principal.c 
	
clean:
	rm -f circonference.o
	rm -f surface.o
	rm -f principal.o
	rm -f principal
	
	
	
	
