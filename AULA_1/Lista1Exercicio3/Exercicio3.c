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
void InserirAgenda();
void ApagarAgenda();
void BuscarAgenda();
void ListarAgenda();

void *pBuffer = NULL;

int main() {
    char nome;
    int numPessoas, idade, telefone;

    pBuffer = malloc(1);
    pBuffer = 0;

    int opMenu = Menu(); 
    while (opMenu != 5) {
        opMenu = Menu();
        switch (opMenu) {
        case 1:
            InserirAgenda();
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

void InserirAgenda(){

}

void ApagarAgenda(){

}

void BuscarAgenda(){

}

void ListarAgenda(){
}

