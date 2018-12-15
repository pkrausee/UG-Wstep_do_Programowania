//Pawel Krause grupa 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int arrX[32];
int a,b,i,j,n;

void clean(int size,char tab[size]);
void setA(char tab[n],int size);
void setB(char tab[n],int size);
bool search_arrX(int x);

int main()
{
    for(i=0;i<32;i++)
        arrX[i]=-1;

    printf("Podaj n: ");
    scanf("%d",&n);
    while(n<1 || n>6)
    {
        printf("Podano n spoza zakresu\n");
        printf("Podaj n: ");
        scanf("%d",&n);
    }

    char xTab[n];
    clean(n,xTab);

    printf("Podaj x: ");
    scanf("%s",xTab);
    while(strlen(xTab)>n)
    {
        printf("Podano zbyt dluga liczbe\n");
        printf("Podaj x: ");
        scanf("%s",xTab);
    }

    int x;
    int iter=0;
    arrX[iter]=atoi(xTab);

    do
    {
        iter++;
        int size = strlen(xTab);
        for(i=size;i<n;i++)
            xTab[i]='0';

        setA(xTab,n);
        setB(xTab,n);
        clean(n,xTab);

        x = a-b;
        arrX[iter]=x;

        sprintf(xTab,"%d", x);
        printf("Iteracja: %d A: %d B: %d X: %d\n",iter,a,b,x);
    }while(search_arrX(x)==false);

    printf("Wynik: Iteracje: %d X: %d\n",iter,x);
    return 0;
}

void clean(int size,char tab[size])
{
    for(i=0;i<size;i++)
            tab[i]='0';
}

void setA(char tab[n],int size)
{
    for(i=0;i<size;i++)
        for(j=1;j<size-i;j++)
            if(tab[j-1]<tab[j])
            {
                char swap = tab[j-1];
                tab[j-1] = tab[j];
                tab[j] = swap;
            }
    a = atoi(tab);
}

void setB(char tab[n],int size)
{
    for(i=0;i<size;i++)
        for(j=1;j<size-i;j++)
            if(tab[j-1]>tab[j])
            {
                char swap = tab[j-1];
                tab[j-1] = tab[j];
                tab[j] = swap;
            }
    b = atoi(tab);
}

bool search_arrX(int x)
{
    j=0;
    for(i=0;i<32;i++)
        if(x==arrX[i])
            j++;

    if(j>1)
        return true;
    else
        return false;
}
