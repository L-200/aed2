#include <stdio.h>
#include "ponto.h"
#include <math.h>
#include <stdlib.h>
ponto* cria_ponto (float x, float y) {
    ponto *p = (ponto*) malloc (sizeof(ponto));
    p->x = x;
    p->y = y;
    return p;
}
void libera_ponto(ponto *p) {
    free(p);
}
void mostrar_ponto(ponto *p) {
    printf("O ponto esta em %.2f em relacao a x e esta em %.2f em relacao a y\n", p->x, p->y);
}
float diferenca_ponto(ponto* p1, ponto* p2) {
    float diferenca_x = (p2->x - p1->x);
    float diferenca_y = (p2->y - p1->x);
    diferenca_x = (diferenca_x * diferenca_x);
    diferenca_y = (diferenca_y * diferenca_y);
    return sqrt(diferenca_x + diferenca_y); 
}