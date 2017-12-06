#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>

#define MAX 50

typedef struct stackHesap
{
    int data;
    struct stackHesap *next;
}stackHesap;



typedef struct stackListe
{
    char data[MAX];
    char top;

}stackListe;


int oncelik(char);
int bosYigin(stackListe *);
int dolu(stackListe *);
int top(stackListe *);
char pop(stackListe *);
int popHesap();
void pushHesap(int data);
void push(stackListe *,char data);
void infix_to_postfix(char infix[],char postfix[]);
void hesapla(char postfix[]);
int tut=0,tut2=0;
stackHesap *iter = NULL;


void main()
{
    char infix[30],postfix[30];
    printf("Infix ifadeyi girin: ");
    gets(infix);
    infix_to_postfix(infix,postfix);
    printf("\nPostfix Ifade: %s",postfix);
    hesapla(postfix);
    return 0;
}



int oncelik(char x)
{
    if(x=='(')
        return(0);
    if(x=='+'||x=='-')
        return(1);
    if(x=='*'||x=='/'||x=='%')
        return(2);

    return(3);
}



void pushHesap(int data)
{
    if(iter==NULL)
    {
        iter=(struct stackHesap*)malloc(sizeof(struct stackHesap));
        iter->next=NULL;
        iter->data = data;

            }
    else
    {
        stackHesap *yeni = (stackHesap*)malloc(sizeof(stackHesap));
        yeni->next = iter;
        yeni->data = data;
        iter= yeni;
    }


}

int popHesap()
{
    stackHesap *temp =iter;
    iter = iter->next;
    int sayi2 = temp->data;
    free(temp);
    return sayi2;
}

void hesapla(char postfix[])
{

    int boyut=0;
    int l=0;
    while(postfix[boyut]!= '\0')
        boyut++;
    char *pt;
    char postfix2[30];
    for(l=0; l<boyut; l++)
    {
        postfix2[l] = postfix[l];
    }
        postfix2[boyut]='\0';
    int sonuc=0,hesap=0,b;
    for(l=0; l<boyut; l++)
    {    char ch= postfix2[l];


            if(ch>='0' && ch<='9' )
            {   sonuc = ch - '0';
               pushHesap(sonuc);
            }

            else if(ch == '+')
            {
                hesap += iter->data;
                popHesap();
                hesap += iter->data;
                popHesap();
                pushHesap(hesap);
                hesap=0;
            }
            else if(ch == '-')
            {
                int y = popHesap();
                int z = popHesap();
                if(y>z)
                {
                    hesap = y;
                    hesap -= z;
                    pushHesap(hesap);
                    hesap=0;
                }
                else
                {
                    hesap = z;
                    hesap -= y;
                    pushHesap(hesap);
                    hesap = 0;
                }
            }

            else if(ch == '*')
            {
                hesap = iter->data;
                popHesap();
                hesap *=iter->data;
                popHesap();
                pushHesap(hesap);
                hesap=0;
            }

            else if(ch == '/')
            {
                int y = popHesap();
                int z = popHesap();
                if(y>z)
                {
                    hesap = y/z;
                    pushHesap(hesap);
                }
                else if(z>y)
                {
                    hesap = z/y;
                    pushHesap(hesap);
                }

                hesap = 0;
            }
        b=l;
       printf("\nPostfix--> ");
    while(postfix2[b] !='\0')
    {
        printf("%c",postfix2[b]);
        b++;
    }

    printf("\nYigin-->");
    stackHesap *node = iter;
    while(node!=NULL)
    {
        printf("%d  ",node->data);
        node = node->next;
    }



}

postfix2[l+1]='\0';
}



void init(stackListe *s)
{
    s->top=-1;
}

int bosYigin(stackListe *s)
{
    if(s->top==-1)
        return(1);

    return(0);
}

int dolu(stackListe *s)
{
    if(s->top==MAX-1)
        return(1);

    return(0);
}
int top(stackListe *p)
{
    return (p->data[p->top]);
}

void push(stackListe *s,char x)
{
    tut++; int a;
    s->top=(s->top)+1;
    s->data[s->top]=x;
    printf("\nYigin-->");
    for(a=0; a<tut; a++)
    {
        if(s->data[(s->top)-a] != '\0')
        printf("%c  ",s->data[(s->top)-a]);
    }


}

char pop(stackListe *s)
{
    tut--; int a;
    char x;
    x=s->data[s->top];
    s->top=(s->top)-1;
    printf("\nYigin-->");
    for(a=0; a<tut; a++)
    {
        if(s->data[(s->top)-a] != '\0')
         printf("%c  ",s->data[(s->top)-a]);
    }
    return(x);
}




void infix_to_postfix(char infix[],char postfix[])
{
    stackListe *s;
    char x,islenecekKarakter;
    int i,j;
    init(&s);
    j=0;
    int k;

    for(i=0;infix[i]!='\0';i++)
    {
        islenecekKarakter=infix[i];
        if(isalnum(islenecekKarakter))
            {postfix[j++]=islenecekKarakter;
            postfix[j]='\0';

            }
        else
            if(islenecekKarakter=='(')
              {

              push(&s,'(');


            }
        else
            if(islenecekKarakter==')')
                while((x=pop(&s))!='(')
                      {postfix[j++]=x;
                      postfix[j]='\0';

                      }
                else
                {
                    while(oncelik(islenecekKarakter)<=oncelik(top(&s))&&!bosYigin(&s))
                    {
                        x=pop(&s);
                        postfix[j++]=x;
                        postfix[j]='\0';
                    }
                    push(&s,islenecekKarakter);

                }
                printf("\nInfix-->  ");
            for(k=i; infix[k]!='\0'; k++)
            {
                printf("%c",infix[k]);
            }

            printf("\nPostfix-->  ");
            for(k=0; postfix[k]!='\0';k++)
            {
                if(postfix[k] != '\0')
                 printf("%c",postfix[k]);
            }

    }

    while(!bosYigin(&s))
    {
        x=pop(&s);
        postfix[j++]=x;

    }

    postfix[j]='\0';




}
