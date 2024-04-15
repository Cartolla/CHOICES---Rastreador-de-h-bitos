///Bibliotecas///
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <locale.h>
///Nossas Bibliotecas///
#include "cadastro.h"
#include "categoria.h"
#include "habitos.h"
#include "Globais.h"
#include "extra.h"
#include "loopgeral.h"
///////////////////////

////////////// main ////////////////
int main() { 
   setlocale(LC_ALL, "Portuguese");
  for (iCAT = 0; iCAT < numcat; iCAT++) {
    switch (iCAT){
    case 0: 
      strcpy(categorias[iCAT].nome, "Exercicios");
      break;
    case 1:
      strcpy(categorias[iCAT].nome, "Saude");
      break;
    default:
      strcpy(categorias[iCAT].nome, "Trabalho");
      break;
    }
    categorias[iCAT].numhabitos = 0;
  }
/////////////////////////////////////////////////////////////////
  
  menuCadastro(); ///chama a tela inicial 
  cadastro(); ///chama a tela e a logica de cadastro
  loopGeral(); /// loop engloba tudo: categoria, habitos, personalizar, fechar.

///////////////////////////////////////////////////////////////////
return 0;
}
