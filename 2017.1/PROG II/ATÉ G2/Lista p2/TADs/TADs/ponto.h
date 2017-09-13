#ifndef PONTO_H
#define PONTO_H

typedef struct Ponto Ponto;

Ponto *ponto_cria (double, double);
void ponto_destroi (Ponto *);
void ponto_atribui(Ponto *p, double, double);
void ponto_obtem (Ponto *p, double *, double*);
double ponto_distancia(Ponto*, Ponto*);

//int ponto_compara(Ponto *, Ponto *);
//Ponto * ponto_clona (Ponto *);
//void ponto_imprime (Ponto *);


#endif