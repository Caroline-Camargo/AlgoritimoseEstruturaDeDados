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
    int op=1;
    char *nomes, nomeAdicionar[20], letra, i=0, j=0;
    nomes = (char*)malloc(sizeof(char));

    while (op != 4) {
        op = Menu();
        switch (op) {
            case 1:
                //AdicionarNome(&i, &nomes);
                j=0;
                printf("Digite o nome que deseja adicionar: \n");
                fflush(stdin);
                scanf("%s", &nomeAdicionar);
                strcat(nomeAdicionar,".");
                
                nomes = (char*)realloc(nomes, sizeof(nomeAdicionar) * sizeof(char) + 1);
                if (!nomes){
                    printf("Erro na alocacao de memoria");
                    exit (1);
                }

                for (i; i<=(strlen(nomes)); i++) {
                    nomes[i] = nomeAdicionar[j];
                    j++;
                }
                i--;            
            break;

            case 2:
                printf("Digite o nome que deseja remover: \n");
                fflush(stdin);
                scanf("%s", &nomeAdicionar);

            break;

            case 3:
                printf("\nLista dos nomes adicionados:\n");
                for (i=0; i<=(strlen(nomes)); i++) {
                    if (nomes[i] != '.'){
                        printf("%c", nomes[i]);
                    }
                    if (nomes[i] == '.') {
                        printf("\n");
                    }
                }
            break;

            case 4:
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

void AdicionarNome(int *i, char *nomes) {
    int j=0;
    char nomeAdicionar[20];

    printf("Digite o nome que deseja adicionar: \n");
    fflush(stdin);
    scanf("%s", &nomeAdicionar);
                
    nomes = (char*)realloc(nomes, sizeof(nomeAdicionar) * sizeof(char) + 1);
    if (!nomes){
        printf("Erro na alocacao de memoria");
        exit (1);
    }

    for (*i; *i<=(strlen(nomes)); *i++) {
        nomes[*i] = nomeAdicionar[j];
        j++;
    }
    *i--;      
} 

