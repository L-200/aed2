#include <stdio.h>

typedef struct ponto
{
    float x;
    float y;
} ponto;

ponto* cria_ponto(float x, float y);
void libera_ponto(ponto* p);
void mostrar_ponto(ponto* p);
float diferenca_ponto(ponto* p1, ponto* p2);