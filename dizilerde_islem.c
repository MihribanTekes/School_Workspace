#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sib[5], sdb[5], i,secim,ssecim,ysecim;

    for(i=0; i<5; i++)
       {
        sib[i] = 0;
        sdb[i] = 0;
        }

        while(7>3)
        {

            printf("bolum secimi --> sigara icilen bolum icin 1, sigara icilmeyen bolum icin 0 a basiniz\n");
            scanf("%d",&secim);

            if(secim==1)
            {
                for(i=0; i<5; i++)
                {
                    if(sib[i]==0)
                        printf("%d. koltuk bos\n",i+1);
                    else
                        printf("%d. koltuk rezerve\n",i+1);

                }
                printf("secim yapiniz\n");
                scanf("%d",&ssecim);

                while(sib[ssecim-1]==1)
                {
                    printf("bu koltuk rezerve baska bir koltuk seciniz\n");
                    scanf("%d",&ssecim);
                }
                if(sib[ssecim-1]==0)
                {
                    sib[ssecim-1] = 1;
                    printf("icerik onaylandi, sigara icilen bolum %d. koltuk no\n",ssecim);
                }

            }
            if(secim==0)
            {
                for(i=0; i<5; i++)
                {
                    if(sdb[i]==0)
                        printf("%d. koltuk bos\n",i+1);
                    else
                        printf("%d. koltuk rezerve\n",i+1);

                }
                printf("secim yapiniz\n");
                scanf("%d",&ssecim);

                while(sdb[ssecim-1]==1)
                {
                    printf("bu koltuk rezerve baska bir koltuk seciniz\n");
                    scanf("%d",&ssecim);
                }
                if(sdb[ssecim-1]==0)
                {
                    sdb[ssecim-1] = 1;
                    printf("icerik onaylandi, sigara icilmeyen %d. koltuk no\n",ssecim);
                }
            }

            if(sib[0]==1 && sib[1]==1 && sib[2]==1 && sib[3]==1 && sib[4]==1 )
               {
                 printf("sigara icilen bolum dolmustur, sigara icilmeyen bolumden secim yapmak ister misiniz? 1/0");
                scanf("%d",&ysecim);
                }
            else if(sdb[0]==1 && sdb[1]==1 && sdb[2]==1 && sdb[3]==1 && sdb[4]==1)
              {
                printf("sigara icilmeyen bolum dolmustur, sigara icilenden secim yapmak ister misiniz? 1/0");
            scanf("%d",&ysecim);
            }
            if(ysecim == 0)
                return 0;
        }
}
