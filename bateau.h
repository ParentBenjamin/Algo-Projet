#ifndef PROJETALGO_BATEAU_H
#define PROJETALGO_BATEAU_H

#include <stdlib.h>
#include <stdio.h>
#include "grille.h"

//orientation : 0 si vers le haut, 1 si vers la droite, 2 si vers le bas, 3 si vers la gauche

//renvoi 1 si le bateau a pu etre place, 0 si impossible
int placerBateau(TAB t, int longBateau, int orientation, int x, int y);

//verifie un emplacement de bateau et renvoi 1 si disponible, 0 si indisponible
int verifEmplacement(TAB t, int longBateau, int orientation, int x, int y);

//Verifie si le bateau est coule, si oui passe son etat à 3 et retourn 1 sinon 0
int checkCoule(TAB t, int nBateau);
#endif
