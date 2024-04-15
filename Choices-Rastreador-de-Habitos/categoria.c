#include "categoria.h"
#include "cadastro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Globais.h"

void criarCat(){
  if (numcat < 10) {
        printf("Digite o nome da nova categoria: ");
        fgets(categorias[numcat].nome, sizeof(categorias[numcat].nome), stdin);

    categorias[numcat].nome[strcspn(categorias[numcat].nome, "\n")] = '\0';
    categorias[numcat].numhabitos = 0;
    numcat++;
    printf("Nova Categoria adicionada com Sucesso!! :)\n");
    enter();

  } 
  else {
    printf("O limite maximo de categorias foi atingido. Delete uma categoria não desejada ou adicione seu hábito a uma já existente.\n");
        getchar();

  }
}



void editCat() {
   system("clear");
    printf("\nAs Categorias Existentes sao:\n");

    for (iCAT = 0; iCAT < numcat; iCAT++) {
        if (strcmp(categorias[iCAT].nome, "") != 0) {
            printf("%d. %s\n", iCAT + 1, categorias[iCAT].nome);
        }
    }

    printf("Escolha a categoria a ser editada (1 - %d): ", numcat);
    int escolhacat;
    scanf("%d", &escolhacat);
    escolhacat--; // ajustando o índice do vetor

    if (escolhacat < 0 || escolhacat >= numcat || strcmp(categorias[escolhacat].nome, "") == 0) {
        printf("Categoria inválida. Pressione Enter para continuar.\n");
        getchar(); 
        return;
    }

    getchar(); 
   system("clear");
    printf("Digite o novo nome da categoria: ");
    fgets(categorias[escolhacat].nome, sizeof(categorias[escolhacat].nome), stdin);

    // remove o caractere da nova linha do nome
    categorias[escolhacat].nome[strcspn(categorias[escolhacat].nome, "\n")] = '\0';

    printf("Categoria editada com sucesso. Pressione Enter para continuar.\n");
    getchar(); 
}


/////////////////////////////////////////////////////////////////

void excluirCat(){
  while(1){
     system("clear");
    printf("\nAs Categorias Existentes sao:\n");
    for (iCAT = 0; iCAT < numcat; iCAT++) {
      if (strcmp(categorias[iCAT].nome, "") != 0) {
        printf("%d. %s\n", iCAT + 1, categorias[iCAT].nome);
      }   
    }
    
  printf("\nEscolha uma categoria para excluir (1 - %d) ou 0 para SAIR:\n", numcat);
  scanf("%d", &escolhacat);
  getchar();

  if (escolhacat >= 1 && escolhacat <= numcat) {
      // Excluir a categoria escolhida
      for (int i = escolhacat - 1; i < numcat - 1; i++) {
          categorias[i] = categorias[i + 1];
      }
      numcat--; //reduz o número total de categorias

      printf("Categoria excluída com sucesso!\n");
      enter();
  } 
  else if (escolhacat == 0) {
      break; //sai do loop e encerra o programa
  } 
  else {
      printf("Escolha inválida. Aperte Enter para continuar.\n");
      enter();
  }
}
}

void visuCat(){
   system("clear");
printf("\nAs Categorias Existentes sao:\n");
for (iCAT = 0; iCAT < numcat; iCAT++) {
  if (strcmp(categorias[iCAT].nome, "") != 0) {
    printf("%d. %s\n", iCAT + 1, categorias[iCAT].nome);
  }   
}
  
  getchar();

}