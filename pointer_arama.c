#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("... start\n");
    char *aranacak = "birbirbir";
    char *aranan = "bir";
    int aranan_index=0 ,sayac1=0,sayac2=0;
    int i=0,j=0;
    int aranacak_index=0;

    while(*aranan !='\0')
    {
        aranan_index++;
        aranan++;

    }
    while(*aranacak != '\0')
{
    aranacak_index++;
    aranacak++;
}
    for(j=0; j<aranacak_index; j++)
{


        for(i=0; i<aranan_index; i++)
           {

            if(*(aranacak+i) == *(aranan+i))
            {
                sayac1++;
                printf("harf bulundu\n");
            }
            printf("----\n");

            }

 printf("................\n");
        if(aranan_index==sayac1)
        {
            printf("---------------------------->");
            sayac2++;
            sayac1=0;
            printf("kelime buldu\n");
        }


    }


    printf("kelime %d kadar bulunmustur",sayac2);
    return 0;
}
