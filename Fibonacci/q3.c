#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da árvore binária
typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;

// Função para criar um novo nó
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo->esquerdo = NULL;
    novoNo->direito = NULL;
    return novoNo;
}

// Função para inserir um valor na árvore
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->dado) {
        raiz->esquerdo = inserir(raiz->esquerdo, valor);
    } else if (valor > raiz->dado) {
        raiz->direito = inserir(raiz->direito, valor);
    }

    return raiz;
}

// Função para exibir a árvore em pré-ordem
void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);       // Visita o nó atual
        preOrdem(raiz->esquerdo);        // Visita subárvore esquerda
        preOrdem(raiz->direito);         // Visita subárvore direita
    }
}

// Função principal
int main() {
    No* raiz = NULL;

    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 20);

    printf("Elementos da árvore em pré-ordem: ");
    preOrdem(raiz);
    printf("\n"); 

    return 0;
}
