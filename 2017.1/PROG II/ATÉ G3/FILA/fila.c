#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

typedef struct Elemento{
	int valor;
	struct Elemento *prox;
}Elemento;

struct Fila{
	Elemento *inicio;
	Elemento *fim;
}Fila;

Fila *fila_cria(){
	Fila *f = (Fila*) malloc (sizeof(Fila));
	assert(f!=NULL);
	f->fim = NULL;
	f->inicio = NULL;
	return f;
}

int fila_vazia(Fila *f){
	if (fila->fim == NULL && fila->inicio == NULL)
		return 1;
	return 0;
}

int fila_insere(Fila *f, int x){
	Elemento *p = (Elemento*)malloc(sizeof(*p)); //*p é um Elemento
	if (p==NULL)
		return 0;

	p->valor = x;
	p->prox = NULL;
	if (fila_vazia(f))
		f->inicio = f->fim = p;
	else{
		f->fim->prox = p;
		f->fim = p;
	}
	return 1;
}

int fila_remove(Fila *f, int *x){
	Elemento *p;
	if (lista_vazia(f))
		return 0;
	*x = f->inicio->valor;
	p = f->inicio;
	f->inicio = f->incio->prox;
	if (f->inicio == NULL)
		fim->prox = NULL;
	free (p);
	return 1;
}

void fila_destroi(Fila *f){
	int x;
	/*while (!fila_vazia(f)){
		fila_remove(f, &x);
	}
	free (f);*/
	while(!fila_remove(f,&x));
	free (f);
}