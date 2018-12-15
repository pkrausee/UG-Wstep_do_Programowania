//Pawel Krause grupa 3
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N 20

void show(char tab[N][40]);

int count(char tab[N][40]); // podpunkt a)
bool check(char tab[N][40],char word[40]); // podpunkt b)
void addWord(char tab[N][40],char word[40]); // podpunkt c)
void removeWord(char tab[N][40],char word[40]); // podpunkt d)
int sum(char tab[N][40]); // podpunkt e)
void aLetter(char tab[N][40]); // podpunkt f)

void commonPart(char tab1[N][40],char tab2[N][40]);

int main()
{
    char tab1[N][40] = {"1234","12345","abcd","abcdef"};
    char tab2[N][40] = {"123","1234","abc","abcd","abcde"};
    char word[40] = "123";

    printf("tab1: ");
    show(tab1);
    printf("tab2: ");
    show(tab2);
    printf("\n");

    commonPart(tab1,tab2);


    return 0;
}

void show(char tab[N][40])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<40;j++)
        {
            if(tab[i][j] != false)
                printf("%c",tab[i][j]);
        }
        if(tab[i][0] != false)
            printf(" ");
    }
    printf("\n");
}

int count(char tab[N][40])
{
    int i,j;
    int size=0;
    for(i=0;i<N;i++)
    {
        if(tab[i][0]!=false)
        {
            size++;
        }
    }
    return size;
}

bool check(char tab[N][40],char word[40])
{
    int i;
    for(i = 0; i < N; i++)
    {
        if(strcmp(word, tab[i]) == 0)
        {
            return true;
        }
    }
    return false;
}

void addWord(char tab[N][40],char word[40])
{
    int k=strlen(word);
    int guard = 1;
    int i,j;
    for(i=0;i<N && guard == 1 && check(tab,word) == false;i++)
    {
        if(tab[i][0]==false)
        {
            guard = 0;
            for(j=0;j<k;j++)
            {
                tab[i][j] = word[j];
            }
        }
    }
    if(guard == 0)
        printf("Dodano napis \"%s\" przy indeksie: %d\n",word,i-1);
    else
        printf("Nie mozna dodac danego elementu\n");
}

void removeWord(char tab[N][40],char word[40])
{
    int k=strlen(word);
    int guard = 1;
    int i,j;
    for(i=0;i<N && guard == 1 && check(tab,word) == true;i++)
    {
        if(strcmp(word, tab[i]) == 0)
        {
            guard = 0;
            for(j=0;j<k;j++)
            {
                tab[i][j] = false;
            }
        }
    }
    if(guard == 0)
        printf("Usunieto napis \"%s\" przy indeksie: %d\n",word,i-1);
    else
        printf("Nie mozna usunac danego elementu\n");
}

int sum(char tab[N][40])
{
    int i,j;
    int sum=0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<40 && tab[i][j] != false;j++)
        {
            sum++;
        }
    }
    return sum;
}

void aLetter(char tab[N][40])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        int guard = 1;
        if(tab[i][0] != false)
        {
            for(j=1;j<40 && guard == 1;j++)
            {
                if(tab[i][j] == false)
                {
                    tab[i][j] = 'a';
                    guard = 0;
                }
            }
        }
    }
}


void commonPart(char tab1[N][40],char tab2[N][40])
{
    int i,j;
    int sum=0;
    printf("Iloraz tab1 i tab2: ");
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(strcmp(tab1[i], tab2[j]) == 0 && tab1[i][0] != false)
            {
                sum++;
                printf("\"%s\" ",tab1[i]);
            }
        }
    }
    printf("\n");
    if(sum!=0)
        printf("Ilosc wspolnych napisow: %d\n",sum);
    else
        printf("Brak czesci wspolnej\n");
}


