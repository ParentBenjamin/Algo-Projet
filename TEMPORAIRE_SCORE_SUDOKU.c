#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    float temps;
    clock_t t1, t2;

    t1 = clock();

    //INSERER LE SUDOKU
    //Sleep(5000);

    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    //printf("temps = %f\n", round(temps));
    //printf("score = %d\n", calculScoreSudoku(round(temps)));

    int score = calculScoreSudoku(round(temps));
    enregistrerScore("THEO", score);


    return 0;
}

//calcule le score du sudoku en fonction du temps de jeu
// + 10 min  =  0 points
int calculScoreSudoku(double temps) {
    if (temps >= 600) {
        return 0;
    } else {
        int score = (600 - (int) temps) / 3;
        return score;
    }
}

//retourne l'arrondi du parametre (double)
double round(double value) {
     return floor(value + 0.5);
}
