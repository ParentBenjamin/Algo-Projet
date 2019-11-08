/*

    Head du fichier Grille.h

*/

#ifndef GRILLE_H_INCLUDED
#define GRILLE_H_INCLUDED

typedef struct {
    int etat;  // pour le poker (1 = coeur, 2 = pique, 3 = carreau, 4 = trefle) // pour sudoku ( 1 = case bloque, 0 = case libre)
    int valeur;
}Case;

typedef Case TAB[9][9] ;


int init(int longueur , int largeur , TAB t);
void modifValeur(int x , int y , int valeur , TAB t);
int changementEtat(int x , int y , TAB t,int etat);
void affiche(TAB t);
void afficheEtat(TAB t);

#endif // GRILLE_H_INCLUDED
