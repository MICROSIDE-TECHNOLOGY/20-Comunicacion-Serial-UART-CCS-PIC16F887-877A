/************************************************************************************************
Company:
Microside Technology Inc.
File Name:
Comunicaci�n Serial.c
Product Revision  :  1
Device            :  X-TRAINER
Driver Version    :  1.0
************************************************************************************************/

/*
------------------------------------------------------------------------------
 Implementar comunicaci�n serial para enviar un comando simple para prender y
 apagar un LED incluido en la tarjeta X-TRAINER, y un segundo comando para
 preguntar el estado de un bot�n.
------------------------------------------------------------------------------
*/

#include <16F877A.h>                  //Incluye el microcontrolador con el que se va a trabajar
#use delay( clock = 20Mhz, crystal )  // Tipo de oscilador y frecuencia dependiendo del microcontrolador

#use rs232( baud = 9600, xmit = PIN_C6, rcv = PIN_C7, STREAM = UART ) // Configuraci�n del puerto UART

#define LED PIN_A1                    // Pin donde est� conectado el LED del X-TRAINER
#define Boton PIN_A2                  // Pin donde est� conectado el BOTON del X-TRAINER

void main( void ) {

   while ( 1 ) {
      char Caracter = getc();         // Guarda el caracter
      
      if ( Caracter == '0' ) {
         output_low( LED );           // Apaga el LED
      } else if ( Caracter == '1' ) {
         output_HIGH( LED );          // Enciende el LED
      } else if ( Caracter == '?' ) {

         if ( 1 == input( Boton ) ) { // Pregunta el estado del bot�n
            Printf( "0" );            // Env�a un 0 si el bot�n no est� presionado
         } else {
            Printf( "1" );            // Env�a un 1 si el bot�n est� presionado
         }
      }
   }
}