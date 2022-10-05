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

Arvore *raiz = NULL;
char tipoChave[10];
int numNodos = 0;

//Protótipos das Funções
Arvore* CriaNodo(char nome[],  int idade, char telefone[], int fator);
void Reset();
void Push(Arvore **raiz, Arvore *newp);
void Clear(Arvore *Arvore);
void PrintArvorePreOrdem(Arvore *arvore);
void PrintArvoreCentral(Arvore *arvore);
void PrintArvorePosOrdem(Arvore *arvore);
void Find(Arvore **raizTemp, char procura[]);
void Pop(Arvore **raizTemp, char procura[]);
int Menu();
int MenuFatorPrecendencia();

int main(){
    Arvore *arvore;
    int tempInt;
    char tempChar[20], tempChar2[20];

    int opMenu = 0, fatorPrecendencia = MenuFatorPrecendencia(); 
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
            arvore = CriaNodo(tempChar, tempInt, tempChar2, fatorPrecendencia);
            Push(&raiz, arvore);
            break;

        case 2:
            printf("\n\nDIGITE O/A %s QUE DESEJA REMOVER\n", tipoChave);
            fflush(stdin);
            scanf("%s", &tempChar);
            break;

        case 3:
            printf("\n\nDIGITE O/A %s QUE DESEJA BUSCAR\n", tipoChave);
            fflush(stdin);
            scanf("%s", &tempChar);
            Find(&raiz, tempChar);
            break;

        case 4:
            printf("\n\nDIGITE A FORMA COMO DESEJA LISTAR A ARVORE\n");
            printf("\t1) Central\n");
            printf("\t2) Pre Ordem\n");
            printf("\t3) Pos Ordem\n");
            fflush(stdin);
            scanf("%d", &tempInt);
            
            if (tempInt == 1) {
                PrintArvoreCentral(raiz);
            } else if (tempInt == 2) {
                PrintArvorePreOrdem(raiz);
            } else if (tempInt == 3) {
                PrintArvorePosOrdem(raiz);
            } else {
                printf("\n\nATENCAO: Digite um numero valido!\n");
            }
    
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
		printf("%s ", arvore->chave);
		PrintArvorePreOrdem(arvore->esquerda);
		PrintArvorePreOrdem(arvore->direita);
	}
}

void PrintArvoreCentral(Arvore *arvore){
    if (arvore){
		PrintArvoreCentral(arvore->esquerda);
        printf("%s ", arvore->chave);
		PrintArvoreCentral(arvore->direita);
	}
}

void PrintArvorePosOrdem(Arvore *arvore){
    if (arvore){
		PrintArvorePosOrdem(arvore->esquerda);
		PrintArvorePosOrdem(arvore->direita);
        printf("%s ", arvore->chave);
	}
}

// Procura um elemento na árvore (de acordo com a chave escolhida no inicio do código)
void Find(Arvore **raizTemp, char procura[]){
    Arvore **tracer = raizTemp;
    if (*raizTemp == NULL) {    //Caso a arvore não tenha nenhum nodo ainda
        printf("\nNão existe nenhum nodo na árvore");
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
    if (*raizTemp == NULL) {    //Caso a arvore não tenha nenhum nodo ainda
        printf("\nNão existe nenhum nodo na árvore para ser removido");
    } else {
        while (*tracer){
            if (strcmp(procura, (*tracer)->chave) == 0) {  
                printf ("\nNodo encontrado!");
                
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

int MenuFatorPrecendencia() {
    int opMenu;
    printf("\n\nESCOLHA UM FATOR DE PRECEDENCIA\n");
    printf("\t1) Nome\n");
    printf("\t2) Idade\n");
    printf("\t3) Telefone\n");
    scanf("%d", &opMenu);

    if (opMenu == 1) {
        strcpy(tipoChave, "NOME");
    } else if (opMenu == 2) {
        strcpy(tipoChave, "IDADE");
    } else {
       strcpy(tipoChave, "TELEFONE");
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