#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
	NOME: CAROLINE SOUZA CAMARGO

	TRABALHO AGENDA:
	Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer.
	Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.
	Exemplo do que não pode: int c; char a; int v[10];  void Funcao(int parametro)
	Não pode usar struct em todo o programa.
	Usar fila ordenada (heap) para armazenar as pessoas em ordem alfabética sempre que o usuário incluir uma nova pessoa.
	Implementar a base de dados da agenda usando lista duplamente ligada
	Somente essa base de dados pode ficar fora do buffer principal, ou seja, pode usar um malloc para cada nodo.
*/

int Menu(int *opMenu);

void *pBuffer = NULL;

typedef struct {
	char nome[30];
	int idade;
	char telefone[20];
} Pessoa;

int main()
{
	//DADOS DO PBUFFER: opMenu QuantidadePessoas i
	int *opMenu, *quantPessoas, *i;

	//Alocando espaço para as pessoas da Struct
	Pessoa *pessoas;
	pessoas = (Pessoa*)(malloc(sizeof(Pessoa) * 1));
    if (pessoas == NULL){
        printf("Erro na alocacao de memoria");
        exit (1);
    }
	
    //Alocando espaço para o ponteiro void
    pBuffer = (void*)(malloc(sizeof(int) * 3));
    if (pBuffer == NULL){
        printf("Erro na alocacao de memoria");
        exit (1);
    }

    //Definindo endereço incial para os ponteiros
    opMenu = pBuffer;
	quantPessoas = pBuffer + sizeof(int);
	i = pBuffer + (sizeof(int) * 2);
	*opMenu = 0;
	*quantPessoas = 0;

    while (*opMenu != 5) {
        *opMenu = Menu(opMenu);
		
        switch (*opMenu) {
        case 1:
			printf("entrou case 1");
			*quantPessoas = *quantPessoas + 1;
			pessoas = (Pessoa*)(realloc(pessoas, sizeof(Pessoa) * (*quantPessoas)));

			fflush(stdin);
			printf("\n\tDigite o nome: \n");
			scanf("%s", pessoas[*quantPessoas-1].nome);
			fflush(stdin);
			printf("\n\tDigite a idade: \n");
			scanf("%d", &pessoas[*quantPessoas-1].idade);
			fflush(stdin);
			printf("\n\tDigite o telefone: \n");
			scanf("%s", pessoas[*quantPessoas-1].telefone);
            break;

        case 2:
			printf("entrou case 2");
            break;

        case 3:
			printf("entrou case 3");
            break;

        case 4:
			printf("entrou case 4");
			for (*i = 0; *i < *quantPessoas; *i = *i + 1)	{
				printf("\n\n\tPessoa %d", *i + 1);
				printf("\n\tNome %s", pessoas[*i].nome);
				printf("\n\tIdade %d", pessoas[*i].idade);
				printf("\n\tTelefone %s", pessoas[*i].telefone);
			}
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
