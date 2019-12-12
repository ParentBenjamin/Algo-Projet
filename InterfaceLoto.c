#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <time.h>


#include "InterfaceLoto.h"
#include "menu.h"
#include "loto.h"

/**Tirage suivant Loto*/
Tirage suivant(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, TAB t, int choix, Tirage tab){
    SDL_Color color = {255, 0, 0};
    TTF_Font *police = TTF_OpenFont("font/arialunicode.ttf",40);
    if(tab.nbtirage<90)
    {
        int numTirage;
        int monentier = tab.nbtirage+1;
        char machaine[4];
        sprintf(machaine,"%d",monentier);

        positionFond.x = 1130;
        positionFond.y = 400;
        imageDeFond = SDL_LoadBMP("loto/blanc2.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
        imageDeFond = TTF_RenderText_Blended(police, machaine, color);
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);


        numTirage=numtire(&tab);
        majtirage(numTirage,&tab);
        ecrireLoto(t,ecran,imageDeFond,positionFond,choix,tab);
    }
    else
    {
        positionFond.x = 100;
        positionFond.y = 250;
        if(verifierVictoire(t,choix))
        {
            imageDeFond = TTF_RenderText_Blended(police, "Gagné", color);
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
            SDL_Flip(ecran);
        }
        else
        {
            imageDeFond = TTF_RenderText_Blended(police, "Perdu", color);
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        }

    }
    return tab;
}








/**Fonction qui écrit les grilles du Loto*/
void ecrireLoto(TAB t, SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, int choix, Tirage tab){
    int y = 0;
    char machaine[4];
    int monentier;
    int i;
    int j;
    int c;

    positionFond.y = 120;
    positionFond.x = 1130;

    imageDeFond = SDL_LoadBMP("loto/blanc2.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);


   monentier = tab.tab[tab.nbtirage-1];
   sprintf(machaine,"%d",monentier);

    SDL_Color color = {255, 0, 0};
    TTF_Font *police = TTF_OpenFont("font/arialunicode.ttf",40);
    imageDeFond = TTF_RenderText_Blended(police, machaine, color);
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);


    for(c=0;c<choix;c++){
        positionFond.y = 60 + y;
        positionFond.x = 420;
        for(i=0+(c*3) ; i<3+(c*3) ; i++){
            if(t[i][0].valeur != 0){
                monentier = t[i][0].valeur;
                sprintf(machaine,"%d",monentier);
                if(t[i][0].etat == 2){
                    color.r = 255;
                    imageDeFond = TTF_RenderText_Blended(police, machaine, color);
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else{
                    color.r = 0;
                    imageDeFond = TTF_RenderText_Blended(police, machaine, color);
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);an
                    SDL_Flip(ecran);
                }
            }
             positionFond.y += 60;
        }

        positionFond.y = 60 + y;
       for(i=0+(c*3) ; i<3+(c*3) ; i++){
            positionFond.x = 470;
            for(j=1;j<9;j++){
                if(t[i][j].valeur != 0){
                    monentier = t[i][j].valeur;
                    sprintf(machaine,"%d",monentier);
                    if(t[i][j].etat == 2){
                        color.r = 255;
                        imageDeFond = TTF_RenderText_Blended(police, machaine, color);
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                    else{

                        color.r = 0;
                        imageDeFond = TTF_RenderText_Blended(police, machaine, color);
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                }
                positionFond.x += 60;
            }
            positionFond.y += 60;
        }
        y += 200;
   }
}

/**onction graphique Loto*/
int interLoto(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond){
    positionFond.x = 0;
    positionFond.y = 0;
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
                if(positionFond.x ==-2 && positionFond.y ==-2){
                    positionFond.x = 0;
                    positionFond.y = 0;
                    interLoto(ecran,imageDeFond,positionFond);
                    return 0;
                }
                break;
            }
            default : break;
        }
    }
    return 0;
}
