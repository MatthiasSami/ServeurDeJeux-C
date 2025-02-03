#include <stdio.h>
#include "server.h"
#include "../include/demande_operation.h"
#include <unistd.h>

int main() {
  DemandeOperation operations[6] = {
      {1, "Echec", "http://echecetmat.com", 0},
      {3, "Go", "http://goettic.com", 0},
      {3, "Othello", "http://oterleau.com", 0},
      {5, "Go", "", 0},
      {2, "", "", 1},
      {6, "Othello", "", 1}
  };

  for (int i = 0; i < 6; i++) {
      printf("Appel de l'opération %d\n", operations[i].CodeOp);
      execute_demande(operations[i]);
  }

  // Attendre la fin des threads non bloquants
  sleep(30); // S'assurer que les threads non bloquants terminent

  return 0;
}
