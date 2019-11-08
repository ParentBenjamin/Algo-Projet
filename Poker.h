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
    bool coucher;
}joueurPoker;

typedef struct {
    Case river[5];
    joueurPoker tableDeJeu[5];
    int pot;
}Parti;



void initJoueur(joueurPoker j);
void initTirage(int n, Case t[5+2*n]);
void initParti(int n,Parti p);
int nbAlea(int n);
bool appartient(int v, int c ,int n ,Case t[5+2*n]);
void remplirTirage(int n ,Case t[5+2*n]);
void distribution(int n, Case t[5+2*n], Parti p);
int maxMise(Parti p);
void Suivre(Parti p,int joueur);
void tapis(Parti p , int joueur);
void ceCoucher(Parti p, int joueur);
int relancer(Parti p ,int joueur, int somme );
void repartitionArgent (Parti p, int joueurGagnant);
void miseDepart(Parti p, int n, int tour);
#endif //PROJETALGO_POKER_H
