// globals.h
#ifndef GLOBAIS_H
#define GLOBAIS_H

struct Habt {
    char nome[50];
    char datatempo[50];
    char notas[100];
    char completo[10];
};
struct cat {
  char nome[50];
  struct Habt habts[100];
  int numhabitos;
int numHabtConclu;
};

extern int iEstatis;
extern int escolhamenuCAT;
extern int escolhamenuHABT;
extern int escolhaGeral;
extern int escolhacat;
extern char nome[100];
extern char nomesemcadastro[50];
extern char opcaonome;
extern int escolhanome; // Inicialize a variável escolhanome
extern int personalizar;
extern int escolhamenuHist;
extern struct cat categorias[50];
extern int numcat, iCAT;
extern struct Habt habt;
extern struct Habt habts[100];
extern int numHabits;
extern int iHABT, iANI;
extern int corDoTexto;
extern int corDoFundo;
extern int voltarCor;
extern char contHabt;
extern char choice;
extern int escolhahabito;
extern int TotalHabt;
extern int TotalHabtConclu;

#endif /* GLOBALS_H */
