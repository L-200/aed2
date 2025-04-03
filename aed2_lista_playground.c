#include <stdio.h>
#include <stdlib.h>  
#include <time.h>

typedef struct Node {
    int value;
    struct Node* prox;
} Node;

typedef struct Int_Linked_List {
    Node* prim;
} Int_Linked_List;

Int_Linked_List* initialize() {
    Int_Linked_List* list = (Int_Linked_List*) malloc(sizeof(Int_Linked_List));
    list->prim = NULL;
    return list;
}

int get(Int_Linked_List* l, int i) {
    Node* n;

    for(n = l->prim; n != NULL; n = n->prox) {
        if(i == 0) {
            return n->value;
        }
        i--;
    }

    printf("Index fora dos limites");
}

int get_size(Int_Linked_List* l) {
    if (l->prim == NULL) {
        return 0;
    }
    Node* n = l->prim;
    int i = 1;
    for(i; n->prox != NULL;i++) {
        n = n->prox;
    }
    return i;
}

void popula_lista (Int_Linked_List* l) {
    int i;
    Node* temp = l->prim;
    for(i=0;i<10000;i++) {
        Node* no = (Node*) malloc(sizeof(Node));
        no->value = i;
        no->prox = l->prim;
        l->prim = no;
    }
}

void popula_lista_random (Int_Linked_List* l) {
    srand(time(NULL));
    int i;
    for(i=0;i<20;i++) {
        Node* no = (Node*) malloc(sizeof(Node));
        no->value = rand();
        no->prox = l->prim;
        l->prim = no;
    }
    // Node* no_teste = l->prim;
    // for(i=0;i<50;i++) {
    //     printf("%d  |", no_teste->value);
    //     no_teste = no_teste->prox;
    // }
}


int search_sequencial(Int_Linked_List* l, int value) {
    Node* n;
    int i;
    for(n = l->prim; n->prox != NULL; n = n->prox) {
        if (n->value == value) {
            return 1;
        }
    }
    return 0;
}

int search_binario(Int_Linked_List* l, int value) {
    Node *n;
    int fim = get_size(l);
    int inicio = 0;
    while (inicio <= fim) {
        int pos;
        int meio = inicio + (fim - inicio)/2;
        n = l->prim;
        for(pos=0; pos<meio ; pos++) {
            n = n->prox;
        }
        if(n->value < value) { // 5000 < 50
            fim = meio - 1;
        }   
        else if (n->value > value) { // 5000 > 50
            inicio = meio + 1;
        }
        else {
            return 1;
        }
    }
    return 0;
}

void bubble_sort(Int_Linked_List* l) {
    Node* i;
    Node* j;
    int aux, tamanho = get_size(l);
    if(l->prim) {
        i = l->prim;
        if(i->prox) {
            j = i->prox;
            for(tamanho; tamanho != -1; tamanho--) {
            while (j->prox != NULL) {
                    if (i->value > j->value) {
                        aux = i->value;
                        i->value = j->value;
                        j->value = aux;
                    }
                    j = j->prox;
                    i = i->prox;
                }
                i = l->prim;
                j = i->prox;
            }
        }
    }
}

void main () {
    printf("ola\n");
    Int_Linked_List* l = initialize();
    popula_lista_random(l);
    // printf("alo\n");
  /*int resposta01 = search_sequencial(l, 50);
    int resposta02 = search_sequencial(l, 9560);
    int resposta03 = search_sequencial(l, 20000); */
    // printf("calculando primeira resposta\n");
    // int resposta04 = search_binario(l, 17);
    // printf("calculando segunda resposta\n");
    // int resposta05 = search_binario(l, 949);
    // printf("calculando terceira resposta\n");
    // int resposta06 = search_binario(l, 200000);
    // printf("respostas calculadas:\n");
    // printf("%d\n", resposta04);
    // printf("%d\n", resposta05);
    // printf("%d\n", resposta06);
    bubble_sort(l);
    printf("fim\n");
}