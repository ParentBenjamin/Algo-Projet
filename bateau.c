#include "bateau.h"

//renvoi 1 si le bateau a pu etre place, 0 si impossible
int placerBateau(TAB t, int longBateau, int orientation, int x, int y) {
    switch (orientation) {
        case 0 : // haut
            if (x-(longBateau-1)>=0) {
                for (int i=x; i>x-longBateau ;i--) {
                    t[i][y].valeur = longBateau;
                }
                return 1;
            }else {
                return 0;
            }
            break;
        case 1 : // droite
            if (y+(longBateau-1)<=8) {
                for (int i=y; i<y+longBateau ;i++) {
                    t[x][i].valeur = longBateau;
                }
                return 1;
            }else {
                return 0;
            }
            break;
        case 2 : // bas
            if (x+(longBateau-1)<=8) {
                for (int i=x; i<x+longBateau ;i++) {
                    t[i][y].valeur = longBateau;
                }
                return 1;
            }else {
                return 0;
            }
            break;
        case 3 : // gauche
            if (y-(longBateau-1)>=0) {
                for (int i=y; i>y-longBateau ;i--) {
                    t[x][i].valeur = longBateau;
                }
                return 1;
            }else {
                return 0;
            }
            break;
        default :
            return 0;
            break;
    }
}

void genererGrilleTMP(TAB t) {
    placerBateau(t, 5, 1, 1, 4);
    placerBateau(t, 4, 3, 7, 8);
    placerBateau(t, 3, 2, 6, 0);
    placerBateau(t, 2, 0, 4, 1);
}
