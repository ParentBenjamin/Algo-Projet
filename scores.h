#ifndef PROJETALGO_SCORES_H
#define PROJETALGO_SCORES_H

#include <stdlib.h>
#include <stdio.h>


typedef int Compteur[1];

//enregistre le score dans le fichier score du joueur en parametre, 1 si succes 0 sinon
int enregistrerScore(char playerName[], int score);

//reinitialise le score dans le fichier score du joueur en parametre
void reinitialiserScore(char playerName[]);

//renvoie le score du joueur en parametre
int getScore(char playerName[]);
#endif
