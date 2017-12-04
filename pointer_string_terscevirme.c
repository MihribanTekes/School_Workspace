#include <stdio.h>
#include <stdlib.h>

int main()
{
    char kelime[30];
    printf("kelime giriniz\n");
    gets(kelime);
    char *baslangic, *bitis;
    baslangic = kelime;
    bitis = kelime;
    char temp;
    while(*bitis)
        bitis++;
    bitis--;
    while(baslangic<bitis)
    {
        temp = *baslangic;
        *baslangic = *bitis;
        *bitis = temp;
        baslangic++;
        bitis--;
    }
    puts(kelime);
    return 0;
}
