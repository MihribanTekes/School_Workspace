#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct yapi
{
    struct yapi *adres0;
    struct yapi *adres1;
}YAPI;


int main()
{
    int i=0,sayi,j;
    char gelen[100];
    printf("Degeri giriniz:\n");
    scanf("%s",&gelen);
    YAPI *q0, *q1, *q2,*sonuc;
    q0 = (YAPI*)malloc(sizeof(YAPI));
    q1 = (YAPI*)malloc(sizeof(YAPI));
    q2 = (YAPI*)malloc(sizeof(YAPI));
    sonuc = (YAPI*)malloc(sizeof(YAPI));
    q0->adres0 = q1;
    q0->adres1 = q1;
    q1->adres0 = q2;
    q1->adres1 = q1;
    q2->adres0 = q2;
    q2->adres1 = q0;
    sonuc = q0;

    for(j=0; j<strlen(gelen); j++)
    {
        if(gelen[j] == '1')
            sonuc = sonuc->adres1;
        else
            sonuc = sonuc->adres0;
    }

    if(sonuc==q0)
        printf("Kabul");
    else
        printf("Red");
}
