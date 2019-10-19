

#include "Grille.h"
#ifndef INTERFACELOTO_H_INCLUDED
#define INTERFACELOTO_H_INCLUDED

void interLoto(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond);
SDL_Rect cliqueSourisLoto1(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, SDL_Event event, TAB t);
SDL_Rect cliqueSourisLoto2(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, SDL_Event event, TAB t, int choix);
SDL_Rect cliqueSourisLoto3(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, SDL_Event event, TAB t, int choix);
#endif // INTERFACELOTO_H_INCLUDED
