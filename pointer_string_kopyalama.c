#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *kelime1 = "Merhaba Dunya";
    char kelime2[20];
    char *temp;
    int baslangic_index;
    int kac_karakter;
    int i,j=0;

    printf("Hangi Karakterden Baslanilsin\n");
    scanf("%d",&baslangic_index);
    printf("Kac Karakter Alinsin\n");
    scanf("%d",&kac_karakter);

    temp = &kelime1[baslangic_index];

    for(i=baslangic_index; i<(kac_karakter+baslangic_index); i++)
    {
        kelime2[j] = *(temp+j);
        j++;


    }
    kelime2[j] = '\0';
    printf("%s\n",kelime2);
    return 0;
}
