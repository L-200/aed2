#include <stdio.h>
#include "ponto.h"
#include <math.h>
#include <stdlib.h>
ponto* cria_ponto (double x, double y) {
    ponto *p = (ponto*) malloc (sizeof(ponto));
    p->x = x;
    p->y = y;
    return p;
}
void libera_ponto(ponto *p) {
    free(p);
}