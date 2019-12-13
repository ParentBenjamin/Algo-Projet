#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>


#include "Menu.h"
#include "InterfaceSudoku.h"
#include "InterfaceLoto.h"
#include "InterfaceBN.h"
#include "InterfacePoker.h"
#include "Clavier.h"
#include "scores.h"


/**Menu Principal*/
int menuPrincipal(Tableau pseudo, SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond){ /* Le menu principal */
    positionFond.x = 0;
    positionFond.y = 0;
    SDL_Event event; // La variable contenant l'événement
    int continuer = 1;



    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2000);

    Mix_Music *music = NULL;



    //music = Mix_LoadMUS("menu.mp3");

    //Mix_PlayMusic(music, 55);

    while(continuer){
        imageDeFond = SDL_LoadBMP("menu.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
        SDL_Flip(ecran);
        SDL_WaitEvent(&event);

        switch(event.type) // On teste le type d'événement
        {
            case SDL_MOUSEBUTTONUP:
            {
                if(event.button.x>1007 && event.button.x<1335 && event.button.y>27 && event.button.y<72)
                {
                    interBN(pseudo,ecran,imageDeFond,positionFond);

                }
                else if(event.button.x>1185 && event.button.x<1347 && event.button.y>80 && event.button.y<119)
                {
                    interSudoku(pseudo,ecran,imageDeFond,positionFond);
                    continuer = 0;
                }
                else if(event.button.x>1220 && event.button.x<1344 && event.button.y>134 && event.button.y<173)
                {
                    interPoker(pseudo,ecran,imageDeFond,positionFond);
                }
                else if(event.button.x>1244 && event.button.x<1346 && event.button.y>189 && event.button.y<228)
                {
                    interLoto(pseudo,ecran,imageDeFond,positionFond);
                }
                else if(event.button.x>1199 && event.button.x<1354 && event.button.y>694 && event.button.y<730)
                {
                    return 0;
                }
                else if(event.button.x>4 && event.button.x<391 && event.button.y>696 && event.button.y<724)
                {
                    Tableau autre;
                    ecrirePseudo(0,pseudo,autre,ecran,imageDeFond,positionFond);
                    return 0;
                }
                else if(event.button.x>12 && event.button.x<121 && event.button.y>16 && event.button.y<50)
                {
                    Tableau autre;
                    autre[0]='\0';
                    tableau_score(0,pseudo,autre,ecran,imageDeFond,positionFond);
                    return 0;
                }
                break;
            }
            default :
            break;
        }
    }
    Mix_FreeMusic(music); //Libération de la musique
    Mix_CloseAudio(); //Fermeture de l'API
    return 0;
}







int ecrirePseudo(int i, Tableau TAB, Tableau autre, SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond){
    positionFond.x = 0;
    positionFond.y = 0;

    int continuer = 1;
    SDL_Event event; // La variable contenant l'événement
    imageDeFond = SDL_LoadBMP("pseudo.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);

    positionFond.x = 450;
    positionFond.y = 180;
    SDL_Color color = {255, 0, 0};
    TTF_Font *police = TTF_OpenFont("font/arialunicode.ttf",40);
    imageDeFond = TTF_RenderText_Blended(police, TAB, color);
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
    SDL_Flip(ecran);




    while(continuer){
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_KEYDOWN :
            {
                clavier(0,i,TAB,autre,event,ecran,imageDeFond,positionFond);
                return 0;
                break;
            }
            case SDL_MOUSEBUTTONDOWN :
            {
                if(event.button.x>876 && event.button.x<910 && event.button.y>178 && event.button.y<218)
                {
                    if(TAB[0]!='\0'){
                        menuPrincipal(TAB,ecran,imageDeFond,positionFond);
                        return 0;
                    }


                }
                break;
            }
            default : break;
        }
    }
}



int tableau_score(int i, Tableau pseudo, Tableau TAB, SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond){
    positionFond.x = 0;
    positionFond.y = 0;

    int continuer = 1;
    SDL_Event event; // La variable contenant l'événement
    imageDeFond = SDL_LoadBMP("score.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);

    positionFond.x = 450;
    positionFond.y = 180;
    SDL_Color color = {255, 0, 0};
    TTF_Font *police = TTF_OpenFont("font/arialunicode.ttf",40);
    imageDeFond = TTF_RenderText_Blended(police, TAB, color);
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
    SDL_Flip(ecran);




    while(continuer){
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_KEYDOWN :
            {
                clavier(1,i,TAB,pseudo,event,ecran,imageDeFond,positionFond);
                return 0;
                break;
            }
            case SDL_MOUSEBUTTONDOWN :
            {
                if(event.button.x>937 && event.button.x<973 && event.button.y>177 && event.button.y<214)
                {
                    if(TAB[0]!='\0'){

                        char machaine[4];
                        int monentier = getScore(TAB);
                        sprintf(machaine,"%d",monentier);
                        positionFond.x = 600;
                        positionFond.y = 400;
                        SDL_Color color = {255, 0, 0};
                        TTF_Font *police = TTF_OpenFont("font/arialunicode.ttf",40);
                        imageDeFond = TTF_RenderText_Blended(police, machaine, color);
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
                        SDL_Flip(ecran);


                    }
                }
                else if(event.button.x>554 && event.button.x<716 && event.button.y>679 && event.button.y<713){
                    menuPrincipal(pseudo,ecran,imageDeFond,positionFond);
                    return 0;
                }
                break;
            }
            default : break;
        }
    }
}
