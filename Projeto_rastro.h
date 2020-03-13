
#ifndef PROJETO_RASTRO_H
#define PROJETO_RASTRO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef enum {VAZIO, BRANCA, PRETA} CASA;
typedef struct {
    int coluna;
    int linha;
} COORDENADA;

typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

typedef JOGADA JOGADAS[32];

typedef struct {
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;

void gameStart (ESTADO *e);
#endif //PROJETO_RASTRO_H
