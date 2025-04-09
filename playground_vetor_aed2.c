#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
    int tam;
    int* v;
} Vector;


Vector* initialize(int tamanho) {
    Vector* vet = (Vector*) malloc(sizeof(Vector));
    vet->tam = tamanho;
    vet->v = malloc(sizeof(int)*tamanho);
    return vet;
}

void sample(Vector* vet) {
    printf("0 a 10: ");
    int i;
    for(i=0; i<= 10; i++) {
        printf("%d  |", vet->v[i]);
    }
    printf("\n");
    printf("5000 a 5010:  ");
    for(i = 5000; i <= 5010; i++) {
        printf("%d  |", vet->v[i]);
    }
    printf("\n");
    printf("FIM DE SAMPLE\n");
}

void popula_vetor_normal(Vector* vet) {
    int i;
    for(i=0; i < vet->tam; i++) {
        vet->v[i] = i;
    }
}

void popula_vetor_random(Vector* vet) {
    srand(time(NULL));
    int i;
    for(i=0; i<vet->tam; i++) {
        vet->v[i] = rand();
    }
} 

int get(Vector* vet, int i) {
    if(i> vet->tam) {
        printf("Index fora dos limites");
    }
    return vet->v[i];
}

void set(Vector* vet, int i, int value) {
    if(i> vet->tam) {
        printf("Index fora dos limites");
    }
    vet->v[i] = value;
}

int search_sequencial(Vector* vet, int value) {
    int i;
    for(i=0 ; i < vet->tam; i++) {
        if(vet->v[i] == value) {
            return 1;
        }
    }
    return 0;
}

int search_binario(Vector* vet, int value) {
    int inicio = 0;
    int fim = vet->tam - 1;
    while(inicio <= fim) {
        int meio = (inicio + fim) /2;
        if(vet->v[meio] > value) {
            fim = meio-1;
        }
        else if (vet->v[meio] < value) {
            inicio = meio+1;
        }
        else {
            return 1;
        }
    }
    return 0;
}

void bubble_sort(Vector* vet) {
    if(vet->tam <= 1) {
        return;
    }
    int i, j, aux;
    for(i = 0; i < vet->tam - 1; i++) {
        for(j = 0; j < vet->tam - 1 - i; j++) {
            if(vet->v[j] > vet->v[j+1]) {
                aux = vet->v[j+1];
                vet->v[j+1] = vet->v[j];
                vet->v[j] = aux;
            }
        }
    }
}

void insertion_sort(Vector* vet) {
    if(vet->tam <= 1) {
        return;
    }
    int i, j, aux;
    for(i=0; i < vet->tam; i++) {
        aux = vet->v[i];
        j = i-1;
        while (j >= 0 && vet->v[j] > aux) {
            vet->v[j+1] = vet->v[j];
            j--;
        }
        vet->v[j+1] = aux;
    }
}

void selection_sort(Vector* vet){
    if(vet == NULL || vet->tam <= 1) {
            return;
        }
    int i, j, menor, aux;
    for(i=0; i < vet->tam; i++) {
        menor = i;
        for(j = i+1; j < vet->tam; j++) {
            if(vet->v[j] < vet->v[menor]) {
                menor = j;
            }
        }
        if(menor != i) {
            aux = vet->v[i];
            vet->v[i] = vet->v[menor];
            vet->v[menor] = aux; 
        }
    }
}

void recursive_quick_sort(Vector* vet, int inicio, int fim) {
    int i = inicio;
    int j = fim;
    int aux;
    int pivo = vet->v[(inicio+fim)/2];
    while(i <= j) {
        while ( i <= fim && vet->v[i] < pivo) {i++;}
        while ( j >= inicio && vet->v[j] > pivo) {j--;}
        if(i <= j) {
            aux = vet->v[i];
            vet->v[i] = vet->v[j];
            vet->v[j] = aux;
            i++;
            j--;
        }
    }
    if ( i < fim) {recursive_quick_sort(vet, i, fim);}
    if ( j > inicio) {recursive_quick_sort(vet, inicio, j);}
}

void quick_sort(Vector* vet) {
    if (vet == NULL || vet->tam <= 1) {
        return;
    }
    int fim = vet->tam -1;
    recursive_quick_sort(vet, 0, fim);
}

void merge(Vector* vet, int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio+1;
    int k = 0;
    int* temp = (int*) malloc(sizeof(int) * (fim - inicio + 1));
    while(i <= meio && j <= fim) {
        if(vet->v[i] <= vet->v[j]) {
            temp[k] = vet->v[i];
            k++;
            i++;
        } else {
            temp[k] = vet->v[j];
            k++;
            j++;
        }
    }
    while(i <= meio) {
        temp[k] = vet->v[i];
        k++;
        i++;
    }
    while(j <= fim) {
        temp[k] = vet->v[j];
        k++;
        j++;
    }
    k = 0;
    for(i = inicio; i <= fim; i++) {
        vet->v[i] = temp[k];
        k++;
    }
    free(temp);
}

void recursive_merge_sort(Vector* vet, int inicio, int fim) {
    if (inicio >= fim) {
        return;
    }
    int meio = (inicio + fim)/2;
    recursive_merge_sort(vet, inicio, meio);
    recursive_merge_sort(vet, meio+1, fim);
    merge(vet, inicio, meio, fim);
}

void merge_sort(Vector* vet) {
    if(vet == NULL || vet->tam <= 1) {
        return;
    }
    recursive_merge_sort(vet, 0, vet->tam - 1);
}

void main () {
    printf("Iniciando execucao da main\n");
    Vector* v = initialize(10000);
    popula_vetor_random(v);
    sample(v);
    merge_sort(v);
    printf("Teste pos-sort\n");
    sample(v);
}