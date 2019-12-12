#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <windows.h>

#include "InterfaceBN.h"
#include "Grille.h"

/**Fonction qui s'active au clique de la souris dans al bataillle Navale*/
SDL_Rect cliqueSourisBN(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, SDL_Event event, TAB t, int etape, int typebateau){
    int longueur_case,hauteur_case = 0;
    SDL_Rect debut_grille;
    if(etape==1){
         imageDeFond = SDL_LoadBMP("bn/eau.bmp");
         SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
         SDL_Flip(ecran);
         debut_grille.x = 84;
         debut_grille.y = 163;
    }
    else if(etape==2){
        debut_grille.x = 841;
        debut_grille.y = 160;
    }
    for(int l=0;l<9;l++)
    {
        longueur_case = 0;
        for(int j=0;j<9;j++)
        {
            if(etape==1){
                debut_grille.x = 84;
                debut_grille.y = 163;
            }
            else{
                debut_grille.x = 841;
                debut_grille.y = 160;
            }
            if(event.button.x>debut_grille.x+longueur_case && event.button.x<=debut_grille.x+50+longueur_case && event.button.y>debut_grille.y+hauteur_case && event.button.y<=debut_grille.y+50+hauteur_case)
            {
                if(etape==1){
                if(t[l][j].valeur == 0){
                positionFond.x = debut_grille.x + j*50;
                positionFond.y = debut_grille.y + l*50;
                if(typebateau == 5){
                    imageDeFond = IMG_Load("bn/triangle-bleu-haut.png");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(typebateau == 4){
                    imageDeFond = IMG_Load("bn/triangle-rouge-haut.png");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(typebateau == 3){
                    imageDeFond = IMG_Load("bn/triangle-rose-haut.png");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(typebateau == 2){
                    imageDeFond = IMG_Load("bn/triangle-vert-haut.png");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else{
                    imageDeFond = IMG_Load("bn/triangle-jaune-haut.png");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                }
                }
                else if(etape==2){
                    positionFond.x = debut_grille.x + j*50;
                    positionFond.y = debut_grille.y + l*50;
                    if(t[l][j].valeur>0){
                        imageDeFond = IMG_Load("bn/croix-rouge.png");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                        t[l][j].etat=1;
                    }
                    else{
                        imageDeFond = IMG_Load("bn/point.png");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                }
                //t[l][j].valeur = 1;
                return positionFond;
            }
            longueur_case += 50;
        }
        hauteur_case +=50;
    }
    return positionFond;
}
