#include <stdio.h>

int main()
{
    int i,j,sayi;
    printf("sayi gir:");
    scanf("%d",&sayi);

    for(i=1; i<=(sayi/2)+1; i++)
    {
        for(j=1; j<=sayi/2-i+1; j++)
        {
            printf(" ");
        }
        for(j=i; j>0; j--)
        {
            printf("%c",'A'+j-1);
        }
        for(j=2; j<=i; j++)
        {
            printf("%c",'A'+j-1);
        }
        printf("\n");
    }
    for(i=1; i<=sayi/2 ; i++)
    {
        for(j=1; j<=i; j++)
        {
            printf(" ");
        }
        for(j=sayi/2-i+1; j>=1; j--)
        {
            printf("%c", 'A'+j-1);
        }
        for(j=2; j<=(sayi/2)-i+1; j++)
        {
             printf("%c", 'A'+j-1);
        }
        printf("\n");
    }
    return 0;


}
