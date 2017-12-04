#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p1,*p2,i,boyut,cift=0,tek=0;
    printf("bir tamsayi giriniz:\n");
    scanf("%d",&boyut);
    p1 = (int*)malloc(boyut*sizeof(int));
    p2 = (int*)malloc(boyut*sizeof(int));
    for(i=0; i<boyut; i++)
    {
        if(i%2==0)
        {
            *(p1+cift)=i;
            cift++;
        }
        else
        {
            *(p2+tek) =i;
            tek++;
        }
    }
    printf("cift sayilar\n");
    for(i=0; i<cift; i++)
    {
        printf("%d\n",*(p1+i));
    }

    printf("tek sayilar\n");
    for(i=0; i<tek; i++)
    {
        printf("%d\n",*(p2+i));
    }

    free(p1);
    free(p2);
    return 0;
}
