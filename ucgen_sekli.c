#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rowNumber,row,col;
    printf("sayi giriniz:");
    scanf("%d",&rowNumber);

    for(row=1; row<=rowNumber; row++)
    {
        for(col=1; col<=row; col++)
        {
            int kosul = col%2;
            printf("%d",kosul);
        }
        printf("\n");
    }
    return 0;
}
