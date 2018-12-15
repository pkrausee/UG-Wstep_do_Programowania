#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "global.h"
#include "game.h"
#include "moves.h"

bool gameStatus(struct checkersBoard * game)
{
    if(game->blackPieces < 1 || game->whitePieces <1)
    {
        return false;
    }
    else
        return true;
}

void saveScore(char data[])
{
    FILE *f = fopen ("scores.txt", "ab+");
    if (f != NULL) {
        fputs (data, f);
        fclose (f);
    }
}

void newGame(struct checkersBoard * game)
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if((i+j)%2!=0 && i<3)
                game->board[i][j] = 2;
            else if((i+j)%2!=0 && i>4)
                game->board[i][j] = 1;
            else
                game->board[i][j] = 0;
        }
    }
    game->blackPieces = 12;
    game->whitePieces = 12;
    game->turn = true;
    game->error = false;
}

void movePiece(struct checkersBoard * game,int pos1Col,int pos1Row,int pos2Col,int pos2Row)
{
    // 1-whitePieces 2-blackPieces 3-whiteQueen 4-blackQueen
    if(pos2Col<8 && pos2Col>=0 && pos2Row<8 && pos2Row>=0 && pos1Col<8 && pos1Col >=0 && pos1Row<8 && pos1Row >=0)
    {
        if(game->board[pos1Row][pos1Col]==3 && game->turn)
        {
            moveWhiteQueen(game,pos1Col,pos1Row,pos2Col,pos2Row);
        }
        else if(game->board[pos1Row][pos1Col]==4 && !game->turn)
        {
            moveBlackQueen(game,pos1Col,pos1Row,pos2Col,pos2Row);
        }
        else if(game->board[pos1Row][pos1Col]==1 && game->turn)
        {
            moveWhitePiece(game,pos1Col,pos1Row,pos2Col,pos2Row);
        }
        else if(game->board[pos1Row][pos1Col]==2 && !game->turn)
        {
            moveBlackPiece(game,pos1Col,pos1Row,pos2Col,pos2Row);
        }
    }
    else
        game->error=true;
}
