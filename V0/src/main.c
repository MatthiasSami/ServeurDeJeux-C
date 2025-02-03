#include <stdio.h>
#include "server.h"
#include "../include/demande_operation.h"

int main() {
    DemandeOperation operations[14] = {
        /*
        Ajout de certains jeux dans la base de données
        */
        {3, "Echec", "http://chess.com", 0},
        {3, "Go", "http://go.com", 0},
        {3, "Bataille navale", "http://bataillenavale.com", 0},

        /*
        Test de la présence de jeux dans la base de données
        */
        {1, "Test", "", 0}, //Doit renvoyer -1 (le jeu n'est présent)
        {1, "Go", "", 0}, //Doit renvoyer 0 (le jeu est présent)

        /*
        Test de la liste des jeux
        */
        {2, "", "", 0}, //Doit renvoyer 3 (3 jeux sont présents)

        /*
        Ajout de jeu test
        */
        {3, "Test", "http://test.com", 0},
        {2, "", "", 0}, //Affichage de la liste avec le jeu test et les 3 autres

        /*Suppression du jeu Go*/
        {4, "Go", "", 0},
        {2, "", "", 0}, //Affichage de la liste sans le jeu Go

        /*Simulation d'un combat sur le jeu Test*/
        {5, "Go", "", 0}, //Doit renvoyer -1 (le jeu n'est présent)
        {5, "Test", "", 0}, //Doit renvoyer 0 (le jeu est présent)

        /*Lancement du jeu Echec*/
        {6, "Go", "", 0}, //Doit renvoyer -1 (le jeu n'est présent)    
        {6, "Echec", "", 0}, //Doit renvoyer 0 (le jeu est présent)
    };

    for (int i = 0; i < 14; i++) {
        int res = execute_demande(operations[i]);
        printf("Résultat de l'opération %d: %d\n", operations[i].CodeOp, res);
    }

    return 0;
}
