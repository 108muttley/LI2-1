
#ifndef PROJETO_RASTRO_H
#define PROJETO_RASTRO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct estado {
    int tabuleiro [8][8]; //0- LIVRE; 1- POSIÇAO ATUAL; 2- BLOQUEADA;
}ESTADO;

void gameStart (ESTADO *e);
#endif //PROJETO_RASTRO_H
