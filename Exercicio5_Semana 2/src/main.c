#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Menu ();

typedef struct {
	char nome[30];
	int idade;
	int altura;
} Pessoa;

int main()
{
	int op=1, quantPessoas=0;
	Pessoa *pessoas;
	pessoas = (Pessoa*)(malloc (sizeof(Pessoa) * 1));

	while (op != 0) {
		op = Menu ();
		switch (op) {
		case 0:
			free(pessoas);
			printf("\n\tOpcao sair foi escolhida");
			break;

		case 1:
			quantPessoas++;
			pessoas = (Pessoa*)(realloc(pessoas, sizeof(Pessoa) * quantPessoas));

			fflush(stdin);
			printf("\n\tDigite o nome: \n");
			scanf("%s", pessoas[quantPessoas-1].nome);
			fflush(stdin);
			printf("\n\tDigite a idade: \n");
			scanf("%d", &pessoas[quantPessoas-1].idade);
			fflush(stdin);
			printf("\n\tDigite o altura: \n");
			scanf("%d", &pessoas[quantPessoas-1].altura);
			break;

		case 2:
			for (int i = 0; i < quantPessoas; i++)	{
				printf("\n\n\tPessoa %d", i+1);
				printf("\n\tNome %s", pessoas[i].nome);
				printf("\n\tIdade %d", pessoas[i].idade);
				printf("\n\tAltura %d", pessoas[i].altura);
			}
			break;
		
		default:
			printf("\n\tDigite um numero valido");
			break;
		}
	}
	return (0);
}

int Menu (){
	int op;
	printf ( " \n\n Escolha uma opcao: " );
	printf ( " \n\t 0 - Sair" );
	printf ( " \n\t 1 - Inserir Pessoas " );
	printf ( " \n\t 2 - Listar Pessoas \n" );
	scanf ( "%d" , &op);
	return op;
}
