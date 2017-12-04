#include <stdio.h>
#include <stdlib.h>

int main()
{
   int rowNumber, row, colSpaces, colStars;
   printf("sayi gir:");
   scanf("%d",&rowNumber);

   for(row=1; row<=rowNumber; row++)
   {
       for(colSpaces=rowNumber-row; colSpaces>=1; colSpaces--)
       {
           printf(" ");

       }
       for(colStars=1; colStars<=row; colStars++)
       {
           printf("* ");
       }
       printf("\n");
   }
    return 0;
}
