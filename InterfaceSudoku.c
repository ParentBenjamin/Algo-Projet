#include <stdlib.h>
#include <stdio.h>
//#include <windows.h>
#include <SDL/SDL.h>
#include <time.h>

#include "InterfaceSudoku.h"
#include "Menu.h"
#include "Grille.h"
#include "Sudoku.h"

/*Fonction qui remplit la grille*/
void remplirTEST(TAB t){
    t[0][0].valeur = 5;
    t[0][1].valeur = 3;
    t[0][2].valeur = 4;
    t[0][3].valeur = 6;
    t[0][4].valeur = 7;
    t[0][5].valeur = 8;
    t[0][6].valeur = 9;
    t[0][7].valeur = 1;
    t[0][8].valeur = 2;

    t[1][0].valeur = 6;
    t[1][1].valeur = 7;
    t[1][2].valeur = 2;
    t[1][3].valeur = 1;
    t[1][4].valeur = 9;
    t[1][5].valeur = 5;
    t[1][6].valeur = 3;
    t[1][7].valeur = 4;
    t[1][8].valeur = 8;

    t[2][0].valeur = 1;
    t[2][1].valeur = 9;
    t[2][2].valeur = 8;
    t[2][3].valeur = 3;
    t[2][4].valeur = 4;
    t[2][5].valeur = 2;
    t[2][6].valeur = 5;
    t[2][7].valeur = 6;
    t[2][8].valeur = 7;

    t[3][0].valeur = 8;
    t[3][1].valeur = 5;
    t[3][2].valeur = 9;
    t[3][3].valeur = 7;
    t[3][4].valeur = 6;
    t[3][5].valeur = 1;
    t[3][6].valeur = 4;
    t[3][7].valeur = 2;
    t[3][8].valeur = 3;

    t[4][0].valeur = 4;
    t[4][1].valeur = 2;
    t[4][2].valeur = 6;
    t[4][3].valeur = 8;
    t[4][4].valeur = 5;
    t[4][5].valeur = 3;
    t[4][6].valeur = 7;
    t[4][7].valeur = 9;
    t[4][8].valeur = 1;

    t[5][0].valeur = 7;
    t[5][1].valeur = 1;
    t[5][2].valeur = 3;
    t[5][3].valeur = 9;
    t[5][4].valeur = 2;
    t[5][5].valeur = 4;
    t[5][6].valeur = 8;
    t[5][7].valeur = 5;
    t[5][8].valeur = 6;

    t[6][0].valeur = 9;
    t[6][1].valeur = 6;
    t[6][2].valeur = 1;
    t[6][3].valeur = 5;
    t[6][4].valeur = 3;
    t[6][5].valeur = 7;
    t[6][6].valeur = 2;
    t[6][7].valeur = 8;
    t[6][8].valeur = 4;

    t[7][0].valeur = 2;
    t[7][1].valeur = 8;
    t[7][2].valeur = 7;
    t[7][3].valeur = 4;
    t[7][4].valeur = 1;
    t[7][5].valeur = 9;
    t[7][6].valeur = 6;
    t[7][7].valeur = 3;
    t[7][8].valeur = 5;

    t[8][0].valeur = 3;
    t[8][1].valeur = 4;
    t[8][2].valeur = 5;
    t[8][3].valeur = 2;
    t[8][4].valeur = 8;
    t[8][5].valeur = 6;
    t[8][6].valeur = 0;
    t[8][7].valeur = 7;
    t[8][8].valeur = 9;




    t[0][0].etat = 1;
    t[0][1].etat = 1;
    t[0][2].etat = 0;
    t[0][3].etat = 0;
    t[0][4].etat = 1;
    t[0][5].etat = 0;
    t[0][6].etat = 0;
    t[0][7].etat = 0;
    t[0][8].etat = 0;

    t[1][0].etat = 1;
    t[1][1].etat = 0;
    t[1][2].etat = 0;
    t[1][3].etat = 1;
    t[1][4].etat = 1;
    t[1][5].etat = 1;
    t[1][6].etat = 0;
    t[1][7].etat = 0;
    t[1][8].etat = 0;

    t[2][0].etat = 0;
    t[2][1].etat = 1;
    t[2][2].etat = 1;
    t[2][3].etat = 0;
    t[2][4].etat = 0;
    t[2][5].etat = 0;
    t[2][6].etat = 0;
    t[2][7].etat = 1;
    t[2][8].etat = 0;

    t[3][0].etat = 1;
    t[3][1].etat = 0;
    t[3][2].etat = 0;
    t[3][3].etat = 0;
    t[3][4].etat = 1;
    t[3][5].etat = 0;
    t[3][6].etat = 0;
    t[3][7].etat = 0;
    t[3][8].etat = 1;

    t[4][0].etat = 1;
    t[4][1].etat = 0;
    t[4][2].etat = 0;
    t[4][3].etat = 1;
    t[4][4].etat = 0;
    t[4][5].etat = 1;
    t[4][6].etat = 0;
    t[4][7].etat = 0;
    t[4][8].etat = 1;

    t[5][0].etat = 1;
    t[5][1].etat = 0;
    t[5][2].etat = 0;
    t[5][3].etat = 0;
    t[5][4].etat = 1;
    t[5][5].etat = 0;
    t[5][6].etat = 0;
    t[5][7].etat = 0;
    t[5][8].etat = 1;

    t[6][0].etat = 0;
    t[6][1].etat = 1;
    t[6][2].etat = 0;
    t[6][3].etat = 0;
    t[6][4].etat = 0;
    t[6][5].etat = 0;
    t[6][6].etat = 1;
    t[6][7].etat = 1;
    t[6][8].etat = 0;

    t[7][0].etat = 0;
    t[7][1].etat = 0;
    t[7][2].etat = 0;
    t[7][3].etat = 1;
    t[7][4].etat = 1;
    t[7][5].etat = 1;
    t[7][6].etat = 0;
    t[7][7].etat = 0;
    t[7][8].etat = 1;

    t[8][0].etat = 0;
    t[8][1].etat = 0;
    t[8][2].etat = 0;
    t[8][3].etat = 0;
    t[8][4].etat = 1;
    t[8][5].etat = 0;
    t[8][6].etat = 0;
    t[8][7].etat = 1;
    t[8][8].etat = 1;
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






/*Fonction qui gère toute l'interface du sudoku*/
void interSudoku(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond){


    imageDeFond = SDL_LoadBMP("sudoku/tableau.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);

    int r;
    TAB t;
    int chiffre;
    //init(9,9,t);

    remplirTEST(t);
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
                positionFond = cliqueSouris(ecran,imageDeFond,positionFond,event,t);
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
                        positionFond = cliqueSouris(ecran,imageDeFond,positionFond,event,t);
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
                        positionFond = cliqueSouris(ecran,imageDeFond,positionFond,event,t);
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
    positionFond.x = 0;
    positionFond.y = 0;
    menuPrincipal(ecran,imageDeFond,positionFond);
}
