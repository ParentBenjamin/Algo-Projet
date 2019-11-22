#include "batailleNavale.h"
#include "grille.h"
#include "iaBN.h"

//Verifie victoire, renvoie 1 si true 0 false
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

//calcule le score si victoire sinon 0
int calculScoreBN(Player *p, int fin) {
    if (fin==1) {
        return (100-p->nbtir)*2;
    } else {
        return 0;
    }
}

//fonction principale de la Bataille Navale
void batailleNavale() {
    srand(time(NULL)); // Necessaire pour la generation aleatoire (ligne a executer 1 seule fois, attention elle est executer dans le loto)

    //INITIALISATION
    IA irobot;
    Player p1;
    TAB tabJOUEUR, tabIA;
    init(9,9,tabJOUEUR);
    init(9,9,tabIA);
    initIA(&irobot);
    initPlayer(&p1);

    //PLACEMENT DES BATEAUX
    placementsDesBateauxJOUEUR(tabJOUEUR);
    placementsDesBateauxIA(tabIA);

    system("cls"); // clear console

    int fin = 0;
    while (fin==0) {
        //TOUR JOUEUR 1
        fin = tirJOUEUR(tabIA, tabJOUEUR, &p1);
        if (fin==0) {
            fin = tirIA(tabJOUEUR, &irobot);
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

    int score = calculScoreBN(&p1, fin);
    printf("Votre score est de : %d points",score);
    enregistrerScore(score);



    afficheEtat(tabJOUEUR);
}

