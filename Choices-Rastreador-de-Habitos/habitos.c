#include "habitos.h"
#include "cadastro.h"
#include "categoria.h"
#include "Globais.h"
#include "extra.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


void addhabtCat(){
   system("clear");
  printf("\nAs Categorias Existentes sao:\n");
    for (iCAT = 0; iCAT < numcat; iCAT++) {
      if (strcmp(categorias[iCAT].nome, "") != 0) {
        printf("%d. %s\n", iCAT + 1,categorias[iCAT].nome);
      } 
     }  
      if (numcat > 0) {
        printf("\nEscolha uma Categoria (1 - %d):\n ", numcat);
        printf("\nR- ");
        scanf("%d", &escolhacat);
        getchar();
      
      if (escolhacat >= 1 && escolhacat <= numcat) {
        struct cat *catSelecionada = &categorias[escolhacat - 1];
        printf("\nDigite o nome do seu habito:\n ");
        fgets(catSelecionada->habts[catSelecionada->numhabitos].nome,sizeof(catSelecionada->habts[catSelecionada->numhabitos].nome),stdin);
          catSelecionada->habts[catSelecionada->numhabitos].nome[strcspn(catSelecionada->habts[catSelecionada->numhabitos].nome, "\n")] = '\0';

                   tempo();
                    catSelecionada->numhabitos++;
                    TotalHabt++;
                   printf("Habito Adicionado com sucesso a categoria '%s'! :)\n",
                          catSelecionada->nome);
                          getchar();
                   } 
                     else {
                       printf("Escolha inválida. :(\n");
                       enter();
                     }

                   }
}


  

  void visuHabt() {
      printf("\nAs Categorias Existentes são:\n");
    for (iCAT = 0; iCAT < numcat; iCAT++) {
      if (strcmp(categorias[iCAT].nome, "") != 0) {
        printf("%d. %s\n", iCAT + 1, categorias[iCAT].nome);
      }   
    }
      printf("\nEscolha uma Categoria (1 - %d):\n ", numcat);
      printf("\nR- ");
      scanf("%d", &escolhacat);
      getchar(); 
      if (escolhacat >= 1 && escolhacat <= numcat) {
          struct cat *catSelecionada = &categorias[escolhacat - 1];
          printf("Hábitos na Categoria %s:\n", categorias[escolhacat - 1].nome);
        
          for (int i = 0; i < categorias[escolhacat - 1].numhabitos; ++i) {
              printf("Hábito %d:\n", i + 1);
              printf("Nome: %s\n", categorias[escolhacat - 1].habts[i].nome);
              
          }
      } 
      else {
          printf("\nEscolha inválida. :(\n");
          enter();
      }
  }
  





void marcarHabt() {
   system("clear");
  printf("As Categorias Existentes são:\n"); //mostra as categorias
  for (int iCAT = 0; iCAT < numcat; iCAT++) {
      if (strcmp(categorias[iCAT].nome, "") != 0) {
          printf("%d. %s\n", iCAT + 1, categorias[iCAT].nome);
      }
  }

  printf("\nEscolha uma categoria (1 - %d):\n", numcat);   //escolher uma categoria
  printf("R- ");
  scanf("%d", &escolhacat);
  getchar(); // Limpar o buffer de entrada
   system("clear");

  if (escolhacat < 1 || escolhacat > numcat) {
      printf("Categoria inválida. Pressione Enter para continuar.\n");
      getchar();
      return;
  }

  escolhacat--; // ajustar para o índice do vetor

  //mostra os hábitos da categoria escolhida 
  printf("\nHábitos da categoria '%s':\n", categorias[escolhacat].nome); 
  for (int iHABT = 0; iHABT < categorias[escolhacat].numhabitos; iHABT++) {
      printf("%d. %s\n", iHABT + 1, categorias[escolhacat].habts[iHABT].nome);
  }

  printf("\nEscolha um hábito (1 - %d):\n", categorias[escolhacat].numhabitos);
  printf("R- ");
  scanf("%d", &escolhahabito);
  getchar(); // Limpar o buffer de entrada

  if (escolhahabito < 1 || escolhahabito > categorias[escolhacat].numhabitos) {
      printf("Hábito inválido. Pressione Enter para continuar.\n");
      getchar();
      return;
  }

  escolhahabito--; // Ajustar para o índice do array (0-based)

  // Marcar o hábito como completo
  tempo();
  strcpy(categorias[escolhacat].habts[escolhahabito].datatempo, habt.datatempo);
  strcpy(categorias[escolhacat].habts[escolhahabito].completo, "Sim");

  categorias[escolhacat].numHabtConclu++;
  TotalHabtConclu++;
  
  printf("Hábito marcado como concluído. Pressione Enter para continuar.\n");
  getchar();
   system("clear");
}



void exibirEstatistica(){
   system("clear");
      printf("Estatísticas dos Hábitos concluídos por: %s. Parabéns!!\n", nome);
      for (int i = 0; i < numcat; i++) {
          if (strcmp(categorias[i].nome, "") != 0) {
              printf("\nCategoria '%s': %d hábitos concluídos.\n", categorias[i].nome, categorias[i].numHabtConclu);
          }
      }
      printf("\nTotal Geral: %d hábitos concluídos.\n", TotalHabtConclu);
      float porcentagem = 0.0;
      if (TotalHabtConclu > 0) {
          porcentagem = ((float)TotalHabtConclu / (float)TotalHabt) * 100;}

      printf("Porcentagem de hábitos concluídos: %.2f%%\n", porcentagem);
      enter();
   system("clear");
  }


void mostrarHistorico() {
   system("clear");
    printf("Histórico do Choices:\n\n");
  
    for (int iCat = 0; iCat < numcat; iCat++) {
        if (strcmp(categorias[iCat].nome, "") != 0) {
            printf("Categoria: %s\n", categorias[iCat].nome);

            for (int iHabt = 0; iHabt < categorias[iCat].numhabitos; iHabt++) {
                printf("Hábito: %s\n", categorias[iCat].habts[iHabt].nome);

                  if (categorias[iCat].habts[iHabt].completo[0] == 'S') {
                      tempo(iHABT); // Chama a função tempo() para obter a data formatada
                      printf("Data de Conclusão: %s\n", habts[iHABT].datatempo);
                  } 
                else {
                    printf("Este hábito ainda não foi concluído.\n");
                }

                printf("\n");
            }
        }
    }

    enter();
   system("clear");
}

