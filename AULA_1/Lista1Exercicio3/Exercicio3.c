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
void ApagarAgenda();
void BuscarAgenda();
void ListarAgenda();

void *pBuffer = NULL;
int teste=0;

int main() {
    char *nome = NULL;
    int *numPessoas = NULL, *idade = NULL, *telefone = NULL;
    
    //Alocando espaço para os void
    pBuffer = (void*)malloc(sizeof(int) + sizeof(char) * 10 + 1 + sizeof(int) + sizeof(int));
    
    if (pBuffer==NULL){
        printf("Erro na alocacao de memoria");
        exit (1);
    }

    printf("TAMANHO OCUPADO POR pBuffer: %d", sizeof(pBuffer)); //Não condiz com que foi alocado ali em cima :/

    numPessoas = &pBuffer;
    if (numPessoas==NULL){
        printf("Erro na alocacao de memoria");
        exit (1);
    }
    *numPessoas = 0;
    
    int opMenu = 0; 
    while (opMenu != 5) {
        opMenu = Menu();
        switch (opMenu) {
        case 1:
            InserirAgenda(numPessoas, &nome, &idade, &telefone);
            
            //printf("\n\nVALOR NOS PONTEIROS: %d, %s", *numPessoas, nome);
            printf("\nVALORES NO VOID: %d, %s, %d", *(int *)numPessoas, (char *)(&numPessoas + sizeof(int)), *(int *)(&nome + sizeof(char) * 10 + 1));  
            printf("\naaaa");
            
            break;
        case 2:
            ApagarAgenda();
            break;

        case 3:
            BuscarAgenda();
            break;

        case 4:
            ListarAgenda();
            break;

        case 5:
            //SAIR
            free(numPessoas);
            free(nome);
            free(idade);
            free(telefone);
            free(pBuffer);
            printf("Opcao sair foi escolhida...\n");
            break;
        
        default:
            printf("\n\nATENCAO: Digite um numero valido!\n");
            break;
        }
    }
    
    free(pBuffer);
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
    int n = 1;
    *numPessoas = *numPessoas + n;
    printf("\nentrou1");
    if (teste == 0) {
        nome = &numPessoas + sizeof(int);
        if (!nome) {
            printf("Erro na alocacao de memoria 00");
        }
        printf("\nentrou2");
        teste=1;
    } else {
        printf("\nentrou3");
        pBuffer = realloc(pBuffer, sizeof(pBuffer) + sizeof(int) + sizeof(char)*10 + 1 + sizeof(int) + sizeof(int));
        if (!pBuffer){
            printf("Erro na alocacao de memoria 01");
            exit (1);
        }
        nome = &telefone + sizeof(int);
        if (!nome) {
            printf("Erro na alocacao de memoria 02");
        }
    } 
    
    idade = &nome + (sizeof(char) * 10 + 1);    
    telefone = &idade + sizeof(int);
    
    if (idade==NULL || telefone==NULL){
        printf("Erro na alocacao de memoria 03");
        exit (1);
    }
    
    printf("\nDigite o nome que deseja incluir: ");
    fflush(stdin);
    char tempNome[10];
    gets(tempNome);

    strcpy(nome,tempNome);
    strcat(tempNome, "\0");

    printf("\nDigite a idade: ");
    fflush(stdin);
    int tempIdade;
    scanf("%d", &tempIdade);

    *idade = tempIdade;

    printf("\nDigite o telefone: ");
    int tempTelefone;
    fflush(stdin);
    scanf("%d", &tempTelefone);

    *telefone = tempTelefone;

    printf("\n\nVALOR NOS PONTEIROS: %d, %s, %d, %d", *numPessoas, nome, *idade, *telefone);
    printf("\nVALORES NO VOID: %d, %s, %d, %d", (int *)pBuffer, (char *)(&numPessoas + sizeof(int)), *(int *)(&nome + sizeof(char) * 10 + 1), *(int *)(&idade + sizeof(int)));  
    printf("\naaaa");
}

void ApagarAgenda(){

}

void BuscarAgenda(){

}

void ListarAgenda(){
}

