#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    23. Escreva um programa que receba dois structs do tipo dma, cada um representando uma
data valida, e calcule o número de dias que decorreram entre as duas datas. 
    struct dma {
        int dia;
        int mes;
        int ano;
    };
*/

typedef struct dma {
    int dia;
    int mes;
    int ano;
} Data;

int main() {
    Data *data;
    int contDias = 0;

    data = (Data*)(malloc(sizeof(Data) * 2));

    for (int i = 0; i < 2; i++) {
        if (i==0) {
            printf("\nPRIMEIRA DATA:");
        } else{
            printf("\nSEGUNDA DATA:");
        }
        
        printf("\n\tDia: ");
        scanf("%d", &data[i].dia);
        if (data[i].dia < 1 || data[i].dia > 31) {
            printf("Dia inválido");
            exit (0);
        }
        
        printf("\n\tMes: ");
        scanf("%d", &data[i].mes);
        if (data[i].mes < 1 || data[i].mes > 12) {
            printf("Mes inválido");
            exit (0);
        }

        printf("\n\tAno: ");
        scanf("%d", &data[i].ano);
        if (data[i].ano < 0) {
            printf("Ano inválido");
            exit (0);
        }
    }
    printf("\n\tData 1: %d/%d/%d ", data[0].dia, data[0].mes, data[0].ano);
    printf("\n\tData 2: %d/%d/%d ", data[1].dia, data[1].mes, data[1].ano);


    if (data[0].ano < data[1].ano) {
        for (int i = data[0].ano; i < data[1].ano; i++) {
            contDias = contDias + 365;
        }
    } else {
        for (int i = data[1].ano; i < data[0].ano; i++) {
            contDias = contDias + 365;
        }
    }

    if (data[0].mes < data[1].mes) {
        for (int i = data[0].mes; i < data[1].mes; i++) {
            contDias = contDias + 30;
        }
        for (int i = data[0].dia; i <= data[1].dia; i++) {
            contDias = contDias + 1;
        }
    } else {
        for (int i = data[1].mes; i < data[0].mes; i++) {
            contDias = contDias + 30;
        }
    }
    
    if (data[0].dia < data[1].dia) {
        for (int i = data[0].dia; i <= data[1].dia; i++) {
            contDias = contDias + 1;
        }
    } else {
        for (int i = data[1].dia; i < data[0].dia; i++) {
            contDias = contDias + 1;
        }
    }

    printf("\n\tDias de Difereca entre as duas datas: %d ",contDias);
}