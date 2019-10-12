#ifndef PROJETALGO_LOTO_H
#define PROJETALGO_LOTO_H

//#include "tableau.h"
#include <stdlib.h>
#include <stdio.h>
#include "grille.h"

int rechercheNombre(int nombresTires[], int nombre);
int verifierVictoire(TAB t, int nombresTires[], int yStart, int yEnd);
void genererTmp(TAB t);
int getRandom(int min, int max);
int presenceNombreGrille(TAB t, int yStart, int yEnd, int nombre);
int colonneRemplie(TAB t, int yStart, int yEnd, int nombre);
int generer(TAB t);

void loto();
#endif
