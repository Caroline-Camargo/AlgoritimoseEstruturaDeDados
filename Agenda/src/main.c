#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
	NOME: CAROLINE SOUZA CAMARGO

	1. O programa deve armazenar no máximo 10 pessoas
	2. Todas as variáveis que forem usadas no programa deve ser ponteiros. A única exceção é o item 1 que deve ser uma variável global Pessoa pessoas[10].
		- Os ponteiros devem apontar para um buffer chamado pBuffer onde os dados devem ser armazenados. Por exemplo, um contador para um for deve ser um ponteiro para int e o int vai ficar armazenado dentro de pBuffer. 
		- Não pode usar struct dentro do pBuffer 3. 
*/

int Menu(int *opMenu);
char* NewElement(char *nome, int *idade, char *telefone);
void Insert(char **tracer, char *last, char *newp);
void UpdatePrevious (char **head, char *last);
void Print(char **tracer);
void Search(char **tracer, char *text);
void Reset(char **head);

/*
void Inserir(int *quantPessoas);
void Listar(int *quantPessoas, int *i);
void Buscar(int *quantPessoas, int *i, char *nomeBusca);
void Excluir(int *quantPessoas, int *i, int *teste, char *nomeBusca);
*/

void *pBuffer = NULL;
char *start = NULL;
char *last = NULL;
const int TAMANHONOME = sizeof(char) * 15 + 1; 
const int TAMANHOIDADE = sizeof(int);
const int TAMANHOTELEFONE = sizeof(char) * 20 + 1; // (55) 51 9 9999-9999
const int TAMANHOBASE = TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE + sizeof(char **) + sizeof(char **);

int main()
{
	//ORDEM DOS DADOS NO PBUFFER: opMenu quantPessoas i teste tempNome tempIdade tempTelefone
	int *opMenu = NULL, *quantPessoas = NULL, *i = NULL, *teste = NULL, *tempIdade = NULL;
	char *tempNome  = NULL, *tempTelefone = NULL;

    //Alocando espaço para o ponteiro void com as váriaveis gerais
    pBuffer = (void*)(malloc((sizeof(int) * 5) + (sizeof(char) * 15 + 1) + (sizeof(char) * 20 + 1)));
    if (pBuffer == NULL){
        printf("Erro na alocacao de memoria");
        exit (1);
    }

    //Definindo endereço incial para os ponteiros do pbuffer
    opMenu = (int *)(pBuffer);
	quantPessoas = (int *)(pBuffer + sizeof(int));
	i = (int *)(pBuffer + (sizeof(int) * 2));
	teste = (int *)(pBuffer + (sizeof(int) * 3));
	tempNome = (char *)(pBuffer + (sizeof(int) * 4));
	tempIdade = (int *)(pBuffer + (sizeof(int) * 4) + ((sizeof(char) * 15) + 1));
	tempTelefone = (char *)(pBuffer + (sizeof(int) * 5) + (sizeof(char) * 15 + 1));
	
	//Definindo conteúdo inicial
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
			
			Insert(&start, last, NewElement(tempNome, tempIdade, tempTelefone));
			Print(&start);
            break;

        case 2:
			//Excluir(quantPessoas, i, teste, nomeBusca);
			//Listar(quantPessoas, i);
            break;

        case 3:
			printf("\n\tDigite o nome que deseja buscar: \n");
			scanf("%s", tempNome);
			Search(&start, tempNome);
            break;

        case 4:
			Print(&start);
            break;

        case 5:
			Reset(&start);
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

	strcpy((char*)(pBufferPessoas), nome); //nome
	*(int*)(pBufferPessoas + TAMANHONOME) = *idade; //idade
	strcpy((char*)(pBufferPessoas + TAMANHONOME + TAMANHOIDADE), telefone); //telefone
	*(char **)(pBufferPessoas + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE) = NULL; //next
	*(char **)(pBufferPessoas + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE + sizeof(char **)) = NULL; //previous

	return pBufferPessoas;
}

void Insert(char **head, char *last, char *newp){
	char **tracer = head;

	while (*tracer != NULL && strcmp(*tracer, (char *)(newp)) < 1) {
		tracer = (char **)(*tracer + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE);
	}

	*(char **)(newp + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE) = *tracer;
	*tracer = newp;

	UpdatePrevious(head, last);
}

void UpdatePrevious (char **head, char *last){
	char **tracer = head;
	char *tracerPrevious = *head;

	while (*tracer != NULL) {
		tracerPrevious = *tracer; //Memoriza o endereço anterior 
		tracer = (char **)(*tracer + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE);  //Vai para o próximo endereço da lista
		if (*tracer != NULL) { 
			*(char **)(*tracer + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE + sizeof(char **)) = (char *) (tracerPrevious);
		}
	}

	//Atualiza o ponteiro last como o último elemento da lista
	last = (char *)(tracerPrevious);
	printf("\n\tNome: %s", (char *)(last));
}

void Print(char **tracer){
	int *quantPessoas =  (int *)(pBuffer + sizeof(int));
	int *i =  (int *)(pBuffer + (sizeof(int) * 2));

	printf("\n\n--- LISTA DAS PESSOAS ADICIONADOS ---");
	printf("\n\tQuantidade total de Pessoas %d", *(int *)(quantPessoas));
	printf("\n\tPrimeiro Nome da Lista: %s", (char *)(start));
	printf("\n\tUltimo Nome da Lista: %s", (char *)(last));

	for (*i = 0; *i < *quantPessoas; *i = *i + 1) {
		printf("\n\n\tPESSOA %d", *(int *)(i));
		printf("\n\tNome: %s", (char **)(*tracer));
		printf("\n\tIdade: %d", *(int **)(*tracer + TAMANHONOME));
		printf("\n\tTelefone: %s", (char **)(*tracer + TAMANHONOME + TAMANHOIDADE));
		tracer = (char **)(*tracer + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE);
	}	
}

void Search(char **tracer, char *text){
	char **temp;
	int *teste = (int *)(pBuffer + (sizeof(int) * 3));
	*teste = 0;

	while (*tracer != NULL) {
		if (strcmp(*tracer, text) == 0) {
			*teste = 1;
			break;
		}
		tracer = (char **)(*tracer + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE);
	}

	if (*teste == 1){
		printf("\n\tPALAVRA ENCONTRADA");
		printf("\n\n\tNome: %s", (char **)(*tracer));
		printf("\n\tIdade: %d", *(int **)(*tracer + TAMANHONOME));
		printf("\n\tTelefone: %s", (char **)(*tracer + TAMANHONOME + TAMANHOIDADE));

		temp = (char **)(*tracer + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE + sizeof(char **));
		printf("\n\n\tNome anterior na lista: %s", (char **)(*temp));
		temp = (char **)(*tracer + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE);
		printf("\n\tProximo nome da lista: %s", (char **)(*temp));
	} else {
		printf("\nPalavra nao encontrada");
	}
}

void Reset(char **head){
	char **tracer = head;
	void **old;
	while (*tracer != NULL) {
		old = *tracer;
		*tracer = (char **)(*tracer + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE);
		free(*old);
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