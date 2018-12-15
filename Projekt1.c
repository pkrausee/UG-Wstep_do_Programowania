//Pawel Krause grupa 3
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char Dzien[], Miesiac[], Rok[];
char *JednosciTab[] = {""," pierwszego"," drugiego"," trzeciego"," czwartego"," piatego"," szostego"," siodmego"," osmego"," dziewiatego"};
char *DziesiatkiTab[] = {""," dziesiatego"," dwudziestego"," trzydziestego"," czterdziestego"," piecdziesiatego"," szescdziesiatego"," siedemdziesiatego"," osiemdziesiatego"," dziewiecdziesiatego"};
char *Dziesiatki2Tab[] = {" dziesiatego"," jedenastego"," dwunastego"," trzynastego"," czternastego"," pietnastego"," szesnastego"," siedemnastego"," osiemnastego"," dziewietnastego"};
char *SetkiTab[] = {""," sto"," dwiescie"," trzysta"," czterysta"," piecset"," szescset"," siedemset"," osiemset"," dziewiecset"};
char *Setki2Tab[] = {""," setnego"," dwusetnego"," trzysetnego"," czterysetnego"," pieciosetnego"," szesciosetnego"," siedemiosetnego"," osiemiosetnego"," dziewieciosetnego"};
char *TysiaceTab[] = {""," tysiac"," dwa tysiace"," trzy tysiace"," cztery tysiace"," piec tysiecy"," szesc tysiecy"," siedem tysiecy"," osiem tysiecy"," dziewiec tysiecy"};
char *Tysiace2Tab[] = {""," tysiecznego"," dwutysiecznego"," trzytysiecznego"," czterotysiecznego"," pieciotysiecznego"," szesiotysiecznego"," siedemiotysiecznego"," osiemiotysiecznego"," dziewieciotysiecznego"};
char *MiesiacTab[] = {""," stycznia"," lutego"," marca"," kwietnia"," maja"," czerwca"," lipca"," sierpnia"," wrzesnia"," pazdziernika"," listopada"," grudnia"};
char *DzienSlowo,*DzienSlowo2,*TysiaceSlowo,*SetkiSlowo,*DziesiatkiSlowo,*JednosciSlowo;
int RokL,MiesiacL,DzZak;

void KtoryDzien(char Zm[]);
void KtoryRok(char Zm[]);
bool Walidacja(char Zm[],int ZakresMin,int ZakresMax);

int main()
{
    printf("Pawel Krause grupa 3\nProjekt 1\n");
    printf("Prosze podawac dane w postaci liczb naturalnych\n\n");

    printf("Podaj rok urodzenia: ");
    gets(Rok);
    while(Walidacja(Rok,1,9999)==false)
    {
        printf("Podano zle dane\n");
        printf("Rok urodzenia: ");
        gets(Rok);
    }
    RokL = atoi(Rok);
    KtoryRok(Rok);

    printf("Miesiac urodzenia: ");
    gets(Miesiac);
    while(Walidacja(Miesiac,1,12)==false)
    {
        printf("Podano zle dane\n");
        printf("Miesiac urodzenia: ");
        gets(Miesiac);
    }
    MiesiacL = atoi(Miesiac);

    switch(MiesiacL)
    {
        case 1:
            DzZak = 31;
            break;
        case 2:
            if((RokL%4==0 && RokL%100!=0) || RokL%400==0)
                DzZak = 29;
            else
                DzZak = 28;
            break;
        case 3:
            DzZak = 31;
            break;
        case 4:
            DzZak = 30;
            break;
        case 5:
            DzZak = 31;
            break;
        case 6:
            DzZak = 30;
            break;
        case 7:
            DzZak = 31;
            break;
        case 8:
            DzZak = 31;
            break;
        case 9:
            DzZak = 30;
            break;
        case 10:
            DzZak = 31;
            break;
        case 11:
            DzZak = 30;
            break;
        case 12:
            DzZak = 31;
            break;
        default:
            break;
    }
    printf("Dzien urodzenia: ");
    gets(Dzien);
    while(Walidacja(Dzien,1,DzZak)==false)
    {
        printf("Podano zle dane\n");
        printf("Dzien urodzenia: ");
        gets(Dzien);
    }
    KtoryDzien(Dzien);

    printf("Urodziles sie%s%s%s%s%s%s%s roku\n",DzienSlowo,DzienSlowo2,MiesiacTab[MiesiacL],TysiaceSlowo,SetkiSlowo,DziesiatkiSlowo,JednosciSlowo);
    return 0;
}

bool Walidacja(char Zm[],int ZakresMin,int ZakresMax)
{
    int Cyfry = 0;
    int k = strlen(Zm);
    if(k!=0)
    {
        int i = 0;
        while(i<k)
        {
            if('0' <= Zm[i] && Zm[i] <= '9')
                Cyfry++;

            i++;
        }
        if(Cyfry == k)
        {
            int Zm1 = atoi(Zm);
            if(Zm1 >= ZakresMin && Zm1 <=ZakresMax)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}
void KtoryDzien(char Zm[])
{
    int CalyDzien = atoi(Zm);
    int Dziesiatki = CalyDzien/10;
    int Jednosci = CalyDzien%10;

    if(Dziesiatki == 0)
    {
        DzienSlowo = "";
        DzienSlowo2 = JednosciTab[Jednosci];
    }
    else if(Dziesiatki == 1)
    {
        DzienSlowo = "";
        DzienSlowo2 = Dziesiatki2Tab[Jednosci];
    }
    else if(Dziesiatki > 1)
    {
        DzienSlowo = DziesiatkiTab[Dziesiatki];
        DzienSlowo2 = JednosciTab[Jednosci];
    }
}
void KtoryRok(char Zm[])
{
    int CalyRok = atoi(Zm);
    int Tysiace = CalyRok/1000;
    int Setki = (CalyRok-Tysiace*1000)/100;
    int Dziesiatki = ((CalyRok-Tysiace*1000)-Setki*100)/10;
    int Jednosci = ((CalyRok-Tysiace*1000)-Setki*100)-Dziesiatki*10;

    if(Tysiace !=0 && Setki == 0 && Dziesiatki == 0 && Jednosci == 0)
    {
        TysiaceSlowo = Tysiace2Tab[Tysiace];
        SetkiSlowo = "";
        DziesiatkiSlowo = "";
        JednosciSlowo = "";
    }

    else if(Tysiace ==0 && Setki != 0 && Dziesiatki == 0 && Jednosci == 0)
    {
        TysiaceSlowo = "";
        SetkiSlowo = Setki2Tab[Setki];
        DziesiatkiSlowo = "";
        JednosciSlowo = "";
    }

    else if(Tysiace !=0 && Setki != 0 && Dziesiatki == 0 && Jednosci == 0)
    {
        TysiaceSlowo = TysiaceTab[Tysiace];
        SetkiSlowo = Setki2Tab[Setki];
        DziesiatkiSlowo = "";
        JednosciSlowo = "";
    }

    else
    {
        TysiaceSlowo = TysiaceTab[Tysiace];
        SetkiSlowo = SetkiTab[Setki];
        if(Dziesiatki>1)
        {
            DziesiatkiSlowo = DziesiatkiTab[Dziesiatki];
            JednosciSlowo = JednosciTab[Jednosci];
        }
        else if(Dziesiatki==1)
        {
            DziesiatkiSlowo = Dziesiatki2Tab[Jednosci];
            JednosciSlowo = "";
        }
        else if(Dziesiatki==0)
        {
            DziesiatkiSlowo = "";
            JednosciSlowo = JednosciTab[Jednosci];
        }
    }
}
