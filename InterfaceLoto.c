#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "InterfaceLoto.h"
#include "menu.h"




void ecrireLoto(TAB t, SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, int choix){
   // for()





}



void interLoto(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond){

    imageDeFond = SDL_LoadBMP("loto/bingo.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);


    TAB t;
    SDL_Event event;

    while(positionFond.x>=0 && positionFond.y>=0)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_MOUSEBUTTONUP:
            {
                positionFond = cliqueSourisLoto1(ecran,imageDeFond,positionFond,event,t);
                break;
            }
            default : break;
        }
    }
    positionFond.x = 0;
    positionFond.y = 0;
    menuPrincipal(ecran,imageDeFond,positionFond);
}
