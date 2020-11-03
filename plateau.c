#include "plateau.h"
#include"constante.h"


void CreerPlateau(int plateau[VERTICAL][HORIZONTAL])
{
    //Soit i l'indice de la vertical et j l'indice de la horizontal
    int i, j;

    //Creation des murs verticaux
    for(i=0 ; i<VERTICAL ; i++){

        plateau[i][0]=1;
        plateau[i][HORIZONTAL-1]=1;
    }

    //Creation des murs horizontaux
    for(j=0 ; j<HORIZONTAL ; j++){

        plateau[0][j]=1;
        plateau[VERTICAL-1][j]=1;
    }

    //Creation de la zone de jeu

    for(i=1 ; i<VERTICAL-1 ; i++){
        for(j=1 ; j<HORIZONTAL-1 ; j++){

            plateau[i][j]=0;
        }
    }
}

void AfficherPlateau(snake S, int plateau[VERTICAL][HORIZONTAL], clock_t temps)
{

    time_t tempsJeu = clock();
    //Soit i l'indice de la vertical et j l'indice de la horizontal
    int i,j;

    //Affichage ligne par ligne
    for (i=0;i<VERTICAL;i++){

    //Affichage chaque ligne selon la forme desiree
        for (j=0;j<HORIZONTAL;j++)
        {
            switch (plateau[i][j])
            {
                //Affichage des bordures
                case 1: printf("%c",219);break;

                //Affichage du vide
                case 0: printf(" ");break;

                //Affichage du corps
                case 4: printf("o");break;

                //Affichage de la tete
                case 8: printf("@");break;

                //Affichage du fruit
                case 6: printf("*");break;
            }

        }
    printf("\n");
    }

    //HUD qui donnc les informations au joueur
    menu_temps(temps, tempsJeu);
    menu_deplacement(S.deplacement);
    menu_score(S.score);

    char titre[] = "RETOUR";
    gotoxy(HORIZONTAL/2 - strlen(titre)/2-2,VERTICAL+1);
    printf("%s\n",titre);
    printf("NIVEAU= %d",S.difficulte);
}

coord ApparitionAleatoire(int plateau[VERTICAL][HORIZONTAL]) //Génération aléatoire des positions pour les objets (fruits, murs...)
{
    //Permet de générer des positions aléatoires pour les objets
    coord position;
    srand(time(NULL));

    position.horiz=0;
    position.vert=0;

    //Permet aux objets de n'apparaitre que sur un sol vide
    while(plateau[position.vert][position.horiz] != 0)
    {
        position.horiz=rand()%(HORIZONTAL-1);
        position.vert=rand()%(VERTICAL-1);
    }

    return position;
}

void CreerFruit(int plateau[VERTICAL][HORIZONTAL])
{
    //Fait apparaitre un fruit dès qu'un est mangé
    fruit F;
    F.position = ApparitionAleatoire(plateau);
    F.estMange = 0;

    plateau[F.position.vert][F.position.horiz]=6;
}

void CreerMur(int plateau[VERTICAL][HORIZONTAL])
{
    //Fait apparaitre un nouveau mur
    coord coordonneesMur;
    coordonneesMur=ApparitionAleatoire(plateau);
    plateau[coordonneesMur.vert][coordonneesMur.horiz]=1;
}

snake Collisions(snake S, int plateau[VERTICAL][HORIZONTAL])
{

    //Permet de tuer le Snake s'il entre en collision avec le mur ou sa queue
    if(plateau[S.corps[0].vert][S.corps[0].horiz]== 1 || plateau[S.corps[0].vert][S.corps[0].horiz]== 4)
    {
        S.estVivant=0;
    }

    //Permet de manger des fruits et d'en faire apparaitre un autre ainsi qu'un mur
    //Permet d'actualiser les propriétés du Snake
    if(plateau[S.corps[0].vert][S.corps[0].horiz]== 6)
    {
        CreerMur(plateau);
        CreerFruit(plateau);
        S.taille++;
        S.score=S.score + 100-S.deplacement;
        S.nbFruits++;
        S.deplacement=0;

        //Appel de la fonction pour changer le niveau de difficulté
        if(S.nbFruits>=5*S.difficulte)
        {
            S=NiveauDifficulte(S);
        }
    }
    return S;
}
