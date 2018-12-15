#ifndef _MOVES_H_
#define _MOVES_H_

#include"global.h"

void moveWhiteQueen(struct checkersBoard * game,int pos1Col,int pos1Row,int pos2Col,int pos2Row);
void moveBlackQueen(struct checkersBoard * game,int pos1Col,int pos1Row,int pos2Col,int pos2Row);
void moveWhitePiece(struct checkersBoard * game,int pos1Col,int pos1Row,int pos2Col,int pos2Row);
void moveBlackPiece(struct checkersBoard * game,int pos1Col,int pos1Row,int pos2Col,int pos2Row);

#endif
