#include "Grille.h"
#ifndef INTERFACEBN_H_INCLUDED
#define INTERFACEBN_H_INCLUDED

int interBN(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond);
void ecrireBN(TAB t, SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, int etape);
SDL_Rect cliqueSourisBN(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, SDL_Event event, TAB t, int etape, int typebateau);
#endif // INTERFACEBN_H_INCLUDED


