#include "rastro.h"

int main() {
    ESTADO* e= malloc(sizeof(ESTADO));
    gameStart(e);
    interpretador(e);
    return 0;
}
