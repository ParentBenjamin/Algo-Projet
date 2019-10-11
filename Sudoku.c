
#include "Sudoku.h"

int tableauRempli(TAB t){
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (t[i][j].valeur == 0){
                return 0;
            }
        }

    }
    return 1;
}
int modifCase(int x,int y,int valeur,TAB t){
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

int verifCarre(TAB t ,int x,int y, int valeur){
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

int  VerifLigne(TAB t,int x ,int y , int valeur){
    for (int i = 0; i < 9; ++i) {
        if(!(i==y-1)){
            if (t[x-1][i].valeur == valeur){
                return 0;
            }
        }
    }
    return 1;
}


int  VerifColonne(TAB t,int x ,int y , int valeur){
    for (int i = 0; i < 9; ++i) {
        if(!(i==x-1)){
            if (t[i][y-1].valeur == valeur){
                return 0;
            }
        }
    }
    //t[x-1][y-1].valeur = valeur;
    return 1;
}

int coordonneeCarre(int x){
    if(x<4) return 1;
    if(x<7) return 2;
    return 3;
}

void sudoku(){
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
        while (valeur !=0) { //si on rentre la valeur 0 la grille recommence
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
