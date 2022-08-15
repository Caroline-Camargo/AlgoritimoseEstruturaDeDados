#include <stdio.h>

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
            /* code */
            break;

            case 3:
                printf("\nVariavel  %s \n", nomes);
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
    printf("ESCOLHA UMA DAS OPCOES\n");
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

