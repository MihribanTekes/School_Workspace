#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct n
{
    char ad[15];
    char soyad[20];
    int no;
   struct n *next;
};
typedef struct n NODE;

NODE* listeye_ekle(FILE *ptDosya, NODE *iter);
NODE* listeden_sil(NODE *root,int silinecek);
/*void bastan_yaz(FILE *ptDosya, NODE *root);

int main()
{
    FILE *ptDosya;
    if((ptDosya = fopen("C:\\Users\\mihri\\Desktop\\txt\\ogrenci.txt","r"))==NULL)
    {
        printf("dosya acilamadi");
        return 0;
    }
    NODE *root = (NODE*)malloc(sizeof(NODE));
    root = listeye_ekle(ptDosya,root);
    int silinecek;
    printf("silinecek no yu giriniz:");
    scanf("%d",&silinecek);
    root = listeden_sil(root,silinecek);
    bastan_yaz(ptDosya,root);
    return 0;


}

NODE* listeye_ekle(FILE *ptDosya, NODE *iter)
{
    while(!feof(ptDosya))
    {
        char geciciad[15];
        char gecicisoyad[15];
        int gecicino;
        printf("giris");
        fscanf(ptDosya,"%s\t%s\t%d",geciciad,gecicisoyad,gecicino);
        strcpy(iter->ad,geciciad);
        strcpy(iter->soyad,gecicisoyad);
        iter->no = gecicino;
        iter = iter->next;
    }
    return iter;
}


NODE* listeden_sil(NODE*root,int silinecek)
{
    NODE *gecici;
    NODE *iter = root;

    if(root->no == silinecek)
    {
        gecici = root;
        root = root->next;
        free(gecici);
        return root;
    }

    while(iter->next != NULL && iter->next->no != silinecek)
    {
        iter = iter->next;
    }

    if(iter->next == NULL)
    {
        printf("no bulunamadi");
        return root;

    }

    gecici = iter->next;
    iter->next = iter->next->next;
    free(gecici);
    return root;


}

