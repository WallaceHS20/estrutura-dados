/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int lernum() {
    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);
    return numero;
}

void imprimirNumero(int num){
    printf("\nO número digitado foi: %d\n", num);
}

typedef struct cel {
    int valor;
    struct cel *seg;
} celula;

void Empilha (int y, celula *p) {
    celula *nova;
    nova = malloc (sizeof (celula));
    nova->valor = y;
    nova->seg = p->seg;
    p->seg = nova;
}

void imprimirPilha(celula *p){
    printf("\n---------- PILHA ----------\n");
    
    while(p){
        imprimirNumero(p->valor);
        p = p-> seg;
    }
    
    printf("\n--------FINAL PILHA -------\n");
}

int main()
{
    
    celula cabeça;
    celula *p;
    p = &cabeça; /* p->seg é o topo da pilha */
    p->seg = NULL;
    
    int n, temp;
    
    printf("Digite quantos numeros voce quer inserir: ");
    scanf("%d", &n);
    
    int lista[n+1];
    lista[0] = p-> valor;
    for (int i = 1; i < n+1; i++) {
        printf("Digite o %dº numero: ", i+1);
        scanf("%d", &lista[i]);
    }
    
    // Ordenar a lista em ordem crescente usando o algoritmo de bubble sort
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (lista[j] > lista[j+1]) {
                temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }
        }
    }
    
     for (int i = 0; i < n; i++) {
        Empilha(lista[i], p);
    }
    
    printf("\n");
    
    imprimirPilha(p);

    return 0;
}


