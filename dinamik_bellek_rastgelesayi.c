#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p,i,boyut;
    printf("kac tane sayi uretilecek:");
    scanf("%d",&boyut);
    p = (int*)malloc(boyut*sizeof(int));
    srand(time(0));
    printf("uretilen sayilar\n");
    for(i=0; i<boyut; i++)
    {
        *(p+i) = rand()%100;
        printf("%d\n",*(p+i));
    }
    printf("sayilarin kareleri\n");
    for(i=0; i<boyut; i++)
    {
        printf("%d\n",(*(p+i))*(*(p+i)));
    }
    free(p);
    return 0;
}
