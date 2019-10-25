#ifndef PROJETALGO_POKER_H
#define PROJETALGO_POKER_H

#include "Grille.h"
#include "Poker.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct {
    int argent;
    int mise;
    Case jeu[2];
}joueur;

typedef struct {
    Case river[5];
    int pot;
    joueur tableDeJeu[5];
}Parti;



joueur initJoueur();
void initTirage(int n, Case t[5+2*n]);
void initParti(int n,Parti p);
int nbAlea(int n);
bool appartient(int v, int c ,int n ,Case t[5+2*n]);
void remplirTirage(int n ,Case t[5+2*n]);
#endif //PROJETALGO_POKER_H
