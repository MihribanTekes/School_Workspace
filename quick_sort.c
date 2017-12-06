#include <stdio.h>
#include <stdlib.h>

void quicksort(int dizi[],int ilk,int son)
{
    int i,j,pivot,temp;
    if(ilk<son)
    {
        pivot=ilk;
        i = ilk;
        j = son;

        while(i<j)
        {
            while(dizi[i]<=dizi[pivot]&& i<son)
                i++;
            while(dizi[pivot]<dizi[j])
                j--;

            if(i<j)
            {
                temp = dizi[i];
                dizi[i] = dizi[j];
                dizi[j] = temp;
            }

            else
            {
                temp = dizi[pivot];
                dizi[pivot] = dizi[j];
                dizi[j] = temp;
                quicksort(dizi,ilk,j-1);
                quicksort(dizi,j+1,son);
            }
        }
    }
}
int main()
{

}
