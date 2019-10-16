
#include "Sudoku.h"
int tableauRempli(TAB t){ //verifie si le tableau est rempli, le tableau est rempli quand toutes les case sont différentes de 0
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (t[i][j].valeur == 0){
                return 0;
            }
        }

    }
    return 1;
}
int modifCase(int x,int y,int valeur,TAB t){ //modifie la case par la valeur proposer si les coordonnées sont bonnes, l'etat le permert et si cette valeur n'est ni sur la ligne, ni la colonne, ni la case
    if(x < 10 && y < 10 && valeur < 10) {
        if (t[x - 1][y - 1].etat == 0 ){
            if (1 == verifCarre(t, x, y, valeur) && 1 == VerifColonne(t, x, y, valeur) && 1 == VerifLigne(t, x, y, valeur)) {

                modifValeur(x,y,valeur,t);
                return 1;
            }
            else printf("ne peut etre place ici\n");
        }
        else printf("case bloque\n");return 0;
    }
    else printf("probleme de coordonnées\n");return 0;
}

int modifCase2(int x,int y,int valeur,TAB t){ //modifie la case par la valeur proposer si les coordonnées sont bonnes, l'etat le permert et si cette valeur n'est ni sur la ligne, ni la colonne, ni la case
    if (1 == verifCarre(t, x, y, valeur) && 1 == VerifColonne(t, x, y, valeur) && 1 == VerifLigne(t, x, y, valeur)) {
        modifValeur(x,y,valeur,t);
        return 1;
    }
    //ne peut etre place ici
    return 0;
}

int verifCarre(TAB t ,int x,int y, int valeur){ //verifie a quelle carré(3*3) corresponde les coordonnées et si cette valeur est deja present dans le carré
    int i = 0,j = 0;
    i = coordonneeCarre(x);
    j = coordonneeCarre(y);
    for (int k = i*3-3; k < i*3 ; ++k) {
        for (int l = j*3-3; l < j*3; ++l) {
            if(!(k==x-1 && l == y-1)){
                if (t[k][l].valeur == valeur){
                    return 0;
                }
            }
        }
    }
    return 1;
}

int  VerifLigne(TAB t,int x ,int y , int valeur){ //verifie si la valeur entrer n'est pas deja dans la ligne de la case demande
    for (int i = 0; i < 9; ++i) {
        if(!(i==y-1)){
            if (t[x-1][i].valeur == valeur){
                return 0;
            }
        }
    }
    return 1;
}


int  VerifColonne(TAB t,int x ,int y , int valeur){ //verifie si la valeur entrer n'est pas deja dans la colonne de la case demande
    for (int i = 0; i < 9; ++i) {
        if(!(i==x-1)){
            if (t[i][y-1].valeur == valeur){
                return 0;
            }
        }
    }
    return 1;
}

int coordonneeCarre(int x){  // convertie le x ou le y pour le faire correspondre au carré
    if(x<4) return 1;
    if(x<7) return 2;
    return 3;
}

/*
chargerSudoku prend comme arguments
n un entier
t un TAB
remplis le sudoku avec un sudoku choisis au hasard enregistré dans le fichier "Sudoku.txt". 
Le sudoku est choisis entre la ligne 1 et la ligne n du fichier, 
donc pour avoir une chance d'avoir tout les sudoku enregistré n doit être égale au nombre de ligne du fichier Sudoku.txt
Mettre un n plus grand que le nombre de ligne du fichier Sudoku.txt peut causer des erreur de chargement
renvoie si le remplissage est un succés ou 0 si c'est un echec
*/
int chargerSudoku(TAB t, int n){
	FILE* fichier = NULL;
    fichier = fopen("Sudoku.txt", "r");
	int lim = nbAlea(n);
    if (fichier != NULL){
		for(int i=0;i<lim;i++){
			fseek(fichier, 165, SEEK_CUR);
		}
		if (fscanf(fichier, "[%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d]", 
				&t[0][0].valeur, &t[0][1].valeur, &t[0][2].valeur, &t[0][3].valeur,&t[0][4].valeur, &t[0][5].valeur, &t[0][6].valeur, &t[0][7].valeur, &t[0][8].valeur,
				&t[1][0].valeur, &t[1][1].valeur, &t[1][2].valeur, &t[1][3].valeur,&t[1][4].valeur, &t[1][5].valeur, &t[1][6].valeur, &t[1][7].valeur, &t[1][8].valeur,
				&t[2][0].valeur, &t[2][1].valeur, &t[2][2].valeur, &t[2][3].valeur,&t[2][4].valeur, &t[2][5].valeur, &t[2][6].valeur, &t[2][7].valeur, &t[2][8].valeur,
				&t[3][0].valeur, &t[3][1].valeur, &t[3][2].valeur, &t[3][3].valeur,&t[3][4].valeur, &t[3][5].valeur, &t[3][6].valeur, &t[3][7].valeur, &t[3][8].valeur,
				&t[4][0].valeur, &t[4][1].valeur, &t[4][2].valeur, &t[4][3].valeur,&t[4][4].valeur, &t[4][5].valeur, &t[4][6].valeur, &t[4][7].valeur, &t[4][8].valeur,
				&t[5][0].valeur, &t[5][1].valeur, &t[5][2].valeur, &t[5][3].valeur,&t[5][4].valeur, &t[5][5].valeur, &t[5][6].valeur, &t[5][7].valeur, &t[5][8].valeur,
				&t[6][0].valeur, &t[6][1].valeur, &t[6][2].valeur, &t[6][3].valeur,&t[6][4].valeur, &t[6][5].valeur, &t[6][6].valeur, &t[6][7].valeur, &t[6][8].valeur,
				&t[7][0].valeur, &t[7][1].valeur, &t[7][2].valeur, &t[7][3].valeur,&t[7][4].valeur, &t[7][5].valeur, &t[7][6].valeur, &t[7][7].valeur, &t[7][8].valeur,
				&t[8][0].valeur, &t[8][1].valeur, &t[8][2].valeur, &t[8][3].valeur,&t[8][4].valeur, &t[8][5].valeur, &t[8][6].valeur, &t[8][7].valeur, &t[8][8].valeur) == -1) {
			printf("\n\tErreur impossible de charger le sudoku");
			return 0;
		}else {
			for(int i=0;i<9;i++){
				for(int j=0;j<9;j++){
					if (t[i][j].valeur == 0){
						changementEtat(i+1,j+1,t,0);
					}else {
						changementEtat(i+1,j+1,t,1);
					}
				}
			}
			fclose(fichier);
			return 1;
		}
    }
    else{
        printf("\n\tImpossible d'ouvrir le fichier test.txt");
		return 0;
    }	
}

/*
chargerSudokuSpe prend comme arguments
n un entier
t un TAB
remplis le sudoku avec un sudoku enregistré dans le fichier "Sudoku.txt" a la ligne n
renvoie si le remplissage est un succés ou 0 si c'est un echec
*/
int chargerSudokuSpe(TAB t, int n){
	FILE* fichier = NULL;
    fichier = fopen("Sudoku.txt", "r");
    if (fichier != NULL){
		for(int i=0;i<n-1;i++){
			fseek(fichier, 165, SEEK_CUR);
		}
		if (fscanf(fichier, "[%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d]", 
				&t[0][0].valeur, &t[0][1].valeur, &t[0][2].valeur, &t[0][3].valeur,&t[0][4].valeur, &t[0][5].valeur, &t[0][6].valeur, &t[0][7].valeur, &t[0][8].valeur,
				&t[1][0].valeur, &t[1][1].valeur, &t[1][2].valeur, &t[1][3].valeur,&t[1][4].valeur, &t[1][5].valeur, &t[1][6].valeur, &t[1][7].valeur, &t[1][8].valeur,
				&t[2][0].valeur, &t[2][1].valeur, &t[2][2].valeur, &t[2][3].valeur,&t[2][4].valeur, &t[2][5].valeur, &t[2][6].valeur, &t[2][7].valeur, &t[2][8].valeur,
				&t[3][0].valeur, &t[3][1].valeur, &t[3][2].valeur, &t[3][3].valeur,&t[3][4].valeur, &t[3][5].valeur, &t[3][6].valeur, &t[3][7].valeur, &t[3][8].valeur,
				&t[4][0].valeur, &t[4][1].valeur, &t[4][2].valeur, &t[4][3].valeur,&t[4][4].valeur, &t[4][5].valeur, &t[4][6].valeur, &t[4][7].valeur, &t[4][8].valeur,
				&t[5][0].valeur, &t[5][1].valeur, &t[5][2].valeur, &t[5][3].valeur,&t[5][4].valeur, &t[5][5].valeur, &t[5][6].valeur, &t[5][7].valeur, &t[5][8].valeur,
				&t[6][0].valeur, &t[6][1].valeur, &t[6][2].valeur, &t[6][3].valeur,&t[6][4].valeur, &t[6][5].valeur, &t[6][6].valeur, &t[6][7].valeur, &t[6][8].valeur,
				&t[7][0].valeur, &t[7][1].valeur, &t[7][2].valeur, &t[7][3].valeur,&t[7][4].valeur, &t[7][5].valeur, &t[7][6].valeur, &t[7][7].valeur, &t[7][8].valeur,
				&t[8][0].valeur, &t[8][1].valeur, &t[8][2].valeur, &t[8][3].valeur,&t[8][4].valeur, &t[8][5].valeur, &t[8][6].valeur, &t[8][7].valeur, &t[8][8].valeur) == -1) {
			printf("\n\tErreur impossible de charger le sudoku");
			return 0;
		}else {
			for(int i=0;i<9;i++){
				for(int j=0;j<9;j++){
					if (t[i][j].valeur == 0){
						changementEtat(i+1,j+1,t,0);
					}else {
						changementEtat(i+1,j+1,t,1);
					}
				}
			}
			fclose(fichier);
			return 1;
		}
    }
    else{
        printf("\n\tImpossible d'ouvrir le fichier test.txt");
		return 0;
    }	
}

/*
nbAlea prend comme argument 
n un entier
et renvoie une valeur aléatoire entre 0 et n (n non inclus)
*/
int nbAlea(int n){
	srand (time (NULL));
	return (rand() % n);
}

/*
compterNombreLigneSudoku prend aucun argument
et renvoie le nombre de ligne du fichier "Sudoku.txt"
*/
int compterNombreLigneSudoku(){
	return compterNombreLigneFichier("Sudoku.txt");
}

/*
compterNombreLigneFichier prend comme argument
nom un string
et renvoie le nombre de ligne du fichier nom
*/
int compterNombreLigneFichier(char nom[]){
	FILE* fichier = NULL;
    fichier = fopen(nom, "r");
    if (fichier != NULL){
		int c;
		int nbLignes = 0;
		int c2 = '\0';
		while((c=fgetc(fichier)) != EOF){
			if(c=='\n')
			nbLignes++;
			c2 = c;
			}
		if(c2 != '\n'){
			nbLignes++;
		}
		else {
			fseek(fichier, -3, SEEK_CUR);
			c=fgetc(fichier);
			while (c=='\n'){
				nbLignes--;
				fseek(fichier, -3, SEEK_CUR);
				c=fgetc(fichier);
			}
		}
		fclose(fichier);
	return nbLignes;
	}
    else{
        printf("Impossible d'ouvrir le fichier test.txt");
		return 0;
    }	
	
}

void sudoku(){ //main du sudoku en ligne de commande
    int n;
    int x;
    int y;
    int valeur;
    TAB t;
    int fini = 0;
    while (fini == 0){
        init(9,9,t);
        n =0;
        valeur = 1;
        while (valeur !=-1) { //si on rentre la valeur 0 la grille recommence
            affiche(t);
            printf("la ligne :\n");
            scanf("%d", &x);
            printf("la colonne :\n");
            scanf("%d", &y);
            printf("la valeur :\n");
            scanf("%d", &valeur);
            if (modifCase(x, y, valeur, t) == 1) {
                n++;
            }
            if(tableauRempli(t) == 1){
                fini = 1;
            }
        }

    }
}
