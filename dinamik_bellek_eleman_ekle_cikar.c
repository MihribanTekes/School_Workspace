#include <stdio.h>
#include <stdlib.h>

int main()
{
    // int p 1 elemanlýk yr ayrmenu oluþtur 1 ekleme 2 çkarma 3 çýkýþ

    int *p;
    p = (int*)malloc(sizeof(int)*1);
    int sayac=0;
    int secim;
    int hesap;

    while(1==1)
    {
        printf("1) Ekleme 2)Cikarma 3)Cikis\n");
        scanf("%d",&secim);

        if(secim==1)
        {
            hesap = _msize(p)/sizeof(int);
            if(_msize(p)<hesap)
            {
                 p = (int*)realloc(p,sayac*2*sizeof(int));
            }

            printf("sayiyi giriniz:\n");
            scanf("%d",(p+sayac));
            sayac++;
            int i;
           // printf("%d dizi boyut\n",_msize(p));
            for(i=0; i<sayac; i++)
            {
                printf("dizi elemeanlari %d \t",*(p+i));


            }
        }

        else if(secim==2)
        {
            *(p+sayac) = '\0';

            hesap = _msize(p)/sizeof(int);
            if(hesap <= (_msize(p)/2))
            {
                p = (int*)realloc(p,(_msize(p)/2));
            }
            sayac--;
            int i;
           // printf("%d dizi boyut\n",_msize(p));
            for(i=0; i<sayac; i++)
            {
                printf("dizi elemeanlari %d \t",*(p+i));


            }
        }

        else if(secim==3)
        {
            int i;
            printf("%d dizi boyut\n",_msize(p));
            for(i=0; i<sayac; i++)
            {
                printf("dizi elemeanlari %d \t",*(p+i));


            }
            free(p);
            break;
        }

    }
    return 0;
}
