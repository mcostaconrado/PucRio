#include <stdlib.h>
#include <stdio.h>

#ifndef FILA_H
#define FILA_H
typedef struct Fila Fila;

/* Cria e retorna uma fila vazia.  */
Fila *fila_cria (void);

/* Desaloca uma fila.  */
void fila_destroi (Fila *);

/* Testa se a fila est� vazia.  */
int fila_vazia (Fila *);

/* Insere um novo elemento no fim da fila;
retorna 1 em caso de sucesso, ou 0 caso contr�rio.  */
int fila_insere (Fila *, int);

/* Remove o primeiro elemento da fila e o retorna por par�metro;
retorna 1 em caso de sucesso, ou 0 caso contr�rio.  */
int fila_remove (Fila *, int *);

#endif