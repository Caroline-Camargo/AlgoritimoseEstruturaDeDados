#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    Faça um programa que armazena nomes.
    • O programa deve armazenar todos os nomes na mesma string
    • O tamanho da string deve crescer e diminuir conforme nomes forem colocados ou removidos. Não pode ter desperdício de memória
    • Faça o seguinte menu:
        – 1) Adicionar nome
        – 2) Remover nome
        – 3) Listar
        – 4) Sair
*/

int menu();

int main() {
    int op=1, i=0, j=0, pos=0, inicio;
    char *nomes=NULL, nomeAdicionar[20], nomeRemover[20], *ponteiro=NULL;
    
    nomes = (char*)malloc(sizeof(char) * 1);
    if (!nomes){
        printf("Erro na alocacao de memoria");
        exit (1);
    }

    while (op != 4) {
        op = Menu();
        switch (op) {
        case 1: //Adicionar nomes
            printf("Digite o nome que deseja adicionar: \n");
            fflush(stdin);
            gets(nomeAdicionar);

            nomes = (char*)realloc(nomes, (strlen(nomes) + strlen(nomeAdicionar)) * sizeof(char) + 2);
            if (!nomes){
                printf("Erro na alocacao de memoria");
                exit (1);
            }

            strcat(nomeAdicionar,".");

            for (j=0; j<=(strlen(nomeAdicionar)); j++) {
                nomes[pos] = nomeAdicionar[j];
                pos++;
            }
            pos--;            
            break;

        case 2: //Removendo nomes
            printf("Digite o nome que deseja remover: \n");
            fflush(stdin);
            gets(nomeRemover);

            ponteiro = strstr(nomes, nomeRemover);
            if (ponteiro) {
                inicio = strlen(nomes) - strlen(ponteiro);
                if (nomes[inicio - 1] == '.') {     
                    inicio--;
                    ponteiro--;
                }

                for (i=0; i<=strlen(nomeRemover); i++) {
                    for (j=0; j<strlen(ponteiro); j++) {
                        nomes[inicio + j] = nomes[inicio + j + 1];
                    }
                    pos--;
                }

                nomes = (char *)realloc(nomes, strlen(nomes) * sizeof(char) + 2);
                printf("\nPalavra removida com sucesso"); 
            } else{
                printf("\nPalavra nao encontrada");
            }
            break;

        case 3: //Listando nomes
            printf("\nLista dos nomes adicionados:\n\t");
            for (i=0; i<=(strlen(nomes)); i++) {
                if (nomes[i] != '.'){
                    printf("%c", nomes[i]);
                }
                if (nomes[i] == '.') {
                    printf("\n\t");
                }
            }
            break;

        case 4: //Saindo do menu
            printf("Opcao sair foi escolhida...\n");
            break;
        
        default:
            printf("\nATENCAO: Digite um numero valido\n");
        break;
        }
    }
    free(nomes);
}

int Menu() {
    int opMenu;
    printf("\n\nESCOLHA UMA DAS OPCOES\n");
    printf("\t1) Adicionar nome\n");
    printf("\t2) Remover nome\n");
    printf("\t3) Listar\n");
    printf("\t4) Sair\n\t");
    scanf("%d", &opMenu);
    return opMenu;
}
