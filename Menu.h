/*

    Head du fichier Menu.h

*/
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
/**Headers Menu*/
typedef char Tableau[25] ;
int menuPrincipal(Tableau pseudo, SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond);
int ecrirePseudo(int i, Tableau pseudo, Tableau score, SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond);
int tableau_score(int i, Tableau pseudo, Tableau score, SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond);
#endif // MENU_H_INCLUDED
