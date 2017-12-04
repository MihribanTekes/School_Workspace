#include <stdio.h>
#include <string.h>
int kontrol(char gelen[]);

int main()
{
    char dizi[50];
    int sonuc;
    printf("karakterleri giriniz:");
    gets(dizi);
    sonuc = kontrol(dizi);
    if(sonuc==1)
    printf("karakterler kurala uygundur");
    else
        printf("karakterler kurala uygun degildir:");
    return 0;
}

int kontrol(char gelen[])
{
    int i,birmi=1,toplam1=0;

    if(gelen[0]=='0')
        return 0;

    for(i=0; i<strlen(gelen); i++)
    {
        if((birmi==1)  && (gelen[i]=='1'))
        {
            toplam1 += 1;
            continue ;
        }
        if((birmi==1) && (gelen[i]=='0'))
        {
            birmi = 0;
            if(toplam1%2==1)
                return 0;

            toplam1 /=2;
            toplam1 -=1;

            //if(toplam1<0)
                //return 0;
            continue ;
        }
        if((birmi==0) && (gelen[i]=='0'))
        {
            toplam1 -= 1;
            if(toplam1<0)
                return 0;
            continue ;
        }

        if((birmi==0) && (gelen[i]=='1'))
        {
            //if(toplam1 != 0)
              //  return 0;

            birmi = 1;
            toplam1 += 1;
            continue ;
        }
    }

    if(toplam1 == 0)
        return 1;
    else
        return 0;
}
