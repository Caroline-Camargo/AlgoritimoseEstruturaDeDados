#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    Suponha que uma fila possua 4 valores na seguinte ordem: 1, 2, 3 e 4. 
    Qual seria a sequencia correta de operações de inserção (I) e eliminação (E) para se obter os registros na ordem 2 4 3 1?
*/

#define MAX 10

typedef struct{
	int elemento[MAX];
    int first;
    int last;
    int limite;
}Fila;



//Escopo de funções
Fila* Reset ();
void Push(int num, Fila *minhaFila);
int Pop(Fila *minhaFila);
void Clear(Fila *minhaFila);
void Print(Fila *minhaFila);
int main()
{
    Fila *minhaFila;
    minhaFila = Reset();
    Push(1, minhaFila);
    Push(3, minhaFila);
    Push(4, minhaFila);
    Push(2, minhaFila);

    Print(minhaFila);
    
    printf("\n\nElementos retirados: \n %d", Pop(minhaFila));
    printf("\n %d", Pop(minhaFila));
    printf("\n %d", Pop(minhaFila));
    printf("\n %d", Pop(minhaFila));
    
}

Fila* Reset (){
    Fila *minhaFila = (Fila *) malloc(sizeof(Fila));
    minhaFila->last = 0;
    minhaFila->limite = MAX;
    minhaFila->first = 0;
    return minhaFila;
}

void Push(int num, Fila *minhaFila){
    if (minhaFila->last == minhaFila->limite){
        printf("A Fila ja atingiu a sua capacidade");
    }
    else{
        minhaFila->elemento[minhaFila->last] = num;
        minhaFila->last++;
    }
}


int Pop(Fila *minhaFila){
    int numRemov = 0;
    if (minhaFila->last == 0){
        printf("\nA Fila esta vazia");
        exit (1);
    }
    else{
        numRemov = minhaFila->elemento[minhaFila->first];
        for (int i = minhaFila->first; i < minhaFila->last; i++) {
            minhaFila->elemento[minhaFila->first + i] = minhaFila->elemento[minhaFila->first + i + 1]; 
        }
        minhaFila->last--;
        return (numRemov);
    }
}


void Clear(Fila *minhaFila){
    free(minhaFila);
}

void Print(Fila *minhaFila){
    printf("\n Fila: \n\t");
    for (int i = minhaFila->first; i < minhaFila->last; i++) {
        printf("%d  ", minhaFila->elemento[i]);
    }   
}