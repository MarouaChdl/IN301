#construit le fichier binaire graphics.o
# ` dit qu'on doit executer differents des ' 
#on ne peut pas use les .h mais que les .c pour faire les .o

all: exec
	./exec

exec:graphics.o principal.o 
	gcc -Wall -o exec graphics.o principal.o `sdl-config --libs` -lSDL_ttf -lm

graphics.o: graphics.c graphics.h
	rm -f police.h
	touch police.h
	if test -e /usr/include/SDL_ttf.h;           then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/include/SDL/SDL_ttf.h;       then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL_ttf.h;     then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL/SDL_ttf.h; then echo "#define SDL_TTF_OK" > police.h; fi
	gcc -Wall `sdl-config --cflags`  -c graphics.c

principal.o: principal.c graphics.h constante.h simul.h liste.h
	gcc -Wall -c principal.c
	
simul.o:simul.c constante.h
	gcc -Wall -c simul.c
	
liste.o:liste.c constante.h
	gcc -Wall -c liste.c
	
	
clean:
	rm -f principal.o
	rm -f simul.o
	rm -f liste.o
	rm -f graphics.o
	rm -f main.o
	rm -f exec
	
