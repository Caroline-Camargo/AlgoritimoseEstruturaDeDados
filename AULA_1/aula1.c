/*  
    NOME: Caroline Souza Camargo
    CURSO: Ciências da Computação

    AULA 1
    LISTA 11
    EXERCÍCIO 5 
    5. Faça um programa que receba do usuário um arquivo de texto e um caracter. Mostre na tela quantas vezes aquele caracter ocorre dentro do arquivo.
*/

#include<stdlib.h>
#include<stdio.h>

int main() {
    //Variáveis
    char nomeArquivo[20], letraDigitada, letraTeste, aux[2];
    int contador_linhas=1, contador=0, teste;

    printf("Por favor, digite o nome do arquivo de texto: ");
    scanf("%s", &nomeArquivo);
    
    //Abrindo arquivo
    FILE *arquivoleitura;
    arquivoleitura = fopen(nomeArquivo, "r");
    if (arquivoleitura == NULL) {
        printf("\nErro ao abrir o arquivo.\n");
        return 1;
    }
    printf("\nArquivo %s aberto com sucesso", nomeArquivo);

    fflush(stdin);  //Descarregando buffers de saída
    printf("\nAgora digite o caracter que deseja pesquisar:");
    scanf("%c", &letraDigitada);

    while ((letraTeste = fgetc(arquivoleitura)) != EOF){
        if (letraTeste == letraDigitada){
            contador++;
        }
        if(letraTeste == '\n'){
            contador_linhas++;
        }
    }
    fclose(arquivoleitura);
    
    printf("\nA letra apareceu %d vezes no arquivo de texto %s", contador, nomeArquivo);
    printf("\nEsse arquivo possui %d linhas", contador_linhas);
}