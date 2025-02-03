#ifndef SERVER_H
#define SERVER_H

#include "../include/demande_operation.h"
#include <pthread.h>

typedef struct {
    DemandeOperation OP;
    int *result;
} ThreadData;



void execute_demande(DemandeOperation OP);
void* execute_demande_thread(void* arg);

#endif
