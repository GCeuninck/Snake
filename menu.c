#include "menu.h"

//Permet de placer le curseur pour écrire à des coordonées précises (code trouvé sur internet)
void gotoxy(int x, int y)
{
   HANDLE hConsoleOutput;
   COORD dwCursorPosition;
   dwCursorPosition.X = x;
   dwCursorPosition.Y = y;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

void Curseur(int i, char titre[], int NB_ELT_MENU, int TAILLE_MAX_ELT, char menu[NB_ELT_MENU][TAILLE_MAX_ELT], char temp[NB_ELT_MENU][TAILLE_MAX_ELT])
{
        int j;

        //Permet d'ajouter le symbole du curseur devant l'élément du menu choisi
        strcat(menu[i], "> ");
        strcat(menu[i], temp[i]);
        system("CLS");
        gotoxy((HORIZONTAL/2)-strlen(titre)/2,5);
        printf("%s",titre);

        //Réaffiche le menu de base sans curseur
        for(j=0;j<NB_ELT_MENU;j++)
        {
            gotoxy((HORIZONTAL/2)-3,VERTICAL/2+j);
            printf("%s\n",temp[j]);
        }

        //Affiche le curseur devant l'élément du menu choisi
        gotoxy((HORIZONTAL/2)-3,VERTICAL/2+i);
        printf("%s\n",menu[i]);
}

void menu_regle()
{
    //Permet d'afficher les règlesn indications et éléments du jeu
    int action;

    char titre1[] = "Les regles";
    gotoxy(HORIZONTAL/2,VERTICAL/4-3);
    printf("%s",titre1);

    char titre2[] = "But du jeu :";
    gotoxy(HORIZONTAL/2,(VERTICAL/4));
    printf("%s",titre2);

    gotoxy(5,(VERTICAL/4)+2);
    printf("Le serpent doit manger le plus de fruits possibles.");

    gotoxy(5,(VERTICAL/4)+3);
    printf("Plus il mange de fruits, plus il accelere.");

    gotoxy(5,(VERTICAL/4)+4);
    printf("S'il touche un mur ou sa queue, c'est perdu.");

    char titre3[] = "Symboles :";
    gotoxy(strlen(titre3)/2,(2*VERTICAL/4+1));
    printf("%s",titre3);

    gotoxy(strlen(titre3)/2,(2*VERTICAL/4)+3);
    printf("Fruits = *");

    gotoxy(strlen(titre3)/2,(2*VERTICAL/4)+4);
    printf("Murs = %c", 219);

    gotoxy(strlen(titre3)/2,(2*VERTICAL/4)+5);
    printf("Tete = @");

    gotoxy(strlen(titre3)/2,(2*VERTICAL/4)+6);
    printf("Corps = o");

    char titre4[] = "Controles";
    gotoxy(HORIZONTAL - strlen(titre4)/2,(2*VERTICAL/4+1));
    printf("%s",titre4);

    gotoxy(HORIZONTAL - strlen(titre4)/2,(2*VERTICAL/4)+3);
    printf("Haut = Z");

    gotoxy(HORIZONTAL - strlen(titre4)/2,(2*VERTICAL/4)+4);
    printf("Gauche = Q");

    gotoxy(HORIZONTAL - strlen(titre4)/2,(2*VERTICAL/4)+5);
    printf("Bas = S");

    gotoxy(HORIZONTAL - strlen(titre4)/2,(2*VERTICAL/4)+6);
    printf("Droite = D");

    retour();
}

void menu_mode()
{
    int action, i=0;

    //Affiche le nom du menu
    char titre[] = "Menu Modes";
    gotoxy((HORIZONTAL/2)-strlen(titre)/2,5);
    printf("%s",titre);

    //Initialise les elements du menu
    char temp[NB_ELT_MENU_M][TAILLE_MAX_ELT_M]={"Base","Intermediaire","Avance","Retour"};
    for(i=0;i<NB_ELT_MENU_M;i++){
        gotoxy((HORIZONTAL/2)-3,VERTICAL/2+i);
        printf("%s\n",temp[i]);
    }

    while(1){

        //Initialise un menu vide qui contiendra les elements initialisés ci-avant
        char menu[NB_ELT_MENU_M][TAILLE_MAX_ELT_M]={"","","",""};
        action =_getch();

        //Selectionne un élément selon input grace à la fonction Curseur
        switch(action){

            case HAUT:
                i--;
                if(i<0){
                    i=NB_ELT_MENU_M-1;
                }
                Curseur(i, titre, NB_ELT_MENU_M, TAILLE_MAX_ELT_M, menu,temp);
            break;

            case BAS:
                i++;
                if(i>NB_ELT_MENU_M-1){
                    i=0;
                }
                Curseur(i, titre, NB_ELT_MENU_M, TAILLE_MAX_ELT_M, menu,temp);
            break;

            //Permet de selectionner le mode de jeu
            case ESPACE:

                switch(i){

                    case 0:
                        system("CLS");
                        jeu_base();
                        break;

                    case 1:
                        system("CLS");
                        jeu_intermediaire();
                        break;

                    case 2:
                        menu_wip();
                        break;

                    case 3:
                        retour_menu();
                        break;

                }
            break;
        }
    }
}

void menu_principal()
{
    int action, i=0;

    //Affiche le nom du menu
    char titre[] = "Bienvenue sur Snake";
    gotoxy((HORIZONTAL/2)-strlen(titre)/2,5);
    printf("%s",titre);

    //Initialise les elements du menu
    char temp[NB_ELT_MENU_P][TAILLE_MAX_ELT_P]={"Modes","Options","Regles","Quitter"};
    for(i=0;i<NB_ELT_MENU_P;i++){
        gotoxy((HORIZONTAL/2)-3,VERTICAL/2+i);
        printf("%s\n",temp[i]);
    }

    //Nom des programmeurs du ce projet
    char titre3[] = "CEUNINCK Guillaume & MERLY Erwan";
    gotoxy(HORIZONTAL/2-strlen(titre3)/2,VERTICAL+1);
    printf("%s %c",titre3, 169);

    while(1){

        //Initialise un menu vide qui contiendra les elements initialisés ci-avant
        char menu[NB_ELT_MENU_P][TAILLE_MAX_ELT_P]={"","","",""};
        action =_getch();

        //Selectionne un élément selon input grace à la fonction Curseur
        switch(action){

            case HAUT:
                i--;
                if(i<0){
                    i=NB_ELT_MENU_P-1;
                }
                Curseur(i, titre, NB_ELT_MENU_P, TAILLE_MAX_ELT_P, menu,temp);
                //Nom des programmeurs du ce projet
                gotoxy(HORIZONTAL/2-strlen(titre3)/2,VERTICAL+1);
                printf("%s %c",titre3, 169);
            break;

            case BAS:
                i++;
                if(i>NB_ELT_MENU_P-1){
                    i=0;
                }
                Curseur(i, titre, NB_ELT_MENU_P, TAILLE_MAX_ELT_P, menu,temp);

                //Nom des programmeurs du ce projet
                gotoxy(HORIZONTAL/2-strlen(titre3)/2,VERTICAL+1);
                printf("%s %c",titre3, 169);
            break;

            //Permet de selectionner le menu suivant
            case ESPACE:

                switch(i){

                    case 0:
                        system("CLS");
                        menu_mode();
                        break;

                    case 1:
                        system("CLS");
                        menu_wip();

                        break;

                    case 2:
                        system("CLS");
                        menu_regle();
                        break;

                    case 3:
                        exit(0);
                        break;

                }
            break;
        }
    }
}

void menu_mort(snake S)
{
    //Permet d'afficher le message de mort pendant un certain temps avant un retour au menu principal
    int DELAY = 1500;

    system("CLS");
    char titre[] = "GAME OVER";
    gotoxy((HORIZONTAL/2)-strlen(titre)/2, VERTICAL/2);
    printf("%s", titre);
    gotoxy(0, VERTICAL);

    //Permet d'afficher le score
    menu_score(S.score);

    Sleep(DELAY);
    retour_menu();
}

void menu_score(int score)
{
    //Permet d'afficher le score en bas de l'écran
    char titre[] = "SCORE";
    gotoxy(0,VERTICAL+1);
    printf("%s = %d",titre,score);
}

void menu_wip()
{
    //Indique que Options et Avancé n'ont pu être réalisé dans le temps imparti
    int DELAY = 1500;

    system("CLS");
    char titre[] = "WORK IN PROGRESS";
    gotoxy((HORIZONTAL/2)-strlen(titre)/2, VERTICAL/2);
    printf("%s", titre);
    gotoxy(0, VERTICAL);


    Sleep(DELAY);
    system("CLS");
    menu_principal();
}

void retour_menu()
{
    //Permet de retourner au menu principal
    system("CLS");
    menu_principal();

}

void retour()
{
    //Permet de retourner au menu principal en jeu et créer un bouton retour
    int action;

    char titre[] = "RETOUR";
    gotoxy(HORIZONTAL/2,VERTICAL+1);
    printf("%s",titre);

    //Retour au menu déclenche par la touche Espace
    action=_getch();
        if(action==ESPACE){
            retour_menu();
    }
}

void menu_deplacement(int deplacement)
{

    //Permet d'afficher le nombre de déplacement par Snake en bas de l'écran
    //Ce compteur est réinitialisé dès qu'il mange un fruit (autre fonction)
    char titre[] = "DEPLACEMENTS = ";

    gotoxy(HORIZONTAL/2+7,VERTICAL+2);
    printf("%s%d",titre, deplacement);

}
