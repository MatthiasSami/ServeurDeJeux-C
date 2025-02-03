#include <stdio.h>
#include <stdlib.h>
#include "jeux.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <CodeOp> <Flag>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int codeOp = atoi(argv[1]);
    printf("[%d] Liste des jeux disponibles :\n", codeOp);
    int result = liste_jeux();
    printf("Résultat de l'opération %d : %d\n", codeOp, result);

    return 0;
}
