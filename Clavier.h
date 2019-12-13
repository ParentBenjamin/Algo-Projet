#ifndef CLAVIER_H_INCLUDED
#define CLAVIER_H_INCLUDED
typedef char Tableau[25] ;
int clavier(int choix, int i, Tableau pseudo, Tableau autre, SDL_Event event, SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond);
#endif // CLAVIER_H_INCLUDED
