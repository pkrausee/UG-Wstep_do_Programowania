#include <stdio.h>
#include <stdlib.h>
#include "show.h"
#include "game.h"

void Menu()
{
    system("clear");
    printf("WARCABY by Pawel Krause\n\n");
    printf("\t1 - New Game\n");
    printf("\t2 - How to play\n");
    printf("\t3 - Past Games\n");
    printf("\t4 - Exit Game\n");
    printf("\t------------ \n");
    printf(": ");

    char option = getchar();

    if(option == '1')
    {
        startGame();
	      Menu();
    }
    else if(option == '2')
    {
        showInstr();
        Menu();
    }
    else if(option == '3')
    {
        showScore();
        Menu();
    }
    else if(option == '4')
    {
        system("clear");
        printf("Thanks for playing\n");
    }
    else
    {
        Menu();
    }
}
