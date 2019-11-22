#ifndef PROJETALGO_BATAILLENAVALE_H
#define PROJETALGO_BATAILLENAVALE_H

#include "grille.h"
#include "bateau.h"
#include "time.h"
#include "joueurBN.h"
#include "iaBN.H"
#include <stdlib.h>
#include <stdio.h>

//Verifie victoire, renvoie 1 si true 0 false
int checkVictoire(TAB t);

//fonction principale de la Bataille Navale
void batailleNavale();

#endif
