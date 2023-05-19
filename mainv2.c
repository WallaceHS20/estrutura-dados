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
        if (p->valor !=0){
            imprimirNumero(p->valor);
        }
        
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
    
    int lista[n];
    lista[0] = p-> valor;
    for (int i = 0; i < n; i++) {
        printf("Digite o %dº numero: ", i+1);
        scanf("%d", &lista[i]);
    }
    
    //ordenar a lista em ordem crescente
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (lista[j] > lista[j+1]) {
                temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }
        }
    }
    
    //chamada para distribuir os numeros para as celulas
     for (int i = 0; i < n; i++) {
        Empilha(lista[i], p);
    }
    
    printf("\n");
    
    imprimirPilha(p);

    return 0;
}

