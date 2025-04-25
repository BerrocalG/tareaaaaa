//bassetarea calculadora
#define F_CPU 16000000UL  
#include <avr/io.h>  
#include <util/delay.h>

int main(void) {
  DDRB|=0x0F; //matrizcolumna
  DDRC&= ~0X0F; //matriz fila
  PORTC |= 0x0F;    // en up fila

  DDRD|=0XF0; //codificador
  DDRB|=0X30; //D(13) C(12)
  DDRC|=0X10; //U


  char filas;
  char cuenta=0;

  while(1){
    //centenas display
    PORTC&=~(0X10); //unidades display
    PORTB&=~(0X20); //decenas display
    PORTB|=0X10; //centenas display
    PORTD = (PORTD & 0x0F) | ((cuenta / 100) << 4);
    _delay_ms(8);

    //UNIDADES display
    PORTB&=~(0X20); //d
    PORTB&=~(0X10); //c
    PORTC|=0X10; //u
    PORTD = (PORTD & 0x0F) | ((cuenta % 10) << 4);
    _delay_ms(8);

    //DECENAS display
    PORTB&=~(0X10); //c
    PORTC&=~(0X10); //U
    PORTB|=0X20; //D
    PORTD = (PORTD & 0x0F) | ((cuenta / 10) << 4);
    _delay_ms(8);

    PORTB |= 0x0F;    // Todas las columnas en high
    PORTB &= ~0x01;   // Activar solo columna 0 (PD4 en LOW)
    _delay_us(5);     // 
    filas = PINC & 0x0F; // Leemos solo las filas (PD0–PD3)

    switch (filas){
      case 0x0E: // fila 1
      cuenta=1;      
      break;

      case 0x0D: // fila 1
      cuenta=2;      
      break;

      case 0x0B: // fila 1
      cuenta=3; //3
      break; 
  }

  //FILA2
    PORTB |= 0x0F;    // Todas las columnas en high
    PORTB &= ~0x02;   // Activar solo columna 0 (PD4 en LOW)
    _delay_us(5);     // 
    filas = PINC & 0x0F; // Leemos solo las filas (PD0–PD3)

    switch (filas){
      case 0x0E: // fila 1
      cuenta=4;
      break;

      case 0x0D: // fila 1
      cuenta=5; //2
      break;

      case 0x0B: // fila 1
      cuenta=6; //3
      break;
    }


      //FILA3
    PORTB |= 0x0F;    // Todas las columnas en high
    PORTB &= ~0x04;   // Activar solo columna 0 (PD4 en LOW)
    _delay_us(5);     // 
    filas = PINC & 0x0F; // Leemos solo las filas (PD0–PD3)

    switch (filas){
      case 0x0E: // fila 1
      cuenta=7;
      break;

      case 0x0D: // fila 1
      cuenta=8; //2
      break;

      case 0x0B: // fila 1
      cuenta=9; //3
      break;  
  }
  //FILA 4
    PORTB |= 0x0F;    // Todas las columnas en high
    PORTB &= ~0x08;   // Activar solo columna 0 (PD4 en LOW)
    _delay_us(5);     // 
    filas = PINC & 0x0F; // Leemos solo las filas (PD0–PD3)

    switch (filas){
      
      case 0x0D: // fila 1
      cuenta=0; //2
      break;
  }
         
  }
}


