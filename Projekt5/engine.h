#ifndef _ENGINE_H_
#define _ENGINE_H_

#include"global.h"

void saveScore();
void newGame(struct checkersBoard * game);
bool gameStatus(struct checkersBoard * game);
void moveWhiteQueen(struct checkersBoard * game,int pos1Col,int pos1Row,int pos2Col,int pos2Row);
void moveBlackQueen(struct checkersBoard * game,int pos1Col,int pos1Row,int pos2Col,int pos2Row);
void moveWhitePiece(struct checkersBoard * game,int pos1Col,int pos1Row,int pos2Col,int pos2Row);
void moveBlackPiece(struct checkersBoard * game,int pos1Col,int pos1Row,int pos2Col,int pos2Row);
void movePiece(struct checkersBoard * game,int pos1Col,int pos1Row,int pos2Col,int pos2Row);

#endif
