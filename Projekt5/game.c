#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "global.h"
#include "engine.h"

void showBoard(struct checkersBoard * game)
{
    system("clear");
    int i,j,k,l;
    printf("WARCABY by Pawel Krause\n\n");
    printf("White Pieces: %d\nBlack Pieces: %d",game->whitePieces,game->blackPieces);
    printf("\n\n   ");
    for(l=0;l<8;l++)
    {
        printf(" %c  ",97+l);
    }
    printf("\n   ");
    for(l=0;l<8;l++)
    {
        printf(" \u2500  ");
    }
    printf("\n");
    for(i=0;i<8;i++)
    {
        printf("%d |",i+1);
        for(j=0;j<8;j++)
        {
            if(game->board[i][j] == 2)
                printf(" \u25CB |");
            else if(game->board[i][j] == 1)
                printf(" \u25C9 |");
            else if(game->board[i][j] == 4)
                printf(" \u25A1 |");
            else if(game->board[i][j] == 3)
                printf(" \u25A0 |");
            else
                printf("   |");
        }
        printf(" \n   ");
        for(k=0;k<31 && i<7;k++)
        {
            printf("\u2500");
        }
        if(i<7)
            printf("\n");
    }
    for(l=0;l<8;l++)
    {
        printf(" \u2500  ");
    }
    printf("\n\n");
}

void startGame()
{
    system("clear");
    printf("WARCABY by Pawel Krause\n\n");
    struct checkersBoard game;
    newGame(&game);

    char player1Name[32];
    char player2Name[32];
    printf("Player 1: ");
    scanf("%s",player1Name);
    printf("Player 2: ");
    scanf("%s",player2Name);

    showBoard(&game);

    game.error = false;
    char command[32];
    while(strcmp(command, "exit")!=0 && strcmp(command, "ff")!=0 && gameStatus(&game))
    {
        if(game.error)
        {
            printf("Error\n");
            game.error = false;
        }
        if(game.turn)
            printf("%s turn\ncommand: ",player1Name);
        else
            printf("%s turn\ncommand: ",player2Name);

        scanf("%s",command);

        if(strcmp(command, "move") == 0)
        {
            char coordinates[2];

            scanf("%s",coordinates);
            int pos1Col = coordinates[0] - 97;
            int pos1Row = coordinates[1] - 49;

            scanf("%s",coordinates);
            int pos2Col = coordinates[0] - 97;
            int pos2Row = coordinates[1] - 49;

            movePiece(&game,pos1Col,pos1Row,pos2Col,pos2Row);
            showBoard(&game);
        }
    }

    system("clear");
    printf("WARCABY by Pawel Krause\n\n");
    char *result;
    if(game.blackPieces < 1 || (game.turn == false && strcmp(command, "ff")==0))
    {
        result = "W-L";
        printf("\t %s won the game\n",player1Name);
    }
    else if(game.whitePieces < 1 || (game.turn && strcmp(command, "ff")==0))
    {
        result = "L-W";
        printf("\t %s won the game\n",player2Name);
    }

    if(strcmp(command, "ff")==0)
    {
      char data[70];
      snprintf(data, sizeof(data), "%s %s %s\n", player1Name,result,player2Name);
      saveScore(data);
      printf("\n<--Go to Menu: Press [ENTER]\n");
      getchar();
      getchar();
    }
}
