#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "InterfacePoker.h"
#include "Poker.h"

/**Fonction qui gère tout le poker*/
int cliqueSourisPoker(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, int nbJoueurs, int numeroJoueur, int nbManche, Parti p, Case t[2*nbJoueurs+5], int newManche, int n1, int nbTour, int blind){

    if(newManche == 1){
        for(int k=0;k<nbJoueurs;k++){
            if(p.tableDeJeu[k].coucher==true){
                p.tableDeJeu[k].coucher = false;
            }
        }

        initTirage(nbJoueurs,t);

        remplirTirage(nbJoueurs,t);
        positionFond.x = 5;
        positionFond.y = 5;
        imageDeFond = SDL_LoadBMP("bn/carre-jaune.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);
        p = distribution(nbJoueurs,t,p);
        p = miseDepart(p,nbJoueurs,(nbManche%nbJoueurs));
       if(blind>=nbJoueurs){
            blind = 0;
        }
    }


    while(p.tableDeJeu[numeroJoueur].argent==0 || numeroJoueur+1>nbJoueurs || p.tableDeJeu[numeroJoueur].coucher==true){
        if(numeroJoueur+1>nbJoueurs){
            numeroJoueur -=nbJoueurs;
         }
         else{
            numeroJoueur++;
         }
    }
    SDL_Color color = {255, 255, 255};
    TTF_Font *police = TTF_OpenFont("font/arialunicode.ttf",60);
    int M = maxMise(p,nbJoueurs);
    int somme = M;
    SDL_Event event;
    char machaine[25];
    int monentier;
    positionFond.x =0;
    positionFond.y = 0;
    imageDeFond = SDL_LoadBMP("poker/fond_noir.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);
    if(newManche==1){
        positionFond.x = 100;
        positionFond.y = 100;
        imageDeFond = TTF_RenderText_Blended(police, "Manche Suivante !", color);
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
        SDL_Flip(ecran);
        newManche = 0;
    }
    monentier = numeroJoueur+1;
    sprintf(machaine,"Joueur %d, veuillez cliquer sur ce fond noir",monentier);
    positionFond.x = 100;
    positionFond.y = 200;

    imageDeFond = TTF_RenderText_Blended(police, machaine, color);
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
    SDL_Flip(ecran);
    while(event.type != SDL_MOUSEBUTTONUP){
        SDL_WaitEvent(&event);
    }



    positionFond.x = 0;
    positionFond.y = 0;
    imageDeFond = SDL_LoadBMP("poker/poker.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);

    monentier = numeroJoueur+1;
    sprintf(machaine,"%d",monentier);
    positionFond.x = 948;
    positionFond.y = 270;
    police = TTF_OpenFont("font/arialunicode.ttf",50);
    imageDeFond = TTF_RenderText_Blended(police, machaine, color);
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
    SDL_Flip(ecran);


    police = TTF_OpenFont("font/arialunicode.ttf",30);
    for(int i=0;i<nbJoueurs;i++){
        positionFond.x = 60;
        positionFond.y = 310+i*40;
        monentier = p.tableDeJeu[i].argent;
        sprintf(machaine,"J%d: %d",i+1,monentier);
        imageDeFond = TTF_RenderText_Blended(police, machaine, color);
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
        SDL_Flip(ecran);
    }
    for(int i=0;i<nbJoueurs;i++){
        positionFond.x = 60;
        positionFond.y = 550+i*40;
        monentier = p.tableDeJeu[i].mise;
        sprintf(machaine,"J%d: %d",i+1,monentier);
        imageDeFond = TTF_RenderText_Blended(police, machaine, color);
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
        SDL_Flip(ecran);
    }
    police = TTF_OpenFont("font/arialunicode.ttf",50);


    afficherPoker(ecran,imageDeFond,positionFond,n1,nbTour,p);
    ecrirePoker_2(ecran,imageDeFond,positionFond,potTotale(p,nbJoueurs),p,numeroJoueur);

    ecrirePoker(ecran,imageDeFond,positionFond,somme);
    while(positionFond.x>=0 && positionFond.y>=0)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_MOUSEBUTTONUP:
            {
                if(event.button.x>1197 && event.button.x<1340 && event.button.y>704 && event.button.y<738){
                    return 0;
                }
                else if(event.button.x>744 && event.button.x<840 && event.button.y>601 && event.button.y<734){
                    positionFond.x = 741;
                    positionFond.y = 600;
                    imageDeFond = SDL_LoadBMP("poker/carte_blanche.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                    positionFond.x = 778;
                    monentier = p.tableDeJeu[numeroJoueur].jeu[0].valeur;
                    sprintf(machaine,"%d",monentier);
                    if(monentier == 10){
                        positionFond.x = 760;
                    }
                    else if(monentier == 11){
                        sprintf(machaine,"J");
                    }
                    else if(monentier == 12){
                        sprintf(machaine,"Q");
                    }
                    else if(monentier == 13){
                        sprintf(machaine,"K");
                    }
                    else if(monentier == 14){
                        sprintf(machaine,"A");
                    }
                    color.b = 0;
                    color.g = 0;
                    color.r = 0;

                    imageDeFond = TTF_RenderText_Blended(police, machaine, color);
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
                    SDL_Flip(ecran);


                    positionFond.x = 768;
                    positionFond.y = 670;
                    if(p.tableDeJeu[numeroJoueur].jeu[0].etat == 1){
                        imageDeFond = SDL_LoadBMP("poker/coeur.bmp");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                    else if(p.tableDeJeu[numeroJoueur].jeu[0].etat == 2){
                        imageDeFond = SDL_LoadBMP("poker/pique.bmp");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                    else if(p.tableDeJeu[numeroJoueur].jeu[0].etat == 3){
                        imageDeFond = SDL_LoadBMP("poker/carreau.bmp");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                    else{
                        imageDeFond = SDL_LoadBMP("poker/trefle.bmp");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }

                }
                else if(event.button.x>922 && event.button.x<1018 && event.button.y>601 && event.button.y<734){
                    positionFond.x = 921;
                    positionFond.y = 601;
                    imageDeFond = SDL_LoadBMP("poker/carte_blanche.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_Flip(ecran);
                    positionFond.x = 958;
                    monentier = p.tableDeJeu[numeroJoueur].jeu[1].valeur;
                    sprintf(machaine,"%d",monentier);
                    if(monentier == 10){
                        positionFond.x = 945;
                    }
                    else if(monentier == 11){
                        sprintf(machaine,"J");
                    }
                    else if(monentier == 12){
                        sprintf(machaine,"Q");
                    }
                    else if(monentier == 13){
                        sprintf(machaine,"K");
                    }
                    else if(monentier == 14){
                        sprintf(machaine,"A");
                    }
                    color.b = 0;
                    color.g = 0;
                    color.r = 0;
                    imageDeFond = TTF_RenderText_Blended(police, machaine, color);
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
                    SDL_Flip(ecran);

                    positionFond.x = 947;
                    positionFond.y = 670;
                    if(p.tableDeJeu[numeroJoueur].jeu[1].etat == 1){
                        imageDeFond = SDL_LoadBMP("poker/coeur.bmp");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                    else if(p.tableDeJeu[numeroJoueur].jeu[1].etat == 2){
                        imageDeFond = SDL_LoadBMP("poker/pique.bmp");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                    else if(p.tableDeJeu[numeroJoueur].jeu[1].etat == 3){
                        imageDeFond = SDL_LoadBMP("poker/carreau.bmp");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                    else{
                        imageDeFond = SDL_LoadBMP("poker/trefle.bmp");
                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                        SDL_Flip(ecran);
                    }
                }
                else if(event.button.x>402 && event.button.x<530 && event.button.y>647 && event.button.y<737){
                    p = tapis(p,numeroJoueur);
                    if(!prochaineMiseEgale(((n1+numeroJoueur)%nbJoueurs),p,nbJoueurs) || n1<nbJoueurs-1){
                       cliqueSourisPoker(ecran,imageDeFond,positionFond,nbJoueurs, ++numeroJoueur,nbManche,p,t,0,n1++,nbTour,blind);
                    }
                    else {
                        if(nbTour < 3 && nombreCoucher(p,nbJoueurs)<nbJoueurs){
                            cliqueSourisPoker(ecran,imageDeFond,positionFond,nbJoueurs, ++numeroJoueur,nbManche,p,t,0,0,++nbTour,blind);
                        }
                        else{
                            p = repartitionArgent(p ,1,nbJoueurs);
                            finPoker(ecran,imageDeFond,positionFond,nbJoueurs, blind++,++nbManche,p,t,1,0,0,blind++);
                        }
                    }
                    positionFond.x = -1;
                    positionFond.y = -1;
                }
                else if(event.button.x>503 && event.button.x<526 && event.button.y>589 && event.button.y<607){
                    if(somme>M){
                        somme--;
                        ecrirePoker(ecran,imageDeFond,positionFond,somme);
                    }
                }
                else if(event.button.x>503 && event.button.x<526 && event.button.y>569 && event.button.y<587){
                    if(somme<p.tableDeJeu[numeroJoueur].argent){
                        somme++;
                        ecrirePoker(ecran,imageDeFond,positionFond,somme);
                    }
                }
                else if(event.button.x>418 && event.button.x<513 && event.button.y>542 && event.button.y<564){
                    somme -= M;
                    p = relancer(p,numeroJoueur,somme,nbJoueurs);
                    if(!prochaineMiseEgale(((n1+numeroJoueur)%nbJoueurs),p,nbJoueurs) || n1<nbJoueurs-1){
                       cliqueSourisPoker(ecran,imageDeFond,positionFond,nbJoueurs, ++numeroJoueur,nbManche,p,t,0,n1++,nbTour,blind);
                    }
                    else {
                        if(nbTour < 3 && nombreCoucher(p,nbJoueurs)<nbJoueurs){
                            cliqueSourisPoker(ecran,imageDeFond,positionFond,nbJoueurs, ++numeroJoueur,nbManche,p,t,0,0,++nbTour,blind);
                        }
                        else{
                            p = repartitionArgent(p ,1,nbJoueurs);
                            finPoker(ecran,imageDeFond,positionFond,nbJoueurs, blind+3,++nbManche,p,t,1,0,0,blind++);
                        }
                    }
                    positionFond.x = -1;
                    positionFond.y = -1;
                }
                else if(event.button.x>402 && event.button.x<530 && event.button.y>407 && event.button.y<497){
                    p = Suivre(p, numeroJoueur,nbJoueurs);
                    if(!prochaineMiseEgale(((n1+numeroJoueur)%nbJoueurs),p,nbJoueurs) || n1<nbJoueurs-1){
                       cliqueSourisPoker(ecran,imageDeFond,positionFond,nbJoueurs, ++numeroJoueur,nbManche,p,t,0,++n1,nbTour,blind);
                    }
                    else {
                        if(nbTour < 3 && nombreCoucher(p,nbJoueurs)<nbJoueurs){
                            cliqueSourisPoker(ecran,imageDeFond,positionFond,nbJoueurs, ++numeroJoueur,nbManche,p,t,0,0,++nbTour,blind);
                        }
                        else{
                            finPoker(ecran,imageDeFond,positionFond,nbJoueurs, blind+3,++nbManche,p,t,1,0,0,blind+1);
                        }
                    }
                    positionFond.x = -1;
                    positionFond.y = -1;
                }
                else if(event.button.x>402 && event.button.x<530 && event.button.y>287 && event.button.y<377){
                    p = seCoucher(p, numeroJoueur);
                    if(nombreCoucher(p,nbJoueurs)<nbJoueurs-1){
                       cliqueSourisPoker(ecran,imageDeFond,positionFond,nbJoueurs, ++numeroJoueur,nbManche,p,t,0,n1++,nbTour,blind);
                    }
                    else{
                        int vainqueur = joueurGagnant(p,nbJoueurs);
                        if(vainqueur==-1){
                            p=repartitionEgaliter(p,nbJoueurs);
                        }
                        else{
                            p = repartitionArgent(p ,1,nbJoueurs);
                        }
                        cliqueSourisPoker(ecran,imageDeFond,positionFond,nbJoueurs, blind+3,++nbManche,p,t,1,0,0,blind+1);
                    }
                    positionFond.x = -1;
                    positionFond.y = -1;
                }
            }
        }
    }
}


/**S'occupe du Raise*/
void ecrirePoker(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, int somme){
    positionFond.x = 399;
    positionFond.y = 528;
    imageDeFond = SDL_LoadBMP("poker/raise.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);
    char machaine[6];
    int monentier;
    positionFond.x = 460;
    positionFond.y = 565;
    if(somme>9){
        positionFond.x = 450;
        positionFond.y = 565;
    }
    if(somme>99){
        positionFond.x = 445;
        positionFond.y = 565;
    }
    if(somme>999){
        positionFond.x = 435;
        positionFond.y = 565;
    }

    monentier = somme;
    sprintf(machaine,"%d",monentier);
    SDL_Color color = {0, 0, 0};
    TTF_Font *police = TTF_OpenFont("font/arialunicode.ttf",30);
    imageDeFond = TTF_RenderText_Blended(police, machaine, color);
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
    SDL_Flip(ecran);
}


/**Affiche les mises et le pot*/
void ecrirePoker_2(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond, int pot, Parti p, int numeroJoueur){

    positionFond.x = 864;
    positionFond.y = 56;
    imageDeFond = SDL_LoadBMP("poker/vert_2.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);
    char machaine[6];
    int monentier;
    positionFond.x = 1000;
    positionFond.y = 60;
    if(pot>9){
        positionFond.x = 1000;
        positionFond.y = 60;
    }
    if(pot>99){
        positionFond.x = 1000;
        positionFond.y = 60;
    }
    if(pot>999){
        positionFond.x = 950;
        positionFond.y = 60;
    }

    monentier = pot;
    sprintf(machaine,"%d",monentier);
    SDL_Color color = {255, 255, 255};
    TTF_Font *police = TTF_OpenFont("font/arialunicode.ttf",70);
    imageDeFond = TTF_RenderText_Blended(police, machaine, color);
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
    SDL_Flip(ecran);

    positionFond.x = 900;
    positionFond.y = 400;
    if(p.tableDeJeu[numeroJoueur].mise>9){
        positionFond.x = 900;
        positionFond.y = 400;
    }
    if(p.tableDeJeu[numeroJoueur].mise>99){
        positionFond.x = 900;
        positionFond.y = 400;
    }
    if(p.tableDeJeu[numeroJoueur].mise>999){
        positionFond.x = 870;
        positionFond.y = 400;
    }

    monentier = p.tableDeJeu[numeroJoueur].mise;
    sprintf(machaine,"%d",monentier);
    imageDeFond = TTF_RenderText_Blended(police, machaine, color);
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // On blitte par-dessus l'écran
    SDL_Flip(ecran);
}
