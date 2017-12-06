#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node
{
    int oncelik;
    int sure;
    struct node *next;

}Process;
Process * process_Ekle(Process *first, int pt, int tm);
void print_Process(Process *first);
Process * process_Calistir(Process *first);
void process_kill(Process *process, int pt, int tm);
int sayac = 0;
int tut = 0;

int main()
{

    int priority, time;
    char al;
    Process *first = NULL;
    Process *target;

    for(;;){

      puts("\n*** Menu ***");
      puts("[E] Process Ekle\n");
      puts("[G] Processleri Goster\n");
      puts("[P] Process Islet\n");
      puts("[C] Cikis");

    scanf("%c",&al);

        if(al=='E'){
            printf("Processin onceligini ve suresini giriniz:\n");
            scanf("%d %d",&priority,&time);
            first = process_Ekle(first,priority,time);
            target = first;
           }

        else if(al=='G'){

            print_Process(first);
        }

        else if(al=='P'){
            target = process_Calistir(target);
        }

        else if(al=='C'){
            exit(0);
        }

     }
     return 0;

     }




Process * process_Ekle(Process *first, int pt, int tm)
{
    if(first == NULL)
    {
        first = (Process*)malloc(sizeof(Process));
        first->oncelik = pt;
        first->sure = tm;
        first->next = first;
        sayac++;
        return first;
    }


    if(first->oncelik > pt)
    {
        Process *temp = (Process*)malloc(sizeof(Process));
        temp->oncelik = pt;
        temp->sure = tm;
        temp->next = first;

        Process *iter = first;

        while(iter->next != first)
        {
            iter = iter->next;
        }

        iter->next = temp;
        sayac++;
        return temp;
    }

    Process *iter = first;
    while(iter->next != first && iter->next->oncelik<pt)
    {
        iter = iter->next;
    }

    Process *temp = (Process*)malloc(sizeof(Process));
    temp->oncelik = pt;
    temp->sure = tm;
    temp->next = iter->next;
    iter->next = temp;
    sayac++;
    return first;


}


void print_Process(Process *first)
{
    Process *iter = first;
    while(iter->next != first)
    {
        printf("Oncelik %d _____ Sure %d\n",iter->oncelik, iter->sure);
        iter = iter->next;
    }

    printf("Oncelik %d _____ Sure %d\n",iter->oncelik, iter->sure);
}


Process * process_Calistir(Process *target)
{


        target->sure = target->sure-1;


        if((target->sure)<=0)
    {
        process_kill(target,target->oncelik,target->sure);
        target = target->next;

    }


    print_Process(target);
    target = target->next;

    return(target);


}
void process_kill(Process *process, int pt, int tm)
{
Process *iter = process;


     if(process->next == process)
    {
        free(process);
        printf("Processler Bitti");
        exit(0);
        return NULL;
    }

    else
    {


        while(iter->next != process)
        {
            if(iter->next->oncelik == pt)
            {
                Process *temp = iter->next;
                iter->next = temp->next;
                free(temp);
            }

            iter= iter->next;

        }

        if(process->oncelik == pt)
        {

            iter->next = iter->next->next;
            free(process);


        }
    }
  return iter;
}
