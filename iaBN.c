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

//effectue un tir aleatoire par l'IA sur le tableau t en appelant tirIA_facile ou tirIA_difficile selon la difficulte
int tirIA(TAB t, int difficulte) {
    int retour;
    if (difficulte==1) {
        retour = tirIA_facile(t);
    } else {
        retour = tirIA_difficile(t);
    }
    return retour;
}

//tir IA facile
int tirIA_facile(TAB t) {
    int retour = 0;
    int next = 0;
    do {
        int x, y;
        do {
            x = getRandom(0,8);
            y = getRandom(0,8);
        }while(t[x][y].etat != 0);

        if (t[x][y].valeur == 0) {
            next = 1;
            t[x][y].etat = 1;
        } else {
            t[x][y].etat = 2;
            checkCoule(t, t[x][y].valeur);
            printf("\nTOUCHE\n");
        }

        if (checkVictoire(t)==1) {
            next = 1;
            retour = 1;
        }

    }while (next==0);

    return retour;
}

//tir IA difficile
int tirIA_difficile(TAB t) {

}
