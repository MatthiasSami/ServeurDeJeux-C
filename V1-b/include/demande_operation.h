#ifndef DEMANDE_OPERATION_H
#define DEMANDE_OPERATION_H

typedef struct {
    int CodeOp;
    char NomJeu[25];
    char Param[200];
    int flag;
} DemandeOperation;

#endif
