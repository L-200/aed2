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
    for(i=0;i<100;i++) {
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

void insertion_sort(Int_Linked_List* l) {
    if (l->prim == NULL || l->prim->prox == NULL) {
        return;
    }

    Node* sorted = NULL; // Lista ordenada inicializada
    Node* no_atual = l->prim; // No atual a ser inserido

    while (no_atual != NULL) {
        Node* prox_no = no_atual->prox; // Guarda referencia para o proximo no

        // Insere no_atual na lista ordenada na posição correta
        if (sorted == NULL || sorted->value >= no_atual->value) {
            no_atual->prox = sorted;
            sorted = no_atual;
        } else {
            Node* temp = sorted;
            while (temp->prox != NULL && temp->prox->value < no_atual->value) {
                temp = temp->prox;
            }
            no_atual->prox = temp->prox;
            temp->prox = no_atual;
        }

        no_atual = prox_no; 
    }

    l->prim = sorted; 
}

void selection_sort(Int_Linked_List* l) {
    if (l->prim == NULL || l->prim->prox == NULL) {
        return;
    }
    Node* atual = l->prim;
    while (atual != NULL) {
        Node* menor = atual;
        Node* temp = atual->prox;
        while (temp != NULL) {
            if (temp->value < menor->value) {
                menor = temp;
            }
            temp = temp->prox;
        }
        int aux = atual->value;
        atual->value = menor->value;
        menor->value = aux;
        atual = atual->prox;
    }
}

void quick_sort(Int_Linked_List* l){
    if(l->prim == NULL || l->prim->prox == NULL) {
        return;
    }
    int size = get_size(l);
    int n;
    int pivo = size/2;
    Node* pivo_location = l->prim;
    for(n = 0; n < pivo; n++) {
        pivo_location = pivo_location->prox;
    }
    Node* move_lado_maior;
    Node* move_lado_menor;
    while(move_lado_menor);
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
    Node* n = l->prim;
    int i;
    for(i=0;i<20;i++) {
        printf("%d  |", n->value);
        n = n->prox;
    }
    printf("alo\n");
    selection_sort(l);
    printf("RESPONDE\n");
    n = l->prim;
    for(i=0;i<20;i++) {
        printf("%d  |", n->value);
        n = n->prox;
    }
    printf("\n");
    for(i;i<40;i++) {
        printf("%d  |", n->value);
        n = n->prox;
    }
    printf("\n");
    for(i;i<60;i++) {
        printf("%d  |", n->value);
        n = n->prox;
    }
    printf("fim\n");
}