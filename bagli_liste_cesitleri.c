#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;

}node;
typedef struct dnode{
    int data;
    struct dnode *next;

}dnode;

typedef struct cnode{
    int data;
    struct cnode *next;
    struct cnode *prev;

}cnode;


cnode * cSiraliEkle(cnode *r, int sayi)
{
    if(r==NULL)
    {
        r = (cnode*)malloc(sizeof(cnode));
        r->data = sayi;
        r->next = NULL;
        r->prev = NULL;
        return r;
    }

    if(r->data > sayi)
    {
        cnode *temp = (cnode*)malloc(sizeof(cnode));
        temp->data = sayi;
        temp->next = r;
        temp->prev = NULL;
        r->prev = temp;
        return temp;
    }

    cnode *iter=r;

    while(iter->next != r && iter->next->data < sayi)
        iter = iter->next;
    cnode *temp = (cnode*)malloc(sizeof(cnode));
    temp->data =sayi;
    temp->prev = iter;
    temp->next = iter->next;
    iter->next = temp;
    return r;
}

void cBastir(cnode *r)
{
    while(r!= NULL)
    {
        printf("%d",r->data);
        r = r->next;
    }
}

void dBastir(dnode *r)
{
    dnode *iter = r;

    while(iter->next != r)
    {
        printf("%d__",iter->data);
        iter=iter->next;
    }

}

dnode * SiraliEkle(dnode *r, int sayi)
{
    if(r==NULL)
    {
        r = (dnode*)malloc(sizeof(dnode));
        r->data = sayi;
        r->next = r;
        return r;
    }

    if(r->data > sayi)
    {
        dnode *temp = (dnode*)malloc(sizeof(dnode));
        temp->data = sayi;
        temp->next = r;
        dnode *iter =r;
        while(iter->next != r)
        {
            iter = iter->next;
        }
        iter->next = temp;
        return temp;

    }
    dnode *iter =r;

    while(iter->next !=r && iter->next->data < sayi)
    {
        iter = iter->next;
    }

    dnode *temp = (dnode*)malloc(sizeof(dnode));
    temp->data = sayi;
    temp->next = iter->next;
    iter->next = temp;
    return r;

}

cnode * cSil(cnode *r,int sayi)
{
    if(r->data ==sayi)
    {
        cnode *temp = r->next;
        temp->prev = NULL;
        free(r);
        return temp;

    }

    cnode *iter =r;

    while(iter->next != NULL && iter->next->data != sayi)
        iter =iter->next;
    cnode *temp =iter->next;
    iter->next = iter->next->next;
    iter->next->prev



}

void dEkle(dnode *r, int sayi)
{
    dnode *iter =r;
    if(r==NULL)
    {
        r = (dnode*)malloc(sizeof(dnode));
        r->data = sayi;
        r->next = r;
    }

    while(iter->next != r)
    {
        iter =iter->next;
    }
    dnode *temp = (dnode*)malloc(sizeof(dnode));
    temp->data = sayi;
    iter->next = temp;
    temp->next = r;
}

dnode * dsil(dnode *r,int sayi)
{
    if(r->data ==sayi)
    {
        node *temp = r->next;
        node *iter =r;
        while(iter->next!=r)
            iter = iter->next;
        iter->next = temp;
        free(r);
        return(temp);
    }

    node *iter =r;
    while(iter->next != r && iter->next->data != sayi)
        iter = iter->next;
    node *temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    return r;
}


node * Siraliekle(node *r,int sayi)
{
  if(r==NULL)
  {
      r = (node*)malloc(sizeof(node));
      r->data = sayi;
      r->next =NULL;
      return r;
  }

  if(r->data > sayi)
  {
      node *temp = (node*)malloc(sizeof(node));
      temp->data = sayi;
      temp->next = r;
      return temp;
  }

  node *iter =r;

  while(iter->next != NULL && iter->next->data < sayi)
  {
      iter = iter->next;
  }

  node *temp = (node*)malloc(sizeof(node));
  temp->data = sayi;
  temp->next = iter->next;
  iter->next = temp;
  return r;
}

void bastir(node *r)
{
    while(r!=NULL)
    {
        printf("%d--",r->data);
        r= r->next;
    }
}

node * sil(node *r,int sayi)
{
    if(r->data == sayi)
    {
        node *temp;
        temp= r->next;
        free(r);
        return temp;

    }

    node *iter = r;
    while(iter->next != NULL && iter->next->data != sayi)
    {
        iter =iter->next;
    }
    node *temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    return r;

}


int main()
{

        node *root=NULL;
        dnode *root2 = NULL;
        cnode *root3 = NULL;
        root3=cSiraliEkle(root3,50);
        root3=cSiraliEkle(root3,21);
        root3=cSiraliEkle(root3,69);
        root3=cSiraliEkle(root3,32);
        root2=SiraliEkle(root2,50);
        root2=SiraliEkle(root2,21);
        root2=SiraliEkle(root2,69);
        root2=SiraliEkle(root2,32);
        root=Siraliekle(root,50);
        root=Siraliekle(root,21);
        root=Siraliekle(root,69);
        root=Siraliekle(root,32);
        bastir(root);
        printf("\n");
        root = sil(root,21);
        bastir(root);
        printf("\n");
        root = sil(root,50);
        bastir(root);
        printf("\n");
        root = sil(root,69);
        bastir(root);
        printf("\n");
        dBastir(root2);
        printf("\n");
        root2 = dsil(root2,21);
        dBastir(root2);
        printf("\n");
        root2 = dsil(root2,50);
        dBastir(root2);
        printf("\n");
        root2 = dsil(root2,69);
        dBastir(root2);
        printf("\n");
        cBastir(root3);






}
