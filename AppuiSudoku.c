#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "InterfaceSudoku.h"
#include "Grille.h"

/**Fonction qui donne les coordonnes du tableau par rapport au clic precedent*/
Coordonees appuiTouche(SDL_Rect positionFond){
    Coordonees c;
    if(positionFond.y<=130 || positionFond.y>580 || positionFond.x<=445 || positionFond.x>895){
        c.x = 0;
        c.y = 0;
        return c;
    }
    if(positionFond.y>130 && positionFond.y<=180){
        c.x = 1;
    }
    else if(positionFond.y>180 && positionFond.y<=230){
        c.x = 2;
    }
    else if(positionFond.y>230 && positionFond.y<=280){
        c.x = 3;
    }
    else if(positionFond.y>280 && positionFond.y<=330){
        c.x = 4;
    }
    else if(positionFond.y>330 && positionFond.y<=380){
        c.x = 5;
    }
    else if(positionFond.y>380 && positionFond.y<=430){
        c.x = 6;
    }
    else if(positionFond.y>430 && positionFond.y<=480){
        c.x = 7;
    }
    else if(positionFond.y>480 && positionFond.y<=530){
        c.x = 8;
    }
    else if(positionFond.y>530 && positionFond.y<=580){
        c.x = 9;
    }
    if(positionFond.x>445 && positionFond.x<=495){
        c.y = 1;
    }
    else if(positionFond.x>495 && positionFond.x<=545){
        c.y = 2;
    }
    else if(positionFond.x>545 && positionFond.x<=595){
        c.y = 3;
    }
    else if(positionFond.x>595 && positionFond.x<=645){
        c.y = 4;
    }
    else if(positionFond.x>645 && positionFond.x<=695){
        c.y = 5;
    }
    else if(positionFond.x>695 && positionFond.x<=745){
        c.y = 6;
    }
    else if(positionFond.x>745 && positionFond.x<=795){
        c.y = 7;
    }
    else if(positionFond.x>795 && positionFond.x<=845){
        c.y = 8;
    }
    else if(positionFond.x>845 && positionFond.x<=895){
        c.y = 9;
    }
    return c;
}

