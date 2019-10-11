#include "loto.h"

//recherche si un nombre est contenu dans un tableau   1 si vrai  0 si faux
int rechercheNombre(int nombresTires[100], int nombre) {
    int myBoolean = 0;
    for (int i=0; i<100; i++) {
        if (nombresTires[i] == 0) {
            break;
        } else if (nombresTires[i] == nombre) {
            myBoolean = 1;
            break;
        }
    }
    return myBoolean;
}

//Verifie pour une, deux ou trois grilles  qu'elles contiennent uniquement des nombres contenus dans le tableau nombresTires   1 si vrai    0 si faux
int verifierVictoire(TAB t, int nombresTires[100], int yStart, int yEnd) {  //nombresTires est le tableau des nombres deja tires, ystart et yend sont les entiers qui delimitent quelle partie du tableau il faut verifier (en fonction du nombre de grilles)
    for (int x=0; x<9; x++) {
        for (int y=yStart; y<=yEnd; y++){
            if (t[y][x].valeur!=0) {
                if (!t[y][x].etat==2 || rechercheNombre(nombresTires,t[y][x].valeur)==0) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

//Genere une grille valide pour pouvoir tester autres fonctions (temporaire)
void genererTmp(TAB t) {
    t[1][0].etat = 1;
    t[1][0].valeur = 3;
    t[2][0].etat = 1;
    t[2][0].valeur = 8;
    t[0][1].etat = 1;
    t[0][1].valeur = 16;
    t[1][2].etat = 1;
    t[1][2].valeur = 22;
    t[2][2].etat = 1;
    t[2][2].valeur = 29;
    t[0][3].etat = 1;
    t[0][3].valeur = 35;
    t[0][4].etat = 1;
    t[0][4].valeur = 44;
    t[2][4].etat = 1;
    t[2][4].valeur = 42;
    t[1][5].etat = 1;
    t[1][5].valeur = 56;
    t[2][5].etat = 1;
    t[2][5].valeur = 54;
    t[0][6].etat = 1;
    t[0][6].valeur = 60;
    t[1][6].etat = 1;
    t[1][6].valeur = 66;
    t[2][7].etat = 1;
    t[2][7].valeur = 70;
    t[0][8].etat = 1;
    t[0][8].valeur = 88;
    t[1][8].etat = 1;
    t[1][8].valeur = 87;
}

//Tirage aleatoire d'un nombre entre min et max compris
int getRandom(int min, int max) {
    int random = (rand() % (max - min + 1)) + min;
    return random;
}

//Verifie si un nombre est present dans une grille    1 si vrai 0 sinon
int presenceNombreGrille(TAB t, int yStart, int yEnd, int nombre) {
}

//Verifie si la colonne où doit être place le nombre est deja pleine ou pas
int colonneRemplie(TAB t, int yStart, int yEnd, int nombre) {
}

//Genere une grille avec toutes les contraintes du loto   (retourne 1 si generation effectuée, 0 sinon)
int generer(TAB t, int yStart, int yEnd) { //yStart et yEnd entiers qui delimitent la partie du tableau a generer (ex 0 et 2 si une seule grille)
    if (yEnd - yStart == 2) { //verification car on genere une grille à la fois
        int cpt = 0; //nombre de nombres places dans la grille
        while (cpt<15) {
            int nbr = getRandom(1,90);
            if (presenceNombreGrille(t,yStart,yEnd,nbr)==0 && colonneRemplie(t,yStart,yEnd,nbr)==0) { //verifie si pas deja present dans la grille et si pas deja 3 nombres dans sa colonne
                //placer dans une ligne où il y moins de 5 valeurs
            }
        }
        return 1;
    } else {
        return 0;
    }
}

void loto() {
    srand(time(NULL)); // Necessaire pour la generation aleatoire (ligne a executer 1 seule fois)

    TAB t;
    init(9,9,t);
    genererTmp(t);
    affiche(t);

    /*
    int nombresTiresFaux[100] = {3,8,16,22,29,35,44,41,56,54,66,60,70,88,87}; //pour test verifierVictoire() pour un cas faux
    int nombresTiresVrai[100] = {3,8,16,22,29,35,44,42,56,54,66,60,70,88,87}; //pour test verifierVictoire() pour un cas vrai
    printf("pour vrai : %d\n",verifierVictoire(t,nombresTiresVrai,0,2));
    printf("pour faux : %d\n",verifierVictoire(t,nombresTiresFaux,0,2));
    */

}

