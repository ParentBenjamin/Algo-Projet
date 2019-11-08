#ifndef PROJETALGO_IABN_H
#define PROJETALGO_IABN_H

#include <stdlib.h>
#include <stdio.h>
#include "grille.h"

//creer la grille de l'IA aleatoirement
int placementsDesBateauxIA(TAB t);

//effectue un tir aleatoire par l'IA sur le tableau t en appelant tirIA_facile ou tirIA_difficile selon la difficulte
int tirIA(TAB t, int difficulte);

int tirIA_facile(TAB t); //tir IA facile
int tirIA_difficile(TAB t); //tir IA difficile
#endif
