#include<stdio.h>

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
    char *nomes, *nomeAdicionar, letra, temp[2];
    while (op != 4) {
        op = Menu();
        switch (op) {
            case 1:
                printf("Digite o nome que deseja adicionar: \n");
                fflush(stdin);
                scanf("%c", &letra);
                
                nomes = (char*)malloc(sizeof(letra));
                if (!nomes){
                    printf("Erro na alocacao de memoria");
                    exit (1);
                }
            
                *nomes = letra;
                printf("\n%c", *nomes);
                
                printf("\n --- %c", letra);
                
                while (letra != '\n') {
                    temp[1] = letra;
                    nomes = (char*)realloc(nomes,sizeof(letra));
                    scanf("%c", &letra);
                    *nomes = letra;
                    printf("\n --- %c", letra);
                    printf("\n%c", *nomes);
                }
                
                //nomeAdicionar = malloc(31);
                //scanf("%s", nomeAdicionar);
                //printf("\n%s", nomeAdicionar);
                //free(nomeAdicionar);
                //AdicionarNome(&nomes, &nomeAdicionar);
            break;

            case 2:
            /* code */
            break;

            case 3:
            /* code */
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

void AdicionarNome(char *nome, char *nomeAdd) {
    printf ("%s e %s", *nome, *nomeAdd);
    printf("entrou");
} 

