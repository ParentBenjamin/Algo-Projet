
#include "Sudoku.h"
int tableauRempli(TAB t){ //verifie si le tableau est rempli, le tableau est rempli quand toutes les case sont différentes de 0
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (t[i][j].valeur == 0){
                return 0;
            }
        }

    }
    return 1;
}
int modifCase(int x,int y,int valeur,TAB t){ //modifie la case par la valeur proposer si les coordonnées sont bonnes, l'etat le permert et si cette valeur n'est ni sur la ligne, ni la colonne, ni la case
    if(x < 10 && y < 10 && valeur < 10) {
        if (t[x - 1][y - 1].etat == 0 ){
            if (1 == verifCarre(t, x, y, valeur) && 1 == VerifColonne(t, x, y, valeur) && 1 == VerifLigne(t, x, y, valeur)) {

                modifValeur(x,y,valeur,t);
                return 1;
            }
            else printf("ne peut etre place ici\n");
        }
        else printf("case bloque\n");return 0;
    }
    else printf("probleme de coordonnées\n");return 0;
}

int modifCase2(int x,int y,int valeur,TAB t){ //modifie la case par la valeur proposer si les coordonnées sont bonnes, l'etat le permert et si cette valeur n'est ni sur la ligne, ni la colonne, ni la case
    if (1 == verifCarre(t, x, y, valeur) && 1 == VerifColonne(t, x, y, valeur) && 1 == VerifLigne(t, x, y, valeur)) {
        modifValeur(x,y,valeur,t);
        return 1;
    }
    //ne peut etre place ici
    return 0;
}

int verifCarre(TAB t ,int x,int y, int valeur){ //verifie a quelle carré(3*3) corresponde les coordonnées et si cette valeur est deja present dans le carré
    int i = 0,j = 0;
    i = coordonneeCarre(x);
    j = coordonneeCarre(y);
    for (int k = i*3-3; k < i*3 ; ++k) {
        for (int l = j*3-3; l < j*3; ++l) {
            if(!(k==x-1 && l == y-1)){
                if (t[k][l].valeur == valeur){
                    return 0;
                }
            }
        }
    }
    return 1;
}

int  VerifLigne(TAB t,int x ,int y , int valeur){ //verifie si la valeur entrer n'est pas deja dans la ligne de la case demande
    for (int i = 0; i < 9; ++i) {
        if(!(i==y-1)){
            if (t[x-1][i].valeur == valeur){
                return 0;
            }
        }
    }
    return 1;
}


int  VerifColonne(TAB t,int x ,int y , int valeur){ //verifie si la valeur entrer n'est pas deja dans la colonne de la case demande
    for (int i = 0; i < 9; ++i) {
        if(!(i==x-1)){
            if (t[i][y-1].valeur == valeur){
                return 0;
            }
        }
    }
    return 1;
}

int coordonneeCarre(int x){  // convertie le x ou le y pour le faire correspondre au carré
    if(x<4) return 1;
    if(x<7) return 2;
    return 3;
}

void sudoku(){ //main du sudoku en ligne de commande
    int n;
    int x;
    int y;
    int valeur;
    TAB t;
    int fini = 0;
    while (fini == 0){
        init(9,9,t);
        n =0;
        valeur = 1;
        while (valeur !=-1) { //si on rentre la valeur 0 la grille recommence
            affiche(t);
            printf("la ligne :\n");
            scanf("%d", &x);
            printf("la colonne :\n");
            scanf("%d", &y);
            printf("la valeur :\n");
            scanf("%d", &valeur);
            if (modifCase(x, y, valeur, t) == 1) {
                n++;
            }
            if(tableauRempli(t) == 1){
                fini = 1;
            }
        }

    }
}
