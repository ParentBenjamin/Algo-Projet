#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "Clavier.h"
#include "Menu.h"
int clavier(int choix, int i, Tableau TAB, Tableau pseudo, SDL_Event event, SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond){
    if(event.key.keysym.sym == SDLK_q)
    {
        TAB[i++]='a';
    }
    else if(event.key.keysym.sym == SDLK_w)
    {
        TAB[i++]='z';
    }
    else if(event.key.keysym.sym == SDLK_e)
    {
        TAB[i++]='e';
    }
    else if(event.key.keysym.sym == SDLK_r)
    {
        TAB[i++]='r';
    }
    else if(event.key.keysym.sym == SDLK_t)
    {
        TAB[i++]='t';
    }
    else if(event.key.keysym.sym == SDLK_y)
    {
        TAB[i++]='y';
    }
    else if(event.key.keysym.sym == SDLK_u)
    {
        TAB[i++]='u';
    }
    else if(event.key.keysym.sym == SDLK_i)
    {
        TAB[i++]='i';
    }
    else if(event.key.keysym.sym == SDLK_o)
    {
        TAB[i++]='o';
    }
    else if(event.key.keysym.sym == SDLK_p)
    {
        TAB[i++]='p';
    }
    else if(event.key.keysym.sym == SDLK_a)
    {
        TAB[i++]='q';
    }
    else if(event.key.keysym.sym == SDLK_s)
    {
        TAB[i++]='s';
    }
    else if(event.key.keysym.sym == SDLK_d)
    {
        TAB[i++]='d';
    }
    else if(event.key.keysym.sym == SDLK_f)
    {
        TAB[i++]='f';
    }
    else if(event.key.keysym.sym == SDLK_g)
    {
        TAB[i++]='g';
    }
    else if(event.key.keysym.sym == SDLK_h)
    {
        TAB[i++]='h';
    }
    else if(event.key.keysym.sym == SDLK_j)
    {
        TAB[i++]='j';
    }
    else if(event.key.keysym.sym == SDLK_k)
    {
        TAB[i++]='k';
    }
    else if(event.key.keysym.sym == SDLK_l)
    {
        TAB[i++]='l';
    }
    else if(event.key.keysym.sym == SDLK_SEMICOLON)
    {
        TAB[i++]='m';
    }
    else if(event.key.keysym.sym == SDLK_COLON)
    {
        TAB[i++]='m';
    }
    else if(event.key.keysym.sym == SDLK_z)
    {
        TAB[i++]='w';
    }
    else if(event.key.keysym.sym == SDLK_x)
    {
        TAB[i++]='x';
    }
    else if(event.key.keysym.sym == SDLK_c)
    {
        TAB[i++]='c';
    }
    else if(event.key.keysym.sym == SDLK_v)
    {
        TAB[i++]='v';
    }
    else if(event.key.keysym.sym ==SDLK_b)
    {
        TAB[i++]='b';
    }
    else if(event.key.keysym.sym == SDLK_n)
    {
        TAB[i++]='n';
    }
    else if(event.key.keysym.sym == SDLK_SPACE)
    {
        TAB[i++]=' ';
    }
    else{
        if(event.key.keysym.sym == SDLK_BACKSPACE)
        {
            if(i>0)
            {
                TAB[--i]='\0';
            }
            if(choix==0){
                ecrirePseudo(i,TAB,pseudo,ecran,imageDeFond,positionFond);
            }
            else{
                tableau_score(i,pseudo,TAB,ecran,imageDeFond,positionFond);
            }
            return 0;
        }
        else{
            if(choix==0){
                ecrirePseudo(i,TAB,pseudo,ecran,imageDeFond,positionFond);
            }
            else{
                tableau_score(i,pseudo,TAB,ecran,imageDeFond,positionFond);
            }
            return 0;
        }
    }
    TAB[i]='\0';

    if(choix==0){
        ecrirePseudo(i,TAB,pseudo,ecran,imageDeFond,positionFond);
    }
    else{
        tableau_score(i,pseudo,TAB,ecran,imageDeFond,positionFond);
    }
    return 0;
}
