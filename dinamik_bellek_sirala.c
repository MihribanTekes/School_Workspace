#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dizi_olustur(int*,int);
void dizi_sirala(int*,int);
void dizi_buyuk(int*,int);

int main()
{
    int *p, boyut;
    srand(time(0));
    printf("sayi griniz:");
    scanf("%d",&boyut);
    p = (int*)malloc(boyut*sizeof(int));
    dizi_olustur(p,boyut);
    dizi_sirala(p,boyut);
    dizi_buyuk(p,boyut);
    free(p);
    return 0;
}

void dizi_olustur(int *e,int n)
{
    int i;
    printf("Dizi Elemanlari\n");
    for(i=0; i<n; i++)
    {
        *(e+i) = rand()%100;
        printf("%d\n",*(e+i));
    }
}

void dizi_sirala(int *e,int n)
{
    int i,j;
    int temp;
    for(i=0; i<(n-1); i++)
    {
        for(j=0; j<n-i; j++)
        {
            if(*(e+j)>*(e+j+1))
            {
                temp = *(e+j);
                *(e+j) = *(e+j+1);
                *(e+j+1) = temp;
            }
        }
    }

    printf("dizinin yeni hali\n");
    for(i=0; i<n; i++)
    {
        printf("%d\n",*(e+i));
    }
}

void dizi_buyuk(int *e, int n)
{
    int i,enb;
    enb = *e;
    for(i=1; i<n; i++)
    {
        if(enb<*(e+i))
            enb = *(e+i);
    }
    printf("en buyuk %d\n",enb);
}







