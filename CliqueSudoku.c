#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "InterfaceSudoku.h"
#include "Grille.h"

int cliqueSouris(int continuer, SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, SDL_Event event, TAB t){
    positionFond.x = 0;
    positionFond.y = 0;
    /*Ligne 1*/
    if(event.button.x>448 && event.button.x<492 && event.button.y>132 && event.button.y<173)
    {
        //1
        positionFond.x = 488;
        positionFond.y = 132;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>498 && event.button.x<542 && event.button.y>132 && event.button.y<173)
    {
        //2
        positionFond.x = 538;
        positionFond.y = 132;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>548 && event.button.x<592 && event.button.y>132 && event.button.y<173)
    {
        //3
        positionFond.x = 588;
        positionFond.y = 132;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>598 && event.button.x<642 && event.button.y>132 && event.button.y<173)
    {
        //4
        positionFond.x = 638;
        positionFond.y = 132;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>648 && event.button.x<692 && event.button.y>132 && event.button.y<173)
    {
        //5
        positionFond.x = 688;
        positionFond.y = 132;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>698 && event.button.x<742 && event.button.y>132 && event.button.y<173)
    {
        //6
        positionFond.x = 738;
        positionFond.y = 132;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>748 && event.button.x<792 && event.button.y>132 && event.button.y<173)
    {
        //7
        positionFond.x = 788;
        positionFond.y = 132;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>798 && event.button.x<842 && event.button.y>132 && event.button.y<173)
    {
        //8
        positionFond.x = 838;
        positionFond.y = 132;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>848 && event.button.x<892 && event.button.y>132 && event.button.y<173)
    {
        //9
        positionFond.x = 888;
        positionFond.y = 132;
        ecrire(t,ecran,imageDeFond);
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
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>498 && event.button.x<542 && event.button.y>182 && event.button.y<223)
    {
        //2
        positionFond.x = 538;
        positionFond.y = 182;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>548 && event.button.x<592 && event.button.y>182 && event.button.y<223)
    {
        //3
        positionFond.x = 588;
        positionFond.y = 182;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>598 && event.button.x<642 && event.button.y>182 && event.button.y<223)
    {
        //4
        positionFond.x = 638;
        positionFond.y = 182;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>648 && event.button.x<692 && event.button.y>182 && event.button.y<223)
    {
        //5
        positionFond.x = 688;
        positionFond.y = 182;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>698 && event.button.x<742 && event.button.y>182 && event.button.y<223)
    {
        //6
        positionFond.x = 738;
        positionFond.y = 182;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>748 && event.button.x<792 && event.button.y>182 && event.button.y<223)
    {
        //7
        positionFond.x = 788;
        positionFond.y = 182;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>798 && event.button.x<842 && event.button.y>182 && event.button.y<223)
    {
        //8
        positionFond.x = 838;
        positionFond.y = 182;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>848 && event.button.x<892 && event.button.y>182 && event.button.y<223)
    {
        //9
        positionFond.x = 888;
        positionFond.y = 182;
        ecrire(t,ecran,imageDeFond);
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
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>498 && event.button.x<542 && event.button.y>232 && event.button.y<273)
    {
        //2
        positionFond.x = 538;
        positionFond.y = 232;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>548 && event.button.x<592 && event.button.y>232 && event.button.y<273)
    {
        //3
        positionFond.x = 588;
        positionFond.y = 232;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>598 && event.button.x<642 && event.button.y>232 && event.button.y<273)
    {
        //4
        positionFond.x = 638;
        positionFond.y = 232;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>648 && event.button.x<692 && event.button.y>232 && event.button.y<273)
    {
        //5
        positionFond.x = 688;
        positionFond.y = 232;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>698 && event.button.x<742 && event.button.y>232 && event.button.y<273)
    {
        //6
        positionFond.x = 738;
        positionFond.y = 232;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>748 && event.button.x<792 && event.button.y>232 && event.button.y<273)
    {
        //7
        positionFond.x = 788;
        positionFond.y = 232;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>798 && event.button.x<842 && event.button.y>232 && event.button.y<273)
    {
        //8
        positionFond.x = 838;
        positionFond.y = 232;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>848 && event.button.x<892 && event.button.y>232 && event.button.y<273)
    {
        //9
        positionFond.x = 888;
        positionFond.y = 232;
        ecrire(t,ecran,imageDeFond);
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
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>498 && event.button.x<542 && event.button.y>282 && event.button.y<323)
    {
        //2
        positionFond.x = 538;
        positionFond.y = 282;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>548 && event.button.x<592 && event.button.y>282 && event.button.y<323)
    {
        //3
        positionFond.x = 588;
        positionFond.y = 282;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>598 && event.button.x<642 && event.button.y>282 && event.button.y<323)
    {
        //4
        positionFond.x = 638;
        positionFond.y = 282;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>648 && event.button.x<692 && event.button.y>282 && event.button.y<323)
    {
        //5
        positionFond.x = 688;
        positionFond.y = 282;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>698 && event.button.x<742 && event.button.y>282 && event.button.y<323)
    {
        //6
        positionFond.x = 738;
        positionFond.y = 282;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>748 && event.button.x<792 && event.button.y>282 && event.button.y<323)
    {
        //7
        positionFond.x = 788;
        positionFond.y = 282;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>798 && event.button.x<842 && event.button.y>282 && event.button.y<323)
    {
        //8
        positionFond.x = 838;
        positionFond.y = 282;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>848 && event.button.x<892 && event.button.y>282 && event.button.y<323)
    {
        //9
        positionFond.x = 888;
        positionFond.y = 282;
        ecrire(t,ecran,imageDeFond);
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
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>498 && event.button.x<542 && event.button.y>332 && event.button.y<373)
    {
        //2
        positionFond.x = 538;
        positionFond.y = 332;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>548 && event.button.x<592 && event.button.y>332 && event.button.y<373)
    {
        //3
        positionFond.x = 588;
        positionFond.y = 332;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>598 && event.button.x<642 && event.button.y>332 && event.button.y<373)
    {
        //4
        positionFond.x = 638;
        positionFond.y = 332;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>648 && event.button.x<692 && event.button.y>332 && event.button.y<373)
    {
        //5
        positionFond.x = 688;
        positionFond.y = 332;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>698 && event.button.x<742 && event.button.y>332 && event.button.y<373)
    {
        //6
        positionFond.x = 738;
        positionFond.y = 332;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>748 && event.button.x<792 && event.button.y>332 && event.button.y<373)
    {
        //7
        positionFond.x = 788;
        positionFond.y = 332;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>798 && event.button.x<842 && event.button.y>332 && event.button.y<373)
    {
        //8
        positionFond.x = 838;
        positionFond.y = 332;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>848 && event.button.x<892 && event.button.y>332 && event.button.y<373)
    {
        //9
        positionFond.x = 888;
        positionFond.y = 332;
        ecrire(t,ecran,imageDeFond);
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
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>498 && event.button.x<542 && event.button.y>382 && event.button.y<423)
    {
        //2
        positionFond.x = 538;
        positionFond.y = 382;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>548 && event.button.x<592 && event.button.y>382 && event.button.y<423)
    {
        //3
        positionFond.x = 588;
        positionFond.y = 382;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>598 && event.button.x<642 && event.button.y>382 && event.button.y<423)
    {
        //4
        positionFond.x = 638;
        positionFond.y = 382;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>648 && event.button.x<692 && event.button.y>382 && event.button.y<423)
    {
        //5
        positionFond.x = 688;
        positionFond.y = 382;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>698 && event.button.x<742 && event.button.y>382 && event.button.y<423)
    {
        //6
        positionFond.x = 738;
        positionFond.y = 382;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>748 && event.button.x<792 && event.button.y>382 && event.button.y<423)
    {
        //7
        positionFond.x = 788;
        positionFond.y = 382;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>798 && event.button.x<842 && event.button.y>382 && event.button.y<423)
    {
        //8
        positionFond.x = 838;
        positionFond.y = 382;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>848 && event.button.x<892 && event.button.y>382 && event.button.y<423)
    {
        //9
        positionFond.x = 888;
        positionFond.y = 382;
        ecrire(t,ecran,imageDeFond);
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
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
        }
    else if(event.button.x>498 && event.button.x<542 && event.button.y>432 && event.button.y<473)
    {
        //2
        positionFond.x = 538;
        positionFond.y = 432;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>548 && event.button.x<592 && event.button.y>432 && event.button.y<473)
    {
        //3
        positionFond.x = 588;
        positionFond.y = 432;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>598 && event.button.x<642 && event.button.y>432 && event.button.y<473)
    {
        //4
        positionFond.x = 638;
        positionFond.y = 432;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>648 && event.button.x<692 && event.button.y>432 && event.button.y<473)
    {
        //5
        positionFond.x = 688;
        positionFond.y = 432;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>698 && event.button.x<742 && event.button.y>432 && event.button.y<473)
    {
        //6
        positionFond.x = 738;
        positionFond.y = 432;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>748 && event.button.x<792 && event.button.y>432 && event.button.y<473)
    {
        //7
        positionFond.x = 788;
        positionFond.y = 432;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>798 && event.button.x<842 && event.button.y>432 && event.button.y<473)
    {
        //8
        positionFond.x = 838;
        positionFond.y = 432;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>848 && event.button.x<892 && event.button.y>432 && event.button.y<473)
    {
        //9
        positionFond.x = 888;
        positionFond.y = 432;
        ecrire(t,ecran,imageDeFond);
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
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>498 && event.button.x<542 && event.button.y>482 && event.button.y<523)
    {
        //2
        positionFond.x = 538;
        positionFond.y = 482;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>548 && event.button.x<592 && event.button.y>482 && event.button.y<523)
    {
        //3
        positionFond.x = 588;
        positionFond.y = 482;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>598 && event.button.x<642 && event.button.y>482 && event.button.y<523)
    {
        //4
        positionFond.x = 638;
        positionFond.y = 482;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>648 && event.button.x<692 && event.button.y>482 && event.button.y<523)
    {
        //5
        positionFond.x = 688;
        positionFond.y = 482;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>698 && event.button.x<742 && event.button.y>482 && event.button.y<523)
    {
        //6
        positionFond.x = 738;
        positionFond.y = 482;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>748 && event.button.x<792 && event.button.y>482 && event.button.y<523)
    {
        //7
        positionFond.x = 788;
        positionFond.y = 482;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>798 && event.button.x<842 && event.button.y>482 && event.button.y<523)
    {
        //8
        positionFond.x = 838;
        positionFond.y = 482;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>848 && event.button.x<892 && event.button.y>482 && event.button.y<523)
    {
        //9
        positionFond.x = 888;
        positionFond.y = 482;
        ecrire(t,ecran,imageDeFond);
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
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>498 && event.button.x<542 && event.button.y>532 && event.button.y<573)
    {
        //2
        positionFond.x = 538;
        positionFond.y = 532;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>548 && event.button.x<592 && event.button.y>532 && event.button.y<573)
    {
        //3
        positionFond.x = 588;
        positionFond.y = 532;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>598 && event.button.x<642 && event.button.y>532 && event.button.y<573)
    {
        //4
        positionFond.x = 638;
        positionFond.y = 532;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>648 && event.button.x<692 && event.button.y>532 && event.button.y<573)
    {
        //5
        positionFond.x = 688;
        positionFond.y = 532;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>698 && event.button.x<742 && event.button.y>532 && event.button.y<573)
    {
        //6
        positionFond.x = 738;
        positionFond.y = 532;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>748 && event.button.x<792 && event.button.y>532 && event.button.y<573)
    {
        //7
        positionFond.x = 788;
        positionFond.y = 532;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>798 && event.button.x<842 && event.button.y>532 && event.button.y<573)
    {
        //8
        positionFond.x = 838;
        positionFond.y = 532;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>848 && event.button.x<892 && event.button.y>532 && event.button.y<573)
    {
        //9
        positionFond.x = 888;
        positionFond.y = 532;
        ecrire(t,ecran,imageDeFond);
        imageDeFond = SDL_LoadBMP("chiffres/barre.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
    }
    else if(event.button.x>1152 && event.button.x<1310 && event.button.y>628 && event.button.y<675)
    {
        continuer = 0;
    }
    else{
        ecrire(t,ecran,imageDeFond);
    }
    return continuer;
}
