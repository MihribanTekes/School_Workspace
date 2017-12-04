#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p1, *p2, bos=0;
    p1 = (int*)malloc(sizeof(int));
    p2 = (int*)malloc(sizeof(int));
    printf("birinci sayiyi giriniz:");
    scanf("%d",&(*p1));
    printf("ikinci sayiyi giriniz:");
    scanf("%d",&(*p2));
    printf("birinci sayi %d\n ikinci sayi %d\n",*p1,*p2);
    bos = *p1;
    *p1 = *p2;
    *p2 = bos;
    printf("birinci sayi %d\n ikinci sayi %d\n",*p1,*p2);
    free(p1);
    free(p2);
    return 0;
}
