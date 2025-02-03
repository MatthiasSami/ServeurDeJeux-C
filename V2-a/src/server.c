#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// Fonction pour lancer un serveur spécialisé
void lancer_serveur_specialise(DemandeOperation *OP) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("Erreur lors du fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Processus enfant : lancer le serveur spécialisé
        char code_op[10];
        char flag[10];
        sprintf(code_op, "%d", OP->CodeOp);
        sprintf(flag, "%d", OP->flag);

        switch (OP->CodeOp) {
            case 1: // JeuEstPresentServ
                execl("./JeuEstPresentServ", "./JeuEstPresentServ", code_op, OP->NomJeu, flag, NULL);
                break;
            case 2: // ListeJeuxServ
                execl("./ListeJeuxServ", "./ListeJeuxServ", code_op, flag, NULL);
                break;
            case 3: // AjoutJeuServ
                execl("./AjoutJeuServ", "./AjoutJeuServ", code_op, OP->NomJeu, OP->Param, flag, NULL);
                break;
            case 4: // SupprimerJeuServ
                execl("./SupprimerJeuServ", "./SupprimerJeuServ", code_op, OP->NomJeu, flag, NULL);
                break;
            case 5: // CombatServ
                execl("./CombatServ", "./CombatServ", code_op, OP->NomJeu, flag, NULL);
                break;
            case 6: // JeuServ
                execl("./JeuServ", "./JeuServ", code_op, OP->NomJeu, flag, NULL);
                break;
            default:
                fprintf(stderr, "CodeOp non pris en charge : %d\n", OP->CodeOp);
                exit(EXIT_FAILURE);
        }

        // Si execl échoue
        perror("Erreur lors de l'exécution du serveur spécialisé");
        exit(EXIT_FAILURE);
    } else {
        // Processus parent
        if (OP->flag == 1) {
            // Mode bloquant : attendre la fin du processus enfant
            waitpid(pid, NULL, 0);
        } else {
            // Mode non bloquant : continuer sans attendre
            printf("Opération %d lancée en mode non bloquant.\n", OP->CodeOp);
        }
    }
}

// Interface principale pour exécuter une demande
void execute_demande(DemandeOperation OP) {
    lancer_serveur_specialise(&OP);
}
