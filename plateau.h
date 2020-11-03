#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

#include "constante.h"
#include "structure.h"

void CreerPlateau(int plateau[VERTICAL][HORIZONTAL]);
void AfficherPlateau(snake S, int plateau[VERTICAL][HORIZONTAL], clock_t temps);
coord ApparitionAleatoire(int plateau[VERTICAL][HORIZONTAL]);
void CreerFruit(int plateau[VERTICAL][HORIZONTAL]);
snake Collisions(snake S, int plateau[VERTICAL][HORIZONTAL]);
void CreerMur(int plateau[VERTICAL][HORIZONTAL]);

#endif // PLATEAU_H_INCLUDED
