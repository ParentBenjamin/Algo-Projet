#ifndef PROJETALGO_SUDOKU_H
#define PROJETALGO_SUDOKU_H

#include <time.h>
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
int aide(Tab t);
void sudoku();
int chargerSudokuSpe2(TAB t, int n);
#endif //PROJETALGO_SUDOKU_H
