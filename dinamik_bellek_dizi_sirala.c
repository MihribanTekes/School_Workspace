#include <stdio.h>
#include <stdlib.h>

int main()
{
   int *sayilar;
   int i,n,j=1;
   printf("dizinin boyutunu giriniz:");
   scanf("%d",&n);
   sayilar =(int*)malloc(sizeof(int)*n);
   for(i=0;i<n;i++)
   {
       printf("%d. elemani giriniz:",i+1);
       scanf("%d",&*(sayilar+i));
   }
   int toplam;
   int sayi1;
   int sayi2;
   int temp;

   for(i=0; i<n;i++)
   {
       for(j=0;j<n;j++)
       {
            if(*(sayilar+i)> *(sayilar+j))
           {
              temp = *(sayilar+i);
               *(sayilar+i) = *(sayilar+j);
              *(sayilar+j)  = temp;
           }

       }


       }
       for(i=0;i<n;i++)
   {
       printf("%d",*(sayilar+i));
       printf("\n");

   }
   printf("---------");



   if(n%2==0)
   {
    sayi1 =*(sayilar + (n/2));
    sayi2 = *(sayilar + ((n/2)-1));
       printf("%d %d",sayi1,sayi2);

   }

   else
   {
       toplam = *(sayilar +(n/2));
       printf("%d",toplam);
   }
}
