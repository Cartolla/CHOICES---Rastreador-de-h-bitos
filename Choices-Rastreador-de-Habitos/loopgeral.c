///Bibliotecas///
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
///Nossas Bibliotecas///
#include "cadastro.h"
#include "categoria.h"
#include "habitos.h"
#include "Globais.h"
#include "extra.h"
#include "loopgeral.h"
///////////////////////

void loopGeral(){
   while (1) {
     escolhamenugeralgo: // menu geral setado em goto

      system("clear");
      printf("Apos a interação, aperte a tecla 'ENTER' para continuar :)\n");
     printf("\nEscolha uma opcao:\n");
      printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      printf("\n1. Categoria\n2. Habitos\n3. Historico\n4. Personalização\n\n5. Sair\n");
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      printf("\nR- ");
      scanf("%d", &escolhaGeral);
      getchar();

  ///////////////////////////////////////////////////////////  
  ///escolha geral se for 1 é categoria, se for 2 é habitos, se for 4 é personalização,mud se for 5 sai

  switch (escolhaGeral){
    ///Menu Categoria////////////////////////////////////////////////////////////////////

    //////////se for 1 cria cat, se for 2 visualiza////

    case 1:
        escolhamenucatgo: // dizendo ao goto onde volta
       system("clear");
        printf("Apos a interação, aperte a tecla 'ENTER' para continuar :)\n");
        printf("\nEscolha uma opcao:\n");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n1. Criar categoria\n");
        printf("2. Categorias Existentes\n3. Editar\n4. Excluir\n\n5. Voltar\n\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\nR- ");
        scanf("%d", &escolhamenuCAT);
        getchar();

////////////////////////////////////////////////////////////////////       
              switch (escolhamenuCAT){///switch para opções de cat
///////////////////// Cria Categoria ///////////////////////////////
                case 1:
                   system("clear");
                criarCat();
                break;

///////////////////// Visualiza Cat ////////////////////////////////
                case 2:
                  
                  while(1){
                    visuCat();
                      break;
                  }
                      break;
                  
                  break;

          /////////////////////     
                case 3:
                   system("clear");
                  editCat();
                goto escolhamenucatgo;
          /////////////////////
                case 4:
                    excluirCat();
                  goto escolhamenucatgo;
                break;
          /////////////////////
                case 5:
                  
                  
                  goto escolhamenugeralgo;/// retorna ao menu geral
              }  /////fechar switch escolha menu Cat
              
              goto escolhamenucatgo;/// retorna ao menu categoria

  ////////////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////

  ////////// Menu Habitos ///////////////////////////////////////////////////////
    case 2:
      escolhamenuHABT: // dizendo ao goto onde volta
       system("clear");
      printf("Apos a interação, aperte a tecla 'ENTER' para continuar :)\n");
      printf("\nEscolha uma opcao:\n");
      printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      printf("\n1. Adicionar habito a categoria");
      printf("\n2. Visualizar\n3. Editar\n4. Excluir\n5. Marcar concluido\n\n6. Voltar\n");
       printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      printf("\nR- ");
      scanf("%d", &escolhamenuHABT);
      getchar();

    //////////////////////////////////////////////////////////////
        switch (escolhamenuHABT) {
        //// add habito////
         case 1:
          addhabtCat();
          goto escolhamenuHABT;
         break; 

        ////////////////////
         case 2:
            while (1) {
               system("clear");
              printf("\nAs Categorias Existentes sao:\n");
              for (iCAT = 0; iCAT < numcat; iCAT++) {
              if (strcmp(categorias[iCAT].nome, "") != 0) {
              printf("%d. %s\n", iCAT + 1, categorias[iCAT].nome);
                } 
              }
              printf("\nEscolha uma categoria (1 - %d)\n", numcat);
              scanf("%d", &escolhacat);
              getchar(); // Limpa o buffer do enter

              if (escolhacat >= 1 && escolhacat <= numcat) {
              escolhacat--; // Ajusta para o índice do array (0-based)

              if (categorias[escolhacat].numhabitos < 1) {
                 system("clear");
              printf("\nCategoria não possui hábitos.\n");
              enter();
              goto escolhamenuHABT;
              } 
              else{
                 system("clear");
                for (int i = 0; i < categorias[escolhacat].numhabitos; i++) {
                    printf("%d. %s\n", i + 1, categorias[escolhacat].habts[i].nome);
                }
                // Agora espera o usuário pressionar Enter antes de continuar
                enter();
                goto escolhamenuHABT;
                break;
                }
                }
              else{
                 system("clear");
                  printf("\nCategoria inválida. Aperte Enter para voltar.\n");
                  enter();
                  // Agora espera o usuário pressionar Enter antes de continuar
                  goto escolhamenuHABT;
                
            }
        }
  ////////////////////////////////////////////////////////////////////////
          case 3: 
            ////editar habito////
          system("clear");
                printf("\nAs Categorias Existentes sao:\n");

                for (iCAT = 0; iCAT < numcat; iCAT++) {
                    if (strcmp(categorias[iCAT].nome, "") != 0) {
                        printf("%d. %s\n", iCAT + 1, categorias[iCAT].nome);
                    }
                }

                printf("Escolha uma categoria (1 - %d) para editar um hábito: ", numcat);
                int escolhacat;
                scanf("%d", &escolhacat);
                escolhacat--; 

                if (escolhacat < 0 || escolhacat >= numcat || strcmp(categorias[escolhacat].nome, "") == 0) {
                    printf("Categoria inválida. Pressione Enter para continuar.\n");
                    getchar(); //espera o enter
                    return;
                }

                getchar(); 

                // Listar hábitos na categoria escolhida
                printf("\nHábitos na categoria '%s':\n", categorias[escolhacat].nome);//mostra o nome da catagoria escolhida
                for (iHABT = 0; iHABT < categorias[escolhacat].numhabitos; iHABT++) { //mostra os hábitos da categoria escolhida
                    printf("%d. %s\n", iHABT + 1, categorias[escolhacat].habts[iHABT].nome);
                }

                printf("Escolha o hábito a ser editado (1 - %d): ", categorias[escolhacat].numhabitos);
                int escolhahabito;
                scanf("%d", &escolhahabito);
                escolhahabito--;

                if (escolhahabito < 0 || escolhahabito >= categorias[escolhacat].numhabitos) {
                    printf("Hábito inválido. Pressione Enter para continuar.\n");
                    getchar(); 
                    return;
                }

                getchar(); 

                //pede o novo nome do hábito e substitui
                printf("Digite o novo nome para o hábito: ");
                fgets(categorias[escolhacat].habts[escolhahabito].nome, sizeof(categorias[escolhacat].habts[escolhahabito].nome), stdin);

                printf("Hábito editado com sucesso! Pressione Enter para continuar.\n");
                getchar();
            

                
                
          

          case 4:
            ////excluir habito////
            system("clear");
           printf("\nAs Categorias Existentes sao:\n");
           for (iCAT = 0; iCAT < numcat; iCAT++) {
             if (strcmp(categorias[iCAT].nome, "") != 0) {
               printf("%d. %s\n", iCAT + 1, categorias[iCAT].nome);
             }   
           }
           printf("Escolha uma categoria (1 - %d): ", numcat);
           printf("\nR- ");
           scanf("%d", &escolhacat);
           escolhacat--; // Ajustar para o índice do array (0-based)

           // verificando se a escolha da categoria é válida
           if (escolhacat >= 0 && escolhacat < numcat) {
               // erificando se há hábitos para excluir na categoria escolhida
               if (categorias[escolhacat].numhabitos == 0) {
                   printf("Esta categoria não possui hábitos para excluir.\n");
                 goto escolhamenuHABT;
               } 
               else {
                   // listando os hábitos existentes na categoria escolhida
                   printf("Hábitos na categoria '%s':\n", categorias[escolhacat].nome);
                   for (int i = 0; i < categorias[escolhacat].numhabitos; i++) {
                       printf("%d. %s\n", i + 1, categorias[escolhacat].habts[i].nome);
                   }

                   //solicitando ao usuário que escolha um hábito para excluir
                   printf("Escolha o hábito para excluir (1 - %d):\n ", categorias[escolhacat].numhabitos);
                   printf("\nR- ");
                   scanf("%d", &escolhahabito);
                   escolhahabito--; // Ajustar para o índice do array (0-based)

                   //verificando se a escolha do hábito é válida
                   if (escolhahabito >= 0 && escolhahabito < categorias[escolhacat].numhabitos) {
                       //excluindo o hábito escolhido
                       for (int i = escolhahabito; i < categorias[escolhacat].numhabitos - 1; i++) {
                           categorias[escolhacat].habts[i] = categorias[escolhacat].habts[i + 1];
                       }
                       categorias[escolhacat].numhabitos--; // Reduz o número total de hábitos na categoria

                       printf("Hábito excluído com sucesso da categoria '%s'! :)\n", categorias[escolhacat].nome);
                     goto escolhamenuHABT;
                   } 
                   else {
                       printf("Escolha inválida do hábito. :(\n");
                     goto escolhamenuHABT;
                   }
               }
           } 
           else {
               printf("Escolha inválida da categoria. :(\n");
             goto escolhamenuHABT;
           }
          
          
          case 5:
          marcarHabt();
          
          case 6:
            goto escolhamenugeralgo; /// retorna ao menu geral
        }
/////////////////////////////////////////////////////////////////////
  
  
  
    

    case 3:
        escolhamenuHist: // dizendo ao goto onde volta
        system("clear");
        printf("Apos a interação, aperte a tecla 'ENTER' para continuar :)\n");
        printf("\nEscolha uma opcao:\n");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n1. Historico\n2. Estatistica\n\n3. Voltar\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\nR- ");
        scanf("%d", &escolhamenuHist);
        getchar();
        switch (escolhamenuHist) {
          case 1:
          mostrarHistorico();
          goto escolhamenuHist;
          
          case 2:
          exibirEstatistica();
          goto escolhamenuHist;

          case 3:
          goto escolhamenugeralgo;
        }
     
     case 4:
     mudarCor();
     goto escolhamenugeralgo;
     break;
     
    case 5:
      sairChoices();
      break;
  }
  }
 

}
