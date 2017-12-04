#include <stdio.h>
#include <stdlib.h>

struct Satis
{
    long satis_id;
    double satis_tutar;
};

struct Personel
{
    char adi[20];
    char soyadi[20];
    int personel_id;
    struct Satis*satislar;
};


int main()
{
    struct Personel *personeller,*cptr;
    struct Satis *sptr,*satislar;
    int calisan_sayisi,i,j,id_kontrol,id_sayac=-1,sid_kontrol,sid_sayac=0;
    printf("calisan sayisini giriniz:");
    scanf("%d",&calisan_sayisi);
    int ilk_satis_kontrol[calisan_sayisi];
    for(i=0; i<calisan_sayisi; i++)
        ilk_satis_kontrol[i]=0;
    int satis_sayac[calisan_sayisi];
    personeller = (struct Personel*)malloc(sizeof(struct Personel)*calisan_sayisi);
    cptr = personeller;
    personeller->satislar = (struct Satis*)malloc(sizeof(struct Satis)*1);
    for(i=0; i<calisan_sayisi; i++)
    {
        printf("%d. personele ait ad soyad giriniz personel id giriniz:\n",i+1);
        scanf("%s %s %d",personeller->adi, personeller->soyadi, &personeller->personel_id);
        personeller++;
    }
    for(i=0; i<calisan_sayisi; i++)
          {
              personeller--;
              satis_sayac[i] = 0;
          }

    while(1==1)
    {

        printf("personel id giriniz:\n");
        scanf("%d",&id_kontrol);

        for(i=0; i<calisan_sayisi; i++)
        {
            if(personeller->personel_id == id_kontrol)
            {
                id_sayac = i;
            }

            personeller++;
        }
        for(i=0; i<calisan_sayisi; i++)
            personeller--;

        if(id_sayac==-1)
        {
            printf("boyle bir personel bulunmamamktadir\n");
            exit(1);
        }
        for(i=0; i<id_sayac; i++)
        {
            personeller++;
        }
        for(i=0; i<satis_sayac[id_sayac]; i++)
        {
            (personeller->satislar)++;
        }


        if(ilk_satis_kontrol[id_sayac]==0)
        {
            personeller->satislar = (struct Satis*)realloc(personeller->satislar,2*sizeof(struct Satis));
            printf("***personelin ilk satis bilgileri***\n");
            printf("personelin satis id sini ve satis tutarini gir\n");
            scanf("%d %lf",&personeller->satislar->satis_id, &personeller->satislar->satis_tutar);
            ilk_satis_kontrol[id_sayac] =1;
            satis_sayac[id_sayac] =1;

        }

        printf("girilen personelin kontrol edilecek satis id sinin giriniz:\n");
        scanf("%d",&sid_kontrol);

        for(i=0; i<satis_sayac[id_sayac]; i++)
        {
            if(sid_kontrol==personeller->satislar->satis_id)
            {
                printf("boyle bir satis mevcuttur\n");

            }

            else
            {
                sid_sayac++;
            }


            (personeller->satislar)++;

        }
        for(i=0; i<satis_sayac[id_sayac]; i++)
            (personeller->satislar)--;

        if(sid_sayac==satis_sayac[id_sayac])
        {

            printf("boyle bir satis mevcut degildir\n");
            printf("personelin satis tutarini gir\n");
            scanf("%lf",&personeller->satislar->satis_tutar);
            personeller->satislar = (struct Satis*)realloc(personeller->satislar,1*sizeof(struct Satis));

            satis_sayac[id_sayac] +=1;
        }
        char cikis;
        printf("cikmak icin h veya H tusuna basiniz:");
        scanf("%s",&cikis);
        if(cikis=='h' || cikis== 'H')
        {
            break;
        }
        id_sayac=-1;
        for(i=0; i<id_sayac; i++)
            personeller--;

    }
    char eleman_listele;
    printf("listeyi gormek icin h veya H tusuna basiniz:");
    scanf("%s",&eleman_listele);
    if(eleman_listele == 'h' || eleman_listele == 'H')
    {
        for(i=0; i<calisan_sayisi; i++)
        {
            printf("personel adi %s\n personel soyadi %s\n personel id %d\n",personeller->adi,personeller->soyadi,personeller->personel_id);
            for(j=0; j<satis_sayac[i]; j++)
            {
                printf("satis id %d\n satis tutar %lf\n",personeller->satislar->satis_id, personeller->satislar->satis_tutar);
            }
        }
    }
    
}
