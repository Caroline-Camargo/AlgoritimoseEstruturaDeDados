#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Implementar uma agenda (nome, idade, telefone) que armazena os dados numa árvore binária de busca (usuário escolhe qual dado é o fator de precedência). A agenda deve permitir incluir, buscar, remover e imprimir toda a árvore usando pré-ordem, central e pós-ordem.
*/


//Estrutura de Dados 
typedef struct _Arvore{
    char *chave;
	char *nome;
	int idade;
	char *telefone;
    struct _Arvore *esquerda;
	struct _Arvore *direita;
} Arvore;

typedef struct _InfoArvore{
    Arvore *raiz;
    char tipoChave[10];
    int numNodos;
} InfoArvore;


//Protótipos das Funções
Arvore* CriaNodo(char nome[],  int idade, char telefone[], int fator);
InfoArvore* Reset();
void Push(Arvore **raiz, Arvore *newp);
void Clear(Arvore *Arvore);
void PrintArvorePreOrdem(Arvore *arvore);
void PrintArvoreCentral(Arvore *arvore);
void PrintArvorePosOrdem(Arvore *arvore);
void Find(Arvore **raizTemp, char procura[]);
void Pop(Arvore **raizTemp, char procura[]);
int Menu();
int MenuFatorPrecendencia(InfoArvore *info);

int main(){
    int tempInt;
    char tempChar[20], tempChar2[20];
    int opMenu = 0, fatorPrecendencia = 0; 

    InfoArvore *arvore = Reset();

    while (fatorPrecendencia < 1 || fatorPrecendencia > 3) {
        fatorPrecendencia = MenuFatorPrecendencia(arvore); 
        if (fatorPrecendencia < 1 || fatorPrecendencia > 3) {
            printf("\nDigite um numero valido");
        }
    }

    while (opMenu != 5) {
        opMenu = Menu();
        switch (opMenu) {
        case 1:
            printf("\nDigite o nome que deseja incluir: ");
            fflush(stdin);
            scanf("%s", tempChar);

            printf("\nDigite a idade: ");
            fflush(stdin);
            scanf("%d", &tempInt);

            printf("\nDigite o telefone: ");
            fflush(stdin);
            scanf("%s", tempChar2);
            Arvore *arvoreN = CriaNodo(tempChar, tempInt, tempChar2, fatorPrecendencia);
            Push(&(arvore->raiz), arvoreN);
            break;

        case 2:
            printf("\n\nDIGITE O/A %s QUE DESEJA REMOVER\n", arvore->tipoChave);
            fflush(stdin);
            scanf("%s", &tempChar);
            Pop(&(arvore->raiz), tempChar);
            break;

        case 3:
            printf("\n\nDIGITE O/A %s QUE DESEJA BUSCAR\n", arvore->tipoChave);
            fflush(stdin);
            scanf("%s", &tempChar);
            Find(&(arvore->raiz), tempChar);
            break;

        case 4:
            printf("\n\nIMPRESSAO DA ARVORE\n");
            printf("\t1) Central:\n\t");
            PrintArvoreCentral(arvore->raiz);
            
            printf("\n\n\t2) Pre Ordem\n\t");
            PrintArvorePreOrdem(arvore->raiz);

            printf("\n\n\t3) Pos Ordem\n\t");
            PrintArvorePosOrdem(arvore->raiz);
    
        case 5:
            //SAIR
            //Clear(arvore);
            break;
        
        default:
            printf("\n\nATENCAO: Digite um numero valido!\n");
            break;
        }
    }
}

InfoArvore* Reset(){
    InfoArvore *arvore = (InfoArvore *)(malloc(sizeof(InfoArvore)));
    arvore->raiz = NULL;
    arvore->numNodos = 0;
    strcpy(arvore->tipoChave, "");
    return arvore;
}

//Inicializa a Arvore
Arvore* CriaNodo(char nome[],  int idade, char telefone[], int fator) {
    //Cria árvore 
    Arvore *arvore = (Arvore *)(malloc(sizeof(Arvore)));
	if (arvore == NULL) {
		printf("Erro de alocacao 1");
		exit (1);
	}

    //Aloca espaço para o nome e o telefone
    arvore->nome =  (char *)(malloc(sizeof(nome)));
    arvore->telefone = (char *)(malloc(sizeof(telefone)));
    if (arvore->nome == NULL || arvore->telefone == NULL) {
		printf("Erro de alocacao 2");
		exit (1);
	}
    
    //Atribui valores iniciais para as variáveis
	arvore->direita = NULL;
	arvore->esquerda = NULL;
    arvore->idade = idade;
    strcpy(arvore->nome, nome);
    strcpy(arvore->telefone, telefone);

    //Define quem será a chave para o fator de precedencia
    if (fator == 1) {
        arvore->chave =  (char *)(malloc(sizeof(nome)));
        strcpy(arvore->chave, nome);
    } else if (fator == 2) {
        arvore->chave =  (char *)(malloc(sizeof(idade)));
        sprintf(arvore->chave, "%d", idade);
    } else {
        arvore->chave =  (char *)(malloc(sizeof(telefone)));
        strcpy(arvore->chave, telefone);
    }

    if (arvore->chave == NULL) {
		printf("Erro de alocacao 3");
		exit (1);
	}
    return arvore;
}


//Adiciona elementos na Arvore
void Push(Arvore **raizTemp, Arvore *newp){
    Arvore **tracer = raizTemp;
    if (*raizTemp == NULL) {    //Caso a arvore não tenha nenhum nodo ainda
        *raizTemp = newp;
    } else {
        while (*tracer){
            if (strcmp(newp->chave, (*tracer)->chave) > 0) {    //insere na direita
                if ((*tracer)->direita == NULL) {
                    (*tracer)->direita = newp;
                    break;
                } else {    
                    tracer = &(*tracer)->direita;
                }  
            } else {    //insere na esquerda
                if ((*tracer)->esquerda == NULL) {
                    (*tracer)->esquerda = newp;
                    break;
                } else {
                    tracer = &(*tracer)->esquerda;
                }
            }
        }
    }
}
 
//Mostra os elementos da Arvore
void PrintArvorePreOrdem(Arvore *arvore){
	if (arvore){
		printf("   %s  |", arvore->chave);
		PrintArvorePreOrdem(arvore->esquerda);
		PrintArvorePreOrdem(arvore->direita);
	}
}

void PrintArvoreCentral(Arvore *arvore){
    if (arvore){
		PrintArvoreCentral(arvore->esquerda);
        printf("   %s  |", arvore->chave);
		PrintArvoreCentral(arvore->direita);
	}
}

void PrintArvorePosOrdem(Arvore *arvore){
    if (arvore){
		PrintArvorePosOrdem(arvore->esquerda);
		PrintArvorePosOrdem(arvore->direita);
        printf("   %s  |", arvore->chave);
	}
}

// Procura um elemento na árvore (de acordo com a chave escolhida no inicio do código)
void Find(Arvore **raizTemp, char procura[]){
    Arvore **tracer = raizTemp;
    if (*raizTemp == NULL) {    //Caso a arvore não tenha nenhum nodo ainda
        printf("\nNao existe nenhum nodo na arvore");
    } else {
        while (*tracer){
            if (strcmp(procura, (*tracer)->chave) == 0) {  
                printf ("\nNodo encontrado!");
                printf ("\n\tNome: %s", (*tracer)->nome);
                printf ("\n\tIdade: %d", (*tracer)->idade);
                printf ("\n\tTelefone: %s", (*tracer)->telefone);
                break;
            } else if (strcmp(procura, (*tracer)->chave) > 0) {    //busca na direita
                if ((*tracer)->direita != NULL) {
                    tracer = &(*tracer)->direita;
                } else {    
                    printf ("\nNodo nao encontrado!");
                    break;
                }  
            } else {    //busca na esquerda
                if ((*tracer)->esquerda != NULL) {
                    tracer = &(*tracer)->esquerda;
                } else {
                    printf ("\nNodo nao encontrado!");
                    break;
                }
            }
        }
    }
}

void Pop(Arvore **raizTemp, char procura[]){
    Arvore **tracer = raizTemp;
    Arvore *pai;
    int direcao = -1;
    if (*raizTemp == NULL) {    //Caso a arvore não tenha nenhum nodo ainda
        printf("\nNao existe nenhum nodo na arvore para ser removido");
    } else {
        while (*tracer){
            if (strcmp(procura, (*tracer)->chave) == 0) {  
                if ((*tracer)->direita == NULL && (*tracer)->esquerda == NULL){  //Removendo nó folha
                    printf ("\nCaso de remocao: No folha");
                    free((*tracer)->chave); 
                    free((*tracer)->nome);
                    free((*tracer)->telefone);  
                    free((*tracer)); 

                    if (direcao == 0) {
                        pai->esquerda = NULL;
                    } else if ((direcao == 1)) {
                        pai->direita = NULL;
                    } else {
                        printf ("\nO ultimo nodo da arvore foi removido");
                        *raizTemp = NULL;
                    }

                } else if ((*tracer)->direita != NULL && (*tracer)->esquerda != NULL) { // Removendo nó com 2 filhos
                    printf ("\nCaso de remocao: No com dois filhos");
                    Arvore *temp = (*tracer)->esquerda; 
                    Arvore *temp2; 

                    while (temp->direita != NULL) {
                        temp2 = temp;
                        temp = temp->direita;                        
                    }

                    strcpy((*tracer)->chave, temp->chave);
                    strcpy((*tracer)->nome, temp->nome);
                    strcpy((*tracer)->telefone, temp->telefone);
                    (*tracer)->idade = temp->idade;

                    strcpy(temp->chave, procura);
                    Pop(&(*tracer)->esquerda, procura);
                                        
                } else { // Removendo nó com 1 filho
                   printf ("\nCaso de remocao: No com 1 filho");
                    Arvore *temp;
                    if ((*tracer)->direita != NULL) { 
                        temp = (*tracer)->direita;
                    } else {
                        temp = (*tracer)->esquerda;
                    } 

                    free((*tracer)->chave); 
                    free((*tracer)->nome);
                    free((*tracer)->telefone);  
                    free((*tracer)); 

                    if (direcao == 0) {
                        pai->esquerda = temp;
                    } else if ((direcao == 1)) {
                        pai->direita = temp;
                    } else {
                        printf ("\nO primeiro nodo da arvore foi removido");
                        *raizTemp = temp;
                    }
                }             
                break;
            } else if (strcmp(procura, (*tracer)->chave) > 0) {    //busca na direita
                if ((*tracer)->direita != NULL) {
                    pai = *tracer;
                    direcao = 1;
                    tracer = &(*tracer)->direita;
                } else {    
                    printf ("\nNodo nao encontrado!");
                    break;
                }  
            } else {    //busca na esquerda
                if ((*tracer)->esquerda != NULL) {
                    pai = *tracer;
                    direcao = 0;
                    tracer = &(*tracer)->esquerda;
                } else {
                    printf ("\nNodo nao encontrado!");
                    break;
                }
            }
        }
    }
}

int FatorBalanceamento(Arvore *raizTemp){
    if (raizTemp) {
        return 0;
    } else {
        return Altura(raizTemp->esquerda) - Altura(raizTemp->direita);
    }  
}

int Altura(Arvore *arvore){
	int iEsq, iDir;

	if (arvore == NULL){
		return 0;
	}

	iEsq = Altura(arvore->esquerda);
	iDir = Altura(arvore->direita);

	if (iEsq > iDir){
		return iEsq + 1;
	} else {
		return iDir + 1;
	}
}

//Remove elementos da Arvore


//Exclui a Arvore
void Clear(Arvore *Arvore){
	
}

int Menu() {
    int opMenu;
    printf("\n\nESCOLHA UMA DAS OPCOES\n");
    printf("\t1) Incluir nome\n");
    printf("\t2) Apagar nome\n");
    printf("\t3) Buscar nome\n");
    printf("\t4) Listar\n");
    printf("\t5) Sair\n\t");
    scanf("%d", &opMenu);
    return opMenu;
}

int MenuFatorPrecendencia(InfoArvore *info) {
    int opMenu;
    printf("\n\nESCOLHA UM FATOR DE PRECEDENCIA\n");
    printf("\t1) Nome\n");
    printf("\t2) Idade\n");
    printf("\t3) Telefone\n");
    scanf("%d", &opMenu);

    if (opMenu == 1) {
        strcpy(info->tipoChave, "NOME");
    } else if (opMenu == 2) {
        strcpy(info->tipoChave, "IDADE");
    } else {
       strcpy(info->tipoChave, "TELEFONE");
    }

    return opMenu;
}
/*
void Push(Arvore **raizTemp, Arvore *newp){
    Arvore **tracer = raizTemp;
    if (*raizTemp == NULL) {
        *raizTemp = newp;
    } else {
        while (*tracer){
            if (newp->idade > (*tracer)->idade) {
                if ((*tracer)->direita == NULL) {
                    (*tracer)->direita = newp;
                    break;
                } else {
                    tracer = &(*tracer)->direita;
                }  
            } else {
                if ((*tracer)->esquerda == NULL) {
                    (*tracer)->esquerda = newp;
                    break;
                } else {
                    tracer = &(*tracer)->esquerda;
                }
            }
        }
    }
}
*/