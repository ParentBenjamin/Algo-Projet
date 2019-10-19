#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>


#include "InterfacePoker.h"
#include "menu.h"


void interPoker(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond){

    imageDeFond = SDL_LoadBMP("loto/bingo.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);



}

//529 : 720
