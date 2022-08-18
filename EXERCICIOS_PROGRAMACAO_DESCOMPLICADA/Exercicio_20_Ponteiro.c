#include <stdio.h>
#include <stdlib.h>

/*
    NOME: Caroline Souza Camargo

    EXERCÍCIO 20 - LISTA SOBRE PONTEIROS
    Implemente uma função que receba como parametro um array de números reais de tamanho N e retorne quantos numeros negativos há nesse array. Essa função deve obedecer ao prototipo: 
    int negativos(float *vet, int N);

*/

int Menu();
int inserirNum (int tamanhoN, float *arrayNumReais);
void exibir(int tamanhoN, float *arrayNumReais);
int negativos(float *vet, int N);

int main(){
    int tamanhoN=0, op=0, quanNegativos=0;
    float *arrayNumReais = NULL;
    
    //Alocando espaço para vetor 
    arrayNumReais = (float*)malloc(sizeof(float) * 1);
    if (!arrayNumReais){
        printf("Erro na alocacao de memoria");
        exit (1);
    }

    do {
        op = Menu();
        switch (op) {
        case 1:
            //Inserir numeros
            tamanhoN = inserirNum(tamanhoN, arrayNumReais);
            break;

        case 2:
            //Exibir numeros digitados
            exibir(tamanhoN, arrayNumReais);
            break;
        
        case 3:
            //Exibir quantidade de numeros negativos digitados
            quanNegativos = negativos(arrayNumReais, tamanhoN);
            printf("\n\tQuantidade de negativos: %d", quanNegativos);
            break;

        case 4:
            //Sair do Loop e liberar memória
            free(arrayNumReais);
            printf("Opcao sair foi escolhida...\n");
            break;

        default:
            printf("\n\nATENCAO: Digite um numero valido!\n");
            break;
        }
    } while (op != 4);   
}

int Menu() {
    int opMenu;
    printf("\n\nESCOLHA UMA DAS OPCOES\n");
    printf("\t1) Inserir numero\n");
    printf("\t2) Exibir numeros digitados\n");
    printf("\t3) Exibir quantidade de numeros negativos digitados\n");
    printf("\t4) Sair\n");
    scanf("%d", &opMenu);
    return opMenu;
}

int inserirNum (int tamanhoN, float *arrayNumReais){
    float temp;
    tamanhoN++;

    arrayNumReais = (float*)realloc(arrayNumReais, tamanhoN * sizeof(float));
    if (!arrayNumReais){
        printf("Erro na alocacao de memoria");
        exit (1);
    }

    printf("\nPor favor, digite um numero: \n\t");
    scanf("%f", &temp);

    arrayNumReais[tamanhoN - 1] = temp;
    return tamanhoN; 
}

void exibir(int tamanhoN, float *arrayNumReais){
    printf("\nNumeros digitados: \t");
    for (int i=0; i<tamanhoN; i++) {
        printf(" %f ", arrayNumReais[i]);
    }
    printf("\n");
}

int negativos(float *vet, int N){
    int quanNegativos=0;
    for (int i=0; i<N; i++) {
        if (vet[i] < 0 ){
            quanNegativos++;
        }
    }
    return quanNegativos;
}