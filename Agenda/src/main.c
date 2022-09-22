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
char* NewElement(char *nome, int *idade, char *telefone);
void Insert(char **tracer, char *newp);
void Print(char **tracer);

/*
void Inserir(int *quantPessoas);
void Listar(int *quantPessoas, int *i);
void Buscar(int *quantPessoas, int *i, char *nomeBusca);
void Excluir(int *quantPessoas, int *i, int *teste, char *nomeBusca);
*/

void *pBuffer = NULL;
const int TAMANHONOME = sizeof(char) * 15 + 1; 
const int TAMANHOIDADE = sizeof(int);
const int TAMANHOTELEFONE = sizeof(char) * 20; // (55) 51 9 9999-9999
const int TAMANHOBASE = TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE + sizeof(char);

int main()
{
	//ORDEM DOS DADOS NO PBUFFER: opMenu QuantidadePessoas i teste nomeBusca tempNome tempIdade tempTelefone start
	int *opMenu = NULL, *quantPessoas = NULL, *i = NULL, *teste = NULL, *tempIdade = NULL;
	char *nomeBusca = NULL, *tempNome  = NULL, *tempTelefone = NULL, *start = NULL;

    //Alocando espaço para o ponteiro void com as váriaveis gerais
    pBuffer = (void*)(malloc((sizeof(int) * 5) + ((sizeof(char) * 10) * 3 + 3) + sizeof(char)));
    if (pBuffer == NULL){
        printf("Erro na alocacao de memoria");
        exit (1);
    }

    //Definindo endereço incial para os ponteiros do pbuffer
    opMenu = pBuffer;
	quantPessoas = pBuffer + sizeof(int);
	i = pBuffer + (sizeof(int) * 2);
	teste = pBuffer + (sizeof(int) * 3);
	nomeBusca = pBuffer + (sizeof(int) * 4);
	tempNome = pBuffer + (sizeof(int) * 4) + (sizeof(char) * 10 + 1);
	tempIdade = pBuffer + (sizeof(int) * 4) + ((sizeof(char) * 10) * 2 + 2);
	tempTelefone = pBuffer + (sizeof(int) * 5) + ((sizeof(char) * 10) * 2 + 2);
	//start = pBuffer + (sizeof(int) * 5) + ((sizeof(char) * 10) * 3 + 2);
	*opMenu = 0;
	*quantPessoas = 0;

    while (*opMenu != 5) {
        *opMenu = Menu(opMenu);
        switch (*opMenu) {
        case 1:
			*quantPessoas = *quantPessoas + 1;
			
			printf("\n\tDigite o nome: \n");
			scanf("%s", tempNome);
			fflush(stdin);
			printf("\n\tDigite a idade: \n");
			scanf("%d", tempIdade);
			fflush(stdin);
			printf("\n\tDigite o telefone: \n");
			scanf("%s", tempTelefone);

			//printf("%s, %d, %s", tempNome, *tempIdade, tempTelefone);
			
			Insert(&start, NewElement(tempNome, tempIdade, tempTelefone));
			Print(&start);

			//start = NewElement(tempNome, tempIdade, tempTelefone);
			
			//printf("\n%p", start);
			//printf("\n PBUFFERNOMES: %s, %d, %s", (char*)(start), *(int *)(start + TAMANHONOME), (char*)(start + TAMANHONOME + TAMANHOIDADE));
			//Inserir(quantPessoas);
            break;

        case 2:
			//Excluir(quantPessoas, i, teste, nomeBusca);
			//Listar(quantPessoas, i);
            break;

        case 3:
			//Buscar(quantPessoas, i, nomeBusca);
            break;

        case 4:
			Print(&start);
			//Listar(quantPessoas, i);
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
    return *opMenu;
}

char* NewElement(char *nome, int *idade, char *telefone){
	void *pBufferPessoas = NULL;
	
	pBufferPessoas = (void*)(malloc(TAMANHOBASE));
	if (pBufferPessoas == NULL){
        printf("Erro na alocacao de memoria");
        exit (1);
    }

	strcpy((char*)(pBufferPessoas), nome);
	*(int*)(pBufferPessoas + TAMANHONOME) = *idade;
	strcpy((char*)(pBufferPessoas + TAMANHONOME + TAMANHOIDADE), telefone);
	*(char **)(pBufferPessoas + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE) = NULL;

	//printf("\n PBUFFERNOMES: %s, %d, %s", (char*)(pBufferPessoas), *(int *)(pBufferPessoas + TAMANHONOME), (char*)(pBufferPessoas + TAMANHONOME + TAMANHOIDADE));

	//printf("\n%p", pBufferPessoas);
	return pBufferPessoas;
}

void Insert(char **head, char *newp){
	char **tracer = head;
	//printf("\n PBUFFERNOMES: %s, %d, %s", (char **)(*tracer), *(int **)(*tracer + TAMANHONOME), (char **)(*tracer + TAMANHONOME + TAMANHOIDADE));

	while (*tracer != NULL && strcmp((char **)(*tracer), (char *)(newp)) < 1) {
		tracer = *tracer + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE;
	}

	*(char **)(newp + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE) = *tracer;
	*tracer = newp;
	
}

void Print(char **tracer){
	printf("\n\n---LISTA DOS NOMES ADICIONADOS---");
	while (*tracer) {
		printf("\n\n\tNOME: %s", (char **)(*tracer));
		printf("\n\tIDADE: %d", *(char **)(*tracer + TAMANHONOME));
		printf("\n\tTELEFONE: %s", (char **)(*tracer + TAMANHONOME + TAMANHOIDADE));
		tracer = *tracer + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE;
	}	
}

/*
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

void Buscar(int *quantPessoas, int *i, char *nomeBusca){
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
    printf("\nDigite a pessoa que deseja remover: \t");
	scanf ("%s" , nomeBusca);
	for (*i = 0; *i < *quantPessoas; *i = *i + 1)	{
		if (strcmp(nomeBusca, pessoas[*i].nome) == 0) {
			*teste = 1;
		}
		if (*teste == 1 && ((*i + 1) != *quantPessoas)) {
			strcpy(pessoas[*i].nome, pessoas[*i + 1].nome);
			pessoas[*i].idade = pessoas[*i + 1].idade;
			strcpy(pessoas[*i].telefone, pessoas[*i + 1].telefone);
		}
	}
	if (*teste == 1) {
		*quantPessoas = *quantPessoas - 1;
		printf("\nPessoa excluida com sucesso");
	} else{
		printf("\nPessoa nao encontrada");
	}
}
*/