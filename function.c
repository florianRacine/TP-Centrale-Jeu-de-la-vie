#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#include <time.h>
#include <unistd.h>

void recupererParametres(int* p_M, int* p_N, int* p_K) {
    FILE* file = fopen("inp", "r"); // Lecture uniquement

    // Test pour voir si le fichier existe
    if (file == NULL) {
        printf("Erreur! Le fichier de paramètre ne peut pas être ouvert\n");
        exit(-1);
    } else {
        fscanf(file, "%d", p_M);
        fscanf(file, "%d", p_N);
        fscanf(file, "%d", p_K);
    }
    fclose(file);

    return;
}

void recupererCarteInitial(int M, int N, int K, char *nomFichier, int** tableau2d) {
    FILE* file = fopen(nomFichier, "r"); // Lecture uniquement

    // Test pour voir si le fichier existe
    if (file == NULL) {
        printf("Le fichier correspondant à la carte n'a pas été trouvé\n");
    } else {
        printf("Le fichier correspondant à la carte a été trouvé\n");
        for (int i = 0; i < N; i++) { 
            for (int j = 0; j < M; j++) {
                fscanf(file, "%d", &tableau2d[i][j]);
            }
        }
    }

    return;
}

void afficherHello(void) {

    printf("Hello world!\n");

    return;
}

void afficherParametres(int M, int N, int K) {
    printf("Le jeu de la vie va utiliser les paramètres suivants :\n");
    printf("M = %d, ", M);
    printf("N = %d, ", N);
    printf("K = %d\n", K);

    return;
}

void afficherJeuDeLaVie(int M, int N, int** tableau2d) {
    printf("\n");
    printf("+");
    for (int j = 0; j < M; j++) {
        printf("-");
    }
    printf("+\n");

    for (int i = 0; i < N; i++) {
        printf("|");
        for (int j = 0; j < M; j++) {
            if (tableau2d[i][j] == 1) {
                printf("o");
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }

    printf("+");
    for (int j = 0; j < M; j++) {
        printf("-");
    }
    printf("+\n");

    return ;
}

void initialiserTableau(int M, int N, int** tableau2d) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            tableau2d[i][j] = 0;
        }
    }

    return ;
}

void initialiserTableauAleatoire(int M, int N, int** tableau2d) {
    srand(time(NULL)); // Initialisation de la seed du générateur aléatoire

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            tableau2d[i][j] = rand() % 2; // Cellule morte (0) ou vivante (1)
        }
    }

    return ;
}

void avancerGeneration(int M, int N, int** tableau2d) {
    int** nouveauTableau = allouerTableau2D(M, N);

    // Parcours des cellules du tableau d'origine
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int nbVoisinsVivants = 0;

            // Parcours des voisins de la cellule (i,j)
            for(int k = i-1; k <= i+1; k++) {
                for(int l = j-1; l <= j+1; l++) {
                    // Vérification des bords du tableau
                    if(k >= 0 && k < N && l >= 0 && l < M) {
                        if(k != i || l != j) {
                            if(tableau2d[k][l] == 1) {
                                nbVoisinsVivants++;
                            }
                        }
                    }
                }
            }

            // Application des règles du jeu de la vie
            if(tableau2d[i][j] == 0) {
                if(nbVoisinsVivants == 3) {
                    nouveauTableau[i][j] = 1; // Naissance d'une cellule
                } else {
                    nouveauTableau[i][j] = 0;
                }
            } else {
                if(nbVoisinsVivants == 2 || nbVoisinsVivants == 3) {
                    nouveauTableau[i][j] = 1;
                } else {
                    nouveauTableau[i][j] = 0; // Mort d'une cellule
                }
            }
        }
    }

    // Copie du nouveau tableau dans le tableau d'origine
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            tableau2d[i][j] = nouveauTableau[i][j];
        }
    }

    // Libération de la mémoire allouée pour le nouveau tableau
    libererTableau2D(M, N, nouveauTableau);
}

int** allouerTableau2D(int M, int N) {
    int** tableau2d = malloc(N * sizeof(int*)); // Allocation de l'espace mémoire pour les lignes

    for (int i = 0; i < N; i++) {
        tableau2d[i] = malloc(M * sizeof(int)); // Allocation de l'espace mémoire pour les colonnes
    }

    return tableau2d;
}

void libererTableau2D(int M, int N, int** tableau2d) {
    for (int i = 0; i < N; i++) {
        free(tableau2d[i]); // Libération de l'espace mémoire pour les colonnes
    }

    free(tableau2d); // Libération de l'espace mémoire pour les lignes

    return;
}

void runJeuDeLaVie(int M, int N, int K, int argc, char* nomFichier) {
    // Allocation dynamique d'un tableau en 2d
    int** tableau2d = allouerTableau2D(M, N);

    if (argc <= 4) {
        initialiserTableauAleatoire(M, N, tableau2d);
    } else {
        recupererCarteInitial(M ,N ,K, nomFichier, tableau2d);
    }

    afficherJeuDeLaVie(M, N, tableau2d);

    for (int i = 1; i <= K; i++) {
        usleep(500000);
        system("clear");
        printf("Genération numéro : %d", i);
        avancerGeneration(M, N, tableau2d);
        afficherJeuDeLaVie(M, N, tableau2d);
    }

    // Libération du tableau en 2d
    libererTableau2D(M, N, tableau2d);

    return;
}
