#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Faça um programa  que testa a sequencia de caracteres fornecida pelo usuário é um palindromo
	Usuário digita um letra e tecla enter
	AABCCBAA
	ADDFDDA
	X e enter termina a sequencia
	Pop e Push de PILHA
*/


//Estrutura de Dados 
typedef struct Pilha{
	char *sequencia;
    int topo;
    int base;
    int quantLetras;
} Pilha;


//Protótipos das Funções
Pilha* Reset();
void Push(Pilha *pilha, char text);
char Pop(Pilha *pilha);
void Clear(Pilha *pilha);
void PrintPilha(Pilha *pilha);
void TestePalindromo(Pilha *pilha);

int main(){
    Pilha *pilha;
    pilha = Reset();

    char letra="";

	while (letra != 'x') {
		printf("\nDigite um caracter:\t");
		fflush(stdin);
		scanf("%c", &letra);
		letra = tolower(letra);
		fflush(stdin);
		Push(pilha, letra);
	} 
	Clear(pilha);
}

//Inicializa a Pilha
Pilha* Reset(){
    Pilha *pilha = (Pilha *)(malloc(sizeof(Pilha)));
	if (pilha == NULL) {
		printf("Erro de alocacao 1.1");
		exit (1);
	}
    pilha->sequencia = (char *)(malloc(sizeof(char)));
	if (pilha->sequencia == NULL) {
		printf("Erro de alocacao 1.2");
		exit (1);
	}
    pilha->base = 0;
    pilha->topo = 0;
    pilha->quantLetras = 0;
    return pilha;
}

//Adiciona elementos na pilha
void Push(Pilha *pilha, char text){
    if (text != 'x') {    
        pilha->quantLetras++;
        pilha->topo = pilha->quantLetras - 1;
		
		pilha->sequencia = (char *)(realloc(pilha->sequencia, sizeof(char) * pilha->quantLetras + 1));
		if (pilha->sequencia == NULL) {
			printf("Erro de alocacao 2");
			exit (1);
		}
		pilha->sequencia[pilha->topo] = text;
		pilha->sequencia[pilha->topo + 1] = '\0';
    } else if (text == 'x' && pilha->quantLetras == pilha->base) {
		//Não faz o teste do palindromo, pois só foi digitado um x
		printf("\nA pilha esta vazia");
	} else {
		TestePalindromo(pilha);
	}
}

//Remove elementos da pilha
char Pop(Pilha *pilha){
	if (pilha->quantLetras == pilha->base) {
		printf("\n Pilha Vazia \n");
		exit (1);
	}

	char temp = pilha->sequencia[pilha->topo];
    pilha->quantLetras--;
    pilha->topo--;
	pilha->sequencia = (char *)(realloc(pilha->sequencia, sizeof(char) * pilha->quantLetras + 1));
    pilha->sequencia[pilha->topo + 1] = '\0';
	return temp;
}

//Mostra os elementos da pilha
void PrintPilha(Pilha *pilha){
	if (pilha->quantLetras == pilha->base) {
		printf("\n\nPilha Vazia \n");
	} else {
		printf("\n\nRESUMO:");
		printf("\nQuantidade de letras: %d", pilha->quantLetras);
		printf("\nTopo: %d [posicao]", pilha->topo);
		printf("\nBase: %d", pilha->base);
		//printf("\nString formada: %s\n", pilha->sequencia);
		
		char letraTemp="";
		Pilha *pilhaTemp;
		pilhaTemp = Reset();

		printf("\n\nPilha:");
		for (int i = pilha->topo; i >= 0; i--) {
			letraTemp = Pop(pilha);
			printf("\n[%d]\t%c", i, letraTemp);
			Push(pilhaTemp, letraTemp);
		}

		for (int i = pilhaTemp->topo; i >= 0; i--) {
			Push(pilha, Pop(pilhaTemp));
		}	
		Clear(pilhaTemp);
	}
}

//Exclui a pilha
void Clear(Pilha *pilha){
	free(pilha->sequencia);
    free(pilha);
}

void TestePalindromo(Pilha *pilha){	
	int temp = pilha->quantLetras / 2, teste=0;
	Pilha *pilhaTemp;
	pilhaTemp = Reset();

	PrintPilha(pilha);

	for (int i = 0; i < temp; i++) {
		Push(pilhaTemp, Pop(pilha));
	}

	if (pilha->quantLetras != pilhaTemp->quantLetras){ 
		Pop(pilha);
	}

	for (int i = 0; i < temp; i++) {
		if (Pop(pilha) != Pop(pilhaTemp)) {
			teste++;
		}
	}

	if (teste == 0) {
		printf("\n\nEH UM PALINDROMO\n");
	} else {
		printf("\n\nNAO EH UM PALINDROMO\n");
	}

	Clear(pilhaTemp);
}