#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
	NOME: Caroline Souza Camargo

	EXERCÍCIO:
	Faça um programa que solicita do usuário uma série de números, cada número pode ser um
	int, float ou double. Antes de solicitar o número pergunte qual tipo de dado o usuário vai entrar.
	Todos os números entrados devem ser armazenados num buffer único. Esse buffer deve ter tamanho dinâmico e não deve desperdiçar memória, por exemplo, alocar sempre espaço para um double quando o usuário inserir um int ou float.
	Você não deve solicitar para o usuário quantos números ele deseja entrar, na escolha do tipo de dados coloque uma opção para parar a entrada da série de números. Após isso você deve imprimir todos os números do buffer, primeiro toda a série em sequência depois novamente, mas primeiro os ints seguido dos floats e doubles.
*/

//Escopo de Funções
int Menu();
void Listar(int quantI, int quantF, int quantD, int *ordemGravada, void *pBuffer);
void ListarInt(int quantI, int quantF, int quantD, int *ordemGravada, void *pBuffer);
void ListarFloat(int quantI, int quantF, int quantD, int *ordemGravada, void *pBuffer);
void ListarDouble(int quantI, int quantF, int quantD, int *ordemGravada, void *pBuffer);

int main()
{  
	void *pBuffer = NULL;
	int *tempInt = NULL;
	float *tempFloat = NULL;
	double *tempDouble = NULL;
	int quantI = 0, quantF = 0, quantD = 0, op = 1, *ordemGravada = NULL;
	/* 												 		  1 -> Inteiro
													 		  2 -> Float
											 		 		  3 -> Double      */
 
	pBuffer = (void*)(malloc(sizeof(int)));
	if (!pBuffer) {
		printf("\nErro de Alocacao de memoria 00");
	}

	ordemGravada = (int*)(malloc(sizeof(int)));
	if (!ordemGravada) {
		printf("\nErro de Alocacao de memoria 01");
	}
	
	while (op!=0) {
		op = Menu();
		switch (op) {
		case 0:
			/* Sair e Listar */
			Listar(quantI, quantF, quantD, ordemGravada, pBuffer);
			ListarInt(quantI, quantF, quantD, ordemGravada, pBuffer);
			ListarFloat(quantI, quantF, quantD, ordemGravada, pBuffer);
			ListarDouble(quantI, quantF, quantD, ordemGravada, pBuffer);

			free(pBuffer);
			free(ordemGravada);
			op=0;
			break;

		case 1:
			/* int */
			quantI++;
			pBuffer = (void*)(realloc(pBuffer, sizeof(int) * quantI + sizeof(float) * quantF + sizeof(double) * quantD));
			if (!pBuffer) {
				printf("\nErro de Alocacao de memoria 02");
			}

			tempInt = (int*)(pBuffer + sizeof(int) * (quantI - 1) + sizeof(float) * quantF + sizeof(double) * quantD);
			if (!tempInt) {
				printf("\nErro de Alocacao de memoria 03");
			}
			
			printf("\n\n\tPor favor, digite um inteiro:  ");
			scanf("%d", tempInt);

			ordemGravada = (int*)(realloc(ordemGravada, sizeof(int) * (quantI + quantF + quantD)));
			if (!ordemGravada) {
				printf("\nErro de Alocacao de memoria 04");
			}
			ordemGravada[quantI + quantF + quantD - 1] = 1;
			break;

		case 2:
			/* float */
			quantF++;
			pBuffer = (void*)(realloc(pBuffer, sizeof(int) * quantI + sizeof(float) * quantF + sizeof(double) * quantD));
			if (!pBuffer) {
				printf("\nErro de Alocacao de memoria 05");
			}

			tempFloat = (float*)(pBuffer + sizeof(int) * quantI + sizeof(float) * (quantF - 1) + sizeof(double) * quantD);
			if (!tempFloat) {
				printf("\nErro de Alocacao de memoria 06");
			}

			printf("\n\n\tPor favor, digite um float:  ");
			scanf("%f", tempFloat);

			ordemGravada = (int*)(realloc(ordemGravada, sizeof(int) * (quantI + quantF + quantD)));
			if (!ordemGravada) {
				printf("\nErro de Alocacao de memoria 07");
			}
			ordemGravada[quantI + quantF + quantD - 1] = 2;
			break;

		case 3:
			/* double */
			quantD++;
			pBuffer = (void*)(realloc(pBuffer, sizeof(int) * quantI + sizeof(float) * quantF + sizeof(double) * quantD));
			if (!pBuffer) {
				printf("\nErro de Alocacao de memoria 08");
			}

			tempDouble = (double*)(pBuffer + sizeof(int) * quantI + sizeof(float) * quantF + sizeof(double) * (quantD - 1));
			if (!tempDouble) {
				printf("\nErro de Alocacao de memoria 09");
			}

			printf("\n\n\tPor favor, digite um double:  ");
			scanf("%lf", tempDouble);

			ordemGravada = (int*)(realloc(ordemGravada, sizeof(int) * (quantI + quantF + quantD)));
			if (!ordemGravada) {
				printf("\nErro de Alocacao de memoria 10");
			}
			ordemGravada[quantI + quantF + quantD - 1] = 3;
			break;
		
		default:
			printf("\n\tInsira um numero valido!");
			break;
		}
	}	
	return (0);
}

int Menu(){
	int op;
	printf("\n\nEscolha uma opcao:");
	printf("\n\t0 - Sair e Listar");
	printf("\n\t1 - Int");
	printf("\n\t2 - Float");
	printf("\n\t3 - Double\n  ");
	scanf("%d", &op);
	return op;
}

void Listar(int quantI, int quantF, int quantD, int *ordemGravada, void *pBuffer){
	int pos = 0;
	printf("\n\tQUANTIDADE  ");
	printf("\n\tINT: %d  FLOAT: %d  DOUBLE: %d", quantI, quantF, quantD);
	printf("\n\n\tNumeros na ordem em que foram adicionados:  \n\t");
	for (int i = 0; i < (quantI + quantF + quantD); i++) {
		if (ordemGravada[i] == 1){
			pos = pos + sizeof(int);
			printf("%d   ", *(int*)(pBuffer + pos - sizeof(int)));	
		} else if (ordemGravada[i] == 2){
			pos = pos + sizeof(float);
			printf("%.2f   ", *(float*)(pBuffer + pos - sizeof(float)));	
		} else {
			pos = pos + sizeof(double);
			printf("%.6f   ", *(double*)(pBuffer + pos - sizeof(double)));	
		}
	}
}

void ListarInt(int quantI, int quantF, int quantD, int *ordemGravada, void *pBuffer){
	int pos = 0;
	printf("\n\n\tNumeros Int:  ");
	for (int i = 0; i < (quantI + quantF + quantD); i++) {
		if (ordemGravada[i] == 1){
			pos = pos + sizeof(int);
			printf("%d   ", *(int*)(pBuffer + pos - sizeof(int)));	
		} else if (ordemGravada[i] == 2){
			pos = pos + sizeof(float);
		} else {
			pos = pos + sizeof(double);
		}
	}
}

void ListarFloat(int quantI, int quantF, int quantD, int *ordemGravada, void *pBuffer){
	int pos = 0;
	printf("\n\tNumeros Float:  ");
	for (int i = 0; i < (quantI + quantF + quantD); i++) {
		if (ordemGravada[i] == 1){
			pos = pos + sizeof(int);
		} else if (ordemGravada[i] == 2){
			pos = pos + sizeof(float);
			printf("%.2f   ", *(float*)(pBuffer + pos - sizeof(float)));	
		} else {
			pos = pos + sizeof(double);
		}
	}
}

void ListarDouble(int quantI, int quantF, int quantD, int *ordemGravada, void *pBuffer){
	int pos = 0;
	printf("\n\tNumeros Double:  ");
	for (int i = 0; i < (quantI + quantF + quantD); i++) {
		if (ordemGravada[i] == 1){
			pos = pos + sizeof(int);
		} else if (ordemGravada[i] == 2){
			pos = pos + sizeof(float);
		} else {
			pos = pos + sizeof(double);
			printf("%.6f   ", *(double*)(pBuffer + pos - sizeof(double)));	
		}
	}
}



