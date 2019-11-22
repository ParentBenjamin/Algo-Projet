#ifndef PROJETALGO_IABN_H
#define PROJETALGO_IABN_H

#include <stdlib.h>
#include <stdio.h>
#include "grille.h"
#include "batailleNavale.h"

typedef struct {
    int etat;
    int orientation;
    int x_initial;
    int y_initial;
    int x_last;
    int y_last;
    int bateau;
}IA;


//initialisation de l'IA
void initIA(IA *robot);

//creer la grille de l'IA aleatoirement
int placementsDesBateauxIA(TAB t);

//effectue un tir aleatoire par l'IA sur le tableau t en appelant tirIA_facile ou tirIA_difficile selon la difficulte
int tirIA(TAB t, IA *robot);

//Verifie si un tir est possible lors de la recherche de l'orientation
int tirPossible(TAB t, int r, int x, int y, int bateau);

#endif
