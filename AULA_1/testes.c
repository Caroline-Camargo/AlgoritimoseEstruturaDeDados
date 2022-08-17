#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 10

int menu(void);
char *insertName(char *namesList);
char *removeName(char *namesList);
void listNames(char *namesList);

int main() {
  int choice;
  char *namesList = NULL;

  namesList = (char *)malloc(sizeof(char) + 1);
  namesList[0] = '\0';

  if (namesList == NULL) {
    printf("Memória insuficiente.\n");
    exit(1);
  }

  while (1) {
    choice = menu();
    switch (choice) {
    case 1:
      namesList = insertName(namesList);
      break;
    case 2:
      namesList = removeName(namesList);
      break;
    case 3:
      listNames(namesList);
      break;
    case 4:
      free(namesList);
      exit(0);
      break;
    }
  }

  return 0;
}

int menu(void) {
  int choice = 0;
  do {
    printf("MENU:\n");
    printf("- 1. Inserir um nome\n");
    printf("- 2. Excluir um nome\n");
    printf("- 3. Listar os nomes\n");
    printf("- 4. Sair\n");
    printf("Digite sua escolha: ");
    scanf("%d", &choice);
  } while (choice < 1 || choice > 4);
  getchar();
  return choice;
}

char *insertName(char *namesList) {
  char newName[NAME_SIZE];

  printf("Digite um nome: ");
  scanf("%s", newName);

  printf("%s\n", namesList);

  if (strlen(namesList) == 0) {
    namesList = (char *)realloc(namesList, (strlen(newName) + 1) * sizeof(char));
    strcat(namesList, newName);
  } else {
    namesList = (char *)realloc(namesList, (strlen(namesList) + 2 + strlen(newName)) * sizeof(char));
    strcat(namesList, ",");
    strcat(namesList, newName);
  }

  strcat(namesList, "\0");

  return namesList;
}

char *removeName(char *namesList) {
  char nameToRemove[NAME_SIZE];
  int auxIndex, firstCharOfNameIndex;

  printf("Digite um nome: ");
  scanf("%s", nameToRemove);

  char *nameString = strstr(namesList, nameToRemove);

  if (nameString == NULL) {
    printf("Nome não encontrado.\n");
    return namesList;
  }

  firstCharOfNameIndex = strlen(namesList) - strlen(nameString);

  if (firstCharOfNameIndex != 0 && namesList[firstCharOfNameIndex - 1] == ',') {
    firstCharOfNameIndex--;
    nameString--;
  }

  for (int i = 0; i <= strlen(nameToRemove); i++) {
    for (int j = 0; j < strlen(nameString); j++) {
      namesList[firstCharOfNameIndex + j] = namesList[firstCharOfNameIndex + j + 1];
    }
  }

  namesList = (char *)realloc(namesList, ((strlen(namesList)-strlen(nameToRemove)) + 1) * sizeof(char));

  strcat(namesList, "\0");

  return namesList;
}

void listNames(char *namesList) {
  if (strlen(namesList) == 0) {
    printf("Lista vazia :(\n");
  } else {
    printf("Nomes: %s\n", namesList);
  }
}