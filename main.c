#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int num;
    struct no *proximo;
}No;

int lernum() {
    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);
    return numero;
}

void imprimirNumero(int num){
    printf("\nO número digitado foi: %d\n", num);
}

/** -------------------------------- Função Empilhar ------------------------------------*/
 
No* empilhar(No *topo){
    No *novo = malloc(sizeof(No));
    
    if(novo){
        novo-> num = lernum();
        novo-> proximo = topo;
        return novo;
    }
    
    else{
        printf("\nErro ao alocar memória!!!\n");
    }
    
}

/** -------------------------------- Função Desempilhar ------------------------------------*/   

No* desempilhar (No **topo){
    if(*topo != NULL){
        No *remover = *topo;
        *topo = remover-> proximo;
        return  remover;
    }
}

/** -------------------------------- Função Imprimir ------------------------------------*/   

void imprimirPilha(No *topo){
    printf("\n---------- PILHA ----------\n");
    
    while(topo){
        imprimirNumero(topo->num);
        topo = topo-> proximo;
    }
    
    printf("\n--------FINAL PILHA -------\n");
}


int main()
{
    No *remover, *topo = NULL;
    int opc;
    
    do{
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\nSelecione uma opção: ");
        scanf("%d", &opc);
        
        switch (opc){
            
            case 1:
            
                topo = empilhar(topo);
                
                break;
                
            case 2:
            
                remover = desempilhar(&topo);
                
                if (remover){
                    printf("\nElemento removido com sucesso!\n");
                    imprimirNumero(remover->num);
                }
                
                break;
                
            case 3:
            
                imprimirPilha(topo);
        } 
        
    } while (opc != 0);
    
}
