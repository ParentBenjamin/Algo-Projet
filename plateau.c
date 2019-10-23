#include "plateau.h"

// dans la grille etat : 0 si rien, 1 a leau 2 touche
// dans la grille valeur : numero de la taille du bateau sinon 0
Joueur initialisationjoueur()
{
    Joueur j;
    j.nbcoule=0;
    return j;
}

int coule(int x, int y, TAB t)//retourne 1 si bateau coule 0 sinon
{
    int valeur = t[x][y].valeur;
    int nbtrouve=0;//stocke le nb de case trouve correspondante au bateau
    if(t[x][y-1].valeur==valeur || t[x][y+1].valeur==valeur)//si la case a gauche ou droite est la suite du bateau : orientation horizontale
    {
        for(int i=0;i<9;i++)
        {
            if(t[x][i].valeur == valeur)
            {
                if(t[x][i].etat==2)nbtrouve++;
            }
        }
    }
    if(t[x-1][y].valeur==valeur || t[x+1][y].valeur==valeur) //si la case en dessous/au dessus est la suite du bateau :orientation verticale
    {
        for(int j=0;j<9;j++)
        {
            if(t[j][y].valeur == valeur)
            {
                if(t[j][y].etat==2)nbtrouve++;
            }
        }
    }
    if(nbtrouve==valeur)return 1;
    else return 0;
}

int tir(TAB t, int x, int y, Joueur j)//0 si a l'eau, 1 si touche, 2 si coule
{
        if(t[x][y].valeur!=0)//il y a un bateau sur cette case
        {
            changementEtat(x,y,t,2);//on met letat a 2 : touche
            if(coule(x,y,t))
            {
                j.nbcoule++;
                return 2;//verifie si le bateau a ete coule ou non, retourne 2 si oui            }
            }
            else return 1;//sinon retourne 1 : il a ete touche
        }
        else //il n'y a pas de bateau sur la case : elle est libre
        {
            changementEtat(x,y,t,1);//on met letat a 1 : a leau
            return 0;
        }
}

bool victoire(Joueur j)
{
    if(j.nbcoule==5)return true;
    else return false;
}


void batailleNavale() {
    TAB tab;
    init(9,9,tab);
    printf("generation...");
    genererGrilleTMP(tab);
    printf("affichage :\n\n");
    affiche(tab);

    /*for (int i=5; i>1; i--) {
        printf("PLACEMENT Bateau taille %d\n",)
        scanf("%d", &x);
        scanf("%d", &y);
    }*/

}
