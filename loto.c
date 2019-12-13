#include "loto.h"
#include "tiragee.h"

//mise a letat 3 de la case du tableu si le numéro est touché
void majetat (TAB t, int nbCartons, int nombre,int choix)
{
    if (nombreTrouve(t,nbCartons,nombre)&&choix==1)
    {
        int yEnd = nbCartons*3-1; //limite dans le tableau en fonction du nombre de cartons utilises
        int col;
        if (nombre==90)col = 8;
        else col = nombre/10;

        for (int i=0; i<=yEnd; i++) //on passe a letat 3 le nbre
        {
            if (t[i][col].valeur==nombre) changementEtat(i+1,col+1,t,3);
        }
    }
}

//calcul du score du joueur
/*si grille remplie : 200 - nbtirages (soit minimum 110 points = grille remplie) OK
donc une ligne = 37 points
si grille non remplie et partie terminée -> si 1 ligne : 110-74
					 -> si 2 lignes : 110-37
					 -> 0 ligne et 7 ou - numéros :0
					 -> 0 ligne et 8 ou + numéros :18
On fait ce calcul pour chaque grille et on fait une moyenne par rapport au nombre de grille*/


//fonction qui calcule le score pour une grille
int score(TAB t, int dep, Tirage tir)//la variable dep sert de numero de depart de ligne si premiere grille dep=0, si 2eme grille dep=3..
{
    int total;
    int somme;
    int nbligne=0;
    int nbnum=0;
    for(int i=dep;i<(dep+3);i++)//i = numero de ligne
    {
        somme=0;
        for(int j=0;j<9;j++)//j=numero de colonne
        {
            if(t[i][j].etat==2)somme=somme+1;//compte le nombre de numero sur la ligne
        }
        nbnum=nbnum+somme;//nbnum est le nombre de num touchés au total sur la grille
        if(somme==5)nbligne=nbligne +1;//la ligne est remplie
    }
    if(nbligne==3)total=200-tir.nbtirage;//la grille est remplie
    if(nbligne==2)total=73;
    if(nbligne==1)total=36;
    if(nbligne==0)
    {
        if (nbnum<=7)total=0;
        else if(nbnum>=8)total=18;
    }
    return total;
}

int scorefinal(TAB t,int nbCartons, Tirage tir)
{
    int res;
    if(nbCartons==1)res=score(t,0,tir);
    if(nbCartons==2)
    {
        int res1;
        int res2;
        res1=score(t,0,tir);
        res2=score(t,4,tir);
        res=(res1+res2)/2;
    }
    if(nbCartons==3)
    {
        int res1;
        int res2;
        int res3;
        res1=score(t,0,tir);
        res2=score(t,3,tir);
        res3=score(t,6,tir);
        res=(res1+res2+res3)/3;
    }
    return res;
}
//Verifie pour une, deux ou trois grilles qu'elles contiennent uniquement des nombres contenus dans le tableau des tirages effectues   1 si vrai    0 si faux
int verifierVictoire(TAB t, int nbCartons) {
    int yEnd = nbCartons*3-1;
    for (int y=0; y<=yEnd; y++){
        for (int x=0; x<9; x++) {
            if (t[y][x].valeur!=0 && t[y][x].etat!=2) { // si la case n est pas une case vide et que l'etat de la case n est pas "decouvert" (2) alors defaite donc faux
                return 0;
            }
        }
    }
    return 1;
}

//Verifie si un nombre est present dans une grille    1 si vrai 0 sinon
int estDejaPresent(TAB t, int yStart, int yEnd, int nombre, int col) {
    for (int i=yStart; i<=yEnd; i++) {
        if (t[i][col].valeur == nombre) {
                return 1;
        }
    }
    return 0;
}

//Verifie si la colonne où doit être place le nombre est pleine ou pas   1 si vrai 0 sinon
int colonneRemplie(TAB t, int yStart, int yEnd, int nombre, int col) {
    for (int i=yStart; i<=yEnd; i++) {
        if (t[i][col].valeur == 0) {
            return 0;
        }
    }
    return 1;
}

//compte le nombre de valeurs dans une ligne du tableau
int compter(TAB t, int ligne) {
    int cpt = 0;
    for (int i=0; i<9; i++) {
        if (t[ligne][i].valeur != 0) {
            cpt++;
        }
    }
    return cpt;
}

//retourne 1 si il y a une place disponible dans la colonne citee qui est valide, cad si la ligne ou la place se situe il y a moins de 5 valeurs
int placeDispoValide(TAB t, int yStart, int yEnd, int col) {
    for (int i=yStart; i<=yEnd; i++) {
        if (t[i][col].valeur==0 && compter(t, i)<5) {
            return 1;
        }
    }
    return 0;
}

//Genere une grille avec toutes les contraintes du loto   (retourne 1 si generation effectuée, 0 sinon)
int generer(TAB t, int yStart, int yEnd) { //yStart et yEnd entiers qui delimitent la partie du tableau a generer (ex 0 et 2 si une seule grille)
    if (yEnd - yStart == 2) { //verification car on genere une grille à la fois
        int cpt = 0; //nombre de nombres places dans la grille
        while (cpt<15) {
            int nbr = getRandom(1,90);
            int col;
            if (nbr==90) {
                col = 8;
            } else {
                col = nbr/10;
            }

            if (estDejaPresent(t, yStart, yEnd, nbr, col)==0 && colonneRemplie(t, yStart, yEnd, nbr, col)==0 && placeDispoValide(t, yStart, yEnd, col)==1) {
                int lig;
                do {
                    lig = getRandom(yStart, yEnd);
                }while (compter(t, lig)>=5 || t[lig][col].valeur != 0);
                modifValeur(lig+1,col+1,nbr,t);
                //changementEtat(lig+1,col+1,t,1);
                cpt++;
            }
        }
        return 1;
    } else {
        return 0;
    }
}

//genere le nombre de cartons demandes (par defaut 3)
int genererCartons(TAB t, int nbCartons) {
    switch(nbCartons) {
        case 1 :
            generer(t, 0, 2);
            break;
        case 2 :
            generer(t, 0, 2);
            generer(t, 3, 5);
            break;
        case 3 :
            generer(t, 0, 2);
            generer(t, 3, 5);
            generer(t, 6, 8);
            break;
        default :
            generer(t, 0, 2);
            generer(t, 3, 5);
            generer(t, 6, 8);
            break;
    }
}

//change l'etat d'un nombre a 2 si il est present dans les cartons t
int nombreTrouve(TAB t, int nbCartons, int nombre) {
    int found = 0;
    int yEnd = nbCartons*3-1; //limite dans le tableau en fonction du nombre de cartons utilises
    int col;
    if (nombre==90) {
        col = 8;
    } else {
        col = nombre/10;
    }

    for (int i=0; i<=yEnd; i++){
        if (t[i][col].valeur==nombre) {
            changementEtat(i+1,col+1,t,2);
            found = true;
        }
    }
    return found;
}

/*void loto() {
    srand(time(NULL)); // Necessaire pour la generation aleatoire (ligne a executer 1 seule fois)

    TAB tab;
    init(9,9,tab);
    Tirage t;
    initialisationTirage(&t);
    int numTirage; //numero du tirage actuel
    int choix; // choix du joueur
    int victoire = -1; //1 si victoire 0 defaite car pas tous les nums -1 defaite car tous les tirages ont ete effectues

    int nbCartons;
    do {
        printf("Combien de cartons de loto voulez-vous ? 1, 2 ou 3 ?\n");
        scanf("%d",&nbCartons);
    }while (nbCartons!=1 && nbCartons!=2 && nbCartons != 3);

    genererCartons(tab, nbCartons);

    printf("DEBUT DU JEU\n\n");

    while(t.nbtirage<90){
        //effectuer un tirage
        numTirage=numtire(&t);
        majtirage(numTirage,&t);
        printf("\nLe numero du Tirage est : %d\n\n",numTirage);
        //afficher le tableau
        affiche(tab);
        //demande du choix du joueur
        printf("\n0 : tirage suivant  |  1 : j'ai ce numero !  |  2 : j'ai gagne !\n");
        do {
            scanf("%d",&choix);
        }while (choix!=0 && choix!=1 && choix!=2);
        //traitement du choix
        if (choix==2) {
            victoire = verifierVictoire(tab, nbCartons); // A REVOIR
            break;
        } else if (choix==1) {
            if (nombreTrouve(tab, nbCartons, numTirage)==0) {
                printf("Vous n'avez pas le %d dans vos grilles !\n ", numTirage);
            }
        }
    }
    //Victoire ou defaire
    if (victoire == 1) {
        printf("VOUS AVEZ GAGNE !\n Nombre de tirages : %d", t.nbtirage);
    } else if (victoire == 0){
        printf("VOUS AVEZ PERDU !\n Vos cartons ne sont pas remplis !\n Nombre de tirages : %d", t.nbtirage);
    } else {
        printf("VOUS AVEZ PERDU !\n Tous les nombres ont ete tires !\nNombre de tirages : %d", t.nbtirage);
    }

    printf("\nFIN DU JEU\n\n");
}*/

