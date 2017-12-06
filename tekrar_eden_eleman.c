//14010011008
//Mihriban TEKES
#include <stdio.h>
#include <stdlib.h>


int main()
{
   int *sayilar;
   int i,n,j,sayac=0,maks=0,tut;
   printf("dizinin boyutunu giriniz:");
   scanf("%d",&n);
   sayilar =(int*)malloc(sizeof(int)*n);
   for(i=0;i<n;i++)
   {
       printf("%d. elemani giriniz:",i+1);
       scanf("%d",&*(sayilar+i));
   }

   for(i=0; i<n;i++)
   {
       for(j=0;j<n;j++)
       {
            if(*(sayilar+i)== *(sayilar+j))
           {
              sayac++;
           }

       }
       if(sayac>maks)
       {
           maks=sayac;
           tut=i; //maks tekrar eden sayinin kacinci indiste oldugunu tutan degisken
       }


       sayac=0;


       }

           printf("%d sayisi %d kere tekrar etmistir",*(sayilar+tut),maks);


       return 0;

}
