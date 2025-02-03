#ifndef SERVER_H
#define SERVER_H

#include "../include/demande_operation.h"

void execute_demande(DemandeOperation OP);
void* execute_operation(void *arg);

#endif
