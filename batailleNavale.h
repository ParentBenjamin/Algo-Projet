#ifndef PROJETALGO_BATAILLENAVALE_H
#define PROJETALGO_BATAILLENAVALE_H

#include "grille.h"
#include "bateau.h"
#include "time.h"
#include "joueurBN.h"
#include "iaBN.H"
#include <stdlib.h>
#include <stdio.h>

void sauvegarderjeu(TAB joueur, TAB ia, char *nom, Player p);//sauvegarde la partie dans un fichier texte
void genererpartie(TAB chainejoueur, TAB chaineia, Player p);//genere la partie a partir du fichier texte

//Verifie victoire, renvoie 1 si true 0 false
int checkVictoire(TAB t);

//calcule le score si victoire sinon 0
int calculScoreBN(Player *p, int fin);

//fonction principale de la Bataille Navale
void batailleNavale();

#endif
