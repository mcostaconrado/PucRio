#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

typedef struct Elemento {
	int valor;
	struct Elemento *prox;
} Elemento;

struct Pilha {
	Elemento *topo;
};


Pilha *pilha_cria() {
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	p->topo = NULL; //NAO ESQUECER DE INICIAR COM NULL
	return p;
}

void pilha_destroi(Pilha *p) {
	Pilha *p2 = p;
	if (p->topo != NULL) {
		p2->topo = p->topo->prox;
		free(p->topo);
		pilha_destroi(p2);
	}
}

int pilha_vazia(Pilha*p) {
	if (p->topo == NULL)
		return 1;
	return 0;
}

int pilha_push(Pilha *p, int x) {
	Elemento *aux = p->topo;

	Elemento *novo = (Elemento*)malloc(sizeof(Elemento));

	if (novo == NULL)
		return 0;

	novo->valor = x;
	p->topo = novo;
	novo->prox = aux;
	return 1;
}

int pilha_pop(Pilha *p, int *x) {
	if (p->topo != NULL) {
		Elemento *aux = p->topo->prox;
		*x = p->topo->valor;
		free(p->topo);
		p->topo = aux;
		return 1;
	}
	return 0;
}