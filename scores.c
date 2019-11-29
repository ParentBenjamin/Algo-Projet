#include "scores.h"
#include <string.h>

//enregistre le score dans le fichier score du joueur en parametre, 1 si succes 0 sinon
int enregistrerScore(char playerName[], int score) {
    FILE* fichier = NULL;
    char fileName[100] = "score";
    strcat(fileName, playerName);
    strcat(fileName, ".txt");

    fichier = fopen(fileName, "r+");

    if (fichier != NULL) {
        int scoreActuel;
        fscanf(fichier, "%d", &scoreActuel);
        fichier = fopen(fileName, "w+");
        fprintf(fichier, "%d", scoreActuel+score);
        fclose(fichier);
    } else {
        fichier = fopen(fileName, "w");

        if (fichier != NULL) {
            fprintf(fichier,"%d", score);
            fclose(fichier);
        } else {
            printf("Impossible d'ouvrir le fichier score de %s", playerName);
            return 0;
        }
    }
    return 1;
}

//reinitialise le score dans le fichier score du joueur en parametre
void reinitialiserScore(char playerName[]) {
    char fileName[100] = "score";
    strcat(fileName, playerName);
    strcat(fileName, ".txt");

    remove(fileName);
}

//renvoie le score du joueur en parametre
int getScore(char playerName[]) {
    FILE* fichier = NULL;
    char fileName[100] = "score";
    strcat(fileName, playerName);
    strcat(fileName, ".txt");

    fichier = fopen(fileName, "r");

    if (fichier != NULL) {
        int score;
        fscanf(fichier, "%d", &score);
        fclose(fichier);
        return score;
    } else {
        return 0;
    }
}

