#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct lnode{
        int data;
        struct lnode * next;
} lnode;
lnode * root;
int size=0;
int dequeue(){
    if(size==0)
               return -1;
    if(size==1){
                int result = root->data;
                root=NULL;
                size--;
                return result;
                }
          lnode * iter;
          iter = root;
          int i;
          for(i = 0;i<size-2;i++){
                  iter = iter->next;
          }
          lnode * temp = iter->next;
          int result = iter->next->data;
          iter->next = NULL;
          free(temp);
          size--;
          return result;
}
void enqueue(int data){
     if(size==0){
                 root = (lnode*)malloc(sizeof(lnode));
                 root->data=data;
                 root->next = NULL;
                 size++;
     }
     else{
          lnode * iter=(lnode*)malloc(sizeof(lnode));
          iter->data=data;
          iter->next=root;
          size++;
          root=iter;
     }
}
void printqueue(){
     lnode  *iter;
     iter=root;
     printf("\n");
     int i;
     for( i = 0;i<size;i++){
             printf("%d__",iter->data);
             iter=iter->next;
     }
}
int main(){
 int sayi;
    char al;
    while(1)
    {
        printf(" Sayi eklemek Icin 1 e basiniz\n Cikarmak Icin 2 ye basiniz\n Programi kapatmak Icin 0 a basiniz\0");
        scanf("%c",&al);

        if(al=='1')
        {
            printf("Eklenecek sayiyi Giriniz:\n");
            scanf("%d",&sayi);
            enqueue(sayi);
            printqueue();
            printf("\n");
        }

        else if( al=='2')
        {
            printf("Cikarilan Sayi -> %d\n",dequeue());
            printqueue();
             printf("\n");
        }

        else if(al=='0')
        {
            exit(0);
        }
    }
 return 0;
}
