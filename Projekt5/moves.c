#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "global.h"
#include "game.h"

void moveWhiteQueen(struct checkersBoard * game,int pos1Col,int pos1Row,int pos2Col,int pos2Row)
{
  int colMovement=pos1Col - pos2Col;
  if(colMovement<0)
    colMovement = colMovement * (-1);
  int rowMovement=pos1Row - pos2Row;
  if(rowMovement<0)
    rowMovement = rowMovement * (-1);
  if(colMovement == rowMovement)
  {
      if((game->board[pos2Row-1][pos2Col-1]==2 || game->board[pos2Row-1][pos2Col+1]==2 || game->board[pos2Row-1][pos2Col-1]==4 || game->board[pos2Row-1][pos2Col+1]==4) && pos2Row-pos1Row>0)
      {
          int swaper = game->board[pos1Row][pos1Col];
          game->board[pos1Row][pos1Col]=0;
          game->board[pos2Row][pos2Col]=swaper;
          game->turn=false;
          if((game->board[pos2Row-1][pos2Col-1]==2 || game->board[pos2Row-1][pos2Col-1]==4) && pos2Col - pos1Col > 0)
              game->board[pos2Row-1][pos2Col-1]=0;
          else if(pos2Col - pos1Col < 0)
              game->board[pos2Row-1][pos2Col+1]=0;
          game->blackPieces--;
      }
      else if((game->board[pos2Row+1][pos2Col-1]==2 || game->board[pos2Row+1][pos2Col+1]==2 || game->board[pos2Row+1][pos2Col-1]==4 || game->board[pos2Row+1][pos2Col+1]==4) && pos2Row-pos1Row<0)
      {
          int swaper = game->board[pos1Row][pos1Col];
          game->board[pos1Row][pos1Col]=0;
          game->board[pos2Row][pos2Col]=swaper;
          game->turn=false;
          if((game->board[pos2Row+1][pos2Col-1]==2 || game->board[pos2Row+1][pos2Col-1]==4) && pos2Col - pos1Col > 0)
              game->board[pos2Row+1][pos2Col-1]=0;
          else if(pos2Col - pos1Col < 0)
              game->board[pos2Row+1][pos2Col+1]=0;
          game->blackPieces--;
      }
      else
      {
          int swaper = game->board[pos1Row][pos1Col];
          game->board[pos1Row][pos1Col]=0;
          game->board[pos2Row][pos2Col]=swaper;
          game->turn=false;
      }
  }
  else
      game->error = true;
}

void moveBlackQueen(struct checkersBoard * game,int pos1Col,int pos1Row,int pos2Col,int pos2Row)
{
  int colMovement=pos1Col - pos2Col;
  if(colMovement<0)
    colMovement = colMovement * (-1);
  int rowMovement=pos1Row - pos2Row;
  if(rowMovement<0)
    rowMovement = rowMovement * (-1);
  if(colMovement == rowMovement)
  {
      if((game->board[pos2Row-1][pos2Col-1]==1 || game->board[pos2Row-1][pos2Col+1]==1 || game->board[pos2Row-1][pos2Col-1]==3 || game->board[pos2Row-1][pos2Col+1]==3) && pos2Row-pos1Row>0)
      {
          int swaper = game->board[pos1Row][pos1Col];
          game->board[pos1Row][pos1Col]=0;
          game->board[pos2Row][pos2Col]=swaper;
          game->turn=true;
          if((game->board[pos2Row-1][pos2Col-1]==1 || game->board[pos2Row-1][pos2Col-1]==3) && pos2Col - pos1Col > 0)
              game->board[pos2Row-1][pos2Col-1]=0;
          else if(pos2Col - pos1Col < 0)
              game->board[pos2Row-1][pos2Col+1]=0;
          game->whitePieces--;
      }
      else if((game->board[pos2Row+1][pos2Col-1]==1 || game->board[pos2Row+1][pos2Col+1]==1 || game->board[pos2Row+1][pos2Col-1]==3 || game->board[pos2Row+1][pos2Col+1]==3) && pos2Row-pos1Row<0)
      {
          int swaper = game->board[pos1Row][pos1Col];
          game->board[pos1Row][pos1Col]=0;
          game->board[pos2Row][pos2Col]=swaper;
          game->turn=true;
          if((game->board[pos2Row+1][pos2Col-1]==1 || game->board[pos2Row+1][pos2Col-1]==3) && pos2Col - pos1Col > 0)
              game->board[pos2Row+1][pos2Col-1]=0;
          else if(pos2Col - pos1Col < 0)
              game->board[pos2Row+1][pos2Col+1]=0;
          game->whitePieces--;
      }
      else
      {
          int swaper = game->board[pos1Row][pos1Col];
          game->board[pos1Row][pos1Col]=0;
          game->board[pos2Row][pos2Col]=swaper;
          game->turn=true;
      }
  }
  else
      game->error = true;
}

void moveWhitePiece(struct checkersBoard * game,int pos1Col,int pos1Row,int pos2Col,int pos2Row)
{
  if(pos1Row-pos2Row == 1 && (pos1Col-pos2Col == 1 || pos2Col-pos1Col == 1) && game->board[pos2Row][pos2Col] == 0)
  {
      int swaper = game->board[pos1Row][pos1Col];
      game->board[pos1Row][pos1Col]=0;
      if(pos2Row == 0)
          game->board[pos2Row][pos2Col] = 3;
      else
          game->board[pos2Row][pos2Col]=swaper;
      game->turn=false;
  }
  else if(pos1Row-pos2Row == 2 && (pos1Col-pos2Col == 2 || pos2Col-pos1Col == 2))
  {
      if(game->board[pos1Row-1][pos1Col-1]==2 || game->board[pos1Row-1][pos1Col+1]==2 || game->board[pos1Row-1][pos1Col-1]==4 || game->board[pos1Row-1][pos1Col+1]==4)
      {
          int swaper = game->board[pos1Row][pos1Col];
          game->board[pos1Row][pos1Col]=0;
          if(pos2Row == 0)
              game->board[pos2Row][pos2Col] = 3;
          else
              game->board[pos2Row][pos2Col]=swaper;
          game->turn=false;
          if(game->board[pos1Row-1][pos1Col-1]==2 || game->board[pos1Row-1][pos1Col-1]==4)
              game->board[pos1Row-1][pos1Col-1]=0;
          else
              game->board[pos1Row-1][pos1Col+1]=0;
          game->blackPieces--;
      }
      else
          game->error=true;
  }
  else if(pos2Row-pos1Row == 2 && (pos1Col-pos2Col == 2 || pos2Col-pos1Col == 2))
  {
      if(game->board[pos1Row+1][pos1Col-1]==2 || game->board[pos1Row+1][pos1Col+1]==2 || game->board[pos1Row+1][pos1Col-1]==4 || game->board[pos1Row+1][pos1Col+1]==4)
      {
          int swaper = game->board[pos1Row][pos1Col];
          game->board[pos1Row][pos1Col]=0;
          if(pos2Row == 0)
              game->board[pos2Row][pos2Col] = 3;
          else
              game->board[pos2Row][pos2Col]=swaper;
          game->turn=false;
          if(game->board[pos1Row+1][pos1Col-1]==2 || game->board[pos1Row+1][pos1Col-1]==4)
              game->board[pos1Row+1][pos1Col-1]=0;
          else
              game->board[pos1Row+1][pos1Col+1]=0;
          game->blackPieces--;
      }
      else
          game->error=true;
  }
  else
      game->error=true;
}

void moveBlackPiece(struct checkersBoard * game,int pos1Col,int pos1Row,int pos2Col,int pos2Row)
{
  if(pos2Row-pos1Row == 1 && (pos1Col-pos2Col == 1 || pos2Col-pos1Col == 1) && game->board[pos2Row][pos2Col]==0)
  {
      int swaper = game->board[pos1Row][pos1Col];
      game->board[pos1Row][pos1Col]=0;
      if(pos2Row == 7)
              game->board[pos2Row][pos2Col] = 4;
          else
              game->board[pos2Row][pos2Col]=swaper;
      game->turn=true;
  }
  else if(pos1Row-pos2Row == 2 && (pos1Col-pos2Col == 2 || pos2Col-pos1Col == 2))
  {
      if(game->board[pos1Row-1][pos1Col-1]==1 || game->board[pos1Row-1][pos1Col+1]==1 || game->board[pos1Row-1][pos1Col-1]==3 || game->board[pos1Row-1][pos1Col+1]==3)
      {
          int swaper = game->board[pos1Row][pos1Col];
          game->board[pos1Row][pos1Col]=0;
          if(pos2Row == 7)
              game->board[pos2Row][pos2Col] = 4;
          else
              game->board[pos2Row][pos2Col]=swaper;
          game->turn=true;
          if(game->board[pos1Row-1][pos1Col-1]==1 || game->board[pos1Row-1][pos1Col-1]==3)
              game->board[pos1Row-1][pos1Col-1]=0;
          else
              game->board[pos1Row-1][pos1Col+1]=0;
          game->whitePieces--;
      }
      else
          game->error=true;
  }
  else if(pos2Row-pos1Row == 2 && (pos1Col-pos2Col == 2 || pos2Col-pos1Col == 2))
  {
      if(game->board[pos1Row+1][pos1Col-1]==1 || game->board[pos1Row+1][pos1Col+1]==1  || game->board[pos1Row+1][pos1Col-1]==3 || game->board[pos1Row+1][pos1Col+1]==3)
      {
          int swaper = game->board[pos1Row][pos1Col];
          game->board[pos1Row][pos1Col]=0;
          if(pos2Row == 7)
              game->board[pos2Row][pos2Col] = 4;
          else
              game->board[pos2Row][pos2Col]=swaper;
          game->turn=true;
          if(game->board[pos1Row+1][pos1Col-1]==1 || game->board[pos1Row+1][pos1Col-1]==3)
              game->board[pos1Row+1][pos1Col-1]=0;
          else
              game->board[pos1Row+1][pos1Col+1]=0;
          game->whitePieces--;
      }
      else
          game->error=true;
  }
  else
      game->error=true;
}
