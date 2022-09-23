#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    Suponha que uma pilha possua 4 valores na seguinte ordem: 1, 2, 3 e 4. 
    Qual seria a sequencia correta de operações de inserção (I) e eliminação (E) para se obter os registros na ordem 2 4 3 1?
*/

#define MAX 10

typedef struct{
	int elemento[MAX];
    int topo;
    int base;
    int limite;
}Pilha;


//Escopo de funções
Pilha* Reset ();
void Push(int num, Pilha *minhaPilha);
int Pop(Pilha *minhaPilha);
void Clear(Pilha *minhaPilha);

int main()
{
    Pilha *minhaPilha;
    minhaPilha = Reset();
    Push(1, minhaPilha);
    Push(3, minhaPilha);
    Push(4, minhaPilha);
    Push(2, minhaPilha);
    
    printf("\n%d", Pop(minhaPilha));
    printf("\n%d", Pop(minhaPilha));
    printf("\n%d", Pop(minhaPilha));
    printf("\n%d", Pop(minhaPilha));
    
}

Pilha* Reset (){
    Pilha *minhaPilha = (Pilha *) malloc(sizeof(Pilha));
    minhaPilha->base = 0;
    minhaPilha->limite = MAX;
    minhaPilha->topo = 0;
    return minhaPilha;
}

void Push(int num, Pilha *minhaPilha){
    if (minhaPilha->topo == minhaPilha->limite){
        printf("A pilha ja atingiu a sua capacidade");
    }
    else{
        minhaPilha->elemento[minhaPilha->topo] = num;
        minhaPilha->topo++;
    }
}


int Pop(Pilha *minhaPilha){
    int numRemov = 0;
    if (minhaPilha->topo == minhaPilha->base){
        printf("\nA pilha esta vazia");
        exit (1);
    }
    else{
        numRemov = minhaPilha->elemento[minhaPilha->topo - 1];
        minhaPilha->topo--;
        return (numRemov);
    }
}


void Clear(Pilha *minhaPilha){
    free(minhaPilha);
}