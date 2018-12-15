#include <stdio.h>
#include <string.h>

struct struktura{
    int tab[1000];
    int cpyMem[1000];
    int tabElements;
    int cpyElements;
};

void newItem(struct struktura * projekt);
void add(struct struktura * projekt,int element);
void del(struct struktura * projekt,int index);
void rew(struct struktura * projekt,int index1,int index2);
void sum(struct struktura * projekt,int index1,int index2);
void cpy(struct struktura * projekt,int index1,int index2,int position);
void move(struct struktura * projekt,int index,int position);
void pst(struct struktura * projekt,int index,int position);
void sho(struct struktura * projekt,int i);
void shocpy(struct struktura * projekt,int i);

int main()
{
    struct struktura projekt;
    newItem(&projekt);

    int i,j;
    char choice[] = "";
    while(strcmp(choice, "exit") != 0)
    {
        printf("Command: ");
        scanf("%s",choice);

        if(strcmp(choice, "add") == 0)
        {
            scanf("%d",&i);
            if(projekt.tabElements >= 1000)
                printf("Error: Table is full\n");
            else
                add(&projekt,i);
        }
        else if(strcmp(choice, "del") == 0)
        {
            scanf("%d",&i);
            if(i > projekt.tabElements)
                printf("Error: There is no element under this index\n");
            else
                del(&projekt,i-1);
        }
        else if(strcmp(choice, "rew") == 0)
        {
            scanf("%d",&i);
            scanf("%d",&j);
            if(j > projekt.tabElements)
                j = projekt.tabElements;
            if(i > projekt.tabElements)
                printf("Error: wrong range\n");
            else
            {
                rew(&projekt,i-1,j-1);
            }
        }
        else if(strcmp(choice, "sum") == 0)
        {
            scanf("%d",&i);
            scanf("%d",&j);
            if(j > projekt.tabElements)
                printf("Error: wrong range\n");
            else if(i > projekt.tabElements)
                printf("Error: wrong range\n");
            else
            {
                sum(&projekt,i-1,j-1);
            }
        }
        else if(strcmp(choice, "cpy") == 0)
        {
            scanf("%d",&i);
            scanf("%d",&j);
            if(j > projekt.tabElements)
                j = projekt.tabElements;
            else if(i > projekt.tabElements)
                projekt.cpyElements = 0;
            else
            {
                cpy(&projekt,i-1,j-1,0);
            }
        }
        else if(strcmp(choice, "pst") == 0)
        {
            scanf("%d",&i);
            if(i >= projekt.tabElements)
                i = projekt.tabElements;
            pst(&projekt,i-1,projekt.cpyElements-1);
        }
        else if(strcmp(choice, "sho") == 0)
            sho(&projekt,0);
        else if(strcmp(choice, "shocpy") == 0)
            shocpy(&projekt,0);
    }

    return 0;
}

void newItem(struct struktura * projekt)
{
    projekt->tabElements = 0;
    projekt->cpyElements = 0;
}

void add(struct struktura * projekt,int element)
{
    projekt->tab[projekt->tabElements] = element;
    projekt->tabElements++;
}

void del(struct struktura * projekt,int index)
{
    if(index < projekt->tabElements)
    {
        projekt->tab[index] = projekt->tab[index+1];
        index++;
        del(projekt,index);
    }
    else
        projekt->tabElements--;
}

void rew(struct struktura * projekt,int index1,int index2)
{
    if(index2 - index1 >= 1)
    {
        int swaper = projekt->tab[index1];
        projekt->tab[index1] = projekt->tab[index2];
        projekt->tab[index2] = swaper;
        index1++;
        index2--;
        rew(projekt,index1,index2);
    }
}

void sum(struct struktura * projekt,int index1,int index2)
{
    projekt->tab[index1] += projekt->tab[index2];
    del(projekt,index2);
}

void cpy(struct struktura * projekt,int index1,int index2,int position)
{
    if(position == 0)
        projekt->cpyElements = 0;
    if(index2 - index1 >= 0)
    {
        projekt->cpyMem[position++] = projekt->tab[index1++];
        projekt->cpyElements++;
        cpy(projekt,index1,index2,position);
    }
}

void move(struct struktura * projekt,int index,int position)
{
    if(position >= index)
    {
        projekt->tab[position+1] = projekt->tab[position];
        position--;
        move(projekt,index,position);
    }
    else
        projekt->tabElements++;

}

void pst(struct struktura * projekt,int index,int position)
{
    if(index > projekt->tabElements)
        index = projekt->tabElements;
    if(position>=0)
    {
        move(projekt,index,projekt->tabElements-1);
        projekt->tab[index] = projekt->cpyMem[position];
        position--;
        pst(projekt,index,position);
    }
}

void sho(struct struktura * projekt,int i)
{
    if(i<projekt->tabElements)
    {
        printf("%d ",projekt->tab[i]);
        i++;
        sho(projekt,i);
    }
    else
        printf("\n");
}

void shocpy(struct struktura * projekt,int i)
{
    if(i<projekt->cpyElements)
    {
        printf("%d ",projekt->cpyMem[i]);
        i++;
        shocpy(projekt,i);
    }
    else
        printf("\n");
}
