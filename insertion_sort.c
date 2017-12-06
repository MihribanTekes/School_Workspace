#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,dizi[8];

    for(i=0; i<8; i++)
    {
        printf("%d. elemani giriniz:\n",i+1);
        scanf("%d",&dizi[i]);
    }

    for(i=0; i<8; i++)
    {
        for(j=0; j<i; j++)
        {
            if(dizi[j]>dizi[i])
            {
                int temp = dizi[i];
                dizi[i] = dizi[j];
                dizi[j] = temp;
            }
        }
    }

    for(i=0; i<8; i++)
    {
        printf("%d__",dizi[i]);
    }
}
