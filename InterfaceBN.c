#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "InterfaceBN.h"
#include "batailleNavale.h"
#include "iaBN.h"


/**Bataille Navale en Grahique*/
int interBN(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond){


     srand(time(NULL)); // Necessaire pour la generation aleatoire (ligne a executer 1 seule fois, attention elle est executer dans le loto)


    positionFond.x = 0;
    positionFond.y = 0;
    imageDeFond = SDL_LoadBMP("BN/bn-2.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);


    //INITIALISATION
    Player p;
    IA irobot;
    TAB tabJOUEUR, tabIA;
    init(9,9,tabJOUEUR);
    init(9,9,tabIA);
    initIA(&irobot);

    int cpt = 0;
    int etape = 1;
    int orientation = 0;
    int typebateau = 5;
    SDL_Rect arriere;
    arriere.x = 0;
    arriere.y = 0;

    SDL_Event event;

    while(positionFond.x>=0 && positionFond.y>=0)
    {
        //ecrireBN(tabIA,ecran,imageDeFond,arriere,etape);
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_MOUSEBUTTONUP:
            {
                if(event.button.x>220 && event.button.x<516 && event.button.y>261 && event.button.y<300){
                    //PLACEMENT DES BATEAUx
                    placementsDesBateauxIA(tabIA);
                    positionFond.x = -1;
                }
                else if(event.button.x>780 && event.button.x<1161 && event.button.y>262 && event.button.y<313){
                    etape = genererpartie(tabJOUEUR,tabIA,p);
                    positionFond.x = -1;
                }
                else if(event.button.x>1190 && event.button.x<1319 && event.button.y>678 && event.button.y<723){
                    return 0;
                }
            }
        }
    }



    positionFond.x = 0;
    positionFond.y = 0;
    imageDeFond = SDL_LoadBMP("bn/bn.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);

    //ecrireBN(tabJOUEUR,ecran,imageDeFond,arriere,1);
    ecrireBN(tabJOUEUR,ecran,imageDeFond,arriere,etape);
    //ecrireBN(tabIA,ecran,imageDeFond,arriere,2);


    while(positionFond.x>=0 && positionFond.y>=0)
    {
        //ecrireBN(tabIA,ecran,imageDeFond,arriere,etape);
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_MOUSEBUTTONUP:
            {
                if(event.button.x>1197 && event.button.x<1346 && event.button.y>682 && event.button.y<716){
                    return 0;
                }
                else if(event.button.x>21 && event.button.x<337 && event.button.y>688 && event.button.y<717){
                    interBN(ecran,imageDeFond,positionFond);
                    return 0;
                }
                else if(event.button.x>563 && event.button.x<801 && event.button.y>676 && event.button.y<720){
                    sauvegarderjeu(tabJOUEUR,tabIA,"SAUVEGARDEPARTIE.txt",p,etape);
                }
                else{
                    if(etape==1){
                        imageDeFond = SDL_LoadBMP("bn/carre-bleu.bmp");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                        positionFond = cliqueSourisBN(ecran,imageDeFond,positionFond,event,tabJOUEUR,etape,typebateau);
                        orientation = 0;
                    }
                    else if(etape==2){
                        positionFond.x = 0;
                        positionFond.y = 0;
                        positionFond = cliqueSourisBN(ecran,imageDeFond,positionFond,event,tabIA,etape,typebateau);
                        if(positionFond.x>=841 && positionFond.x<=1241 && positionFond.y>=160 && positionFond.y<=560){
                        if(checkVictoire(tabIA)){
                            positionFond.x = 236;
                            positionFond.y = 264;
                            imageDeFond = IMG_Load("bn/victoire.png");
                            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                            SDL_Flip(ecran);
                            etape++;
                        }
                        else if(tabIA[(positionFond.y - 160)/50][(positionFond.x - 841)/50].valeur==0){
                            tirIA(tabJOUEUR,&irobot);
                            if(checkVictoire(tabJOUEUR)){
                            ecrireBN(tabJOUEUR,ecran,imageDeFond,arriere,etape);
                            positionFond.x = 236;
                            positionFond.y = 264;
                            imageDeFond = IMG_Load("bn/defaite.png");
                            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                            SDL_Flip(ecran);
                            etape++;
                            }
                            else{
                                ecrireBN(tabJOUEUR,ecran,imageDeFond,arriere,etape);
                            }
                        }
                    }
                    }
                }
                //}
                break;
            }
            case SDL_KEYDOWN:
            {
                if(etape==1){
                imageDeFond = SDL_LoadBMP("bn/eau.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
                if(event.key.keysym.sym == SDLK_UP){
                    orientation = 0;
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
                else if(event.key.keysym.sym == SDLK_RIGHT){
                    orientation = 1;
                    if(typebateau == 5){
                        imageDeFond = IMG_Load("bn/triangle-bleu-droite.png");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                    else if(typebateau == 4){
                        imageDeFond = IMG_Load("bn/triangle-rouge-droite.png");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                    else if(typebateau == 3){
                        imageDeFond = IMG_Load("bn/triangle-rose-droite.png");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                    else if(typebateau == 2){
                        imageDeFond = IMG_Load("bn/triangle-vert-droite.png");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                    else{
                        imageDeFond = IMG_Load("bn/triangle-jaune-droite.png");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                }
                else if(event.key.keysym.sym == SDLK_DOWN){
                    orientation = 2;
                    if(typebateau == 5){
                        imageDeFond = IMG_Load("bn/triangle-bleu-bas.png");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                    else if(typebateau == 4){
                        imageDeFond = IMG_Load("bn/triangle-rouge-bas.png");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                    else if(typebateau == 3){
                        imageDeFond = IMG_Load("bn/triangle-rose-bas.png");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                    else if(typebateau == 2){
                        imageDeFond = IMG_Load("bn/triangle-vert-bas.png");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                    /*else{
                        imageDeFond = IMG_Load("bn/triangle-jaune-bas.png");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }*/
                }
                else if(event.key.keysym.sym == SDLK_LEFT){
                    orientation = 3;
                    if(typebateau == 5){
                        imageDeFond = IMG_Load("bn/triangle-bleu-gauche.png");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                    else if(typebateau == 4){
                        imageDeFond = IMG_Load("bn/triangle-rouge-gauche.png");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                    else if(typebateau == 3){
                        imageDeFond = IMG_Load("bn/triangle-rose-gauche.png");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                    else if(typebateau == 2){
                        imageDeFond = IMG_Load("bn/triangle-vert-gauche.png");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                    /*else{
                        imageDeFond = IMG_Load("bn/triangle-jaune-gauche.png");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }*/
                }
                else if(event.key.keysym.sym == SDLK_RETURN){
                    positionFond.x = (positionFond.x - 84)/50;
                    positionFond.y = (positionFond.y - 163)/50;
                    if(verifEmplacement(tabJOUEUR,typebateau,orientation,positionFond.y,positionFond.x) == 0){
                        positionFond.x = 0;
                        positionFond.y = 0;
                        imageDeFond = SDL_LoadBMP("bn/carre-rouge.bmp");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                    else{
                        placerBateau(tabJOUEUR, typebateau, orientation, positionFond.y, positionFond.x);
                        positionFond.x = 0;
                        positionFond.y = 0;
                        imageDeFond = SDL_LoadBMP("bn/carre-bleu.bmp");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                        ecrireBN(tabJOUEUR,ecran,imageDeFond,arriere,etape);
                        if(typebateau == 2){
                            etape = 2;
                        }
                        else{
                            typebateau--;
                    }
                }

                }
                else{

                }
                ecrireBN(tabJOUEUR,ecran,imageDeFond,arriere,etape);
                }
                break;
            }
            default : break;
        }

    }
    //positionFond.x = 0;
    //positionFond.y = 0;
   // menuPrincipal(ecran,imageDeFond,positionFond);
    return 0;
}
