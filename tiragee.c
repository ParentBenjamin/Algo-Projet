#ifndef TIRAGE_C_INCLUDED
#define TIRAGE_C_INCLUDED
#include "tiragee.h"

void initialisation(Tirage *t) //initialistaion des tirages, nombre et tableau de tirage
{
    t->nbtirage=0;
    for (int i=0;i<100;i++)
    {
        t->tab[i]=0;
    }
}

void majtirage(int numtire, Tirage *t)//maj d'un trirage, on ajoute 1 au nb de tirage et on ajoute la valeur tiree au tableau
{
    t->nbtirage=t->nbtirage+1;
    t->tab[t->nbtirage-1]=numtire;
}

void affichagetableau(Tirage t)//affichage du tableau de tirage et du nombr de tirage effectues
{
    printf("Nombre de tirage = %d\n",t.nbtirage);
    printf("le tableau des tirages :");
    for(int i=0;i<t.nbtirage;i++)
    {
        printf(" %d |",t.tab[i]);
    }
    printf("\n");
}

int numtire(Tirage *t) //numero tiree aleatoirement
{
    int numero;
    numero = (rand()%99)+ 1; // tire un entier aléatoire entre 1 et 99
    for(int i=0;i<t->nbtirage;i++)
    {
        if(t->tab[i]==numero)return numtire(t); //si le numero a deja ete tire present dans le tableau on refait le tirage
    }
    return numero;
}

#endif // TIRAGE_C_INCLUDED
