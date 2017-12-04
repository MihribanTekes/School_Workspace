//14010011008
//MIHRIBAN TEKES


#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n,a,i,j,m,x; // n = ders sayisi, a=ogrenci sayisi, x=donem sayisi, i,j,m dongu degiskenleri
    printf("ders sayisini giriniz:\n");
    scanf("%d",&n);
    printf("ogrenci sayisini giriniz:\n");
    scanf("%d",&a);
    printf("Donem sayisini giriniz:\n");
    scanf("%d",&x);


    struct dersler
    {
        char ders_adi[10];
        double ders_notu;
    };

    struct donem
    {
        double donem_ort;
    };

    struct ogrenci
    {
        char ogrenci_adi[10];
        char ogrenci_soyad[10];
        double genel_ortalama;
        struct dersler ders_bilgileri[n];
        struct donem donem_bilgileri[x];
    };


    struct ogrenci ogrenciler[a];
    struct ogrenci ogr;
    double ort = 0.0; // her donemin ort almak icin kullanilan degisken
double genel_ort = 0.0; // tum donemlerin ortalamasi genel ortalama

for(i=0; i<a; i++)// ogrenci sayisi dongusu
{
    printf("%d. ogrencinin adini giriniz:\n",(i+1));
    scanf("%s",&ogrenciler[i].ogrenci_adi);
    printf("%d. ogrencinin soyadini giriniz:\n",(i+1));
    scanf("%d",&ogrenciler[i].ogrenci_soyad);

    for(m=0; m<x; m++) //donem sayisi dongusu
   {

    for(j=0; j<n; j++) // ders sayisi dongusu
    {
        printf("%d. dersin adini giriniz:  dersinin notunu giriniz: \n",(j+1));
        scanf("%s %lf",&ogr.ders_bilgileri[j].ders_adi,&ogr.ders_bilgileri[j].ders_notu); // ders adini ve notunu alýyor
        ort += (ogr.ders_bilgileri[j].ders_notu); // ders notunu ortalamaya ekliyor

    }


    ort = ort/n; //ders notlarýnýn toplaminin ders sayisina bolumuyle elde edilen ortalama
    ogr.donem_bilgileri[m].donem_ort = ort; // ort degiskenini struct yapisinda tutuyor
    genel_ort += ogr.donem_bilgileri[m].donem_ort; //bulunan donem ortalamasini genel ortalamaya atiyor
    ort = 0.0; // donem ortalamasinin sifirliyor

   }

    ogrenciler[i].genel_ortalama = genel_ort/8; // ogrencinin genel orrtalamasini atiyor
    genel_ort = 0.0; // genel ortalama degiskeninin sifirliyor

}


for(i=0; i<a; i++)
{
    printf("Ogrenci adi %s\n Soyadi %s\n",ogrenciler[i].ogrenci_adi, ogrenciler[i].ogrenci_soyad);

    for(m=0; m<x; m++)
    {
        printf("%d. icinde %lf ortalama yapmistir\n",(m+1), ogr.donem_bilgileri[m].donem_ort);

    for(j=0; j<n; j++)
    {
        printf("%s dersinden %d notu almistir\n",ogr.ders_bilgileri[j].ders_adi, ogr.ders_bilgileri[j].ders_notu);
    }

    }
    printf("ogrencinin genel ortalamasi %lf\n",ogrenciler[i].genel_ortalama);


}


    return 0;
}
