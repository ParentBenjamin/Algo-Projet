#ifndef PROJETALGO_BATEAU_H
#define PROJETALGO_BATEAU_H

#include <stdlib.h>
#include <stdio.h>
#include "grille.h"

//orientation : 0 si vers le haut, 1 si vers la droite, 2 si vers le bas, 3 si vers la gauche

int placerBateau(TAB t, int longBateau, int orientation, int x, int y); //renvoi 1 si le bateau a pu etre place, 0 si impossible

void genererGrilleTMP(TAB t); //generation des bateaux sur une grille a la main pour les tests

#endif
