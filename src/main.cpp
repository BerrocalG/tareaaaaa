//bassetarea calculadora
#define F_CPU 16000000UL  
#include <avr/io.h>  
#include <util/delay.h>

int main(void) {
  DDRD|=0xF0; //matrizcolumna
  DDRD&= ~0X0F; //matriz fila
  PORTD |= 0x0F;    // en up fila

  DDRB|=0X0F; //codificador
  DDRC|=0X07; //A0 A1 A2 display
  DDRC|=0X08; //A3 led

  char filas;
  
  while(1){
    //centenas display
    PORTC&=~(0X01);
    PORTC&=~(0X02);
    PORTC|=0X04;
 
    _delay_ms(8);
    //decenas display
    PORTC&=~(0X01);
    PORTC&=~(0X04);
    PORTC|=0X02;
    

    _delay_ms(8);
    //unidades display
    PORTC&=~(0X04);
    PORTC&=~(0X02);
    PORTC|=0X01;
    
    
    _delay_ms(8);

    PORTD |= 0xF0;    // Todas las columnas en high
    PORTD &= ~0x10;   // Activar solo columna 0 (PD4 en LOW)
    _delay_us(5);     // 
    filas = PIND & 0x0F; // Leemos solo las filas (PD0–PD3)

    switch (filas){
      case 0x0E: // fila 1
      PORTB=0x01;
      break;

      case 0x0D: // fila 1
      PORTB=0x02; //2
      break;

      case 0x0B: // fila 1
      PORTB=0x03; //3
      break;

      case 0x07: // fila 1
      PORTB=0x04; //3
      break;
  
  }
}
}

