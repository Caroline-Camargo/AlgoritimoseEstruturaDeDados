#include <stdio.h>
#include <stdlib.h>

/* 	TAREFA: Preencher uma arvore binária de busca e depois dizer se é AVL ou não quando parar de adicionar nodos
	+ -> Indica o que foi adicionado de novo no código
*/

//Estrutura da Arvore
typedef struct Nodo {
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
void Pop(int procura); //+
void Encerra();	//+

int main() {
	int num = 1;
	printf("\nARVORE BINARIA DE BUSCA\n");
	Reset();

	while (num != 0){
		printf("\n\n----> \tPor favor, Digite um numero: \t (Caso deseja sair digite zero)\n\t");
		scanf("%d", &num);
		if (num != 0) {
			Push(NovoNodo(num));
		} 
	}
	Encerra(); //+
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
					tracer = &((*tracer)->direita);
				}
				
			} else if (nodoADD->chave < (*tracer)->chave) {	//Vai para esquerda
				if ((*tracer)->esquerda == NULL) {			//Encontrou o lugar para adicionar o nó
					(*tracer)->esquerda = nodoADD;
					break;
				} else { 
					tracer = &((*tracer)->esquerda);
				}
			} else { 										//Os nodos possuem o mesmo valor 
				printf("\nATENCAO: Os nodos sao iguais\n");
				free(nodoADD);
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
	if (raiz != NULL) {    							//Caso a arvore tenha nodos para remover
        while (raiz){								//Remove sempre a raiz da árvore
            Pop(raiz->chave);
        }
    }
}

int Altura(Nodo *tracer) {
	int alturaEsquerda = 0, alturaDireita = 0;

	if (tracer != NULL) {
		alturaEsquerda = Altura(tracer->esquerda);	//Calcula altura da esquerda
		alturaDireita = Altura(tracer->direita);	//Calcula altura da direita 
													//+ Tinha colocado: Altura(tracer->esquerda);
	} else {	// +
		return 0;
	}

	if (alturaEsquerda > alturaDireita) {
		return (alturaEsquerda + 1);
	} else {
		return (alturaDireita + 1);
	} 
}

int FatorBalanceamaneto(Nodo *tracer) {
	if (tracer == NULL) { // +
		return 0;
	}
	return (Altura(tracer->esquerda) - Altura(tracer->direita));
}

int VerificaAVL(Nodo *tracer) {
	if (tracer != NULL) {
		int fb = FatorBalanceamaneto(tracer);
		if (fb < -1 || fb > 1) {						//Arvore não esta balanceada 
														//+ Era um ou em vez de um e
			return 0;
		} else { 										//Verifica todos nodos
			if (VerificaAVL(tracer->esquerda) == 0) {	//Arvore não esta balanceada
				return 0;
			} 
			if (VerificaAVL(tracer->direita) == 0) {	//Arvore não esta balanceada
				return 0;
			} 
			return 1;
		}
	}
	return 1;											// + Tracer == NULL a arvore está balanceada
}

void Pop(int procura) {	//+
    Nodo **tracer = &raiz;
    Nodo *pai = NULL;
    int direcao = -1;
    if (raiz != NULL) {    								//Caso a arvore tenha nodos para remover
        while (*tracer){
            if (procura == (*tracer)->chave) {  
                if ((*tracer)->direita == NULL && (*tracer)->esquerda == NULL){  //Removendo nó folha
                    free(*tracer); 

                    if (direcao == 0) {
                        pai->esquerda = NULL;
                    } else if ((direcao == 1)) {
                        pai->direita = NULL;
                    } else {							//ultimo nodo da arvore foi removido
                        raiz = NULL;
                    }

                } else if ((*tracer)->direita != NULL && (*tracer)->esquerda != NULL) { 	// Removendo nó com 2 filhos
                    Nodo *temp = (*tracer)->esquerda; 	//Anda uma vez para esquerda

                    while (temp->direita != NULL) {		//Anda até encontrar o último nó a direita 
                        temp = temp->direita;                        
                    }
					
                    (*tracer)->chave = temp->chave; 
                    temp->chave = procura;
                    Pop(procura);
                                        
                } else { 								//removendo nó com 1 filho
                    Nodo *temp = NULL;
                    if ((*tracer)->direita != NULL) { 
                        temp = (*tracer)->direita;
                    } else {
                        temp = (*tracer)->esquerda;
                    } 

                    free(*tracer); 

                    if (direcao == 0) {
                        pai->esquerda = temp;
                    } else if ((direcao == 1)) {
                        pai->direita = temp;
                    } else {							//primeiro nodo da arvore foi removido
                        raiz = temp;
                    }
                }             
                break;

            } else if (procura > (*tracer)->chave) {    //busca na direita
                if ((*tracer)->direita != NULL) {
                    pai = *tracer;
                    direcao = 1;
                    tracer = &(*tracer)->direita;
                } else {    
                    break;
                }
                  
            } else {    								//busca na esquerda
                if ((*tracer)->esquerda != NULL) {
                    pai = *tracer;
                    direcao = 0;
                    tracer = &(*tracer)->esquerda;
                } else {								//Nodo nao encontrado
                    break;
                }
            }
        }
    }
}

void Encerra() {	//+
	Print();
	int teste = VerificaAVL(raiz);
	if (teste == 1) {
		printf("\n---> A arvore eh AVL\n");
	} else {
		printf("\n---> A arvore nao eh AVL\n");
	}

	Clear();
	raiz = NULL;

	printf("\nSaindo...");
}