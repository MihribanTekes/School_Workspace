//14010011008
//MIHRIBAN TEKES

#include <stdio.h>
#include <stdlib.h>

struct urunler{

    char urunadi[20];
    int fiyat;
};
struct satislar{

    int satisid;
    int urunsayisi;
    struct urunler * urun;
};
struct calisan{

    char ad[20];
    char soyad[20];
    int id;
    int satismiktari;
    struct satislar *satis;
};
int main()
{
    struct calisan *calisanlar,*cptr;
    struct satislar *satis,*sptr;
     struct urunler *urun,*uptr;
    struct calisan *aseleman;
    aseleman=(struct calisan*)malloc(sizeof(struct calisan)*1);
    int calisansayisi,satismiktari,urunsayisi;
    int i=0,j=0,k=0,id;
    int maxsatis=0,top=0;
    printf("Calisan Sayisini Giriniz:\n");
    scanf("%d",&calisansayisi);
     calisanlar=(struct calisan*)malloc(sizeof(struct calisan)*calisansayisi); //tum calisanlar icin bellek ayrildi
     cptr=calisanlar; // cptr pointeri calisanlara atandi,bellegi bozmadan hareket edebilmek icin
    for(i=0;i<calisansayisi;i++)
    {
        printf("%d.Calisanin Adini Giriniz:\n",i+1);
        scanf("%s",cptr->ad);
         printf("%d.Calisanin Soyadini Giriniz:\n",i+1);
        scanf("%s",cptr->soyad);
         printf("%d.Calisanin ID sini giriniz:\n",i+1);
        scanf("%d",&cptr->id);
        printf("%d.Calisanin Yaptigi Satis Miktarini Giriniz:\n",i+1);
        scanf("%d",&cptr->satismiktari);
        cptr->satis=(struct satislar*)malloc(sizeof(struct satislar)*cptr->satismiktari); //satis icin bellek ayarlandý
        sptr=cptr->satis; // sptr pointeri cptr ile satis a atandi
        for(j=0;j<cptr->satismiktari;j++)
        {
            printf("Yaptigi %d. Satisin ID sini Giriniz:\n",j+1);
            scanf("%d",&sptr->satisid);
            printf("Yaptigi %d. Satisin Urun Sayisini Giriniz:\n",j+1);
            scanf("%d",&sptr->urunsayisi);
            sptr->urun=(struct urunler*)malloc(sizeof(struct urunler)*sptr->urunsayisi*cptr->satismiktari); //calisanlarin satislari icin bellek hesabi
            uptr=sptr->urun;

            for(k=0;k<sptr->urunsayisi;k++)
            {

                printf("%d.Urunun Adini Giriniz:",k+1);
                scanf("%s",uptr->urunadi);
                printf("%d.Urunun Fiyatini Giriniz:",k+1);
                scanf("%d",&uptr->fiyat);
                uptr++;//pointer aritmtgi ile tek tek bilgileri saklama
            }
            sptr++;//pointer aritmtgi ile tek tek bilgileri saklama

        }
         cptr++;//pointer aritmtgi ile tek tek bilgileri saklama

    }
    for(i=0;i<calisansayisi;i++) //ayin elemanini bulma
    {
         calisanlar=calisanlar+i;
         for(j=0;j<calisanlar->satismiktari;j++)
         {
            calisanlar->satis=calisanlar->satis+j;
              top=0;
            for(k=0;k<calisanlar->satis->urunsayisi;k++)
            {


                calisanlar->satis->urun=calisanlar->satis->urun+k;
                top+=calisanlar->satis->urun->fiyat;

                if(top>maxsatis) //elemanlarin satislarini karsilastirma ve swap islemleri
                {

                    maxsatis=top;
                    strcpy(aseleman->ad,calisanlar->ad);
                    strcpy(aseleman->soyad,calisanlar->soyad);
                    aseleman->id=calisanlar->id;
                    id=calisanlar->satis->satisid;


                }

            }

         }

    }
    printf("-------------------------------------\n");
    printf("\t\t***Yapilan Maksimum Satis:%d***\n",maxsatis);
    printf("--------------------------------------\n");
    printf("ID:%d\nElemanin Adi:%s\t Soyadi:%s\n",aseleman->id,aseleman->ad,aseleman->soyad);
    printf("Yapilan Satisin ID si:%d\n",id);


    return 0;
}
