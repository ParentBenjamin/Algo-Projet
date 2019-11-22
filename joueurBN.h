#ifndef PROJETALGO_JOUEURBN_H
#define PROJETALGO_JOUEURBN_H

#include <stdlib.h>
#include <stdio.h>
#include "grille.h"

typedef struct {
    int nbtir;
}Player; //structure player sert a enregister le nombre de tirs pour calculer le score

//initialisation du player
void initPlayer(Player *p);

//placement des bateaux par le joueur
int placementsDesBateauxJOUEUR(TAB t);

//effectue un tir par le joueur sur le tableau ennemi t
int tirJOUEUR(TAB t, TAB tjoueur, Player *p);

#endif


