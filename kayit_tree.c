#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 9

struct node {
    int no;
    char *soyad;
    char *ad;
    struct node *sol;
    struct node *sag;
};


typedef int (*Compare)(const char *, const char *);


void insert(char* key, char* key2, int no, struct node** agac, Compare cmp)
{
    int res;
    if( *agac == NULL ) {
        *agac = (struct node*) malloc( sizeof( struct node ) );
        (*agac)->soyad = malloc( strlen (key) +1 );
        strcpy ((*agac)->soyad, key);
		(*agac)->ad = malloc( strlen (key2) +1 );
         strcpy ((*agac)->ad, key2);
		 (*agac)->no = no;
        (*agac)->sol = NULL;
        (*agac)->sag = NULL;

    } else {
        res = cmp (key, (*agac)->soyad);
        if( res < 0)
            insert( key,key2,no, &(*agac)->sol, cmp);
        else if( res > 0)
            insert( key,key2,no, &(*agac)->sag, cmp);
        else
            printf (" '%s' Agacta Var \n", key);
    }
}


int karsilastir(const char *a, const char *b)
{
    return (strcmp (a, b));
}

char *input( void )
{
    static char line[MAXLEN+1];
    printf("---> : ");
    fgets( line, sizeof line, stdin );
    return ( strtok(line, "\n" ));
}


void in_order(struct node *root)
{
    if( root != NULL ) {
        in_order(root->sol);
        printf("   %s\n", root->soyad);
        in_order(root->sag);
    }
}

void post_order(struct node *root)
{
    if( root != NULL ) {
        in_order(root->sol);
        in_order(root->sag);
        printf("   %s\n", root->soyad);

    }
}

void pre_order(struct node *root)
{
    if( root != NULL ) {
        printf("   %s\n", root->soyad);
        in_order(root->sol);
        in_order(root->sag);


    }
}

void bas(struct node *root)
{
    printf("----PREORDER----\n");
   pre_order(root);
   printf("----POSTORDER----\n");
   post_order(root);
   printf("----INORDER----\n");
   in_order(root);
}


void ara(char* key, struct node* agac, Compare cmp)
{
    int res;
    if( agac != NULL ) {
        res = cmp(key, agac->soyad);
        if( res < 0)
            ara( key, agac->sol, cmp);
        else if( res > 0)
            ara( key, agac->sag, cmp);
        else
            printf("\nNo:%d %s'%s' bulundu\n",agac->no,key);
    }
    else printf("\nBulunamadi\n");
    return;
}

void sil(struct node** agac)
{
    if( *agac != NULL ) {
        sil(&(*agac)->sol);
        sil(&(*agac)->sag);
        free( (*agac)->soyad );
        free( (*agac) );
    }
}


struct node* Delete(struct node *root,char *key)
{
	if( root == NULL)
	{
		return NULL;
	}

	int result = strcmp(root->soyad,key);

	if(resul)
	{
		root->left = Delete(root->left,data);

	}
	else if(data > root->data)
	{
		root->right = Delete(root->right,data);
	}
	else
	{
		if(root->left == NULL && root->right == NULL)
		{
			delete(root);
			root = NULL;
		}

		else if(root->left == NULL)
		{
			struct node *temp = root;
			root = root->right;
			delete temp;
		}

		else if(root->right == NULL)
		{
			struct node *temp = root;
			root = root->left;
			delete temp;
		}
		else
		{
			struct node *temp= FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}

	return root;

}


int FindMin(struct node *root)
{
	if(root == NULL)
	 return NULL;

	if(root->sol != NULL)
		return FindMin(root->sol);
	return root->soyad;
}


struct node* yaprakSil(struct node** agac, char *soyadi)
{
    int result;
    if(*agac==NULL)
       return NULL;

    result = strcmp((*agac)->soyad,soyadi);

    if(result == 0)
    {
        if((*agac)->sol == NULL && (*agac)->sag==NULL)
            return NULL;
        if((*agac)->sag != NULL)
        {
            (*agac)->soyad = minsoyad(&(*agac)->soyad);
            (*agac)->sag = yaprakSil(&(*agac)->sag,minsoyad(&(*agac)->sag));
            return (*agac);
        }
        (*agac)->soyad = maxsoyad(&(*agac)->sol);
        (*agac)->sol = yaprakSil(&(*agac)->sol,maxsoyad(&(*agac)->sol));
        return (*agac);

    }
    if(result>0)
    {
        (*agac)->sag = yaprakSil(&(*agac)->sag,soyadi);
        return (*agac);
    }

    (*agac)->sol = yaprakSil(&(*agac)->sol,soyadi);
    return (*agac);
}

char* maxsoyad(struct node* agac)
{
    while(agac->sag != NULL)
        agac = agac->sag;
    return agac->soyad;
}

char* minsoyad(struct node* agac)
{
    while(agac->sol != NULL)
        agac = agac->sol;
    return agac->soyad;
}

void menu()
{
    printf("\nEleman eklemek için 'e'\n");
    printf("Aramak icin 'a' \n");
    printf("Basmak icin 'b'\n");
    printf("Agaci silmek icin 'x'\n");
    printf("Cikmak icin 'c' \n");
}

int main()
{
    struct node *agac = NULL;
    char *soyad;
	char *ad;
	int no;
    char option = 'x';

    while( option != 'c' ) {

        menu();

        option = getch();

        if( option == 'e') {
            printf("No giriniz:");
			scanf("%d",&no);
            getchar();
            printf("Adi giriniz:");
			ad = input();
			getchar();
			printf("Soyadi Giriniz:");
            soyad = input();
            insert(soyad,ad,no,&agac, (Compare)karsilastir);
        }
        else if( option == 'a' ) {
            soyad = input();
            ara(soyad, agac, (Compare)karsilastir);
        }
        else if( option == 'b' ) {
            bas(agac);
        }
        else if( option == 'c' ) {
            printf("Soyadi Giriniz:");
            soyad = input();
            yaprakSil(&agac,soyad);
            //sil(&agac);
            //printf("Agac Yok Edildi");
            //agac = NULL;
        }
        else if( option == 'x' ) {
            printf("Cikiliyor");
        }
    }
return 0;
}
