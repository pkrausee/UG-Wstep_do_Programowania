#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include<stdbool.h>

struct checkersBoard{
    int board[8][8];
    int blackPieces;
    int whitePieces;
    bool turn;
    bool error;
};

#endif
