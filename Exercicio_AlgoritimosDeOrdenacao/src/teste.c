#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void verifica(char * s);
char * removeDuplicates(char * s);

int main() {
    char *s = "abaabaca";
    removeDuplicates(s);
    verifica(s);
}

char * removeDuplicates(char * s){
    int tamanho = strlen(s), encontrou = 0;
    
    for (int i = 0; i < tamanho - 1; i++) {        
        if(s[i] == s[i + 1] || encontrou == 1){ 
            if (s[i+2] != '\0') {
                s[i] =  s[i + 2];
                encontrou = 1;
            } else{
                s[i] = '\0';
            }
        }
	}

    if(encontrou != 0){
        s = removeDuplicates(s);
    }
    
    verifica(s);
    return s;
}

void verifica(char * s){
    int tamanho = strlen(s);
    for (int i = 0; i < tamanho - 1; i++) {        
        if(s[i] == s[i + 1]){ 
            printf("\nNao deu certo");
        }
	}
    printf("\nDeu certo");
}




