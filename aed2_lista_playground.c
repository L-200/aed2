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
    int tamanho = 0;
    Node* n;
    
    // Conta o número de nós corretamente
    for(n = l->prim; n != NULL; n = n->prox) {
        tamanho++;
    }

    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int numero_meio = get(l, meio);  // Supondo que get() retorna o valor na posição "meio"

        if (numero_meio > value) {
            fim = meio - 1;
        } else if (numero_meio < value) {
            inicio = meio + 1;
        } else {
            return 1;  // Encontrado
        }
    }
    return 0;  // Não encontrado
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

void recursive_quick_sort(Int_Linked_List* l, Node* inicio, Node* fim) {
    if (inicio == NULL || fim == NULL || inicio == fim) {
        return;
    }
    Node* pivo = inicio; //escolhido o inicio por que é muito mais facil de implementar
    Node* aux = inicio->prox;
    Node* ultimo_menor = inicio;
    int temp, pivo_value = pivo->value;
    while (aux != NULL && aux != fim->prox) {
        if (aux->value < pivo_value) {
            ultimo_menor = ultimo_menor->prox;
            temp = ultimo_menor->value;
            ultimo_menor->value = aux->value;
            aux->value = temp;
        }
        aux = aux->prox;
    }
    temp = inicio->value;
    inicio->value = ultimo_menor->value;
    ultimo_menor->value = temp;
    pivo = ultimo_menor; //tirar o pivo do inicio e o colocar na divisao entre maiores e menores

    if (pivo != inicio) {
        recursive_quick_sort(l, inicio, pivo);
    }
    if (pivo->prox != NULL && pivo->prox != fim->prox) {
        recursive_quick_sort(l, pivo->prox, fim);
    }
}


void quick_sort(Int_Linked_List* l){
    if(l->prim == NULL || l->prim->prox == NULL) {
        return;
    }
    Node* inicio = l->prim;
    Node* fim;
    for(fim = inicio;fim->prox != NULL; fim = fim->prox);
    recursive_quick_sort(l, inicio, fim);
}

Node* merge(Node* esquerdo, Node* direito) {
    if(esquerdo == NULL) {
        return direito;
    }
    if(direito == NULL ) {
        return esquerdo;
    }
    Node* resultado;
    if(esquerdo->value <= direito->value) {
        resultado = esquerdo;
        resultado->prox = merge(esquerdo->prox, direito);
    } else {
        resultado = direito;
        resultado->prox = merge(esquerdo, direito->prox);
    }
    return resultado;
}

Node* merge_sort_recursive (Node* prim) {
    if(prim == NULL || prim->prox == NULL) {
        return prim;
    }
    Node* devagar = prim;
    Node* rapido = prim->prox;
    while (rapido != NULL && rapido->prox != NULL) //metodo para descobrir o meio e o fim
    { 
        devagar = devagar->prox;
        rapido = rapido->prox->prox;
    }
    Node* meio = devagar->prox; //comeco da nova lista
    devagar->prox = NULL; //fim da primeira lista

    Node* esquerda = merge_sort_recursive(prim);
    Node* direita = merge_sort_recursive(meio);
    return merge(esquerda, direita);
}


void merge_sort(Int_Linked_List* l) {
    if(l->prim == NULL || l->prim->prox == NULL) {
        return;
    }
    l->prim = merge_sort_recursive(l->prim);
    
}

void main () {
    printf("ola\n");
    Int_Linked_List* l = initialize();
    popula_lista(l);
    printf("%d\n", search_binario(l, 1937));
    printf("%d\n", search_binario(l, 9999));
    printf("%d\n", search_binario(l, 12));
    printf("%d\n", search_binario(l, 5677));
}