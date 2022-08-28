/*
    NOME: CAROLINE SOUZA CAMARGO
    9. Faça um programa que leia uma quantidade qualquer de numeros armazenando-os na memoria e pare a leitura quando o usuário entrar um número negativo. Em seguida, imprima o vetor lido. Use a função REALLOC.
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int *numeros, i=0;
    numeros = (int*) malloc(sizeof(int));

    printf("\nDigite um numero: ");
    scanf("%d", &numeros[0]);

    //Lendo numeros positivos e alocando espaço para cada um deles no ponteiro
    while (numeros[i] >= 0) {
        i++;
        numeros = (int*) realloc(numeros, sizeof(int) * (i+1));
        printf("\nDigite um numero: ");
        scanf("%d", &numeros[i]);
    }

    //Mostrando na tela os números presentes no ponteiro
    printf("\nNumeros digitados:\n");
    for (int j=0; j<i; j++) {
        printf("\t %d \n", *numeros);
        numeros++;
    }

    free(numeros);
}