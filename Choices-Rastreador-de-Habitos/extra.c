#include "habitos.h"
#include "cadastro.h"
#include "Globais.h"
#include "extra.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

void tempo(){
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  sprintf(habts[iHABT].datatempo, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

void mudarCor() {
    setlocale(LC_ALL, "Portuguese");

    int corTexto, corFundo;

    do {
        system("clear");
        printf("--------------------------------\n");
        printf("|      Personalizar o CHOICES   |\n");
        printf("--------------------------------\n");
        printf("--------Cores Disponiveis--------\n");
        printf("0 - Preto\t\t|\t1 - Vermelho\n");
        printf("2 - Verde\t\t|\t3 - Amarelo\n");
        printf("4 - Azul\t\t|\t5 - Roxo\n");
        printf("6 - Azul claro\t|\t7 - Branco\n");
     
        printf("-------------------------------------\n\n");
        
      
        printf("Digite o número da cor da fonte: ");
        scanf("%d", &corTexto);

        printf("Digite o número da cor do fundo: ");
        scanf("%d", &corFundo);

        if (corTexto > 8 || corFundo > 8) { //verifica se o número não está fora das opções
            printf("Tente outro número\n");
                                                                            } 
        else {    //se o número estiver nas opções, sai do loop e muda as cores 
            printf("\e[%dm \e[%dm", 30 + corTexto, 40 + corFundo);  
            printf("As cores foram definidas.");
            getchar(); 
            }    
        } 
      while (corTexto > 8 || corFundo > 8);
            
 
}


void sairChoices(){
   system("clear");    
  printf("Ate a proxima :)\nSaindo do Programa...\n");
  for (iANI = 0; iANI < 3; iANI++) {
    printf("o ");
    fflush(stdout); // Limpa o buffer de saída para garantir que a saída            
    sleep(1);       // Dorme por 1 segundo
  }
  exit(0); 
}
