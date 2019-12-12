#include <stdlib.h>
#include <stdio.h>
//#include <windows.h>
#include <SDL/SDL.h>
#include <time.h>

#include "InterfaceSudoku.h"
#include "Menu.h"
#include "Grille.h"
#include "Sudoku.h"





/**Fonction qui ecrit les valeurs du tableaux dans l'interface graphique Sudoku*/
void ecrire(TAB t, SDL_Surface *ecran, SDL_Surface *imageDeFond){
    int i,j;
    SDL_Rect positionFond;
    positionFond.y = 131;
    for(i=0;i<9;i++){
        positionFond.x = 448;
        for(j=0;j<9;j++){
            if(t[i][j].valeur == 0){
                imageDeFond = SDL_LoadBMP("sudoku/vide(case).bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);

            }
            else if(t[i][j].etat == 0)
            {
                if(t[i][j].valeur == 1){
                    imageDeFond = SDL_LoadBMP("sudoku/1.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 2){
                    imageDeFond = SDL_LoadBMP("sudoku/2.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 3 && t[i][j].etat == 0){
                    imageDeFond = SDL_LoadBMP("sudoku/3.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 4 && t[i][j].etat == 0){
                    imageDeFond = SDL_LoadBMP("sudoku/4.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 5 && t[i][j].etat == 0){
                    imageDeFond = SDL_LoadBMP("sudoku/5.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 6 && t[i][j].etat == 0){
                    imageDeFond = SDL_LoadBMP("sudoku/6.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 7 && t[i][j].etat == 0){
                    imageDeFond = SDL_LoadBMP("sudoku/7.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 8 && t[i][j].etat == 0){
                    imageDeFond = SDL_LoadBMP("sudoku/8.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 9 && t[i][j].etat == 0){
                    imageDeFond = SDL_LoadBMP("sudoku/9.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
            }
            else if(t[i][j].etat == 1)
            {
                if(t[i][j].valeur == 1){
                    imageDeFond = SDL_LoadBMP("sudoku/1(rouge).bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 2){
                    imageDeFond = SDL_LoadBMP("sudoku/2(rouge).bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 3){
                    imageDeFond = SDL_LoadBMP("sudoku/3(rouge).bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 4){
                    imageDeFond = SDL_LoadBMP("sudoku/4(rouge).bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 5){
                    imageDeFond = SDL_LoadBMP("sudoku/5(rouge).bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 6){
                    imageDeFond = SDL_LoadBMP("sudoku/6(rouge).bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 7){
                    imageDeFond = SDL_LoadBMP("sudoku/7(rouge).bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 8){
                    imageDeFond = SDL_LoadBMP("sudoku/8(rouge).bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(t[i][j].valeur == 9){
                    imageDeFond = SDL_LoadBMP("sudoku/9(rouge).bmp");
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





void pause(int temps){
    SDL_Event event;
    time_t tempsFin = time(NULL) + (time_t)temps;
    while(time(NULL) < tempsFin){
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            default : break;
        }
    }
}






/**Fonction qui gère toute l'interface du sudoku*/
void interSudoku(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond){


    imageDeFond = SDL_LoadBMP("sudoku/tableau.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);

    int r;
    TAB t;
    int chiffre;

    //init(9,9,t);
    //remplirTEST(t);
    //chargerSudokuSpe(t,5);
    chargerSudoku(t,compterNombreLigneSudoku());
    ecrire(t,ecran,imageDeFond);

    Coordonees c;



    SDL_Event event;

    while(positionFond.x>=0 && positionFond.y>=0){
        if(tableauRempli(t))
        {
            positionFond.x = 162;
            positionFond.y = 269;
            imageDeFond = SDL_LoadBMP("sudoku/Victoire.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
            SDL_Flip(ecran);
            positionFond.x = 0;
            positionFond.y = 0;
        }
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_MOUSEBUTTONUP:
            {
                positionFond.x = event.button.x;
                positionFond.y = event.button.y;
                c = appuiTouche(positionFond);
                positionFond = cliqueSourisSudoku(ecran,imageDeFond,positionFond,event,t);
                break;
            }
            case SDL_KEYDOWN:
            {
                if(positionFond.x!=0 && positionFond.y!=0)
                {
                    if(event.key.keysym.sym == SDLK_BACKSPACE)
                    {
                        chiffre = 0;
                        c = appuiTouche(positionFond);
                        t[c.x-1][c.y-1].valeur = 0;
                        ecrire(t,ecran,imageDeFond);
                        event.button.x = positionFond.x;
                        event.button.y = positionFond.y;
                        positionFond = cliqueSourisSudoku(ecran,imageDeFond,positionFond,event,t);
                        break;
                    }
                    else if(event.key.keysym.sym == SDLK_KP1)
                    {
                        chiffre = 1;
                    }
                    else if(event.key.keysym.sym == SDLK_KP2)
                    {
                        chiffre = 2;
                    }
                    else if(event.key.keysym.sym == SDLK_KP3)
                    {
                        chiffre = 3;
                    }
                    else if(event.key.keysym.sym == SDLK_KP4)
                    {
                        chiffre = 4;
                    }
                    else if(event.key.keysym.sym == SDLK_KP5)
                    {
                        chiffre = 5;
                    }
                    else if(event.key.keysym.sym == SDLK_KP6)
                    {
                        chiffre = 6;
                    }
                    else if(event.key.keysym.sym == SDLK_KP7)
                    {
                        chiffre = 7;
                    }
                    else if(event.key.keysym.sym == SDLK_KP8)
                    {
                        chiffre = 8;
                    }
                    else if(event.key.keysym.sym == SDLK_KP9)
                    {
                        chiffre = 9;
                    }
                    else
                    {
                        break;
                    }
                    c = appuiTouche(positionFond);
                    r = modifCase2(c.x,c.y,chiffre,t);
                    if(r==1){
                        ecrire(t,ecran,imageDeFond);
                        event.button.x = positionFond.x;
                        event.button.y = positionFond.y;
                        positionFond = cliqueSourisSudoku(ecran,imageDeFond,positionFond,event,t);
                    }
                    else{
                        positionFond.x = 152;
                        positionFond.y = 269;
                        imageDeFond = SDL_LoadBMP("sudoku/mauvais_placement.bmp");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                        //Sleep(2000);
                        pause(2);
                        imageDeFond = SDL_LoadBMP("sudoku/vide(mauvais_placement).bmp");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                        positionFond.x = 0;
                        positionFond.y = 0;
                        ecrire(t,ecran,imageDeFond);
                    }
                }
                break;
            }
            default :
            break;
        }
    }
    if(positionFond.x == -2 && positionFond.y == -2){
        positionFond.x = 0;
        positionFond.y = 0;
        interSudoku(ecran,imageDeFond,positionFond);
    }
    if(positionFond.x == -1 && positionFond.y == -1){
        positionFond.x = 0;
        positionFond.y = 0;
        menuPrincipal(ecran,imageDeFond,positionFond);
    }
}
