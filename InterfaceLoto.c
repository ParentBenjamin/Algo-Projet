#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <time.h>


#include "InterfaceLoto.h"
#include "menu.h"
#include "loto.h"


/*Fonction qui remplit la grille*/
void remplirTEST2(TAB t){
    /*t[0][0].valeur = 1;
    t[0][1].valeur = 34;
    t[0][2].valeur = 54;
    t[0][3].valeur = 65;
    t[0][4].valeur = 76;
    t[0][5].valeur = 81;
    t[0][6].valeur = 93;
    t[0][7].valeur = 12;
    t[0][8].valeur = 21;

    t[1][0].valeur = 6;
    t[1][1].valeur = 74;
    t[1][2].valeur = 23;
    t[1][3].valeur = 10;
    t[1][4].valeur = 97;
    t[1][5].valeur = 50;
    t[1][6].valeur = 32;
    t[1][7].valeur = 40;
    t[1][8].valeur = 80;

    t[2][0].valeur = 4;
    t[2][1].valeur = 59;
    t[2][2].valeur = 86;
    t[2][3].valeur = 35;
    t[2][4].valeur = 47;
    t[2][5].valeur = 28;
    t[2][6].valeur = 55;
    t[2][7].valeur = 66;
    t[2][8].valeur = 77;

    t[3][0].valeur = 8;
    t[3][1].valeur = 51;
    t[3][2].valeur = 94;
    t[3][3].valeur = 78;
    t[3][4].valeur = 65;
    t[3][5].valeur = 17;
    t[3][6].valeur = 48;
    t[3][7].valeur = 25;
    t[3][8].valeur = 34;

    t[4][0].valeur = 4;
    t[4][1].valeur = 26;
    t[4][2].valeur = 67;
    t[4][3].valeur = 88;
    t[4][4].valeur = 59;
    t[4][5].valeur = 35;
    t[4][6].valeur = 74;
    t[4][7].valeur = 92;
    t[4][8].valeur = 13;

    t[5][0].valeur = 7;
    t[5][1].valeur = 17;
    t[5][2].valeur = 35;
    t[5][3].valeur = 98;
    t[5][4].valeur = 26;
    t[5][5].valeur = 44;
    t[5][6].valeur = 87;
    t[5][7].valeur = 58;
    t[5][8].valeur = 67;

    t[6][0].valeur = 9;
    t[6][1].valeur = 65;
    t[6][2].valeur = 13;
    t[6][3].valeur = 52;
    t[6][4].valeur = 31;
    t[6][5].valeur = 72;
    t[6][6].valeur = 24;
    t[6][7].valeur = 86;
    t[6][8].valeur = 44;

    t[7][0].valeur = 2;
    t[7][1].valeur = 83;
    t[7][2].valeur = 74;
    t[7][3].valeur = 45;
    t[7][4].valeur = 17;
    t[7][5].valeur = 97;
    t[7][6].valeur = 65;
    t[7][7].valeur = 34;
    t[7][8].valeur = 51;

    t[8][0].valeur = 3;
    t[8][1].valeur = 44;
    t[8][2].valeur = 55;
    t[8][3].valeur = 27;
    t[8][4].valeur = 85;
    t[8][5].valeur = 61;
    t[8][6].valeur = 12;
    t[8][7].valeur = 45;
    t[8][8].valeur = 23;*/




    t[0][0].etat = 2;
    t[0][1].etat = 2;
    t[0][2].etat = 2;
    t[0][3].etat = 2;
    t[0][4].etat = 2;
    t[0][5].etat = 2;
    t[0][6].etat = 2;
    t[0][7].etat = 2;
    t[0][8].etat = 2;

    t[1][0].etat = 2;
    t[1][1].etat = 2;
    t[1][2].etat = 2;
    t[1][3].etat = 2;
    t[1][4].etat = 2;
    t[1][5].etat = 2;
    t[1][6].etat = 2;
    t[1][7].etat = 2;
    t[1][8].etat = 2;

    t[2][0].etat = 2;
    t[2][1].etat = 2;
    t[2][2].etat = 2;
    t[2][3].etat = 2;
    t[2][4].etat = 2;
    t[2][5].etat = 2;
    t[2][6].etat = 2;
    t[2][7].etat = 2;
    t[2][8].etat = 2;

    t[3][0].etat = 2;
    t[3][1].etat = 2;
    t[3][2].etat = 2;
    t[3][3].etat = 2;
    t[3][4].etat = 2;
    t[3][5].etat = 2;
    t[3][6].etat = 2;
    t[3][7].etat = 2;
    t[3][8].etat = 2;

    t[4][0].etat = 2;
    t[4][1].etat = 0;
    t[4][2].etat = 2;
    t[4][3].etat = 2;
    t[4][4].etat = 2;
    t[4][5].etat = 2;
    t[4][6].etat = 2;
    t[4][7].etat = 2;
    t[4][8].etat = 2;

    t[5][0].etat = 2;
    t[5][1].etat = 2;
    t[5][2].etat = 2;
    t[5][3].etat = 2;
    t[5][4].etat = 2;
    t[5][5].etat = 2;
    t[5][6].etat = 2;
    t[5][7].etat = 2;
    t[5][8].etat = 2;

    t[6][0].etat = 2;
    t[6][1].etat = 2;
    t[6][2].etat = 2;
    t[6][3].etat = 2;
    t[6][4].etat = 2;
    t[6][5].etat = 2;
    t[6][6].etat = 2;
    t[6][7].etat = 2;
    t[6][8].etat = 2;

    t[7][0].etat = 2;
    t[7][1].etat = 2;
    t[7][2].etat = 2;
    t[7][3].etat = 2;
    t[7][4].etat = 2;
    t[7][5].etat = 2;
    t[7][6].etat = 2;
    t[7][7].etat = 2;
    t[7][8].etat = 2;

    t[8][0].etat = 2;
    t[8][1].etat = 2;
    t[8][2].etat = 2;
    t[8][3].etat = 2;
    t[8][4].etat = 2;
    t[8][5].etat = 2;
    t[8][6].etat = 2;
    t[8][7].etat = 2;
    t[8][8].etat = 2;
}

Tirage suivant(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, TAB t, int choix, Tirage tab){
    SDL_Color color = {255, 0, 0};
    TTF_Font *police = TTF_OpenFont("font/arialunicode.ttf",40);
    if(tab.nbtirage<90)
    {
        int numTirage; //numero du tirage actuel
        int monentier = tab.nbtirage+1;
        char machaine[4];
        sprintf(machaine,"%d",monentier);

        positionFond.x = 1130;
        positionFond.y = 400;
        imageDeFond = SDL_LoadBMP("loto/blanc2.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
        imageDeFond = TTF_RenderText_Blended(police, machaine, color);
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
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
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
            SDL_Flip(ecran);
        }
        else
        {
            imageDeFond = TTF_RenderText_Blended(police, "Perdu", color);
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
            SDL_Flip(ecran);
        }

    }
    return tab;
}









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
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
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
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
                    SDL_Flip(ecran);
                }
                else{
                    color.r = 0;
                    imageDeFond = TTF_RenderText_Blended(police, machaine, color);
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
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
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
                        SDL_Flip(ecran);
                    }
                    else{

                        color.r = 0;
                        imageDeFond = TTF_RenderText_Blended(police, machaine, color);
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
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
    /*int monentier;
    char machaine[4];
    monentier = (float)t1/CLOCKS_PER_SEC;
    sprintf(machaine,"%d",monentier);
    positionFond.x = 1130;
    positionFond.y = 400;
    SDL_Color color = {255, 0, 0};
    TTF_Font *police = TTF_OpenFont("font/arialunicode.ttf",40);
    imageDeFond = TTF_RenderText_Blended(police, machaine, color);
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
    SDL_Flip(ecran);
    Sleep(50000);*/
    //positionFond.x = 0;
    //positionFond.y = 0;
   // menuPrincipal(ecran,imageDeFond,positionFond);
    return 0;
}
