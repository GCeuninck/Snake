#include "constante.h"

void menu_temps(clock_t temps, clock_t tempsJeu)
{
    //Comparaison du temps actualisé avec le temps au lancement du mode de jeu
    temps = (tempsJeu-temps)/1000;
    char titre1[] = "TIMER =";
    gotoxy(HORIZONTAL/2+7,VERTICAL+1);
    printf("%s %f",titre1, (double)temps);
}


