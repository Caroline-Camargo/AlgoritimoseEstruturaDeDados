#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void InsertionSort(int *vetor, int tamanho);

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

	InsertionSort(vet, tam);

	printf("\n\nVetor Ordenado\n");
	for (int i = 0; i < tam; i++) {
		printf("%d  ", vet[i]);
	}
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