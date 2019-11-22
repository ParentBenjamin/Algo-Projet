#include "scores.h"

//enregistre le score, retourne 1 si succes, 0 sinon
int enregistrerScore(int score) {
    FILE* fichier = NULL;

    fichier = fopen("scores.txt", "r+");

    if (fichier != NULL) {
        int scoreActuel;
        fscanf(fichier, "%d", &scoreActuel);
        remove("scores.txt");
        fichier = fopen("scores.txt", "r+");
        fprintf(fichier, "%d", scoreActuel+score);
        fclose(fichier);
    } else {
        printf("Impossible d'enregistrer les scores");
        return 0;
    }
    return 1;
}

