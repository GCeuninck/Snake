#include "snake.h"

snake CreerSnake(snake S, int plateau[VERTICAL][HORIZONTAL])
{
    int i;

    //Initialise les proprietes du serpent
    S.taille=5;
    S.direction = 'D';
    S.score=0;
    S.estVivant=1;
    S.difficulte=1;
    S.deplacement=0;
    S.nbFruits=0;
    S.DELAY=300;

    //Place le snake au centre de la grille pour départ et definit un symbole de tete different du corps
    S.corps[0].vert=VERTICAL/2;
    S.corps[0].horiz=HORIZONTAL/2;
    plateau[S.corps[0].vert][S.corps[0].horiz]=8;


    //Definition le reste du corps et definit un symbole de corps
    for(i=1 ; i<S.taille ; i++)
    {
        S.corps[i].vert = (S.corps[i-1].vert);
        S.corps[i].horiz = (S.corps[i-1].horiz)-1;
        plateau[S.corps[i].vert][S.corps[i].horiz]=4;
    }

    return S;
}

snake Mouvement(snake S, int plateau[VERTICAL][HORIZONTAL])
{
    int action, i;

    //On garde en mémoire les coordonnées du bout de la queue
    int memHoriz = S.corps[S.taille-1].horiz;
    int memVert = S.corps[S.taille-1].vert;

    //On remplace la tete par un morceau de corps pour que ce symbole soit copie par la premiere partie du corps
    plateau[S.corps[0].vert][S.corps[0].horiz]=4;

    action = _getch();

    //On regarde quel input est fait par le joueur
    switch(action){

        case HAUT:
            if(S.direction != 'B'){

                //On définit une direction pour empecher d'aller à gauche
                S.direction = 'H';
                S.deplacement++;

                //On deplace le corps en commençant par la fin de la queue en prenant les positions des parties plus proches de la tete
                for(i=S.taille ; i>=1 ; i--){

                    S.corps[i].vert = S.corps[i-1].vert;
                    S.corps[i].horiz = S.corps[i-1].horiz;
                }
                //On déplace enfin la tete
                S.corps[0].vert-=1;

                //On efface la dernière partie de l'ancien corps
                plateau[memVert][memHoriz] = 0;
                S = Collisions(S, plateau);
            }
            break;


        case BAS:
            if(S.direction != 'H')
            {
                //On définit une direction pour empecher d'aller à gauche
                S.direction = 'B';
                S.deplacement++;

                //On deplace le corps en commencant par la fin de la queue en prenant les positions des parties plus proches de la tete
                for(i=S.taille ; i>=1 ; i--)
                {
                    S.corps[i].vert = S.corps[i-1].vert;
                    S.corps[i].horiz = S.corps[i-1].horiz;
                }

                //On déplace enfin la tete
                S.corps[0].vert+=1;

                //On efface la dernière partie de l'ancien corps
                plateau[memVert][memHoriz] = 0;
                S = Collisions(S, plateau);
            }
            break;


        case DROITE:
            if(S.direction != 'G')
            {
                //On définit une direction pour empecher d'aller à gauche
                S.direction = 'D';
                S.deplacement++;

                //On deplace le corps en commençant par la fin de la queue en prenant les positions des parties plus proches de la tete
                for(i=S.taille ; i>=1 ; i--)
                {
                    S.corps[i].vert = S.corps[i-1].vert;
                    S.corps[i].horiz = S.corps[i-1].horiz;
                }

                //On déplace enfin la tete
                S.corps[0].horiz+=1;

                //On efface la dernière partie de l'ancien corps
                plateau[memVert][memHoriz] = 0;
                S = Collisions(S, plateau);
            }
            break;


        case GAUCHE:
            if(S.direction != 'D')
            {
                //On définit une direction pour empecher d'aller à gauche
                S.direction = 'G';
                S.deplacement++;

                //On deplace le corps en commençant par la fin de la queue en prenant les positions des parties plus proches de la tete
                for(i=S.taille ; i>=1 ; i--)
                {
                    S.corps[i].vert = S.corps[i-1].vert;
                    S.corps[i].horiz = S.corps[i-1].horiz;
                }

                //On déplace enfin la tete
                S.corps[0].horiz-=1;

                //On efface la dernière partie de l'ancien corps
                plateau[memVert][memHoriz] = 0;
                S = Collisions(S, plateau);
            }
            break;

        case ESPACE:
            retour_menu();
            break;
    }

    //La position finale de la tête redevient un symbole tete
    plateau[S.corps[0].vert][S.corps[0].horiz]=8;

    system("CLS");
    return S;
}

snake MouvementIntermediaire(snake S, int plateau[VERTICAL][HORIZONTAL], int action)
{
    int i;

    //On garde en mémoire les coordonnées du bout de la queue
    int memHoriz = S.corps[S.taille-1].horiz;
    int memVert = S.corps[S.taille-1].vert;

    //On remplace la tete par un morceau de corps pour que ce symbole soit copie par la premiere partie du corps
    plateau[S.corps[0].vert][S.corps[0].horiz]=4;



        //On regarde quel input est fait par le joueur
        switch(action){


        case HAUT:

                //On définit une direction pour empecher d'aller à gauche
                S.direction = 'H';
                S.deplacement++;

                //On deplace le corps en commençant par la fin de la queue en prenant les positions des parties plus proches de la tete
                for(i=S.taille ; i>=1 ; i--){

                    S.corps[i].vert = S.corps[i-1].vert;
                    S.corps[i].horiz = S.corps[i-1].horiz;
                }
                //On déplace enfin la tete
                S.corps[0].vert-=1;

                //On efface la dernière partie de l'ancien corps
                plateau[memVert][memHoriz] = 0;
                S = Collisions(S, plateau);


            break;


        case BAS:

                //On définit une direction pour empecher d'aller à gauche
                S.direction = 'B';
                S.deplacement++;

                //On deplace le corps en commencant par la fin de la queue en prenant les positions des parties plus proches de la tete
                for(i=S.taille ; i>=1 ; i--)
                {
                    S.corps[i].vert = S.corps[i-1].vert;
                    S.corps[i].horiz = S.corps[i-1].horiz;
                }

                //On déplace enfin la tete
                S.corps[0].vert+=1;

                //On efface la dernière partie de l'ancien corps
                plateau[memVert][memHoriz] = 0;
                S = Collisions(S, plateau);

            break;


        case DROITE:

                //On définit une direction pour empecher d'aller à gauche
                S.direction = 'D';
                S.deplacement++;

                //On deplace le corps en commençant par la fin de la queue en prenant les positions des parties plus proches de la tete
                for(i=S.taille ; i>=1 ; i--)
                {
                    S.corps[i].vert = S.corps[i-1].vert;
                    S.corps[i].horiz = S.corps[i-1].horiz;
                }

                //On déplace enfin la tete
                S.corps[0].horiz+=1;

                //On efface la dernière partie de l'ancien corps
                plateau[memVert][memHoriz] = 0;
                S = Collisions(S, plateau);


            break;


        case GAUCHE:

                //On définit une direction pour empecher d'aller à gauche
                S.direction = 'G';
                S.deplacement++;

                //On deplace le corps en commençant par la fin de la queue en prenant les positions des parties plus proches de la tete
                for(i=S.taille ; i>=1 ; i--)
                {
                    S.corps[i].vert = S.corps[i-1].vert;
                    S.corps[i].horiz = S.corps[i-1].horiz;
                }

                //On déplace enfin la tete
                S.corps[0].horiz-=1;

                //On efface la dernière partie de l'ancien corps
                plateau[memVert][memHoriz] = 0;
                S = Collisions(S, plateau);
                break;
        }





    //La position finale de la tête redevient un symbole tete
    plateau[S.corps[0].vert][S.corps[0].horiz]=8;

    system("CLS");

    return S;
}

snake NiveauDifficulte(snake S)
{
    //Augmente la vitesse du Snake selon la difficulté (5 niveaux prévu)
    if(S.difficulte<=4)
    {
        S.DELAY-=25*S.difficulte;
        S.difficulte++;
    }
    return S;
}
