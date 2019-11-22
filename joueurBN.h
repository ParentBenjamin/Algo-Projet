#ifndef PROJETALGO_JOUEURBN_H
#define PROJETALGO_JOUEURBN_H

#include <stdlib.h>
#include <stdio.h>
#include "grille.h"
#include "batailleNavale.h"

//placement des bateaux par le joueur
int placementsDesBateauxJOUEUR(TAB t);

//effectue un tir par le joueur sur le tableau ennemi t
int tirJOUEUR(TAB t, TAB tjoueur);

#endif


