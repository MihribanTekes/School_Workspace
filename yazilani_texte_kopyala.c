#include <stdio.h>
#include <stdlib.h>

char bellekBolgesi[15];

int main()
{
    FILE *ptDosya;
    int i=0;

    if((ptDosya=fopen("C:\\Users\\mihri\\Desktop\\txt\\yazilani_aktar.txt","a"))==NULL)
    {
        printf("dosya acilamadi");
        return 0;
    }

    printf("yazdiginiz her sey texte kopyalanacak sonlandýrmak için * karakterine basýnýz");

    do
    {
        bellekBolgesi[i] = getch();
        putch(bellekBolgesi[i]);
        i++;
        if(i==10)
        {
            if(bellekBolgesi[i-1]== '*')
                break;

            fwrite(bellekBolgesi,sizeof(char),10,ptDosya);
            i=0;
        }
    }while(bellekBolgesi[i-1]!= '*');

    fwrite(bellekBolgesi,sizeof(char),i,ptDosya);

    fclose(ptDosya);
    system("pause");
    return 0;
}
