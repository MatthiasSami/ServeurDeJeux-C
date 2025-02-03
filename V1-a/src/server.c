#include "server.h"
#include "jeux.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void execute_demande(DemandeOperation OP) {
  pid_t pid = fork();

  if (pid < 0) {
      perror("Erreur lors du fork");
      exit(EXIT_FAILURE);
  } else if (pid == 0) {
      // Processus enfant
      printf("Exécution de l'opération %d (%s) en mode %s...\n",
             OP.CodeOp, OP.NomJeu, OP.flag == 1 ? "bloquant" : "non bloquant");

      int result = 0;
      switch (OP.CodeOp) {
          case 1:
              result = jeu_est_present(OP.NomJeu);
              break;
          case 2:
              result = liste_jeux();
              break;
          case 3:
              result = ajouter_jeu(OP.NomJeu, OP.Param);
              break;
          case 4:
              result = supprimer_jeu(OP.NomJeu);
              break;
          case 5:
              result = simuler_combat(OP.NomJeu);
              break;
          case 6:
              result = lancer_jeu(OP.NomJeu);
              break;
          default:
              printf("Opération inconnue.\n");
              result = -1;
              break;
      }

      printf("Résultat de l'opération %d: %d\n", OP.CodeOp, result);
      exit(EXIT_SUCCESS); // Fin du processus enfant
  } else {
      // Processus parent
      if (OP.flag == 1) {
          // Bloquant : attendre la fin du processus enfant
          waitpid(pid, NULL, 0);
      } else {
          // Non bloquant : ne pas attendre
          printf("Opération %d lancée en mode non bloquant.\n", OP.CodeOp);
      }
  }
}
