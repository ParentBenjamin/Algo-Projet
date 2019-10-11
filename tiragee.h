#ifndef TIRAGE_H_INCLUDED
#define TIRAGE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <windows.h>
typedef struct
{
    int nbtirage;
    int tab[100];
}Tirage;

void initialisation(Tirage *t);

void majtirage(int numtire, Tirage *t);

void affichagetableau(Tirage t);

int numtire(Tirage *t);

void general();//effectue l'initialisation et le tirage des 90 numéros aléatoirement avec un temps de 7s entre deux tirages.


#endif // TIRAGE_H_INCLUDED
