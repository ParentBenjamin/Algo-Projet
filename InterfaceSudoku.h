/*

    Head du fichier InterfaceSudoku.h

*/
#include "Grille.h"


#ifndef INTERFACESUDOKU_H_INCLUDED
#define INTERFACESUDOKU_H_INCLUDED

void interSudoku(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond);
int cliqueSouris(int continuer,SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, SDL_Event event,TAB t);
void ecrire(TAB t, SDL_Surface *ecran, SDL_Surface *imageDeFond);
#endif // INTERFACESUDOKU_H_INCLUDED
