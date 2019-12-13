
#include "Poker.h"

int nbAlea2(int n){  //genere une valeur aleatoire entre 0 et n;
    return (rand() % n);
}

joueurPoker initJoueur(joueurPoker j){  //  initialise un joueur
    j.argent = 1500;
    j.jeu[0].valeur=0;
    j.jeu[1].valeur=0;
    j.jeu[0].etat=0;
    j.jeu[1].etat=0;
    j.mise = 0;
    j.coucher = false;
    return j;
}

void initTirage( int n ,Case t[5+2*n]){  // initialise le tableau de tirage de toutes les cartes qui vont constituer une manche
    for (int i = 0; i < 5+2*n; ++i) {
        t[i].etat = 0;
        t[i].valeur = 0;
    }
}

Parti initParti(int n,Parti p){    // initialise la parti
    for (int i = 0; i < 5; ++i) {
        p.river[i].etat = 0;
        p.river[i].valeur = 0;
    }
    for (int j = 0; j < n; ++j) {
        p.tableDeJeu[j] = initJoueur(p.tableDeJeu[j]);
    }
    p.pot = 0;
    return p;
}

void remplirTirage(int n ,Case t[5+2*n]){    // Fait le tirage de toutes qui vont constituer une manche
    int valeur ,couleur;
    int i = 0;
    srand(time(NULL));
    while (i < ((n*2)+5)) {
        valeur = nbAlea2(13) + 2;
        couleur = nbAlea2(4) + 1;
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

Parti distribution(int n, Case t[5+2*n], Parti p){  // donne toutes les cartes aux joueurs et a la river
    for (int i = 0; i < 5 ; ++i) {
            p.river[i] = t[i];
    }
    for (int j = 0; j < (2*n); j = j+2) {
            p.tableDeJeu[j/2].jeu[0]= t[j+5];
            p.tableDeJeu[j/2].jeu[1]= t[j+6];
    }
    return p;
}

int maxMise(Parti p,int n){ // calcul la plus grandes mise actuel
    int max = 0;
    for (int i = 0; i < n; ++i) {
            if (max < p.tableDeJeu[i].mise){
                max = p.tableDeJeu[i].mise;
            }
        }
    return max;
}

Parti Suivre(Parti p,int joueur,int n){   // suit la plus haute mise
    int max = maxMise(p,n);
    int nouvelleMise = max - p.tableDeJeu[joueur].mise;
    if(nouvelleMise < p.tableDeJeu[joueur].argent){
        p.tableDeJeu[joueur].argent -= nouvelleMise;
        p.tableDeJeu[joueur].mise += nouvelleMise;
    }else {
        p.tableDeJeu[joueur].mise += p.tableDeJeu[joueur].argent;
        p.tableDeJeu[joueur].argent = 0;
    }
    return p;
}

Parti tapis(Parti p , int joueur){               // permet au joueur de faire tapis
    p.tableDeJeu[joueur].mise += p.tableDeJeu[joueur].argent;
    p.tableDeJeu[joueur].argent = 0;
    return p;
}

Parti seCoucher(Parti p, int joueur){    // permet au joueur de se coucher
    p.pot += p.tableDeJeu[joueur].mise;
    p.tableDeJeu[joueur].mise = 0;
    p.tableDeJeu[joueur].coucher = true;
    return p;
}

Parti relancer(Parti p ,int joueur, int somme ,int n ){   // permet de relancer du certaine somme mis en paramètre en plus de la mise max
    int max = maxMise(p,n);
    int nouvelleMise = max - p.tableDeJeu[joueur].mise;

    if(nouvelleMise + somme < p.tableDeJeu[joueur].argent){
        p.tableDeJeu[joueur].argent -= nouvelleMise + somme;
        p.tableDeJeu[joueur].mise += nouvelleMise + somme;
    }else {
        p.tableDeJeu[joueur].mise += p.tableDeJeu[joueur].argent;
        p.tableDeJeu[joueur].argent = 0;
    }
    return p;

}

int quitterLaTable(Parti* p, int joueur){ // permet au joueur de quitter la table avec son argent
        int point;
        point = p->tableDeJeu[joueur].argent;
        p->tableDeJeu[joueur].argent = 0;
    return  point;
}

Parti repartitionArgent (Parti p, int joueurGagnant, int n){    // reparti l'argent entre chaque joueur en vérifiant ayant le joueur gagnant
    if (p.tableDeJeu[joueurGagnant].mise < maxMise(p,n)){   //si le joueur gagnant a fait tapis et qu'il a miser moins que les autres
        for (int i = 0; i < n; ++i) {
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
    }else {                                       // si le joueur gagnant a la mise la plus haute
        for (int i = 0; i < n; ++i) {
            if(p.tableDeJeu[i].coucher == false){
                p.tableDeJeu[joueurGagnant].argent += p.tableDeJeu[i].mise;
                p.tableDeJeu[i].mise = 0;
            }
        }
        p.tableDeJeu[joueurGagnant].argent += p.pot;
        p.pot = 0;
    }
    return p;
}

Parti repartitionEgaliter(Parti p, int n){  // en cas d'egaliter tous les joueurs qui ne se sont pas coucher récupere leur mise aussi qu'une partie du pot
    int nb = 0;
    for (int i = 0; i < n; ++i) {
        if(p.tableDeJeu[i].coucher == false){
            nb++;
            p.tableDeJeu[i].argent += p.tableDeJeu[i].mise;
            p.tableDeJeu[i].mise = 0;
        }
    }
    for (int j = 0; j < n ; ++j) {
        if(p.tableDeJeu[j].coucher == false){
            p.tableDeJeu[j].argent += p.pot/nb;
        }
    }
    p.pot = 0;
    return p;
}

Parti miseDepart(Parti p, int n, int tour){ // la mise de chaque joueur au debut du tour avec 1 joueur qui a la grosse blinde et un qui a la petite blinde
    for (int i = 0; i < n; ++i) {
        if (p.tableDeJeu[i].argent != 0) {
            if (i == tour ) {                    // petite blinde
                if (p.tableDeJeu[i].argent >= 75) {    //si il n'a pas assez pour miser
                    p.tableDeJeu[i].argent -= 75;
                    p.tableDeJeu[i].mise = 75;
                } else {                              //si il a assez pour miser
                    p.tableDeJeu[i].mise = p.tableDeJeu[i].argent;
                    p.tableDeJeu[i].argent = 0;
                }
            }
            else {
               if(n-1==tour){
                    if (p.tableDeJeu[0].argent >= 100) { //si il n'a pas assez pour miser
                        p.tableDeJeu[0].argent -= 100;
                        p.tableDeJeu[0].mise = 100;
                    } else {                              //si il a assez pour miser
                        p.tableDeJeu[0].mise = p.tableDeJeu[i].argent;
                        p.tableDeJeu[0].argent = 0;
                    }
                }
                 else if (i == tour + 1) {                  // petite blinde
                    if (p.tableDeJeu[i].argent >= 100) { //si il n'a pas assez pour miser
                        p.tableDeJeu[i].argent -= 100;
                        p.tableDeJeu[i].mise = 100;
                    } else {                              //si il a assez pour miser
                        p.tableDeJeu[i].mise = p.tableDeJeu[i].argent;
                        p.tableDeJeu[i].argent = 0;
                    }
                } else {                              //mise normale
                    if (p.tableDeJeu[i].argent >= 0) {  //si il n'a pas assez pour miser
                        p.tableDeJeu[i].argent -= 0;
                        p.tableDeJeu[i].mise = 0;
                    } else {                              //si il a assez pour miser
                        p.tableDeJeu[i].mise = p.tableDeJeu[i].argent;
                        p.tableDeJeu[i].argent = 0;
                    }
                }
            }
        }
    }
    return p;
}

int potTotale(Parti p,int n){  // somme des mises posées + le pot
    int totale = 0;
    for (int i = 0; i < n; ++i) {
        totale += p.tableDeJeu[i].mise;
    }
    totale += p.pot;
    return totale;
}

int nombreAbbandon(Parti p, int n) { // nombre de personne ne jouant plus sur les n de departs
    int nb = 0;
    for (int i = 0; i < n; ++i) {
        if (p.tableDeJeu[i].argent == 0){
            nb++;
        }
    }
    return nb;
}

int nombreCoucher(Parti p, int n){  // nombre de personne qui se sont couchées durant cette manche
    int nb = 0;
    for (int i = 0; i < n; ++i) {
        if (p.tableDeJeu[i].coucher == true){
            nb++;
        }
    }
    return nb;
}

bool prochaineMiseEgale (int numjoueur, Parti p , int n){ // regarde si la personne qui suit a la meme mise
    int i = 0;
    int joueurTest = (numjoueur+1)%n;
    bool misedifferent = true;
    while (i < n && misedifferent == true)  {
        if (p.tableDeJeu[joueurTest].coucher || (p.tableDeJeu[joueurTest].argent == 0 && p.tableDeJeu[joueurTest].mise == 0)) {
            joueurTest = (joueurTest+1)%n;
            i++;
        }  else {
            if (p.tableDeJeu[numjoueur].mise == p.tableDeJeu[joueurTest].mise) {
                i+=n;
            }else misedifferent = false;
        }
    }
    return  misedifferent;
}

//tri le tableau de cartes
void tri(Case t[5]) {
    Case min;
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            if (t[i].valeur > t[j].valeur) {
                min = t[i];
                t[i] = t[j];
                t[j] = min;
            }
        }
    }
}

bool memeCouleur(Case t[5]) {  // retourn vrai si toutes les carte sont de la meme couleur
    bool couleur = true;
    for (int i = 1; i < 5; ++i) {
        if (t[0].etat != t[i].etat) {
            couleur = false;
        }
    }
    return couleur;
}

int nombrePoint(Case t[5]) { //retorune le nombre de point selon la combinaison
    int point = 0;
    tri(t);
    if ((t[0].valeur == t[1].valeur - 1 && t[1].valeur == t[2].valeur - 1 && t[2].valeur == t[3].valeur - 1 &&    // Quinte
         t[3].valeur == t[4].valeur - 1 && memeCouleur(t))) {
        point = 8;
    } else {
        if (t[0].valeur == t[4].valeur || t[1].valeur == t[4].valeur) {  // Carré
            point = 7;
        } else {
            if ((t[0].valeur == t[2].valeur && t[3].valeur == t[4].valeur) ||    // Full
                (t[2].valeur == t[4].valeur && t[0].valeur == t[1].valeur)) {
                point = 6;
            } else {
                if (memeCouleur(t)) {  // Couleur
                    point = 5;
                } else {
                    if (t[0].valeur == t[1].valeur - 1 && t[1].valeur == t[2].valeur - 1 &&   // Suite
                        t[2].valeur == t[3].valeur - 1 && t[3].valeur == t[4].valeur - 1) {
                        point = 4;
                    } else if (t[0].valeur == t[2].valeur || t[2].valeur == t[4].valeur) {  // Brelan
                        point = 3;
                    } else {
                        if ((t[0].valeur == t[1].valeur &&              // Double paire
                             (t[2].valeur == t[3].valeur || t[3].valeur == t[4].valeur)) ||
                            (t[1].valeur == t[2].valeur && t[3].valeur == t[4].valeur)) {
                            point = 2;
                        } else {
                            if (t[0].valeur == t[1].valeur || t[1].valeur == t[2].valeur ||  // paire
                                t[2].valeur == t[3].valeur || t[3].valeur == t[4].valeur) {
                                point = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return point;
}
void meilleurCarteJoueur(Case t[2], Case t1[5], Case retour[5]) { //retourne les meilleur cartes d'un joueurs
    int sommemax = -1;
    int testsomme;
    Case test[5];
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j < 4; j++) {
            for (int k = 2; k < 5; k++) {
                if (j != i && k != j) {
                    test[0] = t1[i];
                    test[1] = t1[j];
                    test[2] = t1[k];
                    test[3] = t[0];
                    test[4] = t[1];
                    testsomme = nombrePoint(test);
                    if (sommemax < testsomme) {
                        sommemax = testsomme;
                        retour[0] = test[0];
                        retour[1] = test[1];
                        retour[2] = test[2];
                        retour[3] = test[3];
                        retour[4] = test[4];
                    }
                }
            }
        }
    }
    for (int l = 0; l < 2; l++) {
        for (int m = 1; m < 3; m++) {
            for (int n = 2; n < 4; n++) {
                for (int o = 3; o < 5; o++) {
                    for (int p = 0; p < 2; p++)
                        if (l != m && m != n && n != o) {
                            test[0] = t1[l];
                            test[1] = t1[m];
                            test[2] = t1[n];
                            test[3] = t1[o];
                            test[4] = t[p];
                            testsomme = nombrePoint(test);
                            if (sommemax < testsomme) {
                                sommemax = testsomme;
                                retour[0] = test[0];
                                retour[1] = test[1];
                                retour[2] = test[2];
                                retour[3] = test[3];
                                retour[4] = test[4];
                            }
                        }
                }
            }
        }
    }
}

int joueurGagnant(Parti p, int n) {
    int joueur = 0;
    int pointGagnant;
    int pointTest;
    Case carteGagnant[5];
    Case test[5];
    meilleurCarteJoueur(p.tableDeJeu[0].jeu, p.river, carteGagnant);
    for (int i = 1; i < n; ++i) {
        meilleurCarteJoueur(p.tableDeJeu[i].jeu, p.river, test);
        pointGagnant = nombrePoint(carteGagnant);
        pointTest = nombrePoint(test);
        if (pointGagnant < pointTest) {
            carteGagnant[0] = test[0];
            carteGagnant[1] = test[1];
            carteGagnant[2] = test[2];
            carteGagnant[3] = test[3];
            carteGagnant[4] = test[4];
            joueur = i;
        } else {
            if (pointGagnant == pointTest) {
                if (pointGagnant == 1) {
                    if (testeGagnantPaire(carteGagnant, test) == 1) {
                        joueur = i;
                    } else {
                        if (testeGagnantPaire(carteGagnant, test) == -1) {
                            joueur = -1;
                        }
                    }

                } else {
                    if (pointGagnant == 2) {
                        if (testdoublePaire(carteGagnant, test) == 1) {
                            joueur = i;
                        } else {
                            if (testdoublePaire(carteGagnant, test) == -1) {
                                joueur = -1;
                            }
                        }
                    }
                    else{
                        if (pointGagnant == 3 || pointGagnant == 6 || pointGagnant == 7){
                            if (testeGagnantBrelan(carteGagnant, test) == 1) {
                                joueur = i;
                            } else {
                                if (testeGagnantBrelan(carteGagnant, test) == -1) {
                                    joueur = -1;
                                }
                            }
                        }
                        else{
                            if (testeEgaliteSuite(carteGagnant, test) == 1) {
                                joueur = i;
                            } else {
                                if (testeEgaliteSuite(carteGagnant, test) == -1) {
                                    joueur = -1;
                                }
                            }
                        }
                    }
                }


            }
        }
    }
    return joueur;
}

int testdoublePaire(Case carteGagnant[5], Case test[5]) {
    if (carteGagnant[1].valeur <= test[1].valeur) {
        carteGagnant[0] = test[0];
        carteGagnant[1] = test[1];
        carteGagnant[2] = test[2];
        carteGagnant[3] = test[3];
        carteGagnant[4] = test[4];
        return 1;
    } else {
        if (carteGagnant[1].valeur >= test[1].valeur) {
            return 0;
        }
    }
    if (carteGagnant[3].valeur <= test[3].valeur) {
        carteGagnant[0] = test[0];
        carteGagnant[1] = test[1];
        carteGagnant[2] = test[2];
        carteGagnant[3] = test[3];
        carteGagnant[4] = test[4];
        return 1;
    } else {
        if (carteGagnant[3].valeur >= test[3].valeur) {
            return 0;
        }
    }
    return testeEgaliteSuite(carteGagnant, test);
}

int testeGagnantPaire(Case carteGagnant[5], Case test[5]) {
    if (carteGagnant[0].valeur == carteGagnant[1].valeur || carteGagnant[1].valeur == carteGagnant[2].valeur) {
        if (test[0].valeur == test[1].valeur || test[1].valeur == test[2].valeur) {
            if (carteGagnant[1].valeur <= test[1].valeur) {
                carteGagnant[0] = test[0];
                carteGagnant[1] = test[1];
                carteGagnant[2] = test[2];
                carteGagnant[3] = test[3];
                carteGagnant[4] = test[4];
                return 1;
            } else {
                if (carteGagnant[1].valeur == test[1].valeur) {
                    return testeEgaliteSuite(carteGagnant, test);
                }
            }
        } else {
            if (carteGagnant[1].valeur <= test[3].valeur || carteGagnant[1].valeur == test[3].valeur) {
                carteGagnant[0] = test[0];
                carteGagnant[1] = test[1];
                carteGagnant[2] = test[2];
                carteGagnant[3] = test[3];
                carteGagnant[4] = test[4];
                return 1;
            }
        }
    } else {
        if (test[0].valeur == test[1].valeur || test[1].valeur == test[2].valeur) {
            if (carteGagnant[3].valeur <= test[1].valeur) {
                carteGagnant[0] = test[0];
                carteGagnant[1] = test[1];
                carteGagnant[2] = test[2];
                carteGagnant[3] = test[3];
                carteGagnant[4] = test[4];
                return 1;
            }
        } else {
            if (carteGagnant[3].valeur <= test[3].valeur) {
                carteGagnant[0] = test[0];
                carteGagnant[1] = test[1];
                carteGagnant[2] = test[2];
                carteGagnant[3] = test[3];
                carteGagnant[4] = test[4];
                return 1;
            } else {
                if (carteGagnant[3].valeur == test[3].valeur) {
                    return testeEgaliteSuite(carteGagnant, test);
                }
            }
        }
    }

    return 0;
}

int testeGagnantBrelan(Case carteGagnant[5], Case test[5]) {
    if (carteGagnant[3].valeur <= test[3].valeur) {
        carteGagnant[0] = test[0];
        carteGagnant[1] = test[1];
        carteGagnant[2] = test[2];
        carteGagnant[3] = test[3];
        carteGagnant[4] = test[4];
        return 1;
    } else {
        return 0;
    }

}


int testeEgaliteSuite(Case carteGagnant[5], Case test[5]) {

    if (carteGagnant[0].valeur <= test[0].valeur) {
        carteGagnant[0] = test[0];
        carteGagnant[1] = test[1];
        carteGagnant[2] = test[2];
        carteGagnant[3] = test[3];
        carteGagnant[4] = test[4];
        return 1;
    } else {
        if (carteGagnant[0].valeur == test[0].valeur) {
            if (carteGagnant[1].valeur <= test[1].valeur) {
                carteGagnant[0] = test[0];
                carteGagnant[1] = test[1];
                carteGagnant[2] = test[2];
                carteGagnant[3] = test[3];
                carteGagnant[4] = test[4];
                return 1;
            } else {
                if (carteGagnant[1].valeur == test[1].valeur) {
                    if (carteGagnant[2].valeur <= test[2].valeur) {
                        carteGagnant[0] = test[0];
                        carteGagnant[1] = test[1];
                        carteGagnant[2] = test[2];
                        carteGagnant[3] = test[3];
                        carteGagnant[4] = test[4];
                        return 1;
                    } else {
                        if (carteGagnant[2].valeur == test[2].valeur) {
                            if (carteGagnant[3].valeur <= test[3].valeur) {
                                carteGagnant[0] = test[0];
                                carteGagnant[1] = test[1];
                                carteGagnant[2] = test[2];
                                carteGagnant[3] = test[3];
                                carteGagnant[4] = test[4];
                                return 1;
                            } else {
                                if (carteGagnant[3].valeur == test[3].valeur) {
                                    if (carteGagnant[4].valeur <= test[4].valeur) {
                                        carteGagnant[0] = test[0];
                                        carteGagnant[1] = test[1];
                                        carteGagnant[2] = test[2];
                                        carteGagnant[3] = test[3];
                                        carteGagnant[4] = test[4];
                                        return 1;
                                    } else {

                                        if (carteGagnant[4].valeur == test[4].valeur) {
                                            return -1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
}
