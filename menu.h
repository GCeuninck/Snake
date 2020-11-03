#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "constante.h"
#include "structure.h"

#define NB_ELT_MENU_P 4
#define TAILLE_MAX_ELT_P 20

#define NB_ELT_MENU_M 4
#define TAILLE_MAX_ELT_M 20

#define ESPACE 32

void gotoxy(int x, int y);
void Curseur(int i, char titre[], int NB_ELT_MENU, int TAILLE_MAX_ELT, char menu[NB_ELT_MENU][TAILLE_MAX_ELT], char temp[NB_ELT_MENU][TAILLE_MAX_ELT]);
void menu_principal();
void menu_regle();
void menu_mode();
void menu_mort(snake S);
void menu_score(int score);
void retour_menu();
void menu_wip();
void retour();
void menu_deplacement(int deplacement);



#endif // MENU_H_INCLUDED
