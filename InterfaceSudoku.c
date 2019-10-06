#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "InterfaceSudoku.h"
#include "Menu.h"
#include "Grille.h"



void remplirTEST(TAB t){
    t[0][0].valeur = 1;
    t[1][0].valeur = 1;
    t[2][0].valeur = 2;
    t[3][0].valeur = 2;
    t[4][0].valeur = 2;
    t[5][0].valeur = 2;
    t[6][0].valeur = 2;
    t[7][0].valeur = 2;
    t[8][0].valeur = 2;

    t[0][1].valeur = 2;
    t[1][1].valeur = 2;
    t[2][1].valeur = 2;
    t[3][1].valeur = 2;
    t[4][1].valeur = 2;
    t[5][1].valeur = 2;
    t[6][1].valeur = 2;
    t[7][1].valeur = 2;
    t[8][1].valeur = 2;

    t[0][2].valeur = 2;
    t[1][2].valeur = 2;
    t[2][2].valeur = 2;
    t[3][2].valeur = 2;
    t[4][2].valeur = 2;
    t[5][2].valeur = 2;
    t[6][2].valeur = 2;
    t[7][2].valeur = 2;
    t[8][2].valeur = 2;

    t[0][3].valeur = 2;
    t[1][3].valeur = 2;
    t[2][3].valeur = 4;
    t[3][3].valeur = 2;
    t[4][3].valeur = 2;
    t[5][3].valeur = 2;
    t[6][3].valeur = 2;
    t[7][3].valeur = 2;
    t[8][3].valeur = 2;

    t[0][4].valeur = 2;
    t[1][4].valeur = 2;
    t[2][4].valeur = 2;
    t[3][4].valeur = 2;
    t[4][4].valeur = 2;
    t[5][4].valeur = 2;
    t[6][4].valeur = 2;
    t[7][4].valeur = 2;
    t[8][4].valeur = 0;

    t[0][5].valeur = 2;
    t[1][5].valeur = 0;
    t[2][5].valeur = 2;
    TAB[3][5].valeur = 2;
    TAB[4][5].valeur = 2;
    TAB[5][5].valeur = 2;
    TAB[6][5].valeur = 2;
    TAB[7][5].valeur = 2;
    TAB[8][5].valeur = 2;

    TAB[0][6].valeur = 0;
    TAB[1][6].valeur = 0;
    TAB[2][6].valeur = 0;
    TAB[3][6].valeur = 0;
    TAB[4][6].valeur = 0;
    TAB[5][6].valeur = 0;
    TAB[6][6].valeur = 0;
    TAB[7][6].valeur = 0;
    TAB[8][6].valeur = 0;

    TAB[0][7].valeur = 2;
    TAB[1][7].valeur = 0;
    TAB[2][7].valeur = 0;
    TAB[3][7].valeur = 2;
    TAB[4][7].valeur = 2;
    TAB[5][7].valeur = 9;
    TAB[6][7].valeur = 2;
    TAB[7][7].valeur = 2;
    TAB[8][7].valeur = 2;

    TAB[0][8].valeur = 2;
    TAB[1][8].valeur = 2;
    TAB[2][8].valeur = 8;
    TAB[3][8].valeur = 2;
    TAB[4][8].valeur = 2;
    TAB[5][8].valeur = 2;
    TAB[6][8].valeur = 6;
    TAB[7][8].valeur = 2;
    TAB[8][8].valeur = 9;
}




void ecrire(TAB t, SDL_Surface *ecran, SDL_Surface *imageDeFond){
    int i,j;
    SDL_Rect positionFond;
    positionFond.y = 131;
    for(i=0;i<9;i++){
        positionFond.x = 448;
        for(j=0;j<9;j++){
            if(t[i][j].valeur == 0){
                imageDeFond = SDL_LoadBMP("chiffres/vide.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);

            }
            if(t[i][j].valeur== 1){
                imageDeFond = SDL_LoadBMP("chiffres/1.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);

            }
            else if(t[i][j].valeur== 2){
                imageDeFond = SDL_LoadBMP("chiffres/2.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
            }
            else if(t[i][j].valeur== 3){
                imageDeFond = SDL_LoadBMP("chiffres/3.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
            }
            else if(t[i][j].valeur== 4){
                imageDeFond = SDL_LoadBMP("chiffres/4.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
            }
            else if(t[i][j].valeur== 5){
                imageDeFond = SDL_LoadBMP("chiffres/5.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
            }
            else if(t[i][j].valeur== 6){
                imageDeFond = SDL_LoadBMP("chiffres/6.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
            }
            else if(t[i][j].valeur== 7){
                imageDeFond = SDL_LoadBMP("chiffres/7.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
            }
            else if(t[i][j].valeur== 8){
                imageDeFond = SDL_LoadBMP("chiffres/8.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
            }
            else if(t[i][j].valeur== 9){
                imageDeFond = SDL_LoadBMP("chiffres/9.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
            }
            positionFond.x += 50;
        }
        positionFond.y += 50;
    }


positionFond.x = 0;
positionFond.y = 0;

}


void interSudoku(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond){


    imageDeFond = SDL_LoadBMP("tableau.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);


    TAB t;

    int init(int longueur , int largeur , TAB t);





    remplirTEST(t);
    ecrire(t,ecran,imageDeFond);

    int continuer = 1;
    SDL_Event event; // La variable contenant l'événement

    while(continuer){
        SDL_WaitEvent(&event);
        switch(event.type) // On teste le type d'événement
        {
            case SDL_MOUSEBUTTONUP:
            {
                continuer = cliqueSouris(continuer,ecran,imageDeFond,positionFond,event,t);
                break;
            }
            case SDL_KEYDOWN:
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_e:
                    {
                    imageDeFond = SDL_LoadBMP("zozor.bmp");
                    /* On blitte par-dessus l'écran */
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                    break;
                    }
                    default :
                        break;
                }
                    break;
            }
            default :
            break;
        }
    }
    positionFond.x = 0;
    positionFond.y = 0;
    menuPrincipal(ecran,imageDeFond,positionFond);
}
