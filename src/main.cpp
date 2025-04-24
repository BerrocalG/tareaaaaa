//bassetarea calculadora
#define F_CPU 16000000UL  
#include <avr/io.h>  
#include <util/delay.h>

int main(void) {
  DDRD|=0xF0; //matrizcolumna
  DDRD&= ~0X0F; //matriz fila

  DDRB|=0X0F; //codificador
  DDRC|=0X07; //A0 A1 A2 display
  DDRC|=0X08; //A3 led

  char cuenta=0;
  char boton= 0;

  while(1){
  
      PORTD|=0X0F; //prende filas
      while (1){

        PORTC&=~(0X01);
        PORTC&=~(0X02);
        PORTC|=0X04;
        PORTB |= ((cuenta / 100) << 4);   //centenas
        PORTB &= ((cuenta / 100) << 4) | 0x0F; 
        _delay_ms(8);

        PORTC&=~(0X01);
        PORTC&=~(0X04);
        PORTC|=0X02;
        PORTB|=(((cuenta / 10) % 10) << 4);
        PORTB&=(((cuenta / 10) % 10) << 4)| 0X0F;//decenas

        _delay_ms(8);
        PORTC&=~(0X04);
        PORTC&=~(0X02);
        PORTC|=0X01;
        PORTB|=((cuenta % 10) << 4);
        PORTB&=((cuenta  % 10) << 4)| 0X0F;//unidades
      _delay_ms(8);

      PORTD|=0XF0;
      PORTD&=~0X10;
      boton= (!(PIND & 0XF0)) & 0XF0;
      switch (boton){

        case 0X10:
        _delay_ms(100);
        cuenta=1;        
        break;


      }
  }
}
}

