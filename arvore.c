#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int val;
    struct Node* dir;
    struct  Node* esq;
} Node;

Node* initialize(int val) {
    Node* no = (Node*) malloc(sizeof(Node));
    no->dir = NULL;
    no->esq = NULL;
    no->val = val; 
    return no;
}

Node* insert_arvore (Node* root_insert, int value) {
    Node* No = initialize(value);
    if(root_insert == NULL) {
        root_insert = No;
    } else if (root_insert->val > value) {       
        root_insert->esq = insert_arvore(root_insert->esq, value);
    } else {
        root_insert->dir = insert_arvore(root_insert->dir, value);
    }
    return root_insert;
}

void mostra_arvore (Node* root) {
    if(root != NULL) {
        mostra_arvore(root->esq);
        printf("%d   |", root->val);
        mostra_arvore(root->dir);
    }
}

int main () {
    Node* root = initialize(0);
    insert_arvore(root, 6);
    insert_arvore(root, 20);
    insert_arvore(root, 35);
    insert_arvore(root, 8);
    insert_arvore(root, 1);
    mostra_arvore(root);
}