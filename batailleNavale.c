#include "batailleNavale.h"
#include "grille.h"
#include "iaBN.h"

void sauvegarderjeu(TAB joueur, TAB ia, char *nom, Player p, int etape, int compt)//permet de sauvegarder la partie en cours dans un fichier
{
    int taillenbtir=1;
    FILE *f=NULL;
    f=fopen(nom,"w");//ouverture du fichier en ecriture
    if(f!=NULL)//si le fichier est bien ouvert
    {
        //copie de la grille valeur joueur
        for (int i=0; i<9 ; i++)
        {
            for (int j=0; j<9; j++)
            {
                fprintf(f,"%d",joueur[i][j].valeur);
            }
        }
        //copie de la grille etat joueur
        for (int i=0; i<9 ; i++)
        {
            for (int j=0; j<9; j++)
            {
                fprintf(f,"%d",joueur[i][j].etat);
            }
        }
        //copie de la grille valeur ia
        for (int i=0; i<9 ; i++)
        {
            for (int j=0; j<9; j++)
            {
                fprintf(f,"%d",ia[i][j].valeur);
            }
        }
        //copie de la grille etat ia
        for (int i=0; i<9 ; i++)
        {
            for (int j=0; j<9; j++)
            {
                fprintf(f,"%d",ia[i][j].etat);
            }
        }
        //sauvegarde du nombre de tir du joueur
       if(p.nbtir>9)taillenbtir=2;
       fprintf(f,"%d",taillenbtir);
       fprintf(f,"%d",p.nbtir);
       fprintf(f,"%d",etape);
       fprintf(f,"%d",compt);
    }
    else printf("erreur");//sinon affichage dune erreur
    fclose(f);//fermeture du fichier
}

int genererpartie(TAB chainejoueur, TAB chaineia, Player p)//recupere la partie a partie du fichier texte retourne nombre positif=numero etape ou nombre negatif=compteur si etape1
{
    int compt;//compteur pour le nbre de bateau
    int taille;//permet de recuperer la taille en nbre d'unite du nombre de tir du joueur
    int lire1;
    int lire2;
    int etape;//variable pour recuperer a quel moment a été arreté la partie
    FILE* fichier =NULL;
    fichier=fopen("SAUVEGARDEPARTIE.txt","r");//ouverture en lecture du fichier
    if(fichier!=NULL)
    {
        //copie valeur joueur
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                chainejoueur[i][j].valeur=(int)fgetc(fichier)-48;//le -48 permet de recuperer la bonne valeur cf code ASCII
        //copie etat joueur
        for(int k=0;k<9;k++)
            for(int l=0;l<9;l++)
                chainejoueur[k][l].etat=(int)fgetc(fichier)-48;
        //copie valeur ia
        for(int m=0;m<9;m++)
            for(int n=0;n<9;n++)
                chaineia[m][n].valeur=(int)fgetc(fichier)-48;
        //copie etat ia
        for(int o=0;o<9;o++)
            for(int p=0;p<9;p++)
                chaineia[o][p].etat=(int)fgetc(fichier)-48;
        taille=(int)fgetc(fichier)-48;//copie de la taille du nb tir
        if(taille==1)p.nbtir=(int)fgetc(fichier)-48;//copie du nombre de tir du joueur
        else
        {
            lire1=(int)fgetc(fichier)-48;
            lire2=(int)fgetc(fichier)-48;
            p.nbtir=lire1*10 + lire2;
        }
        etape=(int)fgetc(fichier)-48;//copie du numero detape pour savoir quand est ce que letape a ete arretee
        compt=(int)fgetc(fichier)-48;//copie du compteur : compteur qui sert a savoir combien de bateau a deja été placé
    }
    fclose(fichier);
    if(etape==2)return -compt;
    else return etape;
}

//Verifie victoire, renvoie 1 si true 0 false
int checkVictoire(TAB t) {
    int victoire = 1;
    for (int i=0; i<9 ; i++) {
        for (int j=0; j<9; j++) {
            if (t[i][j].valeur != 0 && t[i][j].etat != 3) {
                victoire = 0;
            }
        }
    }
    return victoire;
}
