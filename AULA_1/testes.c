#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int op=1;
    char *nomes, letra, nomeAdicionar[20], temp[1];

    printf("Digite o nome que deseja adicionar: \n");
    fflush(stdin);
    scanf("%s", &nomeAdicionar);
    
    nomes = (char*)malloc(sizeof(char)+1);
    if (!nomes){
        printf("Erro na alocacao de memoria");
        exit (1);
    }

    for (int i=0; i<20; i++) {
        nomes[i] = nomeAdicionar[i];
    }
    
    
    puts(nomes);
    printf("\nVariavel  %s", *nomes);

   
}

   