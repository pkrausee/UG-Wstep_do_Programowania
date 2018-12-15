#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "global.h"

void showInstr()
{
    system("clear");
    int option;
    printf("WARCABY by Pawel Krause\n\n");
    printf("\tMoving pieces:\n");
    printf("\t\tCommand: move position1 position2\n");
    printf("\t\teq. move b3 a4\n");
    printf("\tSurrender:\n");
    printf("\t\tCommand: ff\n");
    printf("\tRage quit:\n");
    printf("\t\tCommand: exit\n\n");
    printf("<--Go back: Press [ENTER]\n");
    getchar();
    getchar();
}

void showScore()
{
    system("clear");
    printf("WARCABY by Pawel Krause\n\n");
    printf("\tPast Games:\n");
    FILE *f = fopen("scores.txt","rt");
    if(f==NULL)
    {
        printf("\t\tError: There is no scores file!\n");
        printf("<--Go back: Press [ENTER]\n");
        int option;
        scanf("%d",&option);
    }
    else
    {
        char s1[32];
        char s2[32];
        char s3[32];

        while(fscanf(f,"%s %s %s",s1,s2,s3)==3)
            printf("\t\t%s %s %s\n",s1,s2,s3);
        fclose(f);

        printf("\n<--Go back: Press [ENTER]\n");
        char key;
	      getchar();
        getchar();
    }
}
