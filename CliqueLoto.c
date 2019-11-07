#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "InterfaceLoto.h"
#include "loto.h"
#include "tiragee.h"

SDL_Rect cliqueSourisLoto1(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, SDL_Event event, TAB t){

    if(event.button.x>1143 && event.button.x<1294 && event.button.y>670 && event.button.y<705)
    {
        positionFond.x = -1;
        positionFond.y = -1;
        return positionFond;
    }
    if(event.button.x>389 && event.button.x<406 && event.button.y>217 && event.button.y<255){
        positionFond = cliqueSourisLoto2(ecran,imageDeFond,positionFond,t,1);
    }
    if(event.button.x>684 && event.button.x<705 && event.button.y>218 && event.button.y<250){
        positionFond = cliqueSourisLoto2(ecran,imageDeFond,positionFond,t,2);
    }
    if(event.button.x>944 && event.button.x<967 && event.button.y>214 && event.button.y<249){
        positionFond = cliqueSourisLoto2(ecran,imageDeFond,positionFond,t,3);
    }
    return positionFond;
}


SDL_Rect cliqueSourisLoto2(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, TAB t, int choix){
    positionFond.x = 0;
    positionFond.y = 0;
    imageDeFond = SDL_LoadBMP("loto/bingo2.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);
    positionFond.x = 400;
    positionFond.y = 50;
    imageDeFond = SDL_LoadBMP("loto/grille.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);
    if(choix==2 || choix==3){
        positionFond.x = 400;
        positionFond.y = 250;
        imageDeFond = SDL_LoadBMP("loto/grille.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
        if(choix==3){
            positionFond.x = 400;
            positionFond.y = 450;
            imageDeFond = SDL_LoadBMP("loto/grille.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
            SDL_Flip(ecran);
        }
    }
    positionFond.x = 1130;
    positionFond.y = 400;
    SDL_Color color = {255, 0, 0};
    TTF_Font *police = TTF_OpenFont("font/arialunicode.ttf",40);
    imageDeFond = TTF_RenderText_Blended(police, "1", color);
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
    SDL_Flip(ecran);


    //remplirTEST2(t);
    srand(time(NULL)); // Necessaire pour la generation aleatoire (ligne a executer 1 seule fois)
    init(9,9,t);
    Tirage tab;
    initialisationTirage(&tab);
    int numTirage; //numero du tirage actuel
    int victoire = -1; //1 si victoire 0 defaite car pas tous les nums -1 defaite car tous les tirages ont ete effectues

    genererCartons(t,choix);

    numTirage=numtire(&tab);
    majtirage(numTirage,&tab);
    ecrireLoto(t,ecran,imageDeFond,positionFond,choix,tab);

    SDL_Event event;
    while(positionFond.x>=0 && positionFond.y>=0)
    {

        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_MOUSEBUTTONUP:
            {
                if(event.button.x>620 && event.button.x<942 && event.button.y>673 && event.button.y<706){
                    if(tab.nbtirage<90){
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
                    else{
                        positionFond.x = 100;
                        positionFond.y = 250;
                        if(verifierVictoire(t,choix)){
                            imageDeFond = TTF_RenderText_Blended(police, "Gagné", color);
                            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
                            SDL_Flip(ecran);
                        }
                        else{
                            imageDeFond = TTF_RenderText_Blended(police, "Perdu", color);
                            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
                            SDL_Flip(ecran);
                        }
                    }

                }
                else if(event.button.x>133 && event.button.x<452 && event.button.y>676 && event.button.y<705){
                    positionFond.x = -2;
                    positionFond.y = -2;
                    return positionFond;
                    break;
                }
                else{
                    positionFond = cliqueSourisLoto3(tab,ecran,imageDeFond,positionFond,event,t,choix);
                    if(positionFond.x>=0 && tab.nbtirage<90){
                        ecrireLoto(t,ecran,imageDeFond,positionFond,choix,tab);
                        if(verifierVictoire(t,choix)){
                            positionFond.x = 100;
                            positionFond.y = 250;
                            imageDeFond = TTF_RenderText_Blended(police, "Gagné", color);
                            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
                            SDL_Flip(ecran);
                    }
                    }
                }
                break;
            }
            default : break;
        }
    }
}

    /*Victoire ou defaire
    if (victoire == 1) {
        printf("VOUS AVEZ GAGNE !\n Nombre de tirages : %d", t.nbtirage);
    } else if (victoire == 0){
        printf("VOUS AVEZ PERDU !\n Vos cartons ne sont pas remplis !\n Nombre de tirages : %d", t.nbtirage);
    } else {
        printf("VOUS AVEZ PERDU !\n Tous les nombres ont ete tires !\nNombre de tirages : %d", t.nbtirage);
    }

    printf("\nFIN DU JEU\n\n");
*/


SDL_Rect cliqueSourisLoto3(Tirage tab, SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, SDL_Event event, TAB t, int choix){
    int longueur_case,hauteur_case,hauteur_grille;
    hauteur_grille = 0;
    if(tab.nbtirage<90){
    for(int i=0;i<choix;i++)
    {
        hauteur_case = 0;
        for(int l=0;l<3;l++)
        {
            longueur_case = 0;
            for(int j=0;j<9;j++)
            {
                if(event.button.x>400+longueur_case && event.button.x<=460+longueur_case && event.button.y>50+hauteur_case+hauteur_grille && event.button.y<=110+hauteur_case+hauteur_grille)
                {
                    if(tab.tab[tab.nbtirage-1] == t[l+(3*i)][j].valeur){
                        t[l+(3*i)][j].etat = 2;
                   }
                    return positionFond;
                }
                longueur_case += 60;
            }
            hauteur_case +=60;
        }
        hauteur_grille += 200;
    }
    }
    if(event.button.x>1143 && event.button.x<1294 && event.button.y>670 && event.button.y<705)
    {
        positionFond.x = -1;
        positionFond.y = -1;
    }
    return positionFond;
}
