#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED
#include <stdbool.h>
#include "Grille.h"

typedef struct
{
    int nbcoule;
}Joueur;

Joueur initialisationjoueur();//initialise le nb de bateau coule a 0

int tir(TAB t, int x, int y, Joueur *j);//retourne 0 si a l'eau, 1 si touche, 2 si coule
int coule(int x, int y,TAB t);//retourne 1 si bateau coule 0 sinon

bool victoire(Joueur j);//defini si un joueur a gagne ou non

void batailleNavale();
#endif // PLATEAU_H_INCLUDED

