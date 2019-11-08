#include "iaBN.h"
#include "tiragee.h"

//creer la grille de l'IA aleatoirement
int placementsDesBateauxIA(TAB t) {
    int x,y,orien;
    //pour 4 bateaux differents
    for (int i=5; i>1; i--) {
        //tant que coordonnees non valides (placement impossible)
        do {
            x = getRandom(0, 8);
            y = getRandom(0, 8);
            orien = getRandom(0, 3);
        }while(verifEmplacement(t, i, orien, x ,y)==0);
        placerBateau(t, i, orien, x, y);
    }
    return 0;
}

//effectue un tir aleatoire par l'IA sur le tableau t
int tirIA(TAB t) {
    int retour = 0;
    int next = 0;
    do {
        int x = getRandom(0,8);
        int y = getRandom(0,8);

        if (t[x][y].valeur == 0) {
            next = 1;
            t[x][y].etat = 1;
        } else {
            t[x][y].etat = 2;
        }

        if (checkVictoire(t)==1) {
            next = 1;
            retour = 1;
        }

    }while (next==0);

    return retour;
}
