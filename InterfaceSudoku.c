#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "InterfaceSudoku.h"
#include "Menu.h"
#include "Grille.h"


/*Fonction qui remplit la grille*/
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
    t[3][5].valeur = 2;
    t[4][5].valeur = 2;
    t[5][5].valeur = 2;
    t[6][5].valeur = 2;
    t[7][5].valeur = 2;
    t[8][5].valeur = 2;

    t[0][6].valeur = 0;
    t[1][6].valeur = 0;
    t[2][6].valeur = 0;
    t[3][6].valeur = 0;
    t[4][6].valeur = 0;
    t[5][6].valeur = 0;
    t[6][6].valeur = 0;
    t[7][6].valeur = 0;
    t[8][6].valeur = 0;

    t[0][7].valeur = 2;
    t[1][7].valeur = 0;
    t[2][7].valeur = 0;
    t[3][7].valeur = 2;
    t[4][7].valeur = 2;
    t[5][7].valeur = 9;
    t[6][7].valeur = 2;
    t[7][7].valeur = 2;
    t[8][7].valeur = 2;

    t[0][8].valeur = 2;
    t[1][8].valeur = 2;
    t[2][8].valeur = 8;
    t[3][8].valeur = 2;
    t[4][8].valeur = 2;
    t[5][8].valeur = 2;
    t[6][8].valeur = 6;
    t[7][8].valeur = 2;
    t[8][8].valeur = 9;




    t[0][0].etat = 1;
    t[1][0].etat = 1;
    t[2][0].etat = 1;
    t[3][0].etat = 0;
    t[4][0].etat = 0;
    t[5][0].etat = 0;
    t[6][0].etat = 0;
    t[7][0].etat = 0;
    t[8][0].etat = 0;

    t[0][1].etat = 0;
    t[1][1].etat = 0;
    t[2][1].etat = 0;
    t[3][1].etat = 0;
    t[4][1].etat = 0;
    t[5][1].etat = 0;
    t[6][1].etat = 0;
    t[7][1].etat = 0;
    t[8][1].etat = 0;

    t[0][2].etat = 0;
    t[1][2].etat = 0;
    t[2][2].etat = 0;
    t[3][2].etat = 0;
    t[4][2].etat = 0;
    t[5][2].etat = 0;
    t[6][2].etat = 0;
    t[7][2].etat = 0;
    t[8][2].etat = 0;

    t[0][3].etat = 0;
    t[1][3].etat = 0;
    t[2][3].etat = 0;
    t[3][3].etat = 0;
    t[4][3].etat = 0;
    t[5][3].etat = 0;
    t[6][3].etat = 0;
    t[7][3].etat = 0;
    t[8][3].etat = 0;

    t[0][4].etat = 0;
    t[1][4].etat = 0;
    t[2][4].etat = 0;
    t[3][4].etat = 0;
    t[4][4].etat = 0;
    t[5][4].etat = 0;
    t[6][4].etat = 0;
    t[7][4].etat = 0;
    t[8][4].etat = 0;

    t[0][5].etat = 0;
    t[1][5].etat = 0;
    t[2][5].etat = 0;
    t[3][5].etat = 0;
    t[4][5].etat = 0;
    t[5][5].etat = 0;
    t[6][5].etat = 0;
    t[7][5].etat = 0;
    t[8][5].etat = 0;

    t[0][6].etat = 1;
    t[1][6].etat = 0;
    t[2][6].etat = 0;
    t[3][6].etat = 0;
    t[4][6].etat = 1;
    t[5][6].etat = 0;
    t[6][6].etat = 0;
    t[7][6].etat = 0;
    t[8][6].etat = 1;

    t[0][7].etat = 0;
    t[1][7].etat = 0;
    t[2][7].etat = 0;
    t[3][7].etat = 0;
    t[4][7].etat = 0;
    t[5][7].etat = 0;
    t[6][7].etat = 0;
    t[7][7].etat = 0;
    t[8][7].etat = 0;

    t[0][8].etat = 0;
    t[1][8].etat = 0;
    t[2][8].etat = 0;
    t[3][8].etat = 0;
    t[4][8].etat = 0;
    t[5][8].etat = 0;
    t[6][8].etat = 0;
    t[7][8].etat = 0;
    t[8][8].etat = 0;
}



/*Fonction qui ecrit les valeurs du tableaux dans l'interface graphique*/
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
            else if(t[i][j].etat == 0)
            {
                if(t[i][j].valeur == 1){
                    imageDeFond = SDL_LoadBMP("chiffres/1.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 2){
                    imageDeFond = SDL_LoadBMP("chiffres/2.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 3 && t[i][j].etat == 0){
                    imageDeFond = SDL_LoadBMP("chiffres/3.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 4 && t[i][j].etat == 0){
                    imageDeFond = SDL_LoadBMP("chiffres/4.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 5 && t[i][j].etat == 0){
                    imageDeFond = SDL_LoadBMP("chiffres/5.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 6 && t[i][j].etat == 0){
                    imageDeFond = SDL_LoadBMP("chiffres/6.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 7 && t[i][j].etat == 0){
                    imageDeFond = SDL_LoadBMP("chiffres/7.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 8 && t[i][j].etat == 0){
                    imageDeFond = SDL_LoadBMP("chiffres/8.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 9 && t[i][j].etat == 0){
                    imageDeFond = SDL_LoadBMP("chiffres/9.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
            }
            else if(t[i][j].etat == 1)
            {
                if(t[i][j].valeur == 1){
                    imageDeFond = SDL_LoadBMP("chiffres/1(rouge).bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 2){
                    imageDeFond = SDL_LoadBMP("chiffres/2(rouge).bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 3 && t[i][j].etat == 0){
                    imageDeFond = SDL_LoadBMP("chiffres/3(rouge).bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 4 && t[i][j].etat == 0){
                    imageDeFond = SDL_LoadBMP("chiffres/4(rouge).bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 5 && t[i][j].etat == 0){
                    imageDeFond = SDL_LoadBMP("chiffres/5(rouge).bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 6 && t[i][j].etat == 0){
                    imageDeFond = SDL_LoadBMP("chiffres/6(rouge).bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 7 && t[i][j].etat == 0){
                    imageDeFond = SDL_LoadBMP("chiffres/7(rouge).bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 8 && t[i][j].etat == 0){
                    imageDeFond = SDL_LoadBMP("chiffres/8(rouge).bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 9 && t[i][j].etat == 0){
                    imageDeFond = SDL_LoadBMP("chiffres/9(rouge).bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
            }
            positionFond.x += 50;
        }
        positionFond.y += 50;
    }


positionFond.x = 0;
positionFond.y = 0;

}

/*Fonction qui gère toute l'interface du sudoku*/
void interSudoku(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond){


    imageDeFond = SDL_LoadBMP("tableau.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);


    TAB t;
    int chiffre;
    //init(9,9,t);

    remplirTEST(t);
    ecrire(t,ecran,imageDeFond);

    Coordonees c;



    SDL_Event event;

    while(positionFond.x>=0 && positionFond.y>=0){
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_MOUSEBUTTONUP:
            {
                positionFond.x = event.button.x;
                positionFond.y = event.button.y;
                c = appuiTouche(positionFond);
                if(t[c.x-1][c.y-1].etat == 0){
                    positionFond = cliqueSouris(ecran,imageDeFond,positionFond,event,t);
                }
                else{
                    positionFond.x = 0;
                    positionFond.y = 0;
                }
                break;
            }
            case SDL_KEYDOWN:
            {
                if(positionFond.x!=0 && positionFond.y!=0)
                {
                    if(event.key.keysym.sym == SDLK_BACKSPACE)
                    {
                        c = appuiTouche(positionFond);
                        chiffre = 0;
                    }
                    else if(event.key.keysym.sym == SDLK_KP1)
                    {
                        c = appuiTouche(positionFond);
                        chiffre = 1;
                    }
                    else if(event.key.keysym.sym == SDLK_KP2)
                    {
                        c = appuiTouche(positionFond);
                        chiffre = 2;
                    }
                    else if(event.key.keysym.sym == SDLK_KP3)
                    {
                        c = appuiTouche(positionFond);
                        chiffre = 3;
                    }
                    else if(event.key.keysym.sym == SDLK_KP4)
                    {
                        c = appuiTouche(positionFond);
                        chiffre = 4;
                    }
                    else if(event.key.keysym.sym == SDLK_KP5)
                    {
                        c = appuiTouche(positionFond);
                        chiffre = 5;
                    }
                    else if(event.key.keysym.sym == SDLK_KP6)
                    {
                        c = appuiTouche(positionFond);
                        chiffre = 6;
                    }
                    else if(event.key.keysym.sym == SDLK_KP7)
                    {
                        c = appuiTouche(positionFond);
                        chiffre = 7;
                    }
                    else if(event.key.keysym.sym == SDLK_KP8)
                    {
                        c = appuiTouche(positionFond);
                        chiffre = 8;
                    }
                    else if(event.key.keysym.sym == SDLK_KP9)
                    {
                        c = appuiTouche(positionFond);
                        chiffre = 9;
                    }
                    else
                    {
                        break;
                    }
                    modifValeur(c.x,c.y,chiffre,t);
                    ecrire(t,ecran,imageDeFond);
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
