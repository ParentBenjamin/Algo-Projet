#include "joueurBN.h"

//placement des bateaux par le joueur
int placementsDesBateauxJOUEUR(TAB t) {
    int x=0,y=0,orien=1;
    int error = 0; //booleen pour gerer affichage message erreur
    for (int i=5; i>1; i--) {
        //tant que coordonnees non valides (placement impossible)
        do {
            system("cls");
            affiche(t);
            if (error==1) {     //gestion de l'erreur si deuxieme(ou +) iteration du while
                printf("\n\nIMPOSSIBLE DE PLACER LE BATEAU ICI !!!");
            }
            //ecoute clavier
            printf("\n\nPLACEMENT Bateau taille %d\n",i);
            printf("x : ");
            scanf("%d", &x);
            x--;
            printf("y : ");
            scanf("%d", &y);
            y--;
            printf("orientation : ");
            scanf("%d", &orien);
            error = 1;
        }while(verifEmplacement(t, i, orien, x ,y)==0);
        error = 0;
        placerBateau(t, i, orien, x, y);
    }
    return 0;
}

//effectue un tir par le joueur
int tirJOUEUR(TAB t) {
    int retour = 0;
    int next = 0;
    do {
        int x,y;
        int error = 0;
        do {
            system("cls");
            affiche(t);
            printf("\n");
            afficheEtat(t);
            if (error == 1) {
                printf("\nMauvaises coordonnees !\n");
            }
            printf("\n\nTIR du JOUEUR\n");
            printf("x : ");
            scanf("%d", &x);
            x--;
            printf("y : ");
            scanf("%d", &y);
            y--;
            error = 1;
        }while (x<0 || x>8 || y<0 || y>8);

        if (t[x][y].valeur == 0) {
            t[x][y].etat = 1;
            next = 1;
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
