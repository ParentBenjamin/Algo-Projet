#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "InterfaceSudoku.h"
#include "Menu.h"
#include "Grille.h"



void remplirTEST(int TAB[9][9]){
    TAB[0][0] = 1;
    TAB[1][0] = 1;
    TAB[2][0] = 2;
    TAB[3][0] = 2;
    TAB[4][0] = 2;
    TAB[5][0] = 2;
    TAB[6][0] = 2;
    TAB[7][0] = 2;
    TAB[8][0] = 2;

    TAB[0][1] = 2;
    TAB[1][1] = 2;
    TAB[2][1] = 2;
    TAB[3][1] = 2;
    TAB[4][1] = 2;
    TAB[5][1] = 2;
    TAB[6][1] = 2;
    TAB[7][1] = 2;
    TAB[8][1] = 2;

    TAB[0][2] = 2;
    TAB[1][2] = 2;
    TAB[2][2] = 2;
    TAB[3][2] = 2;
    TAB[4][2] = 2;
    TAB[5][2] = 2;
    TAB[6][2] = 2;
    TAB[7][2] = 2;
    TAB[8][2] = 2;

    TAB[0][3] = 2;
    TAB[1][3] = 2;
    TAB[2][3] = 4;
    TAB[3][3] = 2;
    TAB[4][3] = 2;
    TAB[5][3] = 2;
    TAB[6][3] = 2;
    TAB[7][3] = 2;
    TAB[8][3] = 2;

    TAB[0][4] = 2;
    TAB[1][4] = 2;
    TAB[2][4] = 2;
    TAB[3][4] = 2;
    TAB[4][4] = 2;
    TAB[5][4] = 2;
    TAB[6][4] = 2;
    TAB[7][4] = 2;
    TAB[8][4] = 0;

    TAB[0][5] = 2;
    TAB[1][5] = 0;
    TAB[2][5] = 2;
    TAB[3][5] = 2;
    TAB[4][5] = 2;
    TAB[5][5] = 2;
    TAB[6][5] = 2;
    TAB[7][5] = 2;
    TAB[8][5] = 2;

    TAB[0][6] = 0;
    TAB[1][6] = 0;
    TAB[2][6] = 0;
    TAB[3][6] = 0;
    TAB[4][6] = 0;
    TAB[5][6] = 0;
    TAB[6][6] = 0;
    TAB[7][6] = 0;
    TAB[8][6] = 0;

    TAB[0][7] = 2;
    TAB[1][7] = 0;
    TAB[2][7] = 0;
    TAB[3][7] = 2;
    TAB[4][7] = 2;
    TAB[5][7] = 9;
    TAB[6][7] = 2;
    TAB[7][7] = 2;
    TAB[8][7] = 2;

    TAB[0][8] = 2;
    TAB[1][8] = 2;
    TAB[2][8] = 8;
    TAB[3][8] = 2;
    TAB[4][8] = 2;
    TAB[5][8] = 2;
    TAB[6][8] = 6;
    TAB[7][8] = 2;
    TAB[8][8] = 9;

}




void ecrire(int TAB[9][9], SDL_Surface *ecran, SDL_Surface *imageDeFond){
    int i,j;
    SDL_Rect positionFond;
    positionFond.y = 131;
    for(i=0;i<9;i++){
        positionFond.x = 448;
        for(j=0;j<9;j++){
            if(TAB[i][j]== 0){
                imageDeFond = SDL_LoadBMP("chiffres/vide.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);

            }
            if(TAB[i][j]== 1){
                imageDeFond = SDL_LoadBMP("chiffres/1.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);

            }
            else if(TAB[i][j]== 2){
                imageDeFond = SDL_LoadBMP("chiffres/2.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
            }
            else if(TAB[i][j]== 3){
                imageDeFond = SDL_LoadBMP("chiffres/3.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
            }
            else if(TAB[i][j]== 4){
                imageDeFond = SDL_LoadBMP("chiffres/4.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
            }
            else if(TAB[i][j]== 5){
                imageDeFond = SDL_LoadBMP("chiffres/5.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
            }
            else if(TAB[i][j]== 6){
                imageDeFond = SDL_LoadBMP("chiffres/6.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
            }
            else if(TAB[i][j]== 7){
                imageDeFond = SDL_LoadBMP("chiffres/7.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
            }
            else if(TAB[i][j]== 8){
                imageDeFond = SDL_LoadBMP("chiffres/8.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
            }
            else if(TAB[i][j]== 9){
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


    remplirTEST(TAB);
    ecrire(TAB,ecran,imageDeFond);

    int continuer = 1;
    SDL_Event event; // La variable contenant l'événement

    while(continuer){
        SDL_WaitEvent(&event);
        switch(event.type) // On teste le type d'événement
        {
            case SDL_MOUSEBUTTONUP:
            {
                positionFond.x = 0;
                positionFond.y = 0;
                /*Ligne 1*/
                if(event.button.x>448 && event.button.x<492 && event.button.y>132 && event.button.y<173)
                {
                    //1
                    positionFond.x = 488;
                    positionFond.y = 132;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>498 && event.button.x<542 && event.button.y>132 && event.button.y<173)
                {
                    //2
                    positionFond.x = 538;
                    positionFond.y = 132;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>548 && event.button.x<592 && event.button.y>132 && event.button.y<173)
                {
                    //3
                    positionFond.x = 588;
                    positionFond.y = 132;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>598 && event.button.x<642 && event.button.y>132 && event.button.y<173)
                {
                    //4
                    positionFond.x = 638;
                    positionFond.y = 132;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>648 && event.button.x<692 && event.button.y>132 && event.button.y<173)
                {
                    //5
                    positionFond.x = 688;
                    positionFond.y = 132;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>698 && event.button.x<742 && event.button.y>132 && event.button.y<173)
                {
                    //6
                    positionFond.x = 738;
                    positionFond.y = 132;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>748 && event.button.x<792 && event.button.y>132 && event.button.y<173)
                {
                    //7
                    positionFond.x = 788;
                    positionFond.y = 132;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>798 && event.button.x<842 && event.button.y>132 && event.button.y<173)
                {
                    //8
                    positionFond.x = 838;
                    positionFond.y = 132;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>848 && event.button.x<892 && event.button.y>132 && event.button.y<173)
                {
                    //9
                    positionFond.x = 888;
                    positionFond.y = 132;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }



                /*Ligne 2*/
                else if(event.button.x>448 && event.button.x<492 && event.button.y>182 && event.button.y<223)
                {
                    //1
                    positionFond.x = 488;
                    positionFond.y = 182;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>498 && event.button.x<542 && event.button.y>182 && event.button.y<223)
                {
                    //2
                    positionFond.x = 538;
                    positionFond.y = 182;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>548 && event.button.x<592 && event.button.y>182 && event.button.y<223)
                {
                    //3
                    positionFond.x = 588;
                    positionFond.y = 182;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>598 && event.button.x<642 && event.button.y>182 && event.button.y<223)
                {
                    //4
                    positionFond.x = 638;
                    positionFond.y = 182;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>648 && event.button.x<692 && event.button.y>182 && event.button.y<223)
                {
                    //5
                    positionFond.x = 688;
                    positionFond.y = 182;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>698 && event.button.x<742 && event.button.y>182 && event.button.y<223)
                {
                    //6
                    positionFond.x = 738;
                    positionFond.y = 182;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>748 && event.button.x<792 && event.button.y>182 && event.button.y<223)
                {
                    //7
                    positionFond.x = 788;
                    positionFond.y = 182;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>798 && event.button.x<842 && event.button.y>182 && event.button.y<223)
                {
                    //8
                    positionFond.x = 838;
                    positionFond.y = 182;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>848 && event.button.x<892 && event.button.y>182 && event.button.y<223)
                {
                    //9
                    positionFond.x = 888;
                    positionFond.y = 182;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }

                /*Ligne 3*/
                else if(event.button.x>448 && event.button.x<492 && event.button.y>232 && event.button.y<273)
                {
                    //1
                    positionFond.x = 488;
                    positionFond.y = 232;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>498 && event.button.x<542 && event.button.y>232 && event.button.y<273)
                {
                    //2
                    positionFond.x = 538;
                    positionFond.y = 232;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>548 && event.button.x<592 && event.button.y>232 && event.button.y<273)
                {
                    //3
                    positionFond.x = 588;
                    positionFond.y = 232;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>598 && event.button.x<642 && event.button.y>232 && event.button.y<273)
                {
                    //4
                    positionFond.x = 638;
                    positionFond.y = 232;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>648 && event.button.x<692 && event.button.y>232 && event.button.y<273)
                {
                    //5
                    positionFond.x = 688;
                    positionFond.y = 232;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>698 && event.button.x<742 && event.button.y>232 && event.button.y<273)
                {
                    //6
                    positionFond.x = 738;
                    positionFond.y = 232;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>748 && event.button.x<792 && event.button.y>232 && event.button.y<273)
                {
                    //7
                    positionFond.x = 788;
                    positionFond.y = 232;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>798 && event.button.x<842 && event.button.y>232 && event.button.y<273)
                {
                    //8
                    positionFond.x = 838;
                    positionFond.y = 232;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>848 && event.button.x<892 && event.button.y>232 && event.button.y<273)
                {
                    //9
                    positionFond.x = 888;
                    positionFond.y = 232;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }

                /*Ligne 4*/
                else if(event.button.x>448 && event.button.x<492 && event.button.y>282 && event.button.y<323)
                {
                    //1
                    positionFond.x = 488;
                    positionFond.y = 282;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>498 && event.button.x<542 && event.button.y>282 && event.button.y<323)
                {
                    //2
                    positionFond.x = 538;
                    positionFond.y = 282;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>548 && event.button.x<592 && event.button.y>282 && event.button.y<323)
                {
                    //3
                    positionFond.x = 588;
                    positionFond.y = 282;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>598 && event.button.x<642 && event.button.y>282 && event.button.y<323)
                {
                    //4
                    positionFond.x = 638;
                    positionFond.y = 282;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>648 && event.button.x<692 && event.button.y>282 && event.button.y<323)
                {
                    //5
                    positionFond.x = 688;
                    positionFond.y = 282;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>698 && event.button.x<742 && event.button.y>282 && event.button.y<323)
                {
                    //6
                    positionFond.x = 738;
                    positionFond.y = 282;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>748 && event.button.x<792 && event.button.y>282 && event.button.y<323)
                {
                    //7
                    positionFond.x = 788;
                    positionFond.y = 282;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>798 && event.button.x<842 && event.button.y>282 && event.button.y<323)
                {
                    //8
                    positionFond.x = 838;
                    positionFond.y = 282;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>848 && event.button.x<892 && event.button.y>282 && event.button.y<323)
                {
                    //9
                    positionFond.x = 888;
                    positionFond.y = 282;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }

                /*Ligne 5*/
                else if(event.button.x>448 && event.button.x<492 && event.button.y>332 && event.button.y<373)
                {
                    //1
                    positionFond.x = 488;
                    positionFond.y = 332;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>498 && event.button.x<542 && event.button.y>332 && event.button.y<373)
                {
                    //2
                    positionFond.x = 538;
                    positionFond.y = 332;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>548 && event.button.x<592 && event.button.y>332 && event.button.y<373)
                {
                    //3
                    positionFond.x = 588;
                    positionFond.y = 332;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>598 && event.button.x<642 && event.button.y>332 && event.button.y<373)
                {
                    //4
                    positionFond.x = 638;
                    positionFond.y = 332;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>648 && event.button.x<692 && event.button.y>332 && event.button.y<373)
                {
                    //5
                    positionFond.x = 688;
                    positionFond.y = 332;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>698 && event.button.x<742 && event.button.y>332 && event.button.y<373)
                {
                    //6
                    positionFond.x = 738;
                    positionFond.y = 332;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>748 && event.button.x<792 && event.button.y>332 && event.button.y<373)
                {
                    //7
                    positionFond.x = 788;
                    positionFond.y = 332;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>798 && event.button.x<842 && event.button.y>332 && event.button.y<373)
                {
                    //8
                    positionFond.x = 838;
                    positionFond.y = 332;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>848 && event.button.x<892 && event.button.y>332 && event.button.y<373)
                {
                    //9
                    positionFond.x = 888;
                    positionFond.y = 332;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }


                /*Ligne 6*/
                else if(event.button.x>448 && event.button.x<492 && event.button.y>382 && event.button.y<423)
                {
                    //1
                    positionFond.x = 488;
                    positionFond.y = 382;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>498 && event.button.x<542 && event.button.y>382 && event.button.y<423)
                {
                    //2
                    positionFond.x = 538;
                    positionFond.y = 382;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>548 && event.button.x<592 && event.button.y>382 && event.button.y<423)
                {
                    //3
                    positionFond.x = 588;
                    positionFond.y = 382;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>598 && event.button.x<642 && event.button.y>382 && event.button.y<423)
                {
                    //4
                    positionFond.x = 638;
                    positionFond.y = 382;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>648 && event.button.x<692 && event.button.y>382 && event.button.y<423)
                {
                    //5
                    positionFond.x = 688;
                    positionFond.y = 382;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>698 && event.button.x<742 && event.button.y>382 && event.button.y<423)
                {
                    //6
                    positionFond.x = 738;
                    positionFond.y = 382;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>748 && event.button.x<792 && event.button.y>382 && event.button.y<423)
                {
                    //7
                    positionFond.x = 788;
                    positionFond.y = 382;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>798 && event.button.x<842 && event.button.y>382 && event.button.y<423)
                {
                    //8
                    positionFond.x = 838;
                    positionFond.y = 382;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>848 && event.button.x<892 && event.button.y>382 && event.button.y<423)
                {
                    //9
                    positionFond.x = 888;
                    positionFond.y = 382;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }

                /*Ligne 7*/
                else if(event.button.x>448 && event.button.x<492 && event.button.y>432 && event.button.y<473)
                {
                    //1
                    positionFond.x = 488;
                    positionFond.y = 432;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>498 && event.button.x<542 && event.button.y>432 && event.button.y<473)
                {
                    //2
                    positionFond.x = 538;
                    positionFond.y = 432;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>548 && event.button.x<592 && event.button.y>432 && event.button.y<473)
                {
                    //3
                    positionFond.x = 588;
                    positionFond.y = 432;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>598 && event.button.x<642 && event.button.y>432 && event.button.y<473)
                {
                    //4
                    positionFond.x = 638;
                    positionFond.y = 432;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>648 && event.button.x<692 && event.button.y>432 && event.button.y<473)
                {
                    //5
                    positionFond.x = 688;
                    positionFond.y = 432;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>698 && event.button.x<742 && event.button.y>432 && event.button.y<473)
                {
                    //6
                    positionFond.x = 738;
                    positionFond.y = 432;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>748 && event.button.x<792 && event.button.y>432 && event.button.y<473)
                {
                    //7
                    positionFond.x = 788;
                    positionFond.y = 432;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>798 && event.button.x<842 && event.button.y>432 && event.button.y<473)
                {
                    //8
                    positionFond.x = 838;
                    positionFond.y = 432;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>848 && event.button.x<892 && event.button.y>432 && event.button.y<473)
                {
                    //9
                    positionFond.x = 888;
                    positionFond.y = 432;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }



                /*Ligne 8*/
                else if(event.button.x>448 && event.button.x<492 && event.button.y>482 && event.button.y<523)
                {
                    //1
                    positionFond.x = 488;
                    positionFond.y = 482;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>498 && event.button.x<542 && event.button.y>482 && event.button.y<523)
                {
                    //2
                    positionFond.x = 538;
                    positionFond.y = 482;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>548 && event.button.x<592 && event.button.y>482 && event.button.y<523)
                {
                    //3
                    positionFond.x = 588;
                    positionFond.y = 482;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>598 && event.button.x<642 && event.button.y>482 && event.button.y<523)
                {
                    //4
                    positionFond.x = 638;
                    positionFond.y = 482;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>648 && event.button.x<692 && event.button.y>482 && event.button.y<523)
                {
                    //5
                    positionFond.x = 688;
                    positionFond.y = 482;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>698 && event.button.x<742 && event.button.y>482 && event.button.y<523)
                {
                    //6
                    positionFond.x = 738;
                    positionFond.y = 482;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>748 && event.button.x<792 && event.button.y>482 && event.button.y<523)
                {
                    //7
                    positionFond.x = 788;
                    positionFond.y = 482;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>798 && event.button.x<842 && event.button.y>482 && event.button.y<523)
                {
                    //8
                    positionFond.x = 838;
                    positionFond.y = 482;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>848 && event.button.x<892 && event.button.y>482 && event.button.y<523)
                {
                    //9
                    positionFond.x = 888;
                    positionFond.y = 482;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }



                /*Ligne 9*/
                else if(event.button.x>448 && event.button.x<492 && event.button.y>532 && event.button.y<573)
                {
                    //1
                    positionFond.x = 488;
                    positionFond.y = 532;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>498 && event.button.x<542 && event.button.y>532 && event.button.y<573)
                {
                    //2
                    positionFond.x = 538;
                    positionFond.y = 532;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>548 && event.button.x<592 && event.button.y>532 && event.button.y<573)
                {
                    //3
                    positionFond.x = 588;
                    positionFond.y = 532;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>598 && event.button.x<642 && event.button.y>532 && event.button.y<573)
                {
                    //4
                    positionFond.x = 638;
                    positionFond.y = 532;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>648 && event.button.x<692 && event.button.y>532 && event.button.y<573)
                {
                    //5
                    positionFond.x = 688;
                    positionFond.y = 532;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>698 && event.button.x<742 && event.button.y>532 && event.button.y<573)
                {
                    //6
                    positionFond.x = 738;
                    positionFond.y = 532;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>748 && event.button.x<792 && event.button.y>532 && event.button.y<573)
                {
                    //7
                    positionFond.x = 788;
                    positionFond.y = 532;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>798 && event.button.x<842 && event.button.y>532 && event.button.y<573)
                {
                    //8
                    positionFond.x = 838;
                    positionFond.y = 532;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }
                else if(event.button.x>848 && event.button.x<892 && event.button.y>532 && event.button.y<573)
                {
                    //9
                    positionFond.x = 888;
                    positionFond.y = 532;
                    ecrire(TAB,ecran,imageDeFond);
                    imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                }


                else if(event.button.x>1152 && event.button.x<1310 && event.button.y>628 && event.button.y<675)
                {
                    continuer = 0;
                }
                else{
                    ecrire(TAB,ecran,imageDeFond);
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
