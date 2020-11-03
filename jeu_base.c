#include "constante.h"
#include "structure.h"

void jeu_base()
{
    //Initialise le temps au d�but du mode
    clock_t temps = clock();

    //Cr�er les assets necessaire pour le Snake (�l�ments du jeu)
    int plateau[VERTICAL][HORIZONTAL];
    CreerPlateau(plateau);
    snake S;
    S = CreerSnake(S, plateau);
    CreerFruit(plateau);
    AfficherPlateau(S, plateau, temps);


    //Permet le mouvement tant que le Snake n'entre pas dans les �l�ments qui le tuent
    while(S.estVivant == 1)
    {
        S = Mouvement(S, plateau);
        AfficherPlateau(S, plateau, temps);
    }
    menu_mort(S);
}
