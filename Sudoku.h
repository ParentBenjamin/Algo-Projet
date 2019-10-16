#ifndef PROJETALGO_SUDOKU_H
#define PROJETALGO_SUDOKU_H

#include "Grille.h"
#include <stdlib.h>
#include <stdio.h>
int tableauRempli(TAB t);
int modifCase(int x,int y,int valeur,TAB t);
int modifCase2(int x,int y,int valeur,TAB t);
int coordonneeCarre(int x);
int verifCarre(TAB t ,int x,int y, int valeur);
int  VerifLigne(TAB t,int x ,int y , int valeur);
int  VerifColonne(TAB t,int x ,int y , int valeur);
int chargerSudoku(TAB t,int n);
int chargerSudokuSpe(TAB t, int n);
int nbAlea(int n);
int compterNombreLigneSudoku();
int compterNombreLigneFichier(char nom[]);
void sudoku();
#endif //PROJETALGO_SUDOKU_H
