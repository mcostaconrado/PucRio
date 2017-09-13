#include <stdio.h>
#include "pilha.h"

int bal(char* c) {
	Pilha *p = pilha_cria();
	int b;

	for (int i = 0; c[i] != '\0'; i++) {
		if (c[i] == '[')
			pilha_push(p, 1);
		else if (c[i] == ']')
			if (!pilha_pop(p, &b))
				return 0;
	}
	return pilha_vazia(p);
}


void main(void) {
	int f;
	char c[] = "1 + 3[x[321+4] - 40]]";
	printf("%i", bal(c));

	/*Pilha *p = pilha_cria();
	pilha_push(p, 0);
	pilha_push(p, 1);
	pilha_push(p, 2);
	pilha_push(p, 3);

	

/*while (!pilha_vazia(p)) {
		int i;
		pilha_pop(p, &i);
		printf("%d\n", i);
	}
	pilha_destroi(p);
	return 0;*/
}