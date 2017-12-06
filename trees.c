#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct kisi
{
    int  no;
    char *ad;
    char *soyad;
    struct kisi *sol;
    struct kisi *sag;
}Kisi;

Kisi *agac = NULL;

Kisi * ekle(Kisi *agac,int x, char *adi, char *soyadi)
{
    char *adi2 = adi;
    char *soyadi2 = soyadi;

    if(agac==NULL)
    {
        Kisi *root = (Kisi*)malloc(sizeof(Kisi));
        root->sag = NULL;
        root->sol = NULL;
        root->no = x;
        root->ad = adi;
        root->soyad = soyadi;
        return root;
    }

    char *soyisim = agac->soyad;

    int result = strcmp(soyisim,soyadi);

    if(result>0)
    {

        agac->sag = ekle(agac->sag,x,adi2,soyadi2);
        return agac;
    }

    agac->sol = ekle(agac->sol,x,adi2,soyadi2);
    return agac;

}

void preorder(Kisi *agac)
{
    if(agac==NULL)
        return;
    printf("No:%d Ad:%s Soyad:%s\n",agac->no,agac->ad,agac->soyad);
    preorder(agac->sol);
    preorder(agac->sag);
}

void postorder(Kisi *agac)
{
    if(agac==NULL)
        return;
    postorder(agac->sol);
    postorder(agac->sag);
    printf("No:%d Ad:%s Soyad:%s\n",agac->no,agac->ad,agac->soyad);
}

void inorder(Kisi *agac)
{
    if(agac==NULL)
        return;
    inorder(agac->sol);
    printf("No:%d Ad:%s Soyad:%s\n",agac->no,agac->ad,agac->soyad);
    inorder(agac->sag);

}

void basCagir(Kisi *agac)
{
    printf("----PREORDER----\n");
   preorder(agac);
   printf("----POSTORDER----\n");
   postorder(agac);
   printf("----INORDER----\n");
   inorder(agac);

}
int bul(Kisi *agac, char *soyadi)
{
    if(agac==NULL)
        return -1;
    if(agac->soyad == soyadi)
    {
        printf("No:%d Ad:%s Soyad:%s\n",agac->no,agac->ad,agac->soyad);
        return 1;
    }

    if(bul(agac->sag,soyadi)==1)
    {
        printf("No:%d Ad:%s Soyad:%s\n",agac->no,agac->ad,agac->soyad);
        return 1;
    }

    if(bul(agac->sol,soyadi)==1)
    {
        printf("No:%d Ad:%s Soyad:%s\n",agac->no,agac->ad,agac->soyad);
        return 1;
    }
    return -1;
}

char *maxsoyad(Kisi *agac)
{
    while(agac->sag != NULL)
        agac = agac->sag;
    return agac->soyad;
}

char *minsoyad(Kisi *agac)
{
    while(agac->sol != NULL)
        agac = agac->sol;
    return agac->soyad;
}

Kisi *sil(Kisi *agac, char *soyadi)
{
    int result;
    if(agac==NULL)
        return NULL;
    result = strcmp(agac->soyad,soyadi);

    if(result == 0)
    {
        if(agac->sol == NULL && agac->sag==NULL)
            return NULL;
        if(agac->sag != NULL)
        {
            agac->soyad = minsoyad(agac->soyad);
            agac->sag = sil(agac->sag,minsoyad(agac->sag));
            return agac;
        }
        agac->soyad = maxsoyad(agac->sol);
        agac->sol = sil(agac->sol,maxsoyad(agac->sol));
        return agac;

    }
    if(result>0)
    {
        agac->sag = sil(agac->sag,soyadi);
        return agac;
    }

    agac->sol = sil(agac->sol,soyadi);
    return agac;
}


int main()
{
    int no;
    char *ad,*soyad;
        while(1)
        {
            printf("\nBinary Search Tree Operations\n");
            printf("1. Ekle\n ");
            printf("2. Sil\n");
            printf("3. Ara\n");
            printf("4. Bastir\n");
            printf("5. Cikis\n");

            int choice;
            scanf("%d",&choice);

            switch (choice)
            {
            case 1 :
                printf("No Ad Soyad Giriniz\n");
                scanf("%d %s %s",&no,&ad,&soyad);
                agac = ekle(agac,no,ad,soyad);
                break;
            case 2 :
                printf("Silmek istediginiz kaydin soyadini giriniz:\n");
                scanf("%s",&soyad);
                agac = sil(agac,soyad);
                break;
            case 3 :
                printf("Aradiginiz soyadi giriniz:\n");
                scanf("%s",soyad);
                bul(agac,soyad);
                break;
            case 4 :
                basCagir(agac);
                break;
            case 5 :
                exit(0);
                break;
            default :
                printf("Hatali Girdi \n ");
                break;
            }

        }


}
