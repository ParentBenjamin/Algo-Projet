#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "Menu.h"
#include "InterfaceSudoku.h"

void menuPrincipal(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond){
    SDL_Event event; // La variable contenant l'événement
    int continuer = 1;
    imageDeFond = SDL_LoadBMP("menu.bmp");

    /* On blitte par-dessus l'écran */
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);

    while(continuer){
        SDL_WaitEvent(&event);
        switch(event.type) // On teste le type d'événement
        {
            case SDL_MOUSEBUTTONUP:
            {
                if(event.button.x>1007 && event.button.x<1335 && event.button.y>27 && event.button.y<72)
                {

                }
                else if(event.button.x>1185 && event.button.x<1347 && event.button.y>80 && event.button.y<119)
                {
                    interSudoku(ecran,imageDeFond,positionFond);
                    continuer = 0;
                    break;
                }
                else if(event.button.x>1220 && event.button.x<1344 && event.button.y>134 && event.button.y<173)
                {

                }
                else if(event.button.x>1244 && event.button.x<1346 && event.button.y>189 && event.button.y<228)
                {

                }
                else if(event.button.x>1199 && event.button.x<1354 && event.button.y>694 && event.button.y<724)
                {
                    continuer = 0;
                }
                break;
            }
            default :
            break;
        }
    }
}
