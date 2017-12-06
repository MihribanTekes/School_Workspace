#include <stdio.h>
#include <stdlib.h>
#define MAX_DUGUM 50
#define FALSE 0
#define TRUE 1
int ugranildimi[MAX_DUGUM];
typedef struct kuyruk *kuyruk_gost;

typedef struct oge* oge_gost;

typedef struct oge
{
    int dugum;
    oge_gost bag;
};

typedef struct kuyruk
{
    int dugum;
    kuyruk_gost bag;
};


oge_gost baslik[ MAX_DUGUM ];

void OnceDerinligineAra( int v )
{

	     oge_gost w;
	     ugranildimi[v] = TRUE;
	     printf("%5d ", v);
	     for( w = baslik[v] ; w ; w = w->bag )
	        {
	            if( !ugranildimi[ w->dugum ] )
             {
                 OnceDerinligineAra( w->dugum );
             }
	        }

}  


void kuyruk_ekle( kuyruk_gost *, kuyruk_gost *, int );
int kuyruk_al( kuyruk_gost * );

void OnceGenisligineAra( int v ){
	       oge_gost w;
	       kuyruk_gost on, arka;
	       on = arka = NULL;
	       printf("%5d ", v);
	       ugranildimi[v] = TRUE;
	       kuyruk_ekle( &on, &arka, v );
	       while( on ){
	           v = kuyruk_al( &on );
	           for( w = baslik[v] ; w ; w = w->bag )
               {
                   if( !ugranildimi[ w->dugum ] ){
	                   printf("%5d ", w->dugum);
	                   kuyruk_ekle( &on, &arka, w->dugum );
	                   ugranildimi[ w->dugum ] = TRUE;
	               }
               }

	       }
	   }
