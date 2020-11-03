#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED


#define HORIZONTAL 45
#define VERTICAL 20


typedef struct{
    int vert;
    int horiz;
} coord;

typedef struct{
    coord corps[(HORIZONTAL-2)*(VERTICAL-2)];
    int score;
    int estVivant;
    int taille;
    char direction;
    int deplacement;
    int difficulte;
    int nbFruits;
    int DELAY;
} snake;

typedef struct{
    coord position;
    int estMange;
} fruit;


#endif // STRUCTURE_H_INCLUDED
