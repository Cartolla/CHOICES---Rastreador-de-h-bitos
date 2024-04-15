#include "cadastro.h"
#include "Globais.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iso646.h>
///////////////Biblioteca/////////////////

////////////Estruturas :)//////////
///Funções/////////////////


void menuCadastro(){
 printf(
        "\t\t╔-------------------------------╗\n"
              "\t\t╠\t\t\tChoices:\t\t\t╣\n"
        "\t\t╚-------►\e[32m[Your routine]\e[37m◄--------╜\n");
printf("\n═══════════════════════════════════════════════"
  "\nBem-vindo ao seu\e[35m Rastreador de Habitos Diarios\e[37m."
  "\nPara continuar aperte ¨\e[35mEnter\e[37m¨"
  "\n═══════════════════════════════════════════════\n"
  );

 getchar();
}

//////////////////////////
void enter(){
  printf("\npressione SOMENTE a tecla ¨ENTER para continuar¨");
  getchar();
}

/////////////////////////

void cadastro() { 
   system("clear");
  printf("\nVamos começar com o seu cadastro!\nEle é importante para que ocorra o \e[35msalvamento\e[37m.\n");
  sleep(3);

  while (1) {
     system("clear");
      printf("\n► Digite o seu nome completo:\n ");
      printf("\nR- ");
      fgets(nome, sizeof(nome), stdin); //armazenando o nome de usuário
     system("clear");

      // Mostrar o nome digitado
      printf("\nO nome digitado foi:\n %s", nome);

      // Perguntar se deseja mudar o nome
      printf("\n► Deseja mudar o nome? (S/N):\n ");
      printf("\nR- ");
      scanf(" %c", &opcaonome);
     system("clear");

      // Limpar o buffer de entrada
      while (getchar() != '\n');

      // Se a resposta não for 'S' ou 's', sair do loop
      if (opcaonome != 'S' && opcaonome != 's') {
          break;
      }
  }

}


