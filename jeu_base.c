#include "constante.h"
#include "structure.h"

void jeu_base()
{
    //Initialise le temps au début du mode
    clock_t temps = clock();

    //Créer les assets necessaire pour le Snake (éléments du jeu)
    int plateau[VERTICAL][HORIZONTAL];
    CreerPlateau(plateau);
    snake S;
    S = CreerSnake(S, plateau);
    CreerFruit(plateau);
    AfficherPlateau(S, plateau, temps);


    //Permet le mouvement tant que le Snake n'entre pas dans les éléments qui le tuent
    while(S.estVivant == 1)
    {
        S = Mouvement(S, plateau);
        AfficherPlateau(S, plateau, temps);
    }
    menu_mort(S);
}
