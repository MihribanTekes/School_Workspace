
int faktoriyel(char sayi)
{
  if(sayi==0)
  {return sayi;}
     else(sayi>0)
     {
       return(sayi*faktoriyel(sayi-1));
     }
}

void main() 
{
        char sayi;
        trisb=0;
        portb=0;
        trisc=1;
        portc=0;
        trisd=1;
        portd=0;
        
        while(1)
        {
          sayi = portc;
          delay_ms(500);
          portb = faktoriyel(sayi);
          delay_ms(500);
          portb=0;
        }

}
