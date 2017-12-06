#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sayi
{
    char *data;
    struct sayi *next;

}Sayi;

typedef struct op
{
    char oprtr;
    struct op *next;
}Op;

Sayi *rootS=NULL;
Op *rootO=NULL;

void pushSayi(char data[10])
{
    if(rootS==NULL)
    {
        rootS=(struct Sayi*)malloc(sizeof(Sayi));
        rootS->next=NULL;
        rootS->data = data;

            }
    else
    {
        Sayi *yeni = (Sayi*)malloc(sizeof(Sayi));
        yeni->next = rootS;
        yeni->data = data;
        rootS= yeni;
    }
}

void pushOp(char operatr)
{
    if(rootO==NULL)
    {
        rootO=(struct Op*)malloc(sizeof(Op));
        rootO->next=NULL;
        rootO->oprtr = operatr;

            }
    else
    {
        Op *yeni = (Op*)malloc(sizeof(Op));
        yeni->next = rootO;
        yeni->oprtr = operatr;
        rootO= yeni;
    }
}

float popSayi()
{
    Sayi *temp =rootS;
    rootS = rootS->next;
    char *karakter = temp->data;
    char kelime[10]; int i=0;
    char a;
    while(*karakter != NULL)
    {
        a = *karakter;
        kelime[i] = a;
        karakter++; i++;
    }
    float donusum = atof(kelime);
    printf("%f",donusum);
    free(temp);
    return donusum;

}

char popOp()
{
    Op *temp =rootO;
    rootO = rootO->next;
    char opertr = temp->oprtr;
    free(temp);
    return opertr;
}


int main()
{
    char sayi[] = "12345";
    char a = '+';
    pushOp(a);
    pushSayi(sayi);
    printf("%s %c\n",rootS->data, rootO->oprtr);
    char x = popOp();
    printf("%c",x);
    int bool=1;int acik=0; int kapali=0;
    char islem[50];
    float sonuclar[50];
    int sayac=0;
    printf("\nIslemi Giriniz:\n");
    scanf("%s",&islem);
    int i=0;
    float sonuc=0.0;
    while(1)
    {
    if(islem[i]=='(' || ' ')
       {
           i++;
           acik++;
       }
    else if(islem[i]== '+')
    {
        pushOp('+');
        i++;
    }
    else if(islem[i]== '-')
    {
        pushOp('-');
        i++;
    }
    else if(islem[i]== '/')
    {
        pushOp('/');
        i++;
    }
    else if(islem[i]== '*')
    {
        pushOp('*');
        i++;
    }

    else if('0' <= islem[i] && islem[i] <= '9')
    {
        int j = i;
        int a=0;
        char tut[10];
        while(1)
        {
            if( (islem[j] =! '(') || (islem[j] =! ')') || (islem[j] =! ' ') || (islem[j] =! '+') || (islem[j] =! '-') || (islem[j] =! '/') || (islem[j] =! '*'))
            {
                tut[a] = islem[j];
                a++;
                j++;
            }
            else
                break;
        }
        tut[++a] = '\0';
        pushSayi(tut);
        i +=a;
    }

    else if(islem[i]== ')')
    {
        float sayi1,sayi2;
        char op;
        kapali++;
        if(acik-1 == kapali)
        {
           sayi1 = popSayi();
           sayi2 = popSayi();
           char op2 = popOp();
           op = popOp();
           pushOp(op2);

        }

        if(acik == kapali)
        {
            op = popOp();
            sayi1 = sonuclar[sayac-2];
            sayi2 = sonuclar[sayac-1];
            if(op == '+')
        {
            sonuc += sayi1+sayi2;
            sonuclar[sayac]=sonuc;
            sayac++;
            sonuc =0.0;

        }
        if(op == '-')
        {
            sonuc += sayi1-sayi2;
            sonuclar[sayac]=sonuc;
            sayac++;
            sonuc =0.0;
        }
        if(op == '*')
        {
            sonuc += sayi1*sayi2;
            sonuclar[sayac]=sonuc;
            sayac++;
            sonuc =0.0;
        }
        if(op == '/')
        {
            sonuc += sayi1/sayi2;
            sonuclar[sayac]=sonuc;
            sayac++;
            sonuc =0.0;
        }
        break;
        }
        if(bool==1)
        {
          sayi1 = popSayi();
          sayi2 = popSayi();
          op = popOp();

        if(op == '+')
        {
            sonuc += sayi1+sayi2;
            sonuclar[sayac]=sonuc;
            sayac++;
            sonuc =0.0;
        }
        if(op == '-')
        {
            sonuc += sayi1-sayi2;
            sonuclar[sayac]=sonuc;
            sayac++;
            sonuc =0.0;
        }
        if(op == '*')
        {
            sonuc += sayi1*sayi2;
            sonuclar[sayac]=sonuc;
            sayac++;
            sonuc =0.0;
        }
        if(op == '/')
        {
            sonuc += sayi1/sayi2;
            sonuclar[sayac]=sonuc;
            sayac++;
            sonuc =0.0;
        }


        }
        else
        {

            float sayi1 = popSayi();
            char op = popOp();

            if(op == '+')
            {
               sonuc = sonuclar[sayac-1] + sayi1;
               sonuclar[sayac] = sonuc;
               sayac++;
               sonuc = 0.0;
            }
            if(op == '-')
            {
               sonuc = sonuclar[sayac-1] - sayi1;
               sonuclar[sayac] = sonuc;
               sayac++;
               sonuc = 0.0;
            }
            if(op == '*')
            {
               sonuc = sonuclar[sayac-1] * sayi1;
               sonuclar[sayac] = sonuc;
               sayac++;
               sonuc = 0.0;
            }
            if(op == '/')
            {
               sonuc = sonuclar[sayac-1] / sayi1;
               sonuclar[sayac] = sonuc;
               printf("%f %c %f = %f",sonuclar[sayac-1],op,sayi1,sonuc);
               sayac++;
               sonuc = 0.0;
            }

        }



    }

    bool =0;

    }

    printf("%f",sonuclar[sayac-1]);

    return 0;
}
