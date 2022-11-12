#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	1- Implementar os algoritmos de ordenação Insertion Sort, Selection Sort, Quick Sort e Merge Sort.
	2- O programa deve solicitar o tamanho do vetor de números (n) que será ordenado
	3- O programa deve preencher um vetor de tamanho n com números aleatórios. Usar srand(time(NULL)); no inicio do programa.
	4- Faça um código que verifica se o resultado dado por cada algoritmo de ordenação está correto.
*/

void InsertionSort(int *vetor, int tamanho);
int Verifica(int *vet, int tam);
clock_t tempo;

int main() {
	int tam = 0;
	
	printf("Por favor, digite o tamanho do vetor\n");
	scanf("%d", &tam);
	int vet[tam];

	printf("Vetor Gerado\n");
	for (int i = 0; i < tam; i++) {
		vet[i] = rand() % 100;
		printf("%d  ", vet[i]);
	}

	clock_t temp = time(NULL);
	FILE* fTempo = NULL;
	if(fTempo == NULL){
		fTempo = fopen("tempo", "r");
	}

	fscanf(fTempo, "%lf",tempo);
	fclose(fTempo);

	InsertionSort(vet, tam);
	InsertionSort(vet, tam);
	InsertionSort(vet, tam);
	InsertionSort(vet, tam);

	printf("\n\nVetor Ordenado\n");
	for (int i = 0; i < tam; i++) {
		printf("%d  ", vet[i]);
	}

	if (Verifica(vet, tam) == 1){
		printf("\n\n-->O vetor esta ordenado");
	} else{
		printf("\n\n-->O vetor nao esta ordenado");
	}
	temp = time(NULL) - temp;
	float t = (((double)temp)/(CLOCKS_PER_SEC));

	printf("\n\nTEMPO: %lf ", t);

	return (0);
}

void InsertionSort(int *vetor, int tamanho) {
	for (int i = 1; i < tamanho; i++) {
		int j = i - 1;
		int temp = vetor[i];

		while (j >= 0 && temp < vetor[j]) {
			vetor[j + 1] = vetor[j];
			j--;
		}
		vetor[j + 1] = temp;
	}	
}

int Verifica(int *vet, int tam) {
	for (int i = 0; i < tam - 1; i++) {
		if (vet[i] > vet[i + 1]){
			return 0;
		}
	}
	return 1;
}