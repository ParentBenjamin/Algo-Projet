#ifndef INTERFACEPOKER_H_INCLUDED
#define INTERFACEPOKER_H_INCLUDED
#include "poker.h"
int interPoker(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond);
int cliqueSourisPoker(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, int nbJoueurs, int numeroJoueur, int nbManche, Parti p, Case t[2*nbJoueurs+5],int newMANCHE, int n1, int nbTour, int blind);
void ecrirePoker(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, int somme);
void afficherPoker(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, int somme, int nbTour, Parti p);
void ecrirePoker_2(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, int pot,Parti p, int numeroJoueur);
void finPoker(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, int nbJoueurs, int numeroJoueur, int nbManche, Parti p, Case t[2*nbJoueurs+5], int newManche, int n1, int nbTour, int blind);
#endif // INTERFACEPOKER_H_INCLUDED
