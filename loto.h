#ifndef PROJETALGO_LOTO_H
#define PROJETALGO_LOTO_H

#include <stdlib.h>
#include <stdio.h>
#include "grille.h"
#include "tiragee.h"

int verifierVictoire_aux(TAB t, int yStart, int yEnd);

int verifierVictoire(TAB t, int nbCartons);

int estDejaPresent(TAB t, int yStart, int yEnd, int nombre, int col);

int colonneRemplie(TAB t, int yStart, int yEnd, int nombre, int col);

int compter(TAB t, int ligne);

int placeDispoValide(TAB t, int yStart, int yEnd, int col);

int generer(TAB t, int yStart, int yEnd);

int genererCartons(TAB t, int nbCartons);

int nombreTrouve(TAB t, int nbCartons, int nombre);

int scorefinal(TAB t,int nbCartons, Tirage tir);

void loto();
#endif
