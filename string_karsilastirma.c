#include <stdio.h>
#include <string.h>

int cevir(char string1[], char string2[]);

int main()
{
    char string1[50], string2[50];
    printf("ilk stringi gir\n\t");
    gets(string1);
    printf("ikinci stringi gir\n\t");
    gets(string2);
    int x = cevir(string1,string2);
    if(x==1)
    {
        printf("dogru");
    }
    else
    {
        printf("yanlis");
    }
    return 0;

}

int cevir(char string1[], char string2[])
{
    int i,j,sayac1 = 0, sayac2 = 0;

      if(strlen(string1)!= strlen(string2))
    {
      return 0;
    }

  else
  {
      for(i=0; i<strlen(string1); i++)
      {
          sayac1 = 0;
          sayac2 = 0;

          for(j=0; j<strlen(string2); j++)
          {
              char c = string1[i];

              if(c == string1[j])
              {
                  sayac1++;
              }
             if(c == string2[j])
              {
                  sayac2++;
              }
          }
         if(sayac1!=sayac2)
          {
              return 0;
          }
      }

  }return 1;

}
