#include "server.h"
#include "jeux.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int execute_demande(DemandeOperation OP) {
  switch (OP.CodeOp) {
        case 1:
          return jeu_est_present(OP.NomJeu);
        case 2:
          return liste_jeux();
        case 3:
          return ajouter_jeu(OP.NomJeu, OP.Param);

        case 4:
          return supprimer_jeu(OP.NomJeu);

        case 5:
          return simuler_combat(OP.NomJeu);

        case 6:
          return lancer_jeu(OP.NomJeu);

        default:
            printf("Opération inconnue\n");
            return -1;
      }
}
