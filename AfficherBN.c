#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

#include "InterfaceBN.h"


/**Affiche la grille du bateau et les coups touchésou ratés*/
void ecrireBN(TAB t, SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, int etape){
    if(etape == 1){
        for(int i=0;i<9;i++){
            positionFond.x = 84;
            for(int j=0;j<9;j++){
                positionFond.x = 84;
                positionFond.y = 163;
                if(t[i][j].valeur == 1){
                    positionFond.x += j*50;
                    positionFond.y += i*50;
                    imageDeFond = SDL_LoadBMP("bn/carre-jaune.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 2){
                    positionFond.x += j*50;
                    positionFond.y += i*50;
                    imageDeFond = SDL_LoadBMP("bn/carre-vert.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 3){
                    positionFond.x += j*50;
                    positionFond.y += i*50;
                    imageDeFond = SDL_LoadBMP("bn/carre-rose.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 4){
                    positionFond.x += j*50;
                    positionFond.y += i*50;
                    imageDeFond = SDL_LoadBMP("bn/carre-rouge.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 5){
                    positionFond.x += j*50;
                    positionFond.y += i*50;
                    imageDeFond = SDL_LoadBMP("bn/carre-bleu.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
            }
        }
    }
    else{
        for(int i=0;i<9;i++){
            positionFond.x = 84;
            for(int j=0;j<9;j++){
                positionFond.x = 84;
                positionFond.y = 163;
                if(t[i][j].etat==1){
                    positionFond.x += j*50;
                    positionFond.y += i*50;
                    imageDeFond = IMG_Load("bn/point.png");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].etat==2 || t[i][j].etat==3){
                    positionFond.x += j*50;
                    positionFond.y += i*50;
                    imageDeFond = IMG_Load("bn/croix-noire.png");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                }
            }
        }
    }

