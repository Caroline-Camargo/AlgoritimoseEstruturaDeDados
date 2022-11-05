#include <stdio.h>
#include <stdlib.h>

// Preencher uma arvore binária de busca e depois dizer se é AVL ou não quando parar de adicionar nodos

//Estrutura da Arvore
typedef struct _Nodo {
	int chave;
	struct Nodo *direita;
	struct Nodo *esquerda;
} Nodo;
Nodo *raiz;

//Escopo de Funções
void Reset();
Nodo* NovoNodo(int num);
void Push(Nodo *nodoADD);
void Print();
void PrintPreOrdem(Nodo *tracer);
void PrintPosOrdem(Nodo *tracer);
void PrintOrdem(Nodo *tracer);
void Clear();
int Altura(Nodo *tracer);
int FatorBalanceamaneto(Nodo *tracer);
int VerificaAVL(Nodo *tracer);

int main() {
	int num = 1;
	
	printf("\nARVORE BINARIA DE BUSCA\n");
	Reset();
	while (num != 0){
		if (num != 0) {
			printf("\n\n---- \tPor favor, Digite um numero: \t\t\t (Caso deseja sair digite zero)\n\t");
			scanf("%d", &num);
			Push(NovoNodo(num));
			Print();

			printf("\nAltura: %d", Altura(raiz));
			//printf("\nFator de Balanceamnto: %d", FatorBalanceamaneto(raiz));
		}
	}

	return (0);
}

void Reset() {
	raiz = NULL;
}

Nodo* NovoNodo(int num) {
	Nodo *tempNodo = (Nodo*)(malloc(sizeof(Nodo)));
	if (tempNodo == NULL) {
		printf("\nErro de alocacao de memoria!");
	}
	
	tempNodo->chave = num;
	tempNodo->direita = NULL;
	tempNodo->esquerda = NULL;
	return tempNodo;
}

void Push(Nodo *nodoADD) {
	Nodo **tracer = &raiz;
	if (raiz == NULL) {										//Não foi adicionado nenhum nodo na arvore ainda
		raiz = nodoADD;
	} else {
		while (*tracer != NULL) {
			if (nodoADD->chave > (*tracer)->chave) {		//Vai para direita
				if ((*tracer)->direita == NULL) {			//Encontrou o lugar para adicionar o nó
					(*tracer)->direita = nodoADD;
					break;
				} else {
					tracer = &(*tracer)->direita;
				}
				
			} else if (nodoADD->chave < (*tracer)->chave) {	//Vai para esquerda
				if ((*tracer)->esquerda == NULL) {			//Encontrou o lugar para adicionar o nó
					(*tracer)->esquerda = nodoADD;
					break;
				} else { 
					tracer = &(*tracer)->esquerda;
				}
			} else { 										//Os nodos possuem o mesmo valor 
				printf("\nATENCAO: Os nodos sao iguais");
				break;
			}
		}	
	}
}

void Print(){
	printf("\nPrint em PreOrdem:");
	PrintPreOrdem(raiz);

	printf("\nPrint em Ordem:\t");
	PrintOrdem(raiz);

	printf("\nPrint em PosOrdem:");
	PrintPosOrdem(raiz);
	printf("\n");
}

void PrintPreOrdem(Nodo *tracer) {
	if (tracer != NULL) {
		printf("\t%d", tracer->chave);
		PrintPreOrdem(tracer->esquerda);
		PrintPreOrdem(tracer->direita);
	}
}

void PrintPosOrdem(Nodo *tracer) {
	if (tracer != NULL) {
		PrintPosOrdem(tracer->esquerda);
		PrintPosOrdem(tracer->direita);
		printf("\t%d", tracer->chave);
	}
}

void PrintOrdem(Nodo *tracer) {
	if (tracer != NULL) {
		PrintOrdem(tracer->esquerda);
		printf("\t%d", tracer->chave);
		PrintOrdem(tracer->direita);
	}
}

void Clear(){
	//Função para remover todos elementos e dar um free nos nodos que foram alocados
}

int Altura(Nodo *tracer) {
	int AlturaEsquerda = 0, AlturaDireita = 0;

	if (tracer != NULL) {
		AlturaEsquerda = Altura(tracer->esquerda);	//Calcula altura da esquerda
		AlturaDireita = Altura(tracer->esquerda);	//Calcula altura da direita
	}

	if (AlturaEsquerda > AlturaDireita) {
		return (AlturaEsquerda + 1);
	} else if (AlturaEsquerda < AlturaDireita) {
		return (AlturaDireita + 1);
	} else {
		return 1;
	}
}

int FatorBalanceamaneto(Nodo *tracer){
	return (Altura(tracer->esquerda) - Altura(tracer->direita));
}

int VerificaAVL(Nodo *tracer){
	if (tracer != NULL) {
		int fb = FatorBalanceamaneto(tracer);
		if (fb < -1 && fb > 1){	//Arvore não esta balanceada
			return 0;
		} else { 	//Verifica todos nodos
			if (VerificaAVL(tracer->esquerda) == 0) {	//Arvore não esta balanceada
				return 0;
			} 
			if (VerificaAVL(tracer->direita) == 0) {	//Arvore não esta balanceada
				return 0;
			} 
			return 1;
		}
	}
	return 0;
}
