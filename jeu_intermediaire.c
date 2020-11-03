#include "constante.h"
#include "structure.h"

void jeu_intermediaire()
{
    //Initialise le temps au début du mode
    clock_t temps = clock();

    //Créer les assets necessaire pour le Snake (éléments du jeu)
    int plateau[VERTICAL][HORIZONTAL];
    CreerPlateau(plateau);
    snake S;
    S = CreerSnake(S, plateau);
    CreerFruit(plateau);
    int action, action_temp;



    while(1){

        //On garde le même mouvement tant qu'il n'y a pas de nouvel input valide et tant que Snake n'est pas met
        while(!_kbhit() && S.estVivant!=0){


                S = MouvementIntermediaire(S, plateau, action);
                AfficherPlateau(S, plateau, temps);
                Sleep(S.DELAY);

        }

        //Inputs valident qui change la direction tant que Snake n'est pas mort
        //DELAY assure le deplacement tous les "DELAY" temps (en ms)
        if (_kbhit()&& S.estVivant!=0){

            action_temp=_getch();


            switch(action_temp){

                //Changement de la direction et déplacement
                case HAUT:
                    if(S.direction != 'B'){
                        action = action_temp;
                        S = MouvementIntermediaire(S, plateau,action);
                        AfficherPlateau(S, plateau, temps);
                        Sleep(S.DELAY);
                    }break;
                case BAS:
                    if(S.direction != 'H'){
                        action = action_temp;
                        S = MouvementIntermediaire(S, plateau,action);
                        AfficherPlateau(S, plateau, temps);
                        Sleep(S.DELAY);
                    }break;
                case DROITE:
                    if(S.direction != 'G'){
                        action = action_temp;
                        S = MouvementIntermediaire(S, plateau,action);
                        AfficherPlateau(S, plateau, temps);
                        Sleep(S.DELAY);
                    }break;
                case GAUCHE:
                    if(S.direction != 'D'){
                        action = action_temp;
                        S = MouvementIntermediaire(S, plateau,action);
                        AfficherPlateau(S, plateau, temps);
                        Sleep(S.DELAY);
                    }break;
                case ESPACE :
                    retour_menu();break;

            }
        }
        else
        {
            //Quand perdu, affiche écran de GameOver
            menu_mort(S);
        }
    }
    return 0;
}
