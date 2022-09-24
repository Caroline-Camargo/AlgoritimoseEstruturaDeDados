#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Faça um programa  que testa a sequencia de caracteres fornecida pelo usuário é um palindromo
	Usuário digita um letra e tecla enter
	AABCCBAA
	ADDFDDA
	X e enter termina a sequencia
	POP e PUSH de PILHA
*/

void PUSH(char *sequencia, char text[1]);
char POP(char *sequencia);
void PrintPilha(char *sequencia);
int quantLetras = 0;


int main()
{
	char letra[1], *sequencia;

	sequencia = malloc(sizeof(char));
	if (sequencia == NULL) {
		printf("Erro de alocação 1");
		exit (0);
	}
	strcpy(sequencia,"");

	while (letra[0] != 'x') {
		printf("\nDigite um caracter:\t");
		fflush(stdin);
		scanf("%s", letra);
		PUSH(sequencia, letra);
	} 

	PrintPilha(sequencia);
	//char excluido = POP(sequencia);
	PrintPilha(sequencia);
	//printf("\nLetra Excluida: %c\n", excluido);
	printf("\n\nQuantidade de letras: %d \nPalavra: %s\n", quantLetras, sequencia);

	return (0);
}

void PUSH(char *sequencia, char text[]){
	if (text[0] != 'x') {
		quantLetras++;
		sequencia = realloc(sequencia, sizeof(char) * quantLetras);
		if (sequencia == NULL) {
			printf("Erro de alocação 2");
			exit (0);
		}
		strcat(sequencia, text);
	} else {
		//PALAVRAS DE TAMANHO IMPAR

		//PALAVRAS DE TAMAHO PAR
		int cont = 0, teste = quantLetras/2, temp=1; // AB BA
		temp = teste -1;

		for (int i = teste; i > 0; i--) {
			if (sequencia[i] == sequencia[temp]) {
				cont++;
			}
			temp++;
		}

		if (cont == teste) {
			printf("\n\nA palavra eh um palindromo\n\n");
		} else {
			printf("\n\nA palavra nao eh um palindromo\n\n");
		}
	}
}

char POP(char *sequencia){
	if (quantLetras == 0) {
		printf("\n Pilha Vazia \n");
		exit (0);
	}
	
	char temp = sequencia[quantLetras-1];
	quantLetras--;
	sequencia = realloc(sequencia, sizeof(char) * quantLetras);
	return temp;
}

void PrintPilha(char *sequencia){
	if (quantLetras == 0) {
		printf("\n\nPilha Vazia \n");
	} else {
		printf("\n\nPilha:");
		for (int i = quantLetras - 1; i >= 0; i--) {
			printf("\n[%d]\t%c", i, sequencia[i]);
		}
	}
}