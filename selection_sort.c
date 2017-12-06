#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n;
    int dizi[8];
    for(i=0; i<8; i++)
    {
        printf("Dizinin %d. elemanini gir\n",i+1);
        scanf("%d",&n);
        dizi[i] = n;
    }

    int min,j;

    for(i=0; i<8; i++)
    {
        min =i;
        for(j=i; j<8; j++)
        {
            if(dizi[j]<dizi[min])
            {
                min = j;
            }
        }

        int temp = dizi[i];
        dizi[i] = dizi[min];
        dizi[min] = temp;
    }
    printf("Siralanmis Hali-->>  ");
    for(i=0; i<8; i++)
    {

        printf("%d__",dizi[i]);
    }

}
