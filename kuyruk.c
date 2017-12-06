#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next;
    int data;
}node;

node * ekle(node *r, int sayi)
{
    if(r==NULL)
    {
        r = (node*)malloc(sizeof(node));
        r->data = sayi;
        r->next = NULL;
        return r;
    }

    node *iter = r;
    while(iter->next != NULL)
        iter=iter->next;
    node *temp = (node*)malloc(sizeof(node));
    temp->data = sayi;
    temp->next = NULL;
    iter->next = temp;
    return r;
}

int cikar(node *r)
{
    if(r==NULL)
    {
        printf("Kuyruk Bos\n");
        return -1;
    }

    node *temp =r;
    int sonuc = r->data;
    r = r->next;
    free(temp);
    return sonuc;


}
void bastir(node *r)
{
    while(r!=NULL)
    {
        printf("%d__",r->data);
        r = r->next;
    }
}

int main()
{
    node *root =NULL;
    root =ekle(root,10);
    root =ekle(root,20);
    root =ekle(root,30);
    root =ekle(root,40);
    bastir(root);
    printf("\n");
    printf("%d",cikar(root));
    //bastir(root);

}
