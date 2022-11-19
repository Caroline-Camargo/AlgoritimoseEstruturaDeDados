#include <stdio.h>
#include <stdlib.h>

/*
	Dado um vetor nums contendo n números inteiros positivos e únicos encontre o número faltante na sequência. Assuma que somente um número está faltando para completar a sequência numérica. 
	A complexidade da resposta não pode ser superior a O(nlogn) Dica, existe uma solução O(n)
*/

void MergeSort(int *vet, int iEsquerda, int iDireita);
int EncontraNum(int *vet, int tamanho);
void VerificaElementosRepetidos(int *vet, int tamanho);	// +
void VersaoN(int *vet, int tamanho);	//+

int main()
{
	int *num = NULL, quant = 0, temp = 0;		
	num = (int *)(malloc(sizeof(int)));	
	if (num == NULL) {
		printf("\n Erro de Alocação de memoria\n");
	}
	
	do {
		printf("\nPor favor, digite numeros:    - Para encerrar digite um numero negativo\n");
		scanf("%d", &temp);

		if (temp >= 0) {
			quant++;
			num = (int *)(realloc(num, sizeof(int) * quant));
			if (num == NULL) {
				printf("\n Erro de Alocação de memoria\n");
			}
			num[quant - 1] = temp;
		}
	} while (temp >= 0);						

	printf("\n\nVetor digitado:   ");
	for (int i = 0; i < quant; i++) {		
		printf("%d  ", num[i]);
	}

	//VersaoN(num, quant);

	MergeSort(num, 0, quant - 1);				//O(n log n)
	VerificaElementosRepetidos(num, quant);		//O(n)

	printf("\n\nVetor ordenado:   ");
	for (int i = 0; i < quant; i++) {		
		printf("%d  ", num[i]);
	}

	printf("\n\nNumero faltante da sequencia: %d", EncontraNum(num, quant));	//O(n)
	
	free(num);
	return (0);
}

void MergeSort(int *vet, int iEsquerda, int iDireita) {
	if (iEsquerda < iDireita) {
		int metade = (iEsquerda + iDireita) / 2;
		MergeSort(vet, iEsquerda, metade);
		MergeSort(vet, metade + 1, iDireita);

		int tamanho = 0, indice1 = 0, indice2 = 0, fimVet1 = 0, fimVet2 = 0;
		tamanho = iDireita - iEsquerda + 1; 
		indice1 = iEsquerda; 							// +
		indice2 = metade + 1;
		int vetTemp[tamanho];

		for (int i = 0; i < tamanho; i++) {				
			if (fimVet1 == 0 && fimVet2 == 0) {
				if (vet[indice1] < vet[indice2]) {
					vetTemp[i] = vet[indice1];
					indice1++;
				} else {
					vetTemp[i] = vet[indice2];
					indice2++;
				}

				if (indice1 > metade) {
					fimVet1 =  1;
				}
				if (indice2 > iDireita) {
					fimVet2 =  1;
				}
			} else if (fimVet1 == 1) {
				vetTemp[i] = vet[indice2];
				indice2++;
			} else {
				vetTemp[i] = vet[indice1];
				indice1++;
			}
		}

		int j = iEsquerda;								// +
		for (int i = 0; i < tamanho; i++) {
			vet[j] = vetTemp[i];
			j++;										// +
		}
	}
}

int EncontraNum(int *vet, int tamanho) {
	int tempProx = vet[0];								// + (Solução quando o vetor tinha uma posicão)
	for (int i = 0; i < tamanho - 1; i++) {
		tempProx = vet[i] + 1;
		if (vet[i + 1] != tempProx) {
			return tempProx;
		}
	}

	tempProx++;											// +
	return tempProx;
}

void VerificaElementosRepetidos(int *vet, int tamanho) { // +
	for (int i = 0; i < tamanho - 1; i++) {
		if (vet[i] == vet[i + 1]) {
			printf("\n\nERRO: O vetor possui elementos repetidos!");
			exit(1);
		}
	}
}

void VersaoN(int *vet, int tamanho) { 		//+ Versão que faz a mesma coisa, mas com complexidade O(n)
	int menor = vet[0], soma = 0;
	for (int i = 0; i < tamanho; i++) {
		if (vet[i] <= menor) {
			menor = vet[i];
		}
		soma = soma + vet[i];
	}

	int somaTotal = menor;
	for (int i = 1; i <= tamanho; i++) {
		menor++;
		somaTotal = somaTotal + menor;
	}

	if ((somaTotal - soma) < 0) {
		printf("\nNumero faltando: %d", vet[tamanho-1] + 1);
	} else {
		printf("\nNumero faltando: %d", somaTotal - soma);
	}
}