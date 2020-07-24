/* 
 * File:   ports.h
 * Author: Sergio
 *
 * Created on 19 de julio de 2020, 10:40 PM
 */

#ifndef PORTS_H
#define	PORTS_H

// CONSTANTES, MACROS Y FUNCIONES PARA LOS PUERTOS DE ENTRADA Y SALIDA DIGITALES

#ifdef	__cplusplus
extern "C" {
#endif

#define set_all_digital()   ADCON1 = 0x06
#define rol_8(value, b)     value = (value << b) | (value >> (8 - b))
#define ror_8(value, b)     value = (value >> b) | (value << (8 - b))
#define bit_set(value, b)   value = value | (1 << b)
#define bit_clear(value, b) value = value & (~(1 << b))

#ifdef	__cplusplus
}
#endif

#endif	/* PORTS_H */

