#include <stdio.h>
#include <stdlib.h>

int main()
{
    int boyut,i,*bellek,toplam=0;
    printf("eleman sayisini giriniz:");
    scanf("%d",&boyut);
    bellek = (int*)calloc(boyut,sizeof(int));
    if(bellek==NULL)
    {
        printf("hata belirtilen yer verilmedi...");
        exit(0);
    }

    for(i=0; i<boyut; i++)
    {
        printf("%d.sayiyi giriniz:",i+1);
        scanf("%d",bellek+i);
        toplam += *(bellek+i);


    }

    printf("toplam = %d",toplam);
    free(bellek);
    return 0;
}
