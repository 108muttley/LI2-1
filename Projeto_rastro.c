#include "rastro.h"
void printa(ESTADO* e){
    int l,c;
    for (l=0; l<8; l++){
        for(c=0; c<8; c++){
            if(l==0 && c==7) printf("2 ");
            else if(l==7 && c==0) printf("1 ");
            else if(e->tab[l][c]==BRANCA) printf("* ");
            else if (e->tab[l][c]==PRETA) printf ("# ");
            else printf(". ");
        } putchar('\n');
    }
}
void gameStart (ESTADO *e){
    int l=0 , c=0;
    for(l; l<8; l++){
        for(c; c<8; c++){
            e->tab[l][c]= VAZIO;
        }
    }
    e->tab[3][4]= BRANCA;
    e->ultima_jogada.coluna = 4;
    e->ultima_jogada.linha= 3;
    e->num_jogadas=0;
    e->jogador_atual =1;
    printa(e);
}
void menu()
{
    printf("\nSelecione a sua opção:\n");
    printf("ler | Ler Jogo\n");
    printf("coordenada | Efetuar uma jogada, se válida\n");
    printf("gr | Guardar Jogo\n");
    printf("movs | Imprimir movimentos do jogo\n");
    printf("pos | visualizar uma posicao anterior\n");
    printf("jog | Sugestão de Jogada\n");
    printf("q | Sair do jogo\n");
}



COORDENADA posicao_atual (ESTADO *e){
    int i=0, j=0;
    COORDENADA c;
    for(i; i<8 ; i++ ){
        for(j; j<8 ; j++){
            if (e->tab[i][j] == BRANCA) {
                c.linha = i;
                c.coluna = j;
            }
        }
    }
    return c;
}
int jogadaValida(ESTADO *e, COORDENADA c){
    COORDENADA c2 = posicao_atual(e);
    if((c.linha<'a' || c.linha>'h') || (c.coluna<1 || c.coluna>8 )) return 0;
    else if(e->tab[c.linha][c.coluna] == VAZIO && ((c.linha == (c2.linha + 1) || (c.linha != (c2.linha - 1))) && (c.coluna == c2.coluna))) return 1;
    else if (e->tab[c.linha][c.coluna] == VAZIO && ((c.coluna == (c2.coluna + 1) || (c.coluna == (c2.coluna - 1))) && (c.linha == c2.linha))) return 1;
    else return 0;

}
int jogar(ESTADO *e , COORDENADA c) {
    COORDENADA c2 = posicao_atual(e);
    if (jogadaValida(e, c) == 0) return 0;
    else {
        e->tab[c2.linha][c2.coluna] == PRETA;
        e->tab[c.linha][c.coluna] == BRANCA;
        if (e->jogador_atual == 1) e->jogador_atual == 2;
        else e->jogador_atual = 1;
        e->num_jogadas += 1;
        e->ultima_jogada = c2;
        printa(e);
        return 1;

    }
}

void interpretador (ESTADO *e){
    char* fst, snd , arr;
    int i=0;
    COORDENADA c;
    fst = malloc(20*sizeof (char));
    snd = malloc(20*sizeof (char));
    arr = malloc(40* sizeof(char));
    menu();
    scanf("%s" , &arr);
    sscanf(arr, "%s %s", fst, snd);

    if (strcmp(fst, "Coordenada") == 0) {
        c.linha = snd;
        c.coluna = snd+1;
        jogar(e , c);
    }

}

