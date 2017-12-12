/*
 * This file is part of not much, if not nothing
 * Copyright (C) 2017  Frédéric Pétrot
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

/* No much to include yet :) */

#include <stdint.h>
#include <timer.h>
#include <gpio.h>

/* Strange declarations as the addresses of these contain the values
 * computed into the ldscript
 */
extern uint32_t edata, end, stack_top;

void __start(void)
{
   volatile uint32_t *addr;

   /* Zeroes bss the bad old way */
   for (addr = &edata; addr < &end; addr++)
      *addr = 0;

   /* Go thru SRAM, between the end of bss and the stack bottom, and poke a value */
   register uint32_t *sp;
   __asm__ volatile ("mrs %0, msp" : "=r"(sp));


   /* Tests instruction */
   /*
    * ________TEST LECTURE/ECRITURE SUR ODR________
    *
    */
   /* Ecriture de la valeur 5 sur l'entrée du port A
    * puis lecture de cette valeur.
    */
#if 0
   volatile uint32_t* p = (uint32_t*) 0x40020000;//addr base port A (MODER)
   *p = 0x00000000; // mode input
   p += 5; //base+5 = registre ODR (Output Data Register)
   *p = (uint32_t) 5; // écriture de 5 dans registre ODR 
   p = (uint32_t*) 0x40020000;// adresse de base port A
   *p = (uint32_t) 0b0101010101010101; // mode ouput
   p += 5;
   volatile uint32_t q = *p;
   /* vérification bon fonctionnement read ODR
    */
   p = (uint32_t*) 0x40020000;// adresse de base port A
   *p = (uint32_t) 0b0101010101010111; // erreur sur le 2ème bit
   p += 5;
   q = *p; // valeur attendu != 5
#endif
   /* 
    * Tests utilisant la lib externe
    */
   /* Initialize a pin init structure containing pins, mode, pupd,
    * speed, otype and af.
    */
   gpio_init_t struct_init;
   GPIO_StructInit(&struct_init);
    
   // Initialize a GPIO port with all its register
   gpio_t* gpio_a = GPIOA;
   GPIO_Init(gpio_a, &struct_init);
   uint16_t pin_state = GPIO_GetPins(gpio_a);
}
