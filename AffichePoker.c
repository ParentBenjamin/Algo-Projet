#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "InterfacePoker.h"
#include "Poker.h"




/**Affiche les cartes des joueurs restants et donne le gagnant et repartit l'argent*/
void finPoker(Tableau pseudo, SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, int nbJoueurs, int numeroJoueur, int nbManche, Parti p, Case t[2*nbJoueurs+5], int newManche, int n1, int nbTour, int blind){

    positionFond.x = 0;
    positionFond.y = 0;
    imageDeFond = SDL_LoadBMP("poker/show.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);

    char machaine[4];
    int monentier;


    positionFond.x = 565;
    positionFond.y = 5;
    monentier = joueurGagnant(p,nbJoueurs)+1;
    sprintf(machaine,"%d",monentier);
    SDL_Color color = {255, 255, 255};
    TTF_Font *police = TTF_OpenFont("font/arialunicode.ttf",60);
    imageDeFond = TTF_RenderText_Blended(police, machaine, color);
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);


    int l = 0;
    int pas = 0;
    for(int i=0;i<nbJoueurs;i++){

        if(p.tableDeJeu[i].coucher==false){
            police = TTF_OpenFont("font/arialunicode.ttf",60);
            color.r = 255;
            color.g = 255;
            color.b = 255;
            positionFond.x = 85 + l;
            positionFond.y = 300;
            monentier = i+1;
            sprintf(machaine,"J%d",monentier);
            imageDeFond = TTF_RenderText_Blended(police, machaine, color);
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
            SDL_Flip(ecran);


            pas = 0;
            for(int j=0;j<2;j++){
            positionFond.x = 10+l+pas;
            positionFond.y = 400;
            imageDeFond = SDL_LoadBMP("poker/carte_blanche.bmp");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
            SDL_Flip(ecran);
            color.r = 0;
            color.g = 0;
            color.b = 0;

            monentier = p.tableDeJeu[i].jeu[j].valeur;
            sprintf(machaine,"%d",monentier);

            positionFond.x = 37+l+pas;
            positionFond.y = 400;

            if(monentier == 10){
                positionFond.x = 25+l+pas;
            }
            else if(monentier == 11){
                sprintf(machaine,"J");
                positionFond.x = 33+l+pas;
            }
            else if(monentier == 12){
                sprintf(machaine,"Q");
                positionFond.x = 33+l+pas;
            }
            else if(monentier == 13){
                sprintf(machaine,"K");
                positionFond.x = 33+l+pas;
            }
            else if(monentier == 14){
                sprintf(machaine,"A");
                positionFond.x = 33+l+pas;
            }

            imageDeFond = TTF_RenderText_Blended(police, machaine, color);
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
            SDL_Flip(ecran);

            positionFond.x = 30+l+pas;
            positionFond.y = 475;
            if(p.tableDeJeu[i].jeu[j].etat == 1){
                imageDeFond = SDL_LoadBMP("poker/coeur.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
            }
            else if(p.tableDeJeu[i].jeu[j].etat == 2){
                imageDeFond = SDL_LoadBMP("poker/pique.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
            }
            else if(p.tableDeJeu[i].jeu[j].etat == 3){
                imageDeFond = SDL_LoadBMP("poker/carreau.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
            }
            else{
                imageDeFond = SDL_LoadBMP("poker/trefle.bmp");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
            }
            pas+=130;
            }
            l+=260;
        }
    }



    SDL_Event event;

     while(positionFond.x>=0 && positionFond.y>=0)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_MOUSEBUTTONUP:
            {
                if(event.button.x>980 && event.button.x<1360 && event.button.y>711 && event.button.y<759){
                    int vainqueur = joueurGagnant(p,nbJoueurs);
                        if(vainqueur==-1){
                            p=repartitionEgaliter(p,nbJoueurs);
                        }
                        else{
                            p = repartitionArgent(p ,vainqueur,nbJoueurs);
                        }
                    int fin=0;
                    for(int k=0;k<nbJoueurs;k++){
                        if(p.tableDeJeu[k].argent<=0 && p.tableDeJeu[k].mise<=0){
                        }
                        else{
                            fin++;
                        }
                    }
                    if(fin==1){
                        resultat(pseudo,ecran,imageDeFond,positionFond,vainqueur,nbJoueurs);
                    }
                    else{
                        cliqueSourisPoker(pseudo,ecran,imageDeFond,positionFond,nbJoueurs, numeroJoueur,nbManche,p,t,1,0,0,blind);
                    }
                    positionFond.x = -1;
                    positionFond.y =-1;
                }
            }
            default : break;
        }
    }

}





void resultat(Tableau pseudo, SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, int vainqueur,int nbJoueurs){
    positionFond.x = 0;
    positionFond.y = 0;
    imageDeFond = SDL_LoadBMP("poker/resultat.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);

    SDL_Event event;
    positionFond.x = 620;
    positionFond.y = 500;
    char machaine[4];
    int monentier = vainqueur+1;
    sprintf(machaine,"%d",monentier);
    positionFond.x = 600;
    positionFond.y = 400;
    SDL_Color color = {255, 0, 0};
    TTF_Font *police = TTF_OpenFont("font/arialunicode.ttf",100);
    imageDeFond = TTF_RenderText_Blended(police, machaine, color);
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
    SDL_Flip(ecran);

    if(vainqueur==0){
        enregistrerScore(pseudo, 1500*nbJoueurs);
    }

    while(positionFond.x>=0 && positionFond.y>=0)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_MOUSEBUTTONUP:
            {
                if(event.button.x>1173 && event.button.x<1345 && event.button.y>684 && event.button.y<743){

                    positionFond.x=-1;
                    positionFond.y=-1;
                }
                break;
            }
            default : break;
        }
    }

}

