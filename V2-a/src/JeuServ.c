#include <stdio.h>
#include <stdlib.h>
#include "jeux.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <CodeOp> <NomJeu> <Flag>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int codeOp = atoi(argv[1]);
    char *nomJeu = argv[2];
    printf("[%d] Lancement du jeu : %s\n", codeOp, nomJeu);

    int result = lancer_jeu(nomJeu);
    printf("Résultat de l'opération %d : %d\n", codeOp, result);

    return 0;
}
