#include "rastro.h"
void printa(ESTADO* e){
    int l,c;
    for (l=0; l<8; l++){
        for(c=0; c<8; c++){
            if(l==0 && c==7) printf("2 ");
            else if(l==7 && c==0) printf("1 ");
            else if(e->tabuleiro[l][c]==1) printf("* ");
            else if (e->tabuleiro[l][c]==2) printf ("# ");
            else printf(". ");
        } putchar('\n');
    }
}
void gameStart (ESTADO *e){
    int l=0 , c=0;
    for(l; l<8; l++){
        for(c; c<8; c++){
            e->tabuleiro[l][c]= 0;
        }
    }
    e->tabuleiro[3][4]= 1;
    printa(e);
}
