#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jeux.h"

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <CodeOp> <NomJeu> <Param> <Flag>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int codeOp = atoi(argv[1]);
    char *nomJeu = argv[2];
    char *param = argv[3];
    printf("[%d] Ajout du jeu %s avec paramètre %s\n", codeOp, nomJeu, param);
    int result = ajouter_jeu(nomJeu, param);
    printf("Résultat de l'opération %d : %d\n", codeOp, result);

    return 0;
}
