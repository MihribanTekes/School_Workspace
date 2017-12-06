#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct sayilar
{
    int data;
    struct sayilar *next;

}Sayilar;

typedef struct islemler
{
    char op;
    struct islemler *next;
}Islemler;

    Sayilar *sayi = NULL;
    Islemler *islem = NULL;

void pushS(int x)
{
    if(sayi == NULL)
    {
        sayi = (Sayilar*)malloc(sizeof(Sayilar));
        sayi->next = NULL;
        sayi->data = x;

    }

    else{

        Sayilar *yeni = (Sayilar*)malloc(sizeof(Sayilar));
        yeni->next = sayi;
        yeni->data = x;
        sayi = yeni;

    }
}


void pushI(char x)
{
    if(islem == NULL)
    {
        islem = (Islemler*)malloc(sizeof(Islemler));
        islem->next = NULL;
        islem->op = x;

    }

    else{

        Islemler *yeni = (Islemler*)malloc(sizeof(Islemler));
        yeni->next = islem;
        yeni->op = x;
        islem = yeni;

    }
}

int popS()
{

    Sayilar *temp = sayi;
    sayi = sayi->next;
    int sayi2 = temp->data;
    free(temp);
    return sayi2;

}

char popI()
{
    Islemler *temp = islem;
    islem = islem->next;
    char op2 = temp->op;
    free(temp);
    return op2;

}

int islemOnceligi(char op1, char op2)
{
    if( op2 == '(' || op2 == ')')
        return 0;
    if((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-') )
        return 0;
    else
        return 1;
}

int islemYap(char op, int b, int a)
{
    switch(op)
    {
    case '+':
        return a+b;
        break;
    case '-':
        return a-b;
        break;
    case '*':
        return a*b;
        break;
    case '/':
        return a/b;
        break;

    }

    return 0;
}

void main()
{

    char karakter[100];
    printf("Ifadeyi giriniz:\n");
    gets(karakter);
    int i,a=0;
    char tut[10];

    for(i=0; i<strlen(karakter); i++)
    {
        if(karakter[i]== ' ')
            continue;

        if(karakter[i]>= '0' && karakter[i]<='9')
        {
            while(i<strlen(karakter) && karakter[i]>= '0' && karakter[i]<='9')
                {
                    tut[a++] = karakter[i++];
                }

            tut[a] = '/0';
            a=0;
            int result = atoi(tut);
            pushS(result);

        }

        else if(karakter[i] == '+' || karakter[i] == '-' || karakter[i] == '*' || karakter[i] == '/')
        {
            if(islem != NULL && sayi != NULL)
            {
                while((islem->op != '\0') && islemOnceligi(karakter[i],islem->op) && (sayi->data != NULL))
                    pushS(islemYap(popI(),popS(),popS()));
            }


            pushI(karakter[i]);
        }
    }

    if(islem != NULL && sayi != NULL)
    {
        while(!(islem->op == '\0')&&(sayi->data != NULL))
            pushS(islemYap(popI(),popS(),popS()));
    }


    printf("\nSonuc--->> %d", popS());
}














