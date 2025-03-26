#include <stdio.h>

typedef struct ponto
{
    double x;
    double y;
} ponto;

ponto cria_ponto(double x, double y);
ponto libera_ponto(double x, double y);
ponto mostrar_ponto(ponto* p);
ponto diferenca_ponto(ponto* p1, ponto* p2);