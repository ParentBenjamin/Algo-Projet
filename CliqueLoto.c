#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "InterfaceLoto.h"

SDL_Rect cliqueSourisLoto1(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, SDL_Event event, TAB t){

    if(event.button.x>1143 && event.button.x<1294 && event.button.y>670 && event.button.y<705)
    {
        positionFond.x = -1;
        positionFond.y = -1;
        return positionFond;
    }
    if(event.button.x>389 && event.button.x<406 && event.button.y>217 && event.button.y<255){
        positionFond = cliqueSourisLoto2(ecran,imageDeFond,positionFond,event,t,1);
    }
    if(event.button.x>684 && event.button.x<705 && event.button.y>218 && event.button.y<250){
        positionFond = cliqueSourisLoto2(ecran,imageDeFond,positionFond,event,t,2);
    }
    if(event.button.x>944 && event.button.x<967 && event.button.y>214 && event.button.y<249){
        positionFond = cliqueSourisLoto2(ecran,imageDeFond,positionFond,event,t,3);
    }
    return positionFond;
}


SDL_Rect cliqueSourisLoto2(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, SDL_Event event, TAB t, int choix){
    positionFond.x = 200;
    positionFond.y = 20;
    imageDeFond = SDL_LoadBMP("loto/blanc.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);
    positionFond.x = 400;
    positionFond.y = 50;
    imageDeFond = SDL_LoadBMP("loto/grille.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);
    if(choix==2 || choix==3){
        positionFond.x = 400;
        positionFond.y = 250;
        imageDeFond = SDL_LoadBMP("loto/grille.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
        if(choix==3){
            positionFond.x = 400;
            positionFond.y = 450;
            imageDeFond = SDL_LoadBMP("loto/grille.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
            SDL_Flip(ecran);
        }
    }
    while(positionFond.x>=0 && positionFond.y>=0)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_MOUSEBUTTONUP:
            {
                positionFond = cliqueSourisLoto3(ecran,imageDeFond,positionFond,event,t,choix);
                break;
            }
            default : break;
        }
    }
    return positionFond;
}

SDL_Rect cliqueSourisLoto3(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, SDL_Event event, TAB t, int choix){
    int longueur_case,hauteur_case,hauteur_grille;
    hauteur_grille = 0;
    for(int i=0;i<choix;i++)
    {
        hauteur_case = 0;
        for(int l=0;l<3;l++)
        {
            longueur_case = 0;
            for(int j=0;j<9;j++)
            {
                if(event.button.x>400+longueur_case && event.button.x<=460+longueur_case && event.button.y>50+hauteur_case+hauteur_grille && event.button.y<=110+hauteur_case+hauteur_grille)
                {
                    positionFond.x = event.button.x;
                    positionFond.y = event.button.y;
                    imageDeFond = SDL_LoadBMP("sudoku/1.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                    return positionFond;
                }
                longueur_case += 60;
            }
            hauteur_case +=60;
        }
        hauteur_grille += 200;
    }


    if(event.button.x>1143 && event.button.x<1294 && event.button.y>670 && event.button.y<705)
    {
        positionFond.x = -1;
        positionFond.y = -1;
    }
    return positionFond;
}
