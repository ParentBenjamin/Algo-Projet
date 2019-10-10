#ifndef PROJETALGO_SUDOKU_H
#define PROJETALGO_SUDOKU_H

#include "tableau.h"
#include <stdlib.h>
#include <stdio.h>
int modifCase(int x,int y,int valeur,TAB t);
int coordonneeCarre(int x);
int verifCarre(TAB t ,int x,int y, int valeur);
int  VerifLigne(TAB t,int x ,int y , int valeur);
int  VerifColonne(TAB t,int x ,int y , int valeur);
void sudoku();
#endif //PROJETALGO_SUDOKU_H
