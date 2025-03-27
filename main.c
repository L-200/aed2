#include <stdio.h>
#include "ponto.h"
#include <math.h>

void main () {
    ponto* p1 = cria_ponto(4.0, 3.5);
    mostrar_ponto(p1);
    ponto* p2 = cria_ponto(1.7, 2.4);
    mostrar_ponto(p2);
    printf("Os pontos estao a %.2f de distancia\n", diferenca_ponto(p1, p2));
    libera_ponto(p1);
    libera_ponto(p2);
}