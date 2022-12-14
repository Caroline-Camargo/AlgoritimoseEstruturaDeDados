#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    Faça uma agenda capaz de incluir, apagar, buscar e listar quantas pessoas o usuário desejar, porém, toda a informação incluída na agenda deve ficar num único lugar 
    chamado: “void *pBuffer”.
        • Não pergunte para o usuário quantas pessoas ele vai incluir.
        • Não pode alocar espaço para mais pessoas do que o necessário.   
        • Cada pessoa tem nome[10], idade e telefone
*/

int Menu();
void InserirAgenda(int *numPessoas, char *nome, int *idade, int *telefone);
void ApagarAgenda(int *numPessoas);
void BuscarAgenda(int *numPessoas);
void ListarAgenda();

void *pBuffer = NULL;
const int TAMANHOBASE = sizeof(char) * 10 + 1 + sizeof(int) + sizeof(int);

int main() {
    char *nome = NULL;
    int *numPessoas = NULL, *idade = NULL;
    int *telefone = NULL;
    
    //Alocando espaço para o ponteiro void
    pBuffer = (void*)(malloc(TAMANHOBASE + sizeof(int)));
    if (pBuffer==NULL){
        printf("Erro na alocacao de memoria");
        exit (1);
    }

    //Definindo endereço incial para os ponteiros
    numPessoas = pBuffer;
    nome = pBuffer + sizeof(int);
    idade = pBuffer + sizeof(int) + sizeof(char) * 10 + 1;    
    telefone = pBuffer + sizeof(int) + sizeof(char) * 10 + 1 + sizeof(int) ;
    if (numPessoas==NULL || nome==NULL || idade==NULL || telefone==NULL){
        printf("Erro na alocacao de memoria");
        exit (1);
    }
    *numPessoas = 0;
    
    int opMenu = 0; 
    while (opMenu != 5) {
        opMenu = Menu();
        switch (opMenu) {
        case 1:
            *numPessoas = (int*)(*numPessoas + 1);
            if (*numPessoas != 1) {
                pBuffer = (void*)(realloc(pBuffer, TAMANHOBASE * (*numPessoas) + sizeof(int)));
                if (!pBuffer){
                    printf("Erro na alocacao de memoria 01");
                    exit (1);
                }
                nome = pBuffer + sizeof(int) + TAMANHOBASE * (*numPessoas-1);
                if (!nome) {
                    printf("Erro na alocacao de memoria 02");
                }

                idade = pBuffer + sizeof(int) + TAMANHOBASE * (*numPessoas-1) + sizeof(char) * 10 + 1; 
                if (idade==NULL){
                    printf("Erro na alocacao de memoria 03");
                    exit (1);
                }   

                telefone = pBuffer + sizeof(int) + TAMANHOBASE * (*numPessoas-1) + sizeof(char) * 10 + 1 + sizeof(int);
                if (telefone==NULL){
                    printf("Erro na alocacao de memoria 04");
                    exit (1);
                }
            } 
            InserirAgenda(pBuffer, nome, idade, telefone);
            ListarAgenda(numPessoas);
            break;

        case 2:
            ApagarAgenda(numPessoas);
            break;

        case 3:
            BuscarAgenda(numPessoas);
            break;

        case 4:
            ListarAgenda(numPessoas);
            break;

        case 5:
            //SAIR
            free(pBuffer);
            printf("Opcao sair foi escolhida...\n");
            break;
        
        default:
            printf("\n\nATENCAO: Digite um numero valido!\n");
            break;
        }
    }
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

void InserirAgenda(int *numPessoas, char *nome, int *idade, int *telefone){
    char tempChar[10];
    int tempInt1;
    int tempInt2;

    printf("\nDigite o nome que deseja incluir: ");
    fflush(stdin);
    gets(tempChar);
    strcpy(nome,tempChar);

    printf("\nDigite a idade: ");
    fflush(stdin);
    scanf("%d", &tempInt1);
    *idade = tempInt1;

    printf("\nDigite o telefone: ");
    fflush(stdin);
    scanf("%d", &tempInt2);
    *telefone = tempInt2;
}

void ApagarAgenda(int *numPessoas){
    char nomeBusca[10];
    int temp = 0;
    printf("\n\tDigite a palavra que deseja excluir: ");
    scanf("%s", nomeBusca);
    for (int i = 1; i <= *numPessoas; i++) {
        if (strcmp(nomeBusca, (char*)(pBuffer + TAMANHOBASE * (i-1) + sizeof(int))) == 0){
            temp = 1;
            printf("\n\tPalavra Encontrada");
            printf("\n\tNOME: %s", (char*)(pBuffer + TAMANHOBASE * (i-1) + sizeof(int)));
            printf("\n\tIDADE: %d", *(int*)(pBuffer + TAMANHOBASE * (i-1) + sizeof(int) + sizeof(char) * 10 + 1));
            printf("\n\tTELEFONE: %d", *(int*)(pBuffer + TAMANHOBASE * (i-1) + sizeof(int) + sizeof(char) * 10 + 1 + sizeof(int)));
            
            strcpy((char *)(pBuffer + TAMANHOBASE * (i-1) + sizeof(int)), (char *) (pBuffer + (TAMANHOBASE * (i)) + sizeof(int)));
            *(int *)(pBuffer + (TAMANHOBASE * (i-1)) + sizeof(int) + sizeof(char) * 10 + 1) = *(int *) (pBuffer + (TAMANHOBASE * (i)) + sizeof(int) + sizeof(char) * 10 + 1);
            strcpy((char *)(pBuffer + (TAMANHOBASE * (i-1)) + sizeof(int) + sizeof(char) * 10 + 1 + sizeof(int)), (char *) (pBuffer + (TAMANHOBASE * (i)) + sizeof(int) + sizeof(char) * 10 + 1 + sizeof(int)));
            printf("\n\tPalavra Removida");
        }
    }
    if (temp == 1) {
        pBuffer = (void*) realloc(pBuffer, (*numPessoas - 1) * TAMANHOBASE + sizeof(int));
        *numPessoas = *numPessoas - 1;
    } else {
        printf("\n\tPalavra nao encontrada");
    }
}

void BuscarAgenda(int *numPessoas){
    char nomeBusca[10];
    printf("\n\tDigite a palavra que deseja buscar: ");
    scanf("%s", nomeBusca);
    for (int i = 1; i <= *numPessoas; i++) {
        printf("\nAA");
        if (strcmp(nomeBusca, (char*)(pBuffer + TAMANHOBASE * (i-1) + sizeof(int))) == 0){
            printf("\n\tPalavra Encontrada");
            printf("\n\tNOME: %s", (char*)(pBuffer + TAMANHOBASE * (i-1) + sizeof(int)));
            printf("\n\tIDADE: %d", *(int*)(pBuffer + TAMANHOBASE * (i-1) + sizeof(int) + sizeof(char) * 10 + 1));
            printf("\n\tTELEFONE: %d", *(int*)(pBuffer + TAMANHOBASE * (i-1) + sizeof(int) + sizeof(char) * 10 + 1 + sizeof(int)));
        }
    }
}

void ListarAgenda(int *numPessoas){
    printf("\n LISTA DE PESSOAS ADICIONADAS: ");  
    if (*numPessoas == 0) {
        printf("\n\tNenhuma pessoa foi adicionada");
    } else {
        printf(" %d", *(int*)(pBuffer));
        for (int i=1; i<=(*numPessoas); i++) {
            if (i == 1) {
                printf("\n\tNome %d: %s", i, (char*)(pBuffer + sizeof(int)));
                printf("\n\tIdade: %d", *(int*)(pBuffer + sizeof(int) + sizeof(char) * 10 + 1));
                printf("\n\tTelefone: %d", *(int*)(pBuffer + sizeof(int) + sizeof(char) * 10 + 1 + sizeof(int)));
            } else {
                printf("\n\n\tNome %d: %s", i, (char*)(pBuffer + TAMANHOBASE * (i-1) + sizeof(int)));
                printf("\n\tIdade: %d", *(int*)(pBuffer + TAMANHOBASE * (i-1) + sizeof(int) + sizeof(char) * 10 + 1));
                printf("\n\tTelefone: %d", *(int*)(pBuffer + TAMANHOBASE * (i-1) + sizeof(int) + sizeof(char) * 10 + 1 + sizeof(int)));
            }
        }
    }    
}
