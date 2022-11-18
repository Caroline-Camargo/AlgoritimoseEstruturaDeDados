#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
	1- Implementar os algoritmos de ordenação Insertion Sort, Selection Sort, Quick Sort e Merge Sort.
	2- O programa deve solicitar o tamanho do vetor de números (n) que será ordenado
	3- O programa deve preencher um vetor de tamanho n com números aleatórios. Usar srand(time(NULL)); no inicio do programa.
	4- Faça um código que verifica se o resultado dado por cada algoritmo de ordenação está correto.
*/

void InsertionSort(int *vetor, int tamanho);
void SelectionSort(int *vetor, int tamanho);
void QuickSort(int *vetor, int iEsquerda, int iDireita);
void MergeSort(int *vetor, int posicaoInicio, int posicaoFim);
int Verifica(int *vet, int tam);

int main() {
	int tamanho = 0, op = 0;
	
	printf("Por favor, digite o tamanho do vetor\n");
	scanf("%d", &tamanho);
	int vet[tamanho];

	printf("\nVetor Gerado\n");
	for (int i = 0; i < tamanho; i++) {
		vet[i] = rand() % 100;
		printf("%d  ", vet[i]);
	}

	printf("\n\nPor favor, digite qual metodo de ordenacao deseja usar");
	printf("\n-- 1 Insert Sort");
	printf("\n-- 2 Selection Sort");
	printf("\n-- 3 Quick Sort");
	printf("\n-- 4 Merge Sort\n");
	scanf("%d", &op);

	switch (op) {
	case 1:
		InsertionSort(vet, tamanho);
		break;
	case 2:
		SelectionSort(vet, tamanho);
		break;
	case 3:
		QuickSort(vet, 0, tamanho - 1);
		break;
	case 4:
		MergeSort(vet, 0, tamanho);
		break;
	
	default:
		printf("\nOpcao invalida");
		break;
	}


	printf("\n\nComo ficou:\n");
	for (int i = 0; i < tamanho; i++) {
		printf("%d  ", vet[i]);
	}

	if (Verifica(vet, tamanho) == 1){
		printf("\n\n-->O vetor esta ordenado");
	} else{
		printf("\n\n-->O vetor nao esta ordenado");
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

void SelectionSort(int *vetor, int tamanho){
    int min;
    for (int i = 0; i < tamanho; i++){
        min = i;
		for (int j = i + 1; j < tamanho; j++){
			if (vetor[j] < vetor[min]) {
				min = j;
			}
		}
		int temp = vetor[min];
		vetor[min] = vetor[i];
		vetor[i] = temp;
    }
}

void QuickSort(int *vetor, int iEsquerda, int iDireita){
	int i = iEsquerda, j = iDireita, pivo = vetor[(iEsquerda + iDireita) / 2]; 

	do {
		while (vetor[i] < pivo) {
			i++;
		}

		while (vetor[j] > pivo) {
			j--;
		}

		if (i <= j) {
			int temp = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	if (i < iDireita) {
		QuickSort(vetor, i, iDireita);
	}

	if (j > iEsquerda) {
		QuickSort(vetor, iEsquerda, j);
	}
}

void MergeSort(int *vetor, int posicaoInicio, int posicaoFim) {
    int metadeTamanho;
    if(posicaoInicio < posicaoFim) {
		metadeTamanho =  floor((posicaoInicio + posicaoFim ) / 2);
		MergeSort(vetor, posicaoInicio, metadeTamanho);
    	MergeSort(vetor, metadeTamanho + 1, posicaoFim);

		int tamanho, vet1, vet2, fimVet1 = 0, fimVet2 = 0;
		tamanho = posicaoFim - posicaoInicio + 1;
		vet1 = posicaoInicio;
		vet2 = metadeTamanho + 1; 

		int vetorTemp[tamanho];

		for (int i = 0; i < tamanho; i++) {
			if (!fimVet1 && !fimVet2) {
				if(vetor[vet1] < vetor[vet2]) {
					vetorTemp[i] = vetor[vet1];
					vet1++;
				} else {
					vetorTemp[i] = vetor[vet2];
					vet2++;
				}

				if (vet1 > metadeTamanho) {
					fimVet1 = 1;
				}
				if (vet2 > posicaoFim) {
					fimVet2 = 1;
				} 	
			
			} else {
				if (!fimVet1) {
					vetorTemp[i] = vetor[vet1];
					vet1++;
				} else {
					vetorTemp[i] = vetor[vet2];
					vet2++;
				}	
			}
		}

		int k = posicaoInicio;
		for(int i = 0; i < tamanho; i++) {
			vetor[k] = vetorTemp[i];
			k++;
		}   
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
