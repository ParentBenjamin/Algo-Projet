#ifndef TIRAGE_C_INCLUDED
#define TIRAGE_C_INCLUDED
#include "tiragee.h"

void initialisationTirage(Tirage *t) //initialistaion des tirages, nombre et tableau de tirage
{
    t->nbtirage=0; //initialisation nb de tirage effectués
    for (int i=0;i<90;i++)
    {
        t->tab[i]=0;//initialisation des valeurs du tableau a 0
    }
}

void majtirage(int numtire, Tirage *t)//maj d'un tirage, on ajoute 1 au nb de tirage et on ajoute la valeur tiree au tableau
{
    t->nbtirage=t->nbtirage+1;
    t->tab[t->nbtirage-1]=numtire;
}


void affichagetableau(Tirage t)//affichage du tableau de tirage et du nombre de tirage effectues
{
    printf("Nombre de tirage = %d\n",t.nbtirage);
    printf("le tableau des tirages :");
    for(int i=0;i<t.nbtirage;i++)
    {
        printf(" %d |",t.tab[i]);
    }
    printf("\n");
}


//Tirage aleatoire d'un nombre entre min et max compris
int getRandom(int mini, int maxi) {
    int random = (rand() % (maxi - mini + 1)) + mini;
    return random;
}

int numtire(Tirage *t) //numero tiree aleatoirement
{
    int numero;
    numero = getRandom(1,90); // tire un entier aléatoire entre 1 et 90
    for(int i=0;i<t->nbtirage;i++)
    {
        if(t->tab[i]==numero)return numtire(t); //si le numero a deja ete tire present dans le tableau on refait le tirage
    }
    return numero;
}


void general()
{
    srand(time(NULL));//eviter la redondance des sequences d'aleatoire;
    Tirage t;//cree un tirage
    initialisationTirage(&t);//initialisation du tirage
    int num;
    for (int i=0;i<90;i++)//boucle pour effectuer les 90 tirages
    {
        num=numtire(&t);
        majtirage(num,&t);
        printf("Le numero est : %d\n",num);//affichage du numero tire
        Sleep(5000); //attente entre deux tirages de 5s
    }
    //affichagetableau(t);
}


#endif // TIRAGE_C_INCLUDED
