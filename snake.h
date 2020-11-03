#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include "constante.h"
#include "structure.h"

snake CreerSnake(snake S, int plateau[VERTICAL][HORIZONTAL]);
snake Mouvement(snake S, int plateau[VERTICAL][HORIZONTAL]);
snake MouvementIntermediaire(snake S, int plateau[VERTICAL][HORIZONTAL], int action);
snake NiveauDifficulte(snake S);

#endif // SNAKE_H_INCLUDED
