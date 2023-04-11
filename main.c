#include "headers.h"
#include <stdio.h>

int main() {
    afficherHello();
    int M, N, K;
    recupererParametres(&M, &N, &K);
    afficherParametres(M, N, K);
    runJeuDeLaVie(M, N, K);
    return(0);
}
