#include "jeux.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int nombreDeJeux = 0;

Jeu jeux[100];

int jeu_est_present(char *nomJeu){
  for(int i=0; i<100; i++) //parcours du tableau de jeux
  {
    int identique = 1;
    for (int j = 0; j < 25 && nomJeu[j] != '\0'; j++)
    {
      if (nomJeu[j] != jeux[i].NomJeu[j]) {
          identique = 0;
          break;
      }
    }
    if(identique==1){
      return 0;
    }
  }
  return -1;
}

int liste_jeux() {
    for (int i = 0; i < nombreDeJeux; i++) {
        if (jeux[i].Code != NULL) {
            printf("Jeu téléchargé : %s\n", jeux[i].NomJeu);
        }
    }
    return nombreDeJeux;
}

int ajouter_jeu(char *nomJeu, char *param) {
    if (nombreDeJeux < 100) {
        strcpy(jeux[nombreDeJeux].NomJeu, nomJeu);
        jeux[nombreDeJeux].Code = malloc(rand() % 1000 + 1);
        nombreDeJeux++;
        sleep(10);
        return 0;
    }
    return -1;
}

int supprimer_jeu(char *nomJeu) {
    for (int i = 0; i < nombreDeJeux; i++) {
        if (strcmp(jeux[i].NomJeu, nomJeu) == 0) {
            free(jeux[i].Code);
            jeux[i] = jeux[nombreDeJeux - 1];
            nombreDeJeux--;
            return 0;
        }
    }
    return -1;
}

int simuler_combat(char *nomJeu) {
    if (jeu_est_present(nomJeu) == 0) {
        sleep(20); // Simule le combat
        printf("Gagnant : J%d sur la simulation du combat sur le jeu \"%s\"\n", rand() % 2 + 1, nomJeu);
        return 0;
    }
    return -1;
}


int lancer_jeu(char *nomJeu) {
    if (jeu_est_present(nomJeu) == 0) {
        printf("Lancement du jeu %s...\n", nomJeu);
        getchar(); // Attente utilisateur
        printf("Gagnant : %s\n", rand() % 2 == 0 ? "Serveur" : "Joueur");
        return 0;
    }
    return -1;
}
