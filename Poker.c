
#include "Poker.h"

int nbAlea(int n){
    srand (time (NULL));
    return (rand() % n);
}

joueur initJoueur(){
    joueur j;
    j.argent = 1500;
    j.jeu[0].valeur=0;
    j.jeu[1].valeur=0;
    j.jeu[0].etat=0;
    j.jeu[1].etat=0;
    j.mise = 0;
    return j;
}

void initTirage( int n ,Case t[5+2*n]){
    for (int i = 0; i < 5+2*n; ++i) {
        t[i].etat = 0;
        t[i].valeur = 0;
    }
}

void initParti(int n,Parti p){
    for (int i = 0; i < 5; ++i) {
        p.river[i].etat = 0;
        p.river[i].valeur = 0;
    }
    for (int j = 0; j < n; ++j) {
        p.tableDeJeu[j] = initJoueur();
    }
    p.pot = 0;
}

void remplirTirage(int n ,Case t[5+2*n]){
    int valeur ,couleur;
    int i = 0;
    while (i < 5+n*2) {
        valeur = nbAlea(13) + 1;
        couleur = nbAlea(4) + 1;
        if (!appartient(valeur, couleur, i, t)){
            t[i].valeur = valeur;
            t[i].etat = couleur;
            i++;
        }
    }
}

bool appartient(int v, int c ,int n ,Case t[5+2*n]){
    for (int i = 0; i < n ; ++i) {
        if(t[i].etat == c && t[i].valeur == v) {
            return true;
        }
    }
    return false;
}

void distribution(int n, Case t[5+2*n], Parti p){  // donne toutes les cartes aux joueurs et a la river
    for (int i = 0; i < 5 ; ++i) {
        if (i < 5) {
            p.river[i] = t[i];
        }
    }
    for (int j = 0; j < 2*n; j+2) {
            p.tableDeJeu[j/2].jeu[1]= t[j];
            p.tableDeJeu[j/2].jeu[2]= t[j+1];
    }
}

int maxMise(Parti p){ // calcul la plus grandes mise actuel
    int max = 0;
    for (int i = 0; i < 5; ++i) {
            if (max < p.tableDeJeu[i].mise){
                max = p.tableDeJeu[i].mise;
            }
        }
    return max;
}


void Suivre(Parti p,int joueur){   // suit la plus haute mise
    int max = maxMise(p);
    int nouvelleMise = max - p.tableDeJeu[joueur].mise;
    if(nouvelleMise < p.tableDeJeu[joueur].argent){
        p.tableDeJeu[joueur].argent -= nouvelleMise;
        p.tableDeJeu[joueur].mise += nouvelleMise;
    }else {
        p.tableDeJeu[joueur].mise += p.tableDeJeu[joueur].argent;
        p.tableDeJeu[joueur].argent = 0;
    }
}

void tapis(Parti p , int joueur){               // permet au joueur de faire tapis
    p.tableDeJeu[joueur].mise = p.tableDeJeu[joueur].argent;
    p.tableDeJeu[joueur].argent = 0;
}

void ceCoucher(Parti p, int joueur){    // permet au joueur de se coucher
    p.pot += p.tableDeJeu[joueur].mise;
    p.tableDeJeu[joueur].mise = 0;
    p.tableDeJeu[joueur].coucher = true;
}

int relancer(Parti p ,int joueur, int somme ){   // permet de relancer du certaine somme mis en paramètre en plus de la mise max
    int max = maxMise(p);
    int nouvelleMise = max - p.tableDeJeu[joueur].mise;

    if(nouvelleMise + somme < p.tableDeJeu[joueur].argent){
        p.tableDeJeu[joueur].argent -= nouvelleMise + somme;
        p.tableDeJeu[joueur].mise += nouvelleMise + somme;
    }else {
        p.tableDeJeu[joueur].mise += p.tableDeJeu[joueur].argent;
        p.tableDeJeu[joueur].argent = 0;
    }

}

