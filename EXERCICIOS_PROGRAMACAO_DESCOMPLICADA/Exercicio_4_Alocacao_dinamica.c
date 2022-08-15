/*
    NOME: CAROLINE SOUZA CAMARGO
    4. Faça um programa que receba do usuario o tamanho de uma string e chame uma função para alocar dinamicamente essa string. Em seguida, o usuário deverá informar o conteudo dessa string. O programa imprime a string sem suas vogais.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int tamanhoString;
    char *palavra;

    printf("\nDigite o tamanho da string: ");
    scanf("%d", &tamanhoString);

    palavra = (char*) malloc(tamanhoString * sizeof(char) + 1);

    printf("\nDigite a string: ");
    scanf("%s", palavra);


    printf("\nString sem vogais: ");
    for (int i=0; i<strlen(palavra); i++) {
        if (palavra[i] != 'a' && palavra[i] != 'e' && palavra[i] != 'i' && palavra[i] != 'o' && palavra[i] != 'u'){
            printf("%c", palavra[i]);
        }
    }
}