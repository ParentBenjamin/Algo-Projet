

#include "Grille.h"
#include "tiragee.h"
#include "Menu.h"
#include "scores.h"
#ifndef INTERFACELOTO_H_INCLUDED
#define INTERFACELOTO_H_INCLUDED
/**Headers Loto*/
int interLoto(Tableau pseudo, SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond);
SDL_Rect cliqueSourisLoto1(Tableau pseudo, SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, SDL_Event event, TAB t);
SDL_Rect cliqueSourisLoto2(Tableau pseudo, SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, TAB t, int choix);
SDL_Rect cliqueSourisLoto3(Tirage tab, SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, SDL_Event event, TAB t, int choix);
void remplirTEST2(TAB t);
void ecrireLoto(TAB t, SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, int choix, Tirage tab);
Tirage suivant(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, TAB t, int choix, Tirage tab);
#endif // INTERFACELOTO_H_INCLUDED
