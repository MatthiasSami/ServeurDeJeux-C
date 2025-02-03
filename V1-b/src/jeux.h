#ifndef JEUX_H
#define JEUX_H

typedef struct {
    char NomJeu[25];
    char* Code;
} Jeu;

int jeu_est_present(char *nomJeu);
int liste_jeux();
int ajouter_jeu(char *nomJeu, char *param);
int supprimer_jeu(char *nomJeu);
int simuler_combat(char *nomJeu);
int lancer_jeu(char *nomJeu);

#endif
