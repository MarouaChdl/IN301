#include "graphics.h"
#include "constante.h"

#include "liste.c"
#include "simul.c"

// ##########
// 4. Le main
// ##########

int main(){

  init_graphics(LARGEUR,HAUTEUR);
  affiche_auto_off();
  fill_screen(COUL_FOND);
  affiche_all();

  simulChaine();



  wait_escape();
  return 0;
}
