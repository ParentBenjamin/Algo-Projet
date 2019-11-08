#include "batailleNavale.h"
#include "grille.h"

int checkVictoire(TAB t) {
    int victoire = 1;
    for (int i=0; i<9 ; i++) {
        for (int j=0; j<9; j++) {
            if (t[i][j].valeur != 0 && t[i][j].etat != 3) {
                victoire = 0;
            }
        }
    }
    return victoire;
}

void batailleNavale() {
    srand(time(NULL)); // Necessaire pour la generation aleatoire (ligne a executer 1 seule fois, attention elle est executer dans le loto)

    //INITIALISATION
    TAB tabJOUEUR, tabIA;
    init(9,9,tabJOUEUR);
    init(9,9,tabIA);

    //PLACEMENT DES BATEAUx
    placementsDesBateauxJOUEUR(tabJOUEUR);
    placementsDesBateauxIA(tabIA);

    system("cls"); // clear console

    int fin = 0;
    int cpt = 0;
    while (fin==0) {
        //TOUR JOUEUR 1
        fin = tirJOUEUR(tabIA, tabJOUEUR);
        if (fin==0) {
            fin = tirIA(tabJOUEUR);
            if (fin==1) {
                fin = 2;
            }
        }
    }

    if (fin==1) {
        printf("\nVictoire !\n");
    } else {
        printf("\nDefaite  !\n");
    }

    afficheEtat(tabJOUEUR);

}
