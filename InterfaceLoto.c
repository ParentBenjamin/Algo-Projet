#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

void interLoto(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond){

    imageDeFond = SDL_LoadBMP("bingo.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);
    while(1){



    }

}
