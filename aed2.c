#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("hello\n");
    clock_t tempo = clock();
    int i;
    int *vet = (int*)malloc(10000000 * sizeof(int));
    srand(time(NULL));
    for (i = 0; i < 10000000; i++) {
        vet[i] = rand();
    }
    for (i = 0; i < 10; i++) {
        printf("%d\n", vet[i]);
    }
    double tempo_exec = (double)(clock() - tempo)/CLOCKS_PER_SEC;
    printf("Demorou %.3f segundos para executar", tempo_exec);
    return 0;
}