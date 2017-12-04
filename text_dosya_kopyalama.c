#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *ptDosyaOrjinal, *ptDosyaKopya;

    if((ptDosyaOrjinal=fopen("C:\\Users\\mihri\\Desktop\\txt\\orjinal_text.txt","r"))==NULL)
    {
        printf("orjinal dosya acilamadi");
        return 0;
    }

    if((ptDosyaKopya=fopen("C:\\Users\\mihri\\Desktop\\txt\\kopya_text.txt","w"))==NULL)
    {
        printf("kopya dosya acilamadi");
        return 0;
    }

    while(!feof(ptDosyaOrjinal)) //dosyann sonuna gelene kadar
    {
        putc(getc(ptDosyaOrjinal),ptDosyaKopya);
    }

    printf("dosya kopyalandi, yeni dosya: kopya_text.txt");
    fclose(ptDosyaOrjinal);
    fclose(ptDosyaKopya);

    return 0;
}
