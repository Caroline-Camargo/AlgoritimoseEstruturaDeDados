#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    NOME: Caroline Souza Camargo

    EXERCÍCIO 63 LISTA RECURSÃO
    Crie uma função que compara duas strings e que retorna se elas são iguais ou diferentes
*/

int compara (char string1[30], char string2[30]);

int main()
{
    int teste, i;
    char temp[30], string1[30], string2[30];
	printf("Por favor, digite a primeira string: \t");
    fflush(stdin);
    gets(string1);

    //Convertendo para minusculo a string 1
    for (i=0; string1[i] != '\0'; i++) {
        temp[i] = string1[i];
        string1[i] = tolower(temp[i]);
    }
    string1[i] = '\0';
    
    
    printf("\nPor favor, digite a segunda string: \t");
    fflush(stdin);
    gets(string2);

    //Convertendo para minusculo a string 2
    for (i=0; string2[i] != '\0'; i++) {
        temp[i] = string2[i];
        string2[i] = tolower(temp[i]);
    }
    string2[i] = '\0';

    teste = compara(string1, string2);

    printf("\nSTRING 1: \t%s", string1);
    printf("\nSTRING 2: \t%s", string2);
    if (teste == 1) {
        printf("\n\nAs duas strings sao iguais");
    } else {
        printf("\n\nAs duas strings sao diferentes");
    }
    
}

int compara (char string1[30], char string2[30]){
    int igual=0;
    for (int i=0; i<strlen(string2); i++) {
        if (string1[i] == string2[i]){
            igual++;
        }        
    }
    if(igual == strlen(string2) && igual == strlen(string2)){
        return 1;
    } else{
        return 0;
    }
}