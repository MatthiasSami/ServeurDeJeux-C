#include <stdio.h>
#include "server.h"
#include <sys/wait.h>
#include <unistd.h>
#include "../include/demande_operation.h"

int main() {
    DemandeOperation operations[6] = {
        {1, "Echec", "http://echecetmat.com", 1},  // Bloquant
        {3, "Go", "http://goettic.com", 1},       // Non bloquant
        {3, "Othello", "http://oterleau.com", 1}, // Non bloquant
        {5, "Echec", "", 0},                      // Bloquant
        {2, "", "", 0},                           // Non bloquant
        {6, "Othello", "", 0}                     // Non bloquant
    };

    for (int i = 0; i < 6; i++) {
        printf("Appel de l'opération %d\n", operations[i].CodeOp);
        execute_demande(operations[i]);
    }

    // Nettoyer tous les processus enfants restants
    int status;
    while (waitpid(-1, &status, 0) > 0);

    return 0;
}
