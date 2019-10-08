#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "InterfaceSudoku.h"
#include "Grille.h"


Coordonees appuiTouche(SDL_Rect positionFond){
    int x,y;
    if(positionFond.y>130 && positionFond.y<=180){
        x = 1;
    }
    else if(positionFond.y>180 && positionFond.y<=230){
        x = 2;
    }
    else if(positionFond.y>230 && positionFond.y<=280){
        x = 3;
    }
    else if(positionFond.y>280 && positionFond.y<=330){
        x = 4;
    }
    else if(positionFond.y>330 && positionFond.y<=380){
        x = 5;
    }
    else if(positionFond.y>380 && positionFond.y<=430){
        x = 6;
    }
    else if(positionFond.y>430 && positionFond.y<=480){
        x = 7;
    }
    else if(positionFond.y>480 && positionFond.y<=530){
        x = 8;
    }
    else{
        x = 9;
    }
    if(positionFond.x>445 && positionFond.x<=495){
        y = 1;
    }
    else if(positionFond.x>495 && positionFond.x<=545){
        y = 2;
    }
    else if(positionFond.x>545 && positionFond.x<=595){
        y = 3;
    }
    else if(positionFond.x>595 && positionFond.x<=645){
        y = 4;
    }
    else if(positionFond.x>645 && positionFond.x<=695){
        y = 5;
    }
    else if(positionFond.x>695 && positionFond.x<=745){
        y = 6;
    }
    else if(positionFond.x>745 && positionFond.x<=795){
        y = 7;
    }
    else if(positionFond.x>795 && positionFond.x<=845){
        y = 8;
    }
    else{
        y = 9;
    }

    Coordonees c;
    c.x = x;
    c.y = y;
    return c;
}

