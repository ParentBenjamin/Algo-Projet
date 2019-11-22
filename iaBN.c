#include "iaBN.h"
#include "tiragee.h"

//initialisation de l'IA
void initIA(IA *robot) {
    robot->etat = 0;
    robot->orientation = 0;
    robot->x_initial = 0;
    robot->y_initial = 0;
    robot->x_last = 0;
    robot->y_last = 0;
    robot->bateau = 0;
}

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

//Verifie si un tir est possible lors de la recherche de l'orientation    0 non , 1 oui
int tirPossible(TAB t, int r, int x, int y, int bateau) {
    int valide = 0;
    switch(r) {
        case 0:
            if ((x-1)>=0 && t[x-1][y].etat==0 && (t[x-1][y].valeur==0 || t[x-1][y].valeur==bateau)) {
                valide = 1;
            }
            break;
        case 1:
            if ((y+1)<=9 && t[x][y+1].etat==0 && (t[x][y+1].valeur==0 || t[x][y+1].valeur==bateau)) {
                valide = 1;
            }
            break;
        case 2:
            if ((x+1)<=9 && t[x+1][y].etat==0 && (t[x+1][y].valeur==0 || t[x+1][y].valeur==bateau)) {
                valide = 1;
            }
            break;
        case 3:
            if ((y-1)>=0 && t[x][y-1].etat==0 && (t[x][y-1].valeur==0 || t[x][y-1].valeur==bateau)) {
                valide = 1;
            }
            break;
        default:
            break;
    }
    return valide;
}

//tir IA
int tirIA(TAB t, IA *robot) {
    int retour = 0;
    int next = 0;
    do {
        int x, y;
        if ((*robot).etat == 0) {
            do {
                x = getRandom(1,9);
                y = getRandom(1,9);
            }while(t[x-1][y-1].etat != 0 ||(!(x%2==0 && y%2==0) && !(x%2!=0 && y%2!=0)));  //tir en damier
            x--;
            y--;

            //si pas touche
            if (t[x][y].valeur==0) {
                next = 1; //sortie de boucle
                t[x][y].etat = 1;
            } else { //si touche
                (*robot).bateau = t[x][y].valeur;
                (*robot).etat = 1;  // etat ia
                (*robot).x_initial = x;
                (*robot).y_initial = y;
                t[x][y].etat = 2;
            }

        }else if ((*robot).etat == 1) { //cherche orientation du bateau
            int r;
            do {
                r = getRandom(0,3); //0 : dessus, 1 droite, 2 bas, 3 gauche
            }while(tirPossible(t, r, (*robot).x_initial, (*robot).y_initial, (*robot).bateau)==0);

            switch(r) {
                case 0:
                    x = (*robot).x_initial-1;
                    y = (*robot).y_initial;
                    break;
                case 1:
                    x = (*robot).x_initial;
                    y = (*robot).y_initial+1;
                    break;
                case 2:
                    x = (*robot).x_initial+1;
                    y = (*robot).y_initial;
                    break;
                case 3:
                    x = (*robot).x_initial;
                    y = (*robot).y_initial-1;
                    break;
                default:
                    break;
            }


            //si pas touche
            if (t[x][y].valeur==0) {
                next = 1; //sortie de boucle
                t[x][y].etat = 1;
            } else { //si touche
                t[x][y].etat = 2;
                if (checkCoule(t, t[x][y].valeur)==1) { //si on coule on repart en tir damier
                    (*robot).etat = 0;
                } else {
                    (*robot).orientation = r;
                    (*robot).x_last = x;
                    (*robot).y_last = y;
                    (*robot).etat = 2;
                }
            }

        }else if ((*robot).etat == 2) {
            switch((*robot).orientation) {
                case 0:
                    x = (*robot).x_last-1;
                    y = (*robot).y_last;
                    break;
                case 1:
                    x = (*robot).x_last;
                    y = (*robot).y_last+1;
                    break;
                case 2:
                    x = (*robot).x_last+1;
                    y = (*robot).y_last;
                    break;
                case 3:
                    x = (*robot).x_last;
                    y = (*robot).y_last-1;
                    break;
                default:
                    break;
            }

            //si pas touche
            if (t[x][y].valeur==0) {
                next = 1; //sortie de boucle
                t[x][y].etat = 1;
                //orientation change pour terminer bateau
                if ((*robot).orientation==0 || (*robot).orientation==1) {
                    (*robot).orientation = (*robot).orientation + 2;
                } else {
                    (*robot).orientation = (*robot).orientation - 2;
                }
            } else { //si touche
                t[x][y].etat = 2;
                if (checkCoule(t, t[x][y].valeur)==1) { //si on coule on repart en tir damier
                    (*robot).etat = 0;
                } else { // touche mais pas coule
                    (*robot).x_last = x;
                    (*robot).y_last = y;
                }
            }
        }


        if (checkVictoire(t)==1) { //si victoire
            next = 1;
            retour = 1; //variable qui reprensent la victoire
        }

    }while (next==0);

    return retour;
}
