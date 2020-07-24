#include <htc.h>        // Incluimos libreria del micro a usar
#include "ports.h"

#define _XTAL_FREQ 4000000      // Oscilador interno de 4MHz
__CONFIG(WRT_OFF & WDTE_OFF & PWRTE_OFF & FOSC_XT & LVP_OFF);   // Configuracion del PIC

// Variables
bit CAMBIAR = 0;    // Flag para cambiar la secuencia de los LED

unsigned char SECUENCIA1 = 0x11;    // Secuencia 1 empieza con LED D0 encendido
unsigned char SECUENCIA2 = 0x09;    // Secuencia 2 empieza con LEDs D3-D0 encendidos

// PROGRAMA PRINCIPAL
void main()
{
    // INICIALIZACIONES PARA EL PIC
    set_all_digital();      // Desactivamos PORTA como entradas analógicas
    
    TRISA = 0x10;           // PORTA con RA4 como entrada y resto como salidas
    TRISB = 0x00;           // PORTB con todos los terminales de salida.
    
    while(1)
    {
        if (RA4 == 0){              // Se ha presionado el pulsador
            CAMBIAR = ~CAMBIAR;     // Cambiar secuencia
        }
        if (CAMBIAR == 0){
            PORTB = SECUENCIA1;
            __delay_ms(500);        // Esperar 500 ms
            rol_8(SECUENCIA1, 1);   // Rotar un bit a la izquierda en SECUENCIA1
        } else {
            PORTB = SECUENCIA2;
            __delay_ms(500);            // Espera 500 ms
            SECUENCIA2 = ~SECUENCIA2;   // Cambiar LED encendidos en SECUENCIA2
        }
    }
}