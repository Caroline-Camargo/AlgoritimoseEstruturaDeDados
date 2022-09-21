#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;

/* um conjunto de rotinas para ilustrar a inserção e exclusão de uma 
lista vinculada usando técnicas de ponteiro de nível único 'tradicionais'. As rotinas para 
deletar um elemento de lista, e para inserir na frente de uma lista são 
adaptadas de Kernighan e Pike's "The Practice of Programming" pp.46 et 
seq. (Addison-Wesley 1999). Os elementos da lista são do tipo COISA 
onde cada COISA é uma estrutura na qual o campo 'item' contém uma 
string e o campo 'próximo' contém um ponteiro para a próxima COISA na lista.

As técnicas para adicionar uma COISA antes do início de uma lista, ou após o 
final de uma lista, são dois casos especiais bastante simples. 
No entanto, se os elementos da lista devem ser mantidos em ordem alfabética (digamos),   
a inserção de um novo elemento precisa de muito cuidado para garantir que o 
marcador de fim de lista NULL não seja desreferenciado.  

Em resumo, as rotinas devem ser robustas contra: 

 1) inserir/excluir de/para uma lista vazia 
 2) inserir/excluir de/para uma lista de um único elemento 
 3) inserir/excluir no final de uma lista 
 4) inserir/excluir em a frente de uma lista - com atualização do 
    ponteiro para o cabeçalho da lista
 
A rotina geral `addmiddle', fornecida abaixo, é de propósito geral, mas 
chama 'addfront' e 'addend' em casos especiais específicos. Observe 
cuidadosamente que ele permite elementos de lista duplicados. 
Exercício: modifique `addmiddle para que esta duplicação NÃO seja permitida.
 */


// BASE DOS LEGOS
typedef struct _thing 
{ 
	char *item;
	struct _thing *next;
} THING;		//É como se fosse o tipo da variável, COISA funciona como um int  

THING *start = NULL;	//Variavel do tipo COISA

// cria um novo elemento de lista do tipo THING a partir do texto fornecido string e retorna o endereço dessa COISA
THING *newelement(char *text)
{
	THING *newp; //Variavel do tipo COISA
	newp = (THING *) malloc (sizeof(THING)); //Alocando espaço para uma COISA 
	newp->item = (char *)malloc(strlen(text) + 1); //Alocando espaco suficiente para adicionar um string dentro da coisa + 1 por causa do \n
        strcpy(newp->item, text); //Depois de alocar o espaço suficiente para o item, esse item é adicionado dentro da COISA 
        newp -> next = NULL; //Próximo endereço será null, pois não existe nenhuma COISA depois dessa
	return newp; //Retorna o endereço de memória da COISA que foi criada e alocada 
	//Aqui simplesmente foi alocado e criado a struct com a COISA, mas ela não está se relacionado com ninguém, ou seja, não faz parte de uma lista encadeada ainda...
}

// delelement: remove da lista a primeira instância de um elemento 
// contendo uma determinada string de texto 
// NOTA!! pedidos de exclusão para elementos que não estão na lista são ignorados silenciosamente 
THING *delelement(THING *head, char *text)
{
	THING *p, *prev;
	prev = NULL;
	for (p = head; p != NULL; p = p -> next) {
            if (strcmp(text, p -> item) == 0) {
		if(prev == NULL)
		   head = p-> next;
		else
		   prev -> next = p -> next;
		free(p -> item); //free off the the string field
		free(p);	// remove rest of THING
		return head;
	   }
	   prev = p;	
	}
}

/* addfront: adiciona novo THING à frente da lista */ 
/* exemplo de uso: start = (addfront(start, newelement("burgers")); */
THING *addfront(THING *head, THING *newp)	//Precisa do endereço inicial da lista encadeada e o endereço da COISA que quer ser adicionada na lista encadeada
{
	newp -> next = head;	//Adicionando COISA no inicio da lista encadeada, ou seja, essa nova coisa será a primeira da lista (cabeça), para isso é necessário atualizar o campo next que receberá o endereço da antiga cabeça
	//Obs.: Precisa atualizar o start, pois nesse exato momento o start está aopontando para a segunda COISA e não mais para a primeira
	return newp;
}

/* addend: adiciona nova THING ao final de uma lista */ 
/* exemplo de uso: start = (addend(start, newelement("wine")); */

THING *addend (THING *head, THING *newp)
{
	THING *p2; 	
	if (head == NULL)	//Cabeça igual a null -> lista vazia (não tem nenhum elemento)
		return newp;	//O next da lista não precisa ser atualizado pois não existe nenhuma coisa na frente. Após o retorno da função ocorrerá a cabeca será atualizada para essa COISA
// agora encontre o final da lista
	for (p2 = head; p2 -> next != NULL; p2 = p2 -> next) //Se chegou nessa parte, no minimo vai ter uma coisa alocada
	//Para chegar no fim de uma lista encadeada é necessário percorrer todos elementos da lista
		;
	p2 -> next = newp; //Antes de executar essa linha p2 -> next = NULL, após isso vai conter o enderço da COISA adicionada
	return head;	//O
}

// adiciona um elemento no meio de uma lista de THINGs baseado em ordem alfabética 
// das strings de `item' dentro das estruturas 
THING *addmiddle (THING *head, THING *newp)
{
	BOOL found = FALSE;	//Vai indicar se achou onde precisa inserir o elemento elemento
	THING *p1, *p2; 	
	if (head == NULL) { //caso especial: lista COISA está vazia
//		printf("lista inicial era NULL\n");
		head = addfront(head, newp);
		return head;
	}
	//Se chegou aqui a lista não está vazia
// Laço principal. Use p2 para lembrar p1 anterior
	p2 = p1 = head ; //Todo mundo é cabeca 
	while (!found) { //Enquanto não encontrar 
  		if (found = strcmp(p1 -> item, newp -> item) >= 1) { //Found descobrio o lugar onde vai ser inserido
			if (p1 == head) { 
//					printf("adding at head\n");
					head = addfront(head, newp); 
					return(head);
		        }
			else { //general case - insert the item
//        		        printf("General case entered\n");
				p2 -> next = newp;;
				newp -> next = p1;
				return head;
	  		}
	  	}
	// match not found before end of list so insert at end 
		if  (p1 -> next == NULL) {
			head = addend(head, newp); 
			return (head);
		}
	// go round while loop one more time
		p2 = p1; p1 = p1 -> next; 
		
		}// end of while 
	
}



void printlist(THING **head)
// this routine uses pointer-to-pointer techniques :-)
{
	THING **tracer = head;
	while ((*tracer) != NULL) {
		printf("%s \n",(*tracer)->item);
		tracer = &(*tracer)->next;
	}
}


int main(int argc, char **argv)
{
	start = addmiddle(start, newelement("chips")); 
	start = addmiddle(start, newelement("wine")); 
	start = addmiddle(start, newelement("beer")); 
	start = addmiddle(start, newelement("pizza")); 
	start = addmiddle(start, newelement("zucchini"));
	start = addmiddle(start, newelement("burgers"));
	start = addmiddle(start, newelement("burgers"));
	start = addmiddle(start, newelement("slaw"));
	printf("\nINITIAL LIST\n");
	printlist (&start);
	delelement(start, "pizza");
	delelement(start, "zucchini");
	delelement(start, "burgers");
	printf("\nALTERED LIST\n");
	printlist(&start);
	
}