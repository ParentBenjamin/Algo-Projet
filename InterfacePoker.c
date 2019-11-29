#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "InterfacePoker.h"
#include "Menu.h"
#include "Poker.h"


int interPoker(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond){

    imageDeFond = SDL_LoadBMP("poker/pokerchoix.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);
    SDL_Event event;

     while(positionFond.x>=0 && positionFond.y>=0)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_MOUSEBUTTONUP:
            {
                if(event.button.x>1197 && event.button.x<1340 && event.button.y>704 && event.button.y<738){
                    return 0;
                }
                else if(event.button.x>351 && event.button.x<370 && event.button.y>144 && event.button.y<173){
                    int nombredeManche = 0;
                    Parti p;
                    Case t[2*2+5];
                    p = initParti(2,p);
                    cliqueSourisPoker(ecran,imageDeFond,positionFond,2, 0,0,p,t,1,0,0,0);
                    return 0;
                }
                else if(event.button.x>569 && event.button.x<588 && event.button.y>144 && event.button.y<173){
                    int nombredeManche = 0;
                    Parti p;
                    Case t[2*3+5];
                    p = initParti(3,p);
                    cliqueSourisPoker(ecran,imageDeFond,positionFond,3, 2,0,p,t,1,0,0,0);
                    return 0;
                }
                else if(event.button.x>785 && event.button.x<805 && event.button.y>144 && event.button.y<173){
                    int nombredeManche = 0;
                    Parti p;
                    Case t[2*4+5];
                    p = initParti(4,p);
                    cliqueSourisPoker(ecran,imageDeFond,positionFond,4, 2,0,p,t,1,0,0,0);
                    return 0;
                }
                else if(event.button.x>1007 && event.button.x<1027 && event.button.y>144 && event.button.y<173){
                    int nombredeManche = 0;
                    Parti p;
                    Case t[2*5+5];
                    p = initParti(5,p);
                    cliqueSourisPoker(ecran,imageDeFond,positionFond,5, 2,0,p,t,1,0,0,0);
                    return 0;
                }
            }
        }
    }
    return 0;

}


void afficherPoker(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, int nl, int nbTour, Parti p){
    char machaine[25];
    int monentier;
    SDL_Color color = {0, 0, 0};
    TTF_Font *police = TTF_OpenFont("font/arialunicode.ttf",50);
    if(nbTour>=1){
        nbTour+=2;
    for(int i=0;i<nbTour;i++){
    positionFond.x = 140+i*140;
    positionFond.y = 40;
    if(i>=3){
       imageDeFond = SDL_LoadBMP("poker/vert.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    imageDeFond = SDL_LoadBMP("poker/carte_blanche.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);
    positionFond.x = 177+i*140;
    monentier = p.river[i].valeur;
    sprintf(machaine,"%d",monentier);
    if(monentier == 10){
        positionFond.x = 165+i*140;
    }
    else if(monentier == 11){
        sprintf(machaine,"J");
        positionFond.x = 172+i*140;
    }
    else if(monentier == 12){
        sprintf(machaine,"Q");
        positionFond.x = 172+i*140;
    }
    else if(monentier == 13){
        sprintf(machaine,"K");
        positionFond.x = 172+i*140;
    }
    else if(monentier == 14){
        sprintf(machaine,"A");
        positionFond.x = 172+i*140;
    }

    imageDeFond = TTF_RenderText_Blended(police, machaine, color);
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
    SDL_Flip(ecran);

    positionFond.x = 167+i*140;
    positionFond.y = 110;
    if(p.river[i].etat == 1){
        imageDeFond = SDL_LoadBMP("poker/coeur.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(p.river[i].etat == 2){
        imageDeFond = SDL_LoadBMP("poker/pique.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(p.river[i].etat == 3){
        imageDeFond = SDL_LoadBMP("poker/carreau.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else{
        imageDeFond = SDL_LoadBMP("poker/trefle.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    }
    }
}

