#ifndef PILHA_INT_H
#define PILHA_INT_H
typedef struct Pilha Pilha;

Pilha *pilha_cria(void);
void pilha_destroi(Pilha*);
int pilha_vazia(Pilha*);
int pilha_push(Pilha*, int);
int pilha_pop(Pilha*, int *);

#endif
