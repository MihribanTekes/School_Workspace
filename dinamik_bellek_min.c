#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p,i,boyut,enk;
    printf("kac adet sayi uretilsin:");
    scanf("%d",&boyut);
    p = (int*)malloc(boyut*sizeof(int));
    srand(time(0));
    printf("uretilen sayilar");
    for(i=0; i<boyut; i++)
    {
        *(p+i) = rand()%100;
        printf("%d\n",*(p+i));
    }

    enk = *p;
    for(i=0;i<boyut;i++)
    {
        if(*(p+i)<enk)
            enk = *(p+i);
    }
    printf("en kucuk sayi %d",enk);
    free(p);
    return 0;
}
