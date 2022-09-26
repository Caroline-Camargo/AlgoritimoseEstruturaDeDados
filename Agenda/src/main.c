#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    NOME: CAROLINE SOUZA CAMARGO

    PARTE 1:
    Faça uma agenda capaz de incluir, apagar, buscar e listar quantas pessoas o usuário desejar, porém, toda a informação incluída na agenda deve ficar num único lugar chamado: “void *pBuffer”.
    Não pergunte para o usuário quantas pessoas ele vai incluir. Não pode alocar espaço para mais pessoas do que o necessário.

    PARTE 2:
    Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer. Nem mesmo como parâmetro de função.  Só ponteiros que apontam para dentro do pBuffer. 
    Exemplo do que não pode: int c; char a; int v[10]; void Funcao(int parametro)
    Não pode usar struct em todo o programa. 
    Usar fila ordenada (heap) para armazenar as pessoas em ordem alfabética sempre que o usuário incluir uma nova pessoa.  Implementar a base de dados da agenda usando lista duplamente ligada
    Somente essa base de dados pode ficar fora do buffer principal, ou seja, pode usar um malloc para cada nodo.
*/

//Funções
int Menu(int *opMenu);
char* NewElement(char *nome, int *idade, char *telefone);
void Insert(char **tracer, char *newp);
void UpdatePrevious (char **head);
void Print(char **tracer);
void Search(char **tracer, char *text);
void Remove(char **head);
void Clear(char *tracer);

//Ponteiros globais referentes ao início e fim da fila  
char *start = NULL;
char *last = NULL;

//Dados do programa vão estar nesse ponteiro
void *pBuffer = NULL;  

//Constantes auxiliares 
#define TAMANHONOME sizeof(char) * 15 + 1
#define TAMANHOIDADE sizeof(int)
#define TAMANHOTELEFONE sizeof(char) * 20 + 1  //(55) 51 9 9999-9999
#define TAMANHOBASE TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE + sizeof(char **) + sizeof(char **)


int main() {
    //ORDEM DOS DADOS NO PBUFFER: opMenu quantPessoas i teste tempNome tempIdade tempTelefone
    int *opMenu = NULL, *quantPessoas = NULL, *i = NULL, *teste = NULL, *tempIdade = NULL;
    char *tempNome  = NULL, *tempTelefone = NULL;

    //Alocando espaço para o ponteiro void com as váriaveis gerais
    pBuffer = (void *)(malloc((sizeof(int) * 5) + (sizeof(char) * 15 + 1) + (sizeof(char) * 20 + 1)));
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
            //INCLUIR
            printf("\n\tDigite o nome: \n");
            scanf("%s", tempNome);
            //fflush(stdin);
            printf("\n\tDigite a idade: \n");
            scanf("%d", tempIdade);
           // fflush(stdin);
            printf("\n\tDigite o telefone: \n");
            scanf("%s", tempTelefone);
            
            *quantPessoas = *quantPessoas + 1;
            Insert(&start, NewElement(tempNome, tempIdade, tempTelefone));
            Print(&start);
            break;

        case 2:
            //APAGAR
            Remove(&start);
            Print(&start);
            break;

        case 3:
            //BUSCAR
            printf("\n\tDigite o nome que deseja buscar: \n");
            scanf("%s", tempNome);
            Search(&start, tempNome);
            break;

        case 4:
            //LISTAR
            Print(&start);
            break;

        case 5: 
            //SAIR
            Clear(start);
            free(pBuffer);
            printf("\n\nOpcao sair foi escolhida...\n");
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

//Cria o buffer, mas não faz as ligações ainda
char* NewElement(char *nome, int *idade, char *telefone){ 
    void *pBufferPessoas = NULL;

    pBufferPessoas = (void*)(malloc(TAMANHOBASE));
    if (pBufferPessoas == NULL){
        printf("Erro na alocacao de memoria");
        exit (1);
    }

    strcpy((char *)(pBufferPessoas), nome); //nome
    *(int *)(pBufferPessoas + TAMANHONOME) = *idade; //idade
    strcpy((char*)(pBufferPessoas + TAMANHONOME + TAMANHOIDADE), telefone); //telefone
    *(char **)(pBufferPessoas + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE) = NULL; //next
    *(char **)(pBufferPessoas + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE + sizeof(char **)) = NULL; //previous

    return pBufferPessoas;
}

//Coloca o buffer criado na fila encadeada, fazendo as Ligações dos ponteiros  
void Insert(char **head, char *newp){
    char **tracer = head;

    //*tracer != NULL (Existe mais elementos na fila, next != Null)
    //strcmp < 1 Enquanto não achar um elemento maior que o newp não sai do while
    while (*tracer != NULL && strcmp(*tracer, (char *)(newp)) < 1) {     
        tracer = (char **)(*tracer + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE); //Vai para o próximo da fila
    }

    *(char **)(newp + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE) = *tracer;  //Atualiza o next do newp
    *tracer = newp; //Atualiza o next do que vem antes do newp 

    UpdatePrevious(head);
}

//Atualiza o previous de todos elementos da fila encadeada
void UpdatePrevious(char **tracer){ 
    char *tracerPrevious = *tracer;

    while (*tracer != NULL) {
        tracerPrevious = *tracer; //Memoriza o endereço anterior 
        tracer = (char **)(*tracer + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE);  //Vai para o próximo endereço da lista
        if (*tracer != NULL) { //Certifica-se que existe um endereço válido
            *(char **)(*tracer + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE + sizeof(char **)) = (char *)(tracerPrevious);
        }
    }

    //Atualiza o ponteiro last como o último elemento da lista
    last = (char *)(tracerPrevious);
}

//Mostra todos elementos
void Print(char **tracer){
    //Ponteiros auxiliares que estão no pBuffer
    int *quantPessoas =  (int *)(pBuffer + sizeof(int));
    int *i =  (int *)(pBuffer + (sizeof(int) * 2));

    printf("\n\n\n\t--- LISTA DAS PESSOAS ADICIONADOS NA FILA---\n");
    printf("\n\tQuantidade total de Pessoas %d", *(int *)(quantPessoas));
    printf("\n\tPrimeiro Nome da Lista: %s", (char *)(start));
    printf("\n\tUltimo Nome da Lista: %s", (char *)(last));

    //Faz a leitura pelo inicío da fila
    for (*i = 0; *i < *quantPessoas; *i = *i + 1) {
        printf("\n\n\tPESSOA %d", *(int *)(i));
        printf("\n\tNome: %s", (char **)(*tracer));
        printf("\n\tIdade: %d", *(int **)(*tracer + TAMANHONOME));
        printf("\n\tTelefone: %s", (char **)(*tracer + TAMANHONOME + TAMANHOIDADE));
        tracer = (char **)(*tracer + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE); //Vai para o próximo elemento da fila
    }   
}

//Pesquisa um nome na lista
void Search(char **tracer, char *text){
    int *teste = (int *)(pBuffer + (sizeof(int) * 3));  //Ponteiro auxiliar que está no pBuffer
    *teste = 0;

    //Lê toda fila
    while (*tracer != NULL) {
        if (strcmp(*tracer, text) == 0) {  //Compara se o campo nome é igual
            *teste = 1;
            break;
        }
        tracer = (char **)(*tracer + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE); //Vai para o próximo elemento da fila
    }

    if (*teste == 1){  
        printf("\n\tPALAVRA ENCONTRADA");  //Mostra dados do elemento encontrado
        printf("\n\n\tNome: %s", (char **)(*tracer));
        printf("\n\tIdade: %d", *(int **)(*tracer + TAMANHONOME));
        printf("\n\tTelefone: %s", (char **)(*tracer + TAMANHONOME + TAMANHOIDADE));

        char **temp = NULL;   //Mostra quem vem antes e depois na fila
        temp = (char **)(*tracer + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE + sizeof(char **)); //Endereço do Previous
        printf("\n\n\tNome anterior na fila: %s", (char **)(*temp));
        temp = (char **)(*tracer + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE);  //Endereço do Next
        printf("\n\tProximo nome da fila: %s", (char **)(*temp));
    } else {
        printf("\nPalavra nao encontrada");
    }
}

void Remove(char **head){
    //Ponteiros auxiliares que estão no pBuffer
    int *quantPessoas =  (int *)(pBuffer + sizeof(int));
    char *remove = NULL, **tracer = head;
    
    //Sempre remove a primeira pessoa da fila
    if ((*tracer) != NULL){
        remove = *tracer; //Memoriza o endereço de quem vai ser removido
        *tracer =  *(char **)(remove + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE);  //Atualiza tracer para endereço do próximo elemento
        *quantPessoas = *quantPessoas - 1; 
        free(remove);
        printf ("\n\nPESSOA RETIRADA DA FILA COM SUCESSO");
    } else {
        printf ("\n\nA FILA ESTA VAZIA");
    }
    
    if ((*tracer) == NULL){  //Removeu o último elemento da lista
        last = NULL;
    } else { //Caso tenha mais de um pessoa apenas na fila, atualiza o previous do elemento que ficou
        *(char **)(*tracer + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE + sizeof(char **)) = NULL; //Endereço do previous fica NULL
    }
}

//Exclui todos elementos da lista
void Clear(char *tracer){
    char *temp = NULL;
    while (tracer != NULL) {
        temp = *(char **)(tracer + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE); //Recebe o endereço do campo next para não perder
        Remove(&tracer); //Remove o endereço atual
        tracer = temp; //Atualiza o tracer para o próximo elemento
    }
}
