#include "headers.h"
#include <stdio.h>

int main(int argc, char **argv) {
    afficherHello();
    int M, N, K;
    char * nomFichier = "default";
    //Si les paramètres n'ont pas été saisies sur la ligne de commande on va les chercher dans le fichier inp
    if (argc <= 3) {
        recupererParametres(&M, &N, &K);
    } else {
        M = atoi(argv[1]);
        N = atoi(argv[2]);
        K = atoi(argv[3]);
        nomFichier = argv[4];
    }
    afficherParametres(M, N, K);
    runJeuDeLaVie(M, N, K, argc, nomFichier);
    return(0);
}
