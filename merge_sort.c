#include <stdio.h>
#include <stdlib.h>

void mergeSirala(int dizi[],int sol,int sag,int orta)
{
    int i,j,tutsol,tutorta,dizi2[30];
    tutsol = sol;
    tutorta = orta+1;

    for(i=sol; tutsol<=orta && tutorta<=sag; i++)
    {
        if(dizi[tutsol]<=dizi[tutorta])
        {
            dizi2[i]=dizi[tutsol];
            printf("%d   ",dizi2[i]);
            tutsol++;
        }

        else
        {
            dizi2[i] = dizi[tutorta];
            printf("%d   ",dizi2[i]);
            tutorta++;

        }

    }

    if(tutsol>orta)
    {
        for(j=tutorta; j<=sag; j++)
        {
            dizi2[i] = dizi[j];
            printf("%d   ",dizi2[i]);
            i++;
        }
    }

    else
    {
        for(j=tutsol; j<=orta; j++)
        {
            dizi2[i] = dizi[j];
            printf("%d   ",dizi2[i]);
            i++;
        }
    }

    for(j=sol; j<=sag; j++)
    {
        dizi[j]= dizi2[j];
    }
}

void parcala(int dizi[],int min, int max)
{
    int orta;
    if(min<max)
    {
        orta = (min+max)/2;
        printf("\n*******");
        parcala(dizi,min,orta);
        printf("\n-------");
        parcala(dizi,orta+1,max);
        mergeSirala(dizi,min,max,orta);
    }
}


int main()
{
    int dizi[30];
    int i,boyut;

    printf("Dizinin boyutunu giriniz:");
    scanf("%d",&boyut);

    for(i=0; i<boyut; i++)
    {
        printf("%d. elemani giriniz: ",i+1);
        scanf("%d",&dizi[i]);
    }

    parcala(dizi,0,boyut-1);
    printf("\n");
    for(i=0; i<boyut; i++)
    {
        printf("%d__",dizi[i]);
    }

}
