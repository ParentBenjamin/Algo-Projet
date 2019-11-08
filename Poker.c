
#include "Poker.h"

int nbAlea(int n){  //genere une valeur aleatoire entre 0 et n;
    srand (time (NULL));
    return (rand() % n);
}

void initJoueur(joueurPoker j){  //  initialise un joueur
    j.argent = 1500;
    j.jeu[0].valeur=0;
    j.jeu[1].valeur=0;
    j.jeu[0].etat=0;
    j.jeu[1].etat=0;
    j.mise = 0;
    j.coucher = false;
}

void initTirage( int n ,Case t[5+2*n]){  // initialise le tableau de tirage de toutes les cartes qui vont constituer une manche
    for (int i = 0; i < 5+2*n; ++i) {
        t[i].etat = 0;
        t[i].valeur = 0;
    }
}

void initParti(int n,Parti p){    // initialise la parti
    for (int i = 0; i < 5; ++i) {
        p.river[i].etat = 0;
        p.river[i].valeur = 0;
    }
    for (int j = 0; j < n; ++j) {
         initJoueur(p.tableDeJeu[j]);
    }
    p.pot = 0;
}

void remplirTirage(int n ,Case t[5+2*n]){    // Fait le tirage de toutes qui vont constituer une manche
    int valeur ,couleur;
    int i = 0;
    while (i < 5+n*2) {
        valeur = nbAlea(13) + 2;
        couleur = nbAlea(4) + 1;
        if (!appartient(valeur, couleur, i, t)){
            t[i].valeur = valeur;
            t[i].etat = couleur;
            i++;
        }
    }
}

bool appartient(int v, int c ,int n ,Case t[5+2*n]){   // verifie si la carte n'a pas deja etait sorti
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

void repartitionArgent (Parti p, int joueurGagnant){ // reparti l'argent entre chaque joueur en vérifiant ayant le joueur gagnant 
    if (p.tableDeJeu[joueurGagnant].mise < maxMise(p)){ //si le joueur gagnant a fait tapis et qu'il a miser moins que les autres
        for (int i = 0; i < 5; ++i) {
            if(i != joueurGagnant || p.tableDeJeu[i].coucher){
                p.tableDeJeu[i].mise -= p.tableDeJeu[joueurGagnant].mise;
                p.tableDeJeu[joueurGagnant].argent += p.tableDeJeu[joueurGagnant].mise;
                p.tableDeJeu[i].argent += p.tableDeJeu[i].mise;
                p.tableDeJeu[i].mise = 0;
            }
        }
        p.tableDeJeu[joueurGagnant].argent += p.pot;
        p.pot = 0;
        p.tableDeJeu[joueurGagnant].argent +=p.tableDeJeu[joueurGagnant].mise;
        p.tableDeJeu[joueurGagnant].mise = 0;
    }else {                                             // si le joueur gagnant a la mise la plus haute
        for (int i = 0; i < 5; ++i) {
            if(p.tableDeJeu[i].coucher){
                p.tableDeJeu[joueurGagnant].argent += p.tableDeJeu[i].mise;
                p.tableDeJeu[i].mise = 0;
            }
        }
        p.tableDeJeu[joueurGagnant].argent += p.pot;
        p.pot = 0;
    }
}

void miseDepart(Parti p, int n, int tour){ // la mise de chaque joueur au debut du tour avec 1 joueur qui a la grosse blinde et un qui a la petite blinde
    for (int i = 0; i < n; ++i) {
        if(i == tour%n){                    // grosse blinde 
            if(p.tableDeJeu[i].argent >= 100){    //si il n'a pas assez pour miser
                p.tableDeJeu[i].argent -= 100;
                p.tableDeJeu[i].mise = 100;
            }
            else {                              //si il a assez pour miser
                p.tableDeJeu[i].mise = p.tableDeJeu[i].argent;
                p.tableDeJeu[i].argent = 0;
            }
        }
        if(i == tour+1%n){                  // petite blinde
            if(p.tableDeJeu[i].argent >= 75){ //si il n'a pas assez pour miser
                p.tableDeJeu[i].argent -= 75;
                p.tableDeJeu[i].mise = 75;
            }
            else {                              //si il a assez pour miser
                p.tableDeJeu[i].mise = p.tableDeJeu[i].argent;
                p.tableDeJeu[i].argent = 0;
            }
        }
        else {                              //mise normale
            if(p.tableDeJeu[i].argent >= 50){  //si il n'a pas assez pour miser
                p.tableDeJeu[i].argent -= 50;
                p.tableDeJeu[i].mise = 50;
            }
            else {                              //si il a assez pour miser
                p.tableDeJeu[i].mise = p.tableDeJeu[i].argent;
                p.tableDeJeu[i].argent = 0;
            }
        }
    }
}

