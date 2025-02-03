#include "server.h"
#include "jeux.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

int valider_demande(DemandeOperation *OP) {
    // Vérifier que le pointeur n'est pas NULL
    if (OP == NULL) {
        fprintf(stderr, "Erreur : DemandeOperation est NULL.\n");
        return -1;
    }

    // Vérifier que le code de l'opération est valide
    if (OP->CodeOp < 1 || OP->CodeOp > 6) {
        fprintf(stderr, "Erreur : CodeOp invalide (%d).\n", OP->CodeOp);
        return -1;
    }

    // Vérifier que le nom du jeu est valide pour les opérations nécessitant un nom
    if ((OP->CodeOp == 1 || OP->CodeOp == 3 || OP->CodeOp == 5 || OP->CodeOp == 6) &&
        (OP->NomJeu == NULL || strlen(OP->NomJeu) == 0)) {
        fprintf(stderr, "Erreur : NomJeu invalide pour l'opération %d.\n", OP->CodeOp);
        return -1;
    }

    // Vérifier que le paramètre est valide pour les opérations nécessitant un paramètre
    if (OP->CodeOp == 3 && (OP->Param == NULL || strlen(OP->Param) == 0)) {
        fprintf(stderr, "Erreur : Param invalide pour l'ajout de jeu.\n");
        return -1;
    }

    // Si toutes les validations passent
    return 0;
}

void *execute_operation(void *arg) {
    DemandeOperation *OP = (DemandeOperation *)arg;
    printf("DEBUG: NomJeu=%s, Param=%s, CodeOp=%d\n", OP->NomJeu, OP->Param, OP->CodeOp);

    if (OP->CodeOp == 2) {
      printf("Exécution de l'opération 2 (Liste des jeux) en mode %s...\n", OP->flag == 1 ? "bloquant" : "non bloquant");
    }
    else if (OP->CodeOp == 5) {
        if (OP->NomJeu && strlen(OP->NomJeu) > 0) {
            printf("Exécution de l'opération 5 (%s) en mode %s...\n", OP->NomJeu, OP->flag == 1 ? "bloquant" : "non bloquant");
        } else {
            printf("Exécution de l'opération 5 (Aucun jeu) en mode %s...\n", OP->flag == 1 ? "bloquant" : "non bloquant");
        }
    }
    else{
      printf("Exécution de l'opération %d (%s) en mode %s...\n",
             OP->CodeOp, (OP->NomJeu && strlen(OP->NomJeu) > 0) ? OP->NomJeu : "N/A", OP->flag == 1 ? "bloquant" : "non bloquant");
    }


    int result = 0;
    switch (OP->CodeOp) {
        case 1:
            result = jeu_est_present(OP->NomJeu);
            break;
        case 2:
            result = liste_jeux();
            break;
        case 3:
            result = ajouter_jeu(OP->NomJeu, OP->Param);
            break;
        case 4:
            result = supprimer_jeu(OP->NomJeu);
            break;
        case 5:
            result = simuler_combat(OP->NomJeu);
            break;
        case 6:
            result = lancer_jeu(OP->NomJeu);
            break;
        default:
            printf("Opération inconnue.\n");
            result = -1;
            break;
    }

    printf("Résultat de l'opération %d: %d\n", OP->CodeOp, result);
    return NULL;
}

void execute_demande(DemandeOperation OP) {
    if (valider_demande(&OP) != 0) {
        fprintf(stderr, "Opération non valide, elle sera ignorée.\n");
        return;
    }

    pthread_t thread;

    if (pthread_create(&thread, NULL, execute_operation, &OP) != 0) {
        perror("Erreur lors de la création du thread");
        exit(EXIT_FAILURE);
    }

    if (OP.flag == 1) {
        // Bloquant : attendre la fin du thread
        pthread_join(thread, NULL);
    } else {
        // Non bloquant : le thread s'exécute en arrière-plan
        printf("Opération %d lancée en mode non bloquant.\n", OP.CodeOp);
    }
}
