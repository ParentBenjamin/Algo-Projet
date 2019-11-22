
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
    p.tableDeJeu[joueur].mise = p.tableDeJeu[joueur].argent;
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
            if (i == tour ) {                    // grosse blinde
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

int potTotale(Parti p,int n){
    int totale = 0;
    for (int i = 0; i < n; ++i) {
        totale += p.tableDeJeu[i].mise;
    }
    totale += p.pot;
    return totale;
}

int nombreAbbandon(Parti p, int n) {
    int nb = 0;
    for (int i = 0; i < n; ++i) {
        if (p.tableDeJeu[i].argent == 0){
            nb++;
        }
    }
    return nb;
}

int nombreCoucher(Parti p, int n){
    int nb = 0;
    for (int i = 0; i < n; ++i) {
        if (p.tableDeJeu[i].coucher == true){
            nb++;
        }
    }
    return nb;
}

bool prochaineMiseEgale (int numjoueur, Parti p , int n){
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






Parti tourJoueur(Parti p,int numerojoueur, int n){
    int choix,somme = 0;
    printf("carte une :%d , %d  /",p.tableDeJeu[numerojoueur].jeu[0].valeur,p.tableDeJeu[numerojoueur].jeu[0].etat);
    printf("carte deux %d ,%d",p.tableDeJeu[numerojoueur].jeu[1].valeur,p.tableDeJeu[numerojoueur].jeu[1].etat) ;
    printf("1 = fold, 2 = call, 3 = raise et 4 = all-in\n");
    scanf("%d",&choix);
    switch(choix){
        case 1: p = seCoucher(p, numerojoueur);
            break;
        case 2: p = Suivre(p, numerojoueur,n);
            break;
        case 3 :printf("quelle somme en plus de la mise :");
            scanf("%d",&somme);
            p = relancer(p,numerojoueur,somme,n);
            break;
        case 4 :p = tapis(p,numerojoueur);
        default :somme = quitterLaTable(&p,numerojoueur);
            break;
    }
    return p;

}

int tour(Parti* p, int n, int premier){
    int n1 = 0;
    while(((n1-1 >= n && !prochaineMiseEgale(((n1+premier)%n),*p,n)) || (n1-1 < n)) && (nombreCoucher(*p,n) < n-1)) {
        *p = tourJoueur(*p,n1%n,n);
        n1++;
        for (int i = 0; i < n; ++i) {
            printf("%d   ", p->tableDeJeu[i].mise);
        }
        printf("%d  %d",n1,nombreCoucher(*p,n));
    }
}

Parti tourPartie (Parti p , int n, Case t[5+2*n]){
    int numjoueur = 0;
    int i = 0;
    int joueurGagnant = 3;
    while(i<4 && nombreCoucher(p,n) < n-1) {
        numjoueur = tour(&p, n , numjoueur);
        //retourne les cartes
        i++;
    }
        // definie le joueur gagnant
        p = repartitionArgent(p ,joueurGagnant,n);
    return p;
}


void partie(){
    int n;
    int nombredeManche = 0;
    Parti p;
    printf("nombre de joueur : \n");
    scanf("%d", &n);
    Case t[2*n+5];
    p = initParti(n,p);
    while(nombreAbbandon(p,n) < n-1){
        initTirage(n,t);
        remplirTirage(n,t);
        p = distribution(n,t,p);
        printf("\n%d\n",maxMise(p,n));
        p = miseDepart(p,n,(nombredeManche%n));
        printf("\n%d\n",maxMise(p,n));
        p = tourPartie(p,n,t);
        nombredeManche++;
    }
}

