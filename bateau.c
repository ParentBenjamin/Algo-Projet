#include "bateau.h"

//renvoi 1 si le bateau a pu etre place, 0 si impossible
int placerBateau(TAB t, int longBateau, int orientation, int x, int y) {
    if (verifEmplacement(t, longBateau, orientation, x ,y)==0) {
        return 0;
    }
    switch (orientation) {
        case 0 : // haut
            for (int i=x; i>x-longBateau ;i--) {
                modifValeur(i+1, y+1, longBateau, t);
            }
            break;
        case 1 : // droite
            for (int i=y; i<y+longBateau ;i++) {
                modifValeur(x+1, i+1, longBateau, t);
            }
            break;
        case 2 : // bas
            for (int i=x; i<x+longBateau ;i++) {
                modifValeur(i+1, y+1, longBateau, t);
            }
            break;
        case 3 : // gauche
            for (int i=y; i>y-longBateau ;i--) {
                modifValeur(x+1, i+1, longBateau, t);
            }
            break;
        default :
            return 0;
            break;
    }
    return 1;
}

//verifie un emplacement de bateau et renvoi 1 si disponible, 0 si indisponible
int verifEmplacement(TAB t, int longBateau, int orientation, int x, int y) {
    switch (orientation) {
        case 0 : // haut
            if (x-(longBateau-1)>=0) {
                for (int i=x; i>x-longBateau ;i--) {
                    if (t[i][y].valeur != 0) {
                        return 0;
                    }
                }
                return 1;
            }else {
                return 0;
            }
            break;
        case 1 : // droite
            if (y+(longBateau-1)<=8) {
                for (int i=y; i<y+longBateau ;i++) {
                    if (t[x][i].valeur != 0) {
                        return 0;
                    }
                }
                return 1;
            }else {
                return 0;
            }
            break;
        case 2 : // bas
            if (x+(longBateau-1)<=8) {
                for (int i=x; i<x+longBateau ;i++) {
                    if (t[i][y].valeur != 0) {
                        return 0;
                    }
                }
                return 1;
            }else {
                return 0;
            }
            break;
        case 3 : // gauche
            if (y-(longBateau-1)>=0) {
                for (int i=y; i>y-longBateau ;i--) {
                    if (t[x][i].valeur != 0) {
                        return 0;
                    }
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

//Verifie si le bateau est coule, si oui passe son etat à 3 et retourn 1 sinon 0
int checkCoule(TAB t, int nBateau) {
    int coule = 1;
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            if (t[i][j].valeur==nBateau && t[i][j].etat!=2) {
                coule = 0;
            }
        }
    }

    if (coule==1) {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (t[i][j].valeur==nBateau) {
                    t[i][j].etat = 3;
                }
            }
        }
    }
    return coule;
}
