#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Telefone {
    long numero;
    char nome[50];
    struct Telefone* esquerda;
    struct Telefone* direita;
};

struct Telefone* criarTelefone(long numero, const char* nome) {
    struct Telefone* novoTelefone = (struct Telefone*)malloc(sizeof(struct Telefone));
    novoTelefone->numero = numero;
    strcpy(novoTelefone->nome, nome);
    novoTelefone->esquerda = NULL;
    novoTelefone->direita = NULL;
    return novoTelefone;
}

struct Telefone* inserir(struct Telefone* raiz, long numero, const char* nome) {
    if (raiz == NULL) {
        return criarTelefone(numero, nome);
    }
    else {
        if (numero < raiz->numero) {
            raiz->esquerda = inserir(raiz->esquerda, numero, nome);
        }
        else {
            raiz->direita = inserir(raiz->direita, numero, nome);
        }
    }
    return raiz;
}

void percursoEmOrdem(struct Telefone* raiz) {
    if (raiz != NULL) {
        percursoEmOrdem(raiz->esquerda);
        printf("Nome: %s - Número: %ld\n", raiz->nome, raiz->numero);
        percursoEmOrdem(raiz->direita);
    }
}

struct Telefone* encontrarMenorValor(struct Telefone* no) {
    struct Telefone* atual = no;

    while (atual->esquerda != NULL) {
        atual = atual->esquerda;
    }

    return atual;
}

struct Telefone* remover(struct Telefone* raiz, long numero) {
    
    if (raiz == NULL) {
        return raiz;
    }
    
    if (numero < raiz->numero) {
        raiz->esquerda = remover(raiz->esquerda, numero);
    }
    
    else if (numero > raiz->numero) {
        raiz->direita = remover(raiz->direita, numero);
    }
    else {

        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);
            raiz = NULL;
        }
        
        // -
        else if (raiz->esquerda == NULL) {
            struct Telefone* temp = raiz;
            raiz = raiz->direita;
            free(temp);
        }
        else if (raiz->direita == NULL) {
            struct Telefone* temp = raiz;
            raiz = raiz->esquerda;
            free(temp);
        }
        
        else {
            struct Telefone* temp = encontrarMenorValor(raiz->direita);

            // ->
            raiz->numero = temp->numero;
            strcpy(raiz->nome, temp->nome);

            // Remove o sucessor da subárvore direita
            raiz->direita = remover(raiz->direita, temp->numero);
        }
    }
    return raiz;
}

int main() {
    struct Telefone* arvore = NULL;
    arvore = inserir(arvore, 996141491, "Wallace");
    arvore = inserir(arvore, 918521478, "Nadalete");
    arvore = inserir(arvore, 997881270, "Mineda");
    arvore = inserir(arvore, 948165278, "Sabha");
    arvore = inserir(arvore, 999852147, "Bertoti");

    printf("Percurso em ordem:\n");
    percursoEmOrdem(arvore);
    
    printf("elemento removido:\n");
    remover(arvore, 948165278);
    
    printf("Lista final\n");
    percursoEmOrdem(arvore);

    return 0;
}
