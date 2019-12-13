#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <windows.h>
#include <SDL/SDL_image.h>

#include "Menu.h"




/**Main*/
int main(int argc, char *argv[])
{

    SDL_Surface *ecran = NULL, *imageDeFond = NULL;
    SDL_Rect positionFond;


    positionFond.x = 0;
    positionFond.y = 0;


    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);


    ecran = SDL_SetVideoMode(1366, 768, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN); //définit la taille de la fenêtre ainsi que son mode

    Tableau pseudo;
    Tableau autre;
    pseudo[0]='\0';
    int i = 0;

    ecrirePseudo(i,pseudo,autre,ecran,imageDeFond,positionFond);


    TTF_Quit();
    SDL_Quit(); //quitte l'interface graphique

    return EXIT_SUCCESS;
}
