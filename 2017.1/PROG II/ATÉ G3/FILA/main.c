#include <stdio.h>
#include "fila.h"

int main (void) {
	Fila *q = fila_cria ();
	fila_insere (q, 0);
	fila_insere (q, 1);
	fila_insere (q, 2);
	fila_insere (q, 3);
	while (!fila_vazia (q)) {
		int i;
		fila_remove (q, &i);
		printf ("%d\n", i);
	}
	fila_destroi (q);
	return 0;
}