#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Aluno {
	char nome[256];
	double nota;
}Aluno;

typedef struct Elemento {
	Aluno aluno;
	struct Elemento *prox;
}Elemento;

Elemento *lst_insere(Elemento *lista, char *nome, double nota) {
	Elemento *t, *p=lista;
	t = (Elemento*)malloc(sizeof(Elemento));

	assert(t != NULL);

	t->aluno.nota = nota;
	strcpy(t->aluno.nome, nome);

	t->prox = NULL;

	if (p == NULL) {
		return t;
	}


	for (; p->prox != NULL; p = p->prox );
	p->prox = t;

	return lista;
}

void lst_destroi(Elemento *lista) {
	Elemento *dest = lista, *seguinte;

	if (dest != NULL) {
		seguinte = dest->prox;
		free(dest);
		lst_destroi(seguinte);
	}

}

void lst_imprime(Elemento *lista) {
	if (lista == NULL) {
		printf("\n---FIM---\n\n");
	}
	else {
		printf("\nNOME: %s. NOTA: %lf.\n", lista->aluno.nome, lista->aluno.nota);
		lst_imprime(lista->prox);
	}
}

double lst_calc_media(Elemento *lista) {
	int i;
	double nota = 0;
	Elemento *p = lista;

	for (i = 0; p != NULL; i++) {
		nota += p->aluno.nota;
		p = p->prox;

	}

	if (i != 0)
		return nota/i;
	else {
		printf("\nLISTA VAZIA\n");
		return -1;
	}
}

Elemento *lst_remove_abaixo_media(Elemento *lista) {
	Elemento *atual, *anterior, *aux;
	int i;
	double media = lst_calc_media(lista);
	atual = lista;
	anterior = NULL;

	for (i = 0; atual != NULL; i++) {
		if (atual->aluno.nota >= media) { //caso de nao retirar o elemento
			anterior = atual;
			atual = atual->prox;
		}
		else { //caso de retirar o atual elemento  _> _> _>
			if (anterior == NULL) { //se for o primeiro elemento
				anterior = atual;
				atual = atual->prox;
				free(anterior);
				lista = atual;
			}
			else {
				aux = atual;
				atual = atual->prox;
				anterior->prox = atual;
				free(aux);
			}
		}
	}
	return lista;
}


void main() {
	Elemento *lista = (Elemento*) malloc(sizeof(Elemento));
	lista = NULL;

	lista = lst_insere(lst_insere(lst_insere(lista, "Thiago", 20), "Conrado", 18), "Leo", 3);


	printf("\nALUNOS E NOTAS:\n");
	lst_imprime(lista);

	printf("\nMEDIA: %lf.\n", lst_calc_media(lista));

	printf("\n\nALUNOS COM NOTA ACIMA DA MEDIA: \n");

	lst_imprime(lst_remove_abaixo_media(lista));

	lst_destroi(lista);
}