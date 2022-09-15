#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
	NOME: CAROLINE SOUZA CAMARGO

	1. O programa deve armazenar no máximo 10 pessoas
	2. Todas as variáveis que forem usadas no programa deve ser ponteiros. A única exceção é o item 1 que deve ser uma variável global Pessoa pessoas[10].
		- Os ponteiros devem apontar para um buffer chamado pBuffer onde os dados devem ser armazenados. Por exemplo, um contador para um for deve ser um ponteiro para int e o int vai ficar armazenado dentro de pBuffer . 
		- Não pode usar struct dentro do pBuffer 3. 
*/

int Menu(int *opMenu);
void Inserir(int *quantPessoas);
void Listar(int *quantPessoas, int *i);
void Buscar(int *quantPessoas, int *i, int *nomeBusca);
void Excluir(int *quantPessoas, int *i, int *teste, char *nomeBusca);

typedef struct {
	char nome[30];
	int idade;
	char telefone[20];
} Pessoa;

void *pBuffer = NULL;
Pessoa *pessoas;

int main()
{
	//DADOS DO PBUFFER: opMenu QuantidadePessoas i nomeBusca
	int *opMenu, *quantPessoas, *i, *nomeBusca, *teste;

	//Alocando espaço para as pessoas da Struct
	pessoas = (Pessoa*)(malloc(sizeof(Pessoa) * 1));
    if (pessoas == NULL){
        printf("Erro na alocacao de memoria");
        exit (1);
    }
	
    //Alocando espaço para o ponteiro void
    pBuffer = (void*)(malloc((sizeof(int) * 4) + (sizeof(char) * 11)));
    if (pBuffer == NULL){
        printf("Erro na alocacao de memoria");
        exit (1);
    }

    //Definindo endereço incial para os ponteiros
    opMenu = pBuffer;
	quantPessoas = pBuffer + sizeof(int);
	i = pBuffer + (sizeof(int) * 2);
	teste = pBuffer + (sizeof(int) * 3);
	nomeBusca = pBuffer + (sizeof(int) * 4);
	*opMenu = 0;
	*quantPessoas = 0;

    while (*opMenu != 5) {
        *opMenu = Menu(opMenu);
		
        switch (*opMenu) {
        case 1:
			*quantPessoas = *quantPessoas + 1;
			pessoas = (Pessoa*)(realloc(pessoas, sizeof(Pessoa) * (*quantPessoas)));
			if (pessoas == NULL){
        		printf("Erro na alocacao de memoria");
        		exit (1);
    		}
			Inserir(quantPessoas);
            break;

        case 2:
			Excluir(quantPessoas, i, teste, nomeBusca);
			Listar(quantPessoas, i);
			printf("entrou case 2");
            break;

        case 3:
			Buscar(quantPessoas, i, nomeBusca);
            break;

        case 4:
			Listar(quantPessoas, i);
            break;

        case 5:
            //SAIR
            free(pBuffer);
            printf("\nOpcao sair foi escolhida...\n");
			return (0);
            break;
        
        default:
            printf("\n\nATENCAO: Digite um numero valido!\n");
            break;
        }
    }
}

int Menu(int *opMenu) {
    printf("\n\nESCOLHA UMA DAS OPCOES\n");
    printf("\t1) Incluir nome\n");
    printf("\t2) Apagar nome\n");
    printf("\t3) Buscar nome\n");
    printf("\t4) Listar\n");
    printf("\t5) Sair\n\t");
    scanf("%d", opMenu);
	printf("%d", *opMenu);
    return *opMenu;
}

void Inserir(int *quantPessoas){
	fflush(stdin);
	printf("\n\tDigite o nome: \n");
	scanf("%s", pessoas[*quantPessoas-1].nome);
	fflush(stdin);
	printf("\n\tDigite a idade: \n");
	scanf("%d", &pessoas[*quantPessoas-1].idade);
	fflush(stdin);
	printf("\n\tDigite o telefone: \n");
	scanf("%s", pessoas[*quantPessoas-1].telefone);
}

void Listar(int *quantPessoas, int *i){
	for (*i = 0; *i < *quantPessoas; *i = *i + 1)	{
		printf("\n\n\tPessoa %d", *i + 1);
		printf("\n\tNome %s", pessoas[*i].nome);
		printf("\n\tIdade %d", pessoas[*i].idade);
		printf("\n\tTelefone %s", pessoas[*i].telefone);
	}
}

void Buscar(int *quantPessoas, int *i, int *nomeBusca){
    scanf ("%s" , nomeBusca);
	printf("%s", nomeBusca);
	for (*i = 0; *i < *quantPessoas; *i = *i + 1)	{
		if (strcmp(nomeBusca, pessoas[*i].nome) == 0) {
			printf("\n\tPessoa encontrada");
			printf("\n\n\tPessoa %d", *i + 1);
			printf("\n\tNome %s", pessoas[*i].nome);
			printf("\n\tIdade %d", pessoas[*i].idade);
			printf("\n\tTelefone %s", pessoas[*i].telefone);
		}
	}
}

void Excluir(int *quantPessoas, int *i, int *teste, char *nomeBusca){ 
    scanf ("%s" , nomeBusca);
	printf("%s", nomeBusca);
	for (*i = 0; *i < *quantPessoas; *i = *i + 1)	{
		if (strcmp(nomeBusca, pessoas[*i].nome) == 0) {
			teste = 1;
		}
		if (teste == 1) {
			strcpy(pessoas[*i].nome, pessoas[*i + 1].nome);
			pessoas[*i].idade = pessoas[*i + 1].idade;
			strcpy(pessoas[*i].telefone, pessoas[*i + 1].telefone);
		}
	}
	if (teste == 1) {
		*quantPessoas = *quantPessoas - 1;
		printf("\nPessoa excluida com sucesso");
	} else{
		printf("\nPessoa nao encontrada");
	}
}