#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "Grille.h"

int init(int longueur , int largeur , TAB t){ //retourne 1 si l'initiation a ete fait sinon 0
    if(longueur <10 && largeur <10) {
        for (int i = 0; i < largeur; i++) {
            for (int j = 0; j < longueur; j++) {
                t[i][j].etat = 0;
                t[i][j].valeur = 0;
            }
        }
        return 1;
    }
    return 0;
}

void modifValeur(int x , int y , int valeur , TAB t){ //retourne 1 si la modification a ete fait sinon 0
        t[x - 1][y - 1].valeur = valeur;
}

int changementEtat(int x , int y , TAB t,int etat){ //change l'etat de la case selectionner et reourne 0 si l'etat demander correspont a l'etat actuel
    if( t[x - 1][y - 1].etat != etat) {
        t[x - 1][y - 1].etat = etat;
        return 1;
    }
    else return 0;
}

void affiche(TAB t){
printf("   ");
        for (int i = 0; i < 9; i++) {
            if (i == 0){
                for (int k = 0; k < 9; ++k) {


                    printf("%d   ", k + 1);
                }
                printf("\n");
            }
            printf("%d  ",i+1);


            for (int j = 0; j < 9; j++) {

               //printf("%d ",t[i][j].etat);
               printf("%d   ",t[i][j].valeur);
            }
            printf("\n");
        }
}


