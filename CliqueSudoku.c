#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "InterfaceSudoku.h"

/*Fonction s'active dès que l'utilisateur clique sur la souris*/
SDL_Rect cliqueSourisSudoku(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, SDL_Event event, TAB t){
    if(event.button.x>1152 && event.button.x<1310 && event.button.y>628 && event.button.y<675)
    {
        positionFond.x = -1;
        positionFond.y = -1;
        return positionFond;
    }
    if(event.button.x>975 && event.button.x<1179 && event.button.y>290 && event.button.y<417)
    {
        positionFond.x = -2;
        positionFond.y = -2;
        return positionFond;
    }
    positionFond.x = event.button.x;
    positionFond.y = event.button.y;
    Coordonees c;
    c = appuiTouche(positionFond);
    if(c.x == 0 && c.y == 0){
        ecrire(t,ecran,imageDeFond);
        return positionFond;
    }
    else{
    if(t[c.x-1][c.y-1].etat == 0){
    /*Ligne 1*/
    if(event.button.x>445 && event.button.x<=495 && event.button.y>130 && event.button.y<=180)
    {
        //1
        positionFond.x = 488;
        positionFond.y = 132;
    }
    else if(event.button.x>495 && event.button.x<=545 && event.button.y>130 && event.button.y<=180)
    {
        //2
        positionFond.x = 538;
        positionFond.y = 132;
    }
    else if(event.button.x>545 && event.button.x<=595 && event.button.y>130 && event.button.y<=180)
    {
        //3
        positionFond.x = 588;
        positionFond.y = 132;
    }
    else if(event.button.x>595 && event.button.x<=645 && event.button.y>130 && event.button.y<=180)
    {
        //4
        positionFond.x = 638;
        positionFond.y = 132;
    }
    else if(event.button.x>645 && event.button.x<=695 && event.button.y>130 && event.button.y<=180)
    {
        //5
        positionFond.x = 688;
        positionFond.y = 132;
    }
    else if(event.button.x>695 && event.button.x<=745 && event.button.y>130 && event.button.y<=180)
    {
        //6
        positionFond.x = 738;
        positionFond.y = 132;
    }
    else if(event.button.x>745 && event.button.x<=795 && event.button.y>130 && event.button.y<=180)
    {
        //7
        positionFond.x = 788;
        positionFond.y = 132;
    }
    else if(event.button.x>795 && event.button.x<=845 && event.button.y>130 && event.button.y<=180)
    {
        //8
        positionFond.x = 838;
        positionFond.y = 132;
    }
    else if(event.button.x>845 && event.button.x<=895 && event.button.y>130 && event.button.y<=180)
    {
        //9
        positionFond.x = 888;
        positionFond.y = 132;
    }
    /*Ligne 2*/
    else if(event.button.x>445 && event.button.x<=495 && event.button.y>180 && event.button.y<=230)
    {
        //1
        positionFond.x = 488;
        positionFond.y = 182;
    }
    else if(event.button.x>495 && event.button.x<=545 && event.button.y>180 && event.button.y<=230)
    {
        //2
        positionFond.x = 538;
        positionFond.y = 182;
    }
    else if(event.button.x>545 && event.button.x<=595 && event.button.y>180 && event.button.y<=230)
    {
        //3
        positionFond.x = 588;
        positionFond.y = 182;
    }
    else if(event.button.x>595 && event.button.x<=645 && event.button.y>180 && event.button.y<=230)
    {
        //4
        positionFond.x = 638;
        positionFond.y = 182;
    }
    else if(event.button.x>645 && event.button.x<=695 && event.button.y>180 && event.button.y<=230)
    {
        //5
        positionFond.x = 688;
        positionFond.y = 182;
    }
    else if(event.button.x>695 && event.button.x<=745 && event.button.y>180 && event.button.y<=230)
    {
        //6
        positionFond.x = 738;
        positionFond.y = 182;
    }
    else if(event.button.x>745 && event.button.x<=795 && event.button.y>180 && event.button.y<=230)
    {
        //7
        positionFond.x = 788;
        positionFond.y = 182;
    }
    else if(event.button.x>795 && event.button.x<=845 && event.button.y>180 && event.button.y<=230)
    {
        //8
        positionFond.x = 838;
        positionFond.y = 182;
    }
    else if(event.button.x>845 && event.button.x<=895 && event.button.y>180 && event.button.y<230)
    {
        //9
        positionFond.x = 888;
        positionFond.y = 182;
    }
    /*Ligne 3*/
    else if(event.button.x>445 && event.button.x<=495 && event.button.y>230 && event.button.y<=280)
    {
        //1
        positionFond.x = 488;
        positionFond.y = 232;
    }
    else if(event.button.x>495 && event.button.x<=545 && event.button.y>230 && event.button.y<=280)
    {
        //2
        positionFond.x = 538;
        positionFond.y = 232;
    }
    else if(event.button.x>545 && event.button.x<=595 && event.button.y>230 && event.button.y<=280)
    {
        //3
        positionFond.x = 588;
        positionFond.y = 232;
    }
    else if(event.button.x>595 && event.button.x<=645 && event.button.y>230 && event.button.y<=280)
    {
        //4
        positionFond.x = 638;
        positionFond.y = 232;
    }
    else if(event.button.x>645 && event.button.x<=695 && event.button.y>230 && event.button.y<=280)
    {
        //5
        positionFond.x = 688;
        positionFond.y = 232;
    }
    else if(event.button.x>695 && event.button.x<=745 && event.button.y>230 && event.button.y<=280)
    {
        //6
        positionFond.x = 738;
        positionFond.y = 232;
    }
    else if(event.button.x>745 && event.button.x<=795 && event.button.y>230 && event.button.y<=280)
    {
        //7
        positionFond.x = 788;
        positionFond.y = 232;
    }
    else if(event.button.x>795 && event.button.x<=845 && event.button.y>230 && event.button.y<=280)
    {
        //8
        positionFond.x = 838;
        positionFond.y = 232;
    }
    else if(event.button.x>845 && event.button.x<=895 && event.button.y>230 && event.button.y<=280)
    {
        //9
        positionFond.x = 888;
        positionFond.y = 232;
    }
    /*Ligne 4*/
    else if(event.button.x>445 && event.button.x<=495 && event.button.y>280 && event.button.y<=330)
    {
        //1
        positionFond.x = 488;
        positionFond.y = 282;
    }
    else if(event.button.x>495 && event.button.x<=545 && event.button.y>280 && event.button.y<=330)
    {
        //2
        positionFond.x = 538;
        positionFond.y = 282;
    }
    else if(event.button.x>545 && event.button.x<=595 && event.button.y>280 && event.button.y<=330)
    {
        //3
        positionFond.x = 588;
        positionFond.y = 282;
    }
    else if(event.button.x>595 && event.button.x<=645 && event.button.y>280 && event.button.y<=330)
    {
        //4
        positionFond.x = 638;
        positionFond.y = 282;
    }
    else if(event.button.x>645 && event.button.x<=695 && event.button.y>280 && event.button.y<=330)
    {
        //5
        positionFond.x = 688;
        positionFond.y = 282;
    }
    else if(event.button.x>695 && event.button.x<=745 && event.button.y>280 && event.button.y<=330)
    {
        //6
        positionFond.x = 738;
        positionFond.y = 282;
    }
    else if(event.button.x>745 && event.button.x<=795 && event.button.y>280 && event.button.y<=330)
    {
        //7
        positionFond.x = 788;
        positionFond.y = 282;
    }
    else if(event.button.x>795 && event.button.x<=845 && event.button.y>280 && event.button.y<=330)
    {
        //8
        positionFond.x = 838;
        positionFond.y = 282;
    }
    else if(event.button.x>845 && event.button.x<=895 && event.button.y>280 && event.button.y<=330)
    {
        //9
        positionFond.x = 888;
        positionFond.y = 282;
    }
    /*Ligne 5*/
    else if(event.button.x>445 && event.button.x<=495 && event.button.y>330 && event.button.y<=380)
    {
        //1
        positionFond.x = 488;
        positionFond.y = 332;
    }
    else if(event.button.x>495 && event.button.x<=545 && event.button.y>330 && event.button.y<=380)
    {
        //2
        positionFond.x = 538;
        positionFond.y = 332;
    }
    else if(event.button.x>545 && event.button.x<=595 && event.button.y>330 && event.button.y<=380)
    {
        //3
        positionFond.x = 588;
        positionFond.y = 332;
    }
    else if(event.button.x>595 && event.button.x<=645 && event.button.y>330 && event.button.y<=380)
    {
        //4
        positionFond.x = 638;
        positionFond.y = 332;
    }
    else if(event.button.x>645 && event.button.x<=695 && event.button.y>330 && event.button.y<=380)
    {
        //5
        positionFond.x = 688;
        positionFond.y = 332;
    }
    else if(event.button.x>695 && event.button.x<=745 && event.button.y>330 && event.button.y<=380)
    {
        //6
        positionFond.x = 738;
        positionFond.y = 332;
    }
    else if(event.button.x>745 && event.button.x<=795 && event.button.y>330 && event.button.y<=380)
    {
        //7
        positionFond.x = 788;
        positionFond.y = 332;
    }
    else if(event.button.x>795 && event.button.x<=845 && event.button.y>330 && event.button.y<=380)
    {
        //8
        positionFond.x = 838;
        positionFond.y = 332;
    }
    else if(event.button.x>845 && event.button.x<=895 && event.button.y>330 && event.button.y<=380)
    {
        //9
        positionFond.x = 888;
        positionFond.y = 332;
    }
    /*Ligne 6*/
    else if(event.button.x>445 && event.button.x<=495 && event.button.y>380 && event.button.y<=430)
    {
        //1
        positionFond.x = 488;
        positionFond.y = 382;
    }
    else if(event.button.x>495 && event.button.x<=545 && event.button.y>380 && event.button.y<=430)
    {
        //2
        positionFond.x = 538;
        positionFond.y = 382;
    }
    else if(event.button.x>545 && event.button.x<=595 && event.button.y>380 && event.button.y<=430)
    {
        //3
        positionFond.x = 588;
        positionFond.y = 382;
    }
    else if(event.button.x>595 && event.button.x<=645 && event.button.y>380 && event.button.y<=430)
    {
        //4
        positionFond.x = 638;
        positionFond.y = 382;
    }
    else if(event.button.x>645 && event.button.x<=695 && event.button.y>380 && event.button.y<=430)
    {
        //5
        positionFond.x = 688;
        positionFond.y = 382;
    }
    else if(event.button.x>695 && event.button.x<=745 && event.button.y>380 && event.button.y<=430)
    {
        //6
        positionFond.x = 738;
        positionFond.y = 382;
    }
    else if(event.button.x>745 && event.button.x<=795 && event.button.y>380 && event.button.y<=430)
    {
        //7
        positionFond.x = 788;
        positionFond.y = 382;
    }
    else if(event.button.x>795 && event.button.x<=845 && event.button.y>380 && event.button.y<=430)
    {
        //8
        positionFond.x = 838;
        positionFond.y = 382;
    }
    else if(event.button.x>845 && event.button.x<=895 && event.button.y>380 && event.button.y<=430)
    {
        //9
        positionFond.x = 888;
        positionFond.y = 382;
    }
    /*Ligne 7*/
    else if(event.button.x>445 && event.button.x<=495 && event.button.y>430 && event.button.y<=480)
    {
        //1
        positionFond.x = 488;
        positionFond.y = 432;
        }
    else if(event.button.x>495 && event.button.x<=545 && event.button.y>430 && event.button.y<=480)
    {
        //2
        positionFond.x = 538;
        positionFond.y = 432;
    }
    else if(event.button.x>545 && event.button.x<=595 && event.button.y>430 && event.button.y<=480)
    {
        //3
        positionFond.x = 588;
        positionFond.y = 432;
    }
    else if(event.button.x>595 && event.button.x<=645 && event.button.y>430 && event.button.y<=480)
    {
        //4
        positionFond.x = 638;
        positionFond.y = 432;
    }
    else if(event.button.x>645 && event.button.x<=695 && event.button.y>430 && event.button.y<=480)
    {
        //5
        positionFond.x = 688;
        positionFond.y = 432;
    }
    else if(event.button.x>695 && event.button.x<=745 && event.button.y>430 && event.button.y<=480)
    {
        //6
        positionFond.x = 738;
        positionFond.y = 432;
    }
    else if(event.button.x>745 && event.button.x<=795 && event.button.y>430 && event.button.y<=480)
    {
        //7
        positionFond.x = 788;
        positionFond.y = 432;
    }
    else if(event.button.x>795 && event.button.x<=845 && event.button.y>430 && event.button.y<=480)
    {
        //8
        positionFond.x = 838;
        positionFond.y = 432;
    }
    else if(event.button.x>845 && event.button.x<=895 && event.button.y>430 && event.button.y<=480)
    {
        //9
        positionFond.x = 888;
        positionFond.y = 432;
    }
    /*Ligne 8*/
    else if(event.button.x>445 && event.button.x<=495 && event.button.y>480 && event.button.y<=530)
    {
        //1
        positionFond.x = 488;
        positionFond.y = 482;
    }
    else if(event.button.x>495 && event.button.x<=545 && event.button.y>480 && event.button.y<=530)
    {
        //2
        positionFond.x = 538;
        positionFond.y = 482;
    }
    else if(event.button.x>545 && event.button.x<=595 && event.button.y>480 && event.button.y<=530)
    {
        //3
        positionFond.x = 588;
        positionFond.y = 482;
    }
    else if(event.button.x>595 && event.button.x<=645 && event.button.y>480 && event.button.y<=530)
    {
        //4
        positionFond.x = 638;
        positionFond.y = 482;
    }
    else if(event.button.x>645 && event.button.x<=695 && event.button.y>480 && event.button.y<=530)
    {
        //5
        positionFond.x = 688;
        positionFond.y = 482;
    }
    else if(event.button.x>698 && event.button.x<742 && event.button.y>480 && event.button.y<=530)
    {
        //6
        positionFond.x = 738;
        positionFond.y = 482;
    }
    else if(event.button.x>745 && event.button.x<=795 && event.button.y>480 && event.button.y<=530)
    {
        //7
        positionFond.x = 788;
        positionFond.y = 482;
    }
    else if(event.button.x>795 && event.button.x<=845 && event.button.y>480 && event.button.y<=530)
    {
        //8
        positionFond.x = 838;
        positionFond.y = 482;
    }
    else if(event.button.x>845 && event.button.x<=895 && event.button.y>480 && event.button.y<=530)
    {
        //9
        positionFond.x = 888;
        positionFond.y = 482;
    }
    /*Ligne 9*/
    else if(event.button.x>445 && event.button.x<=495 && event.button.y>530 && event.button.y<=580)
    {
        //1
        positionFond.x = 488;
        positionFond.y = 532;
    }
    else if(event.button.x>495 && event.button.x<=545 && event.button.y>530 && event.button.y<=580)
    {
        //2
        positionFond.x = 538;
        positionFond.y = 532;
    }
    else if(event.button.x>545 && event.button.x<=595 && event.button.y>530 && event.button.y<=580)
    {
        //3
        positionFond.x = 588;
        positionFond.y = 532;
    }
    else if(event.button.x>595 && event.button.x<=645 && event.button.y>530 && event.button.y<=580)
    {
        //4
        positionFond.x = 638;
        positionFond.y = 532;
    }
    else if(event.button.x>645 && event.button.x<=695 && event.button.y>530 && event.button.y<=580)
    {
        //5
        positionFond.x = 688;
        positionFond.y = 532;
    }
    else if(event.button.x>695 && event.button.x<=745 && event.button.y>530 && event.button.y<=580)
    {
        //6
        positionFond.x = 738;
        positionFond.y = 532;
    }
    else if(event.button.x>745 && event.button.x<=795 && event.button.y>530 && event.button.y<=580)
    {
        //7
        positionFond.x = 788;
        positionFond.y = 532;
    }
    else if(event.button.x>795 && event.button.x<=845 && event.button.y>530 && event.button.y<=580)
    {
        //8
        positionFond.x = 838;
        positionFond.y = 532;
    }
    else if(event.button.x>845 && event.button.x<=895 && event.button.y>530 && event.button.y<=580)
    {
        //9
        positionFond.x = 888;
        positionFond.y = 532;
    }
    ecrire(t,ecran,imageDeFond);
    imageDeFond = SDL_LoadBMP("sudoku/barre.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);
    return positionFond;
    }
    }
    return positionFond;
}
