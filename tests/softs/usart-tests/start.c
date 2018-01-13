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
#include "map.h"
// #include <nvic.h>

/* Strange declarations as the addresses of these contain the values
* computed into the ldscript
*/
extern uint32_t edata, end, stack_top;

void __start(void)
{

  uint32_t i=0,j;

  volatile uint32_t *usart1_CR1_p =(uint32_t *) (USART1_BASE + USART_CR1_OFS);  //pointeur vers CR1 de usart1
  volatile uint32_t *usart1_TDR_p =(uint32_t *) (USART1_BASE + USART_DR_OFS);  //pointeur vers CR1 de usart1
  volatile uint32_t *usart1_SR_p =(uint32_t *) (USART1_BASE + USART_SR_OFS);  //pointeur vers CR1 de usart1
  volatile uint32_t *usart1_BRR_p =(uint32_t *) (USART1_BASE + USART_BRR_OFS);  //pointeur vers CR1 de usart1

  //Envoi de 0x15 depuis usart1
   //
   //
   // NVIC_Init();
   // NVIC_EnableInterrupt(NVIC_USART1);

  *usart1_BRR_p = 12 | (27 << 4); //USARTDIV= 27,75

  *usart1_CR1_p = *usart1_CR1_p | 1<<TE_POS     //mise à 1 de TE, declanche une frame idle
                                | 1<<TXIE_POS;  //mise a 1 de TXIE, activation des interruption sur TXE: irq quand copie des data dans SR ok.
  //
  // for(i=0; i<6; i++){

    *usart1_TDR_p = i++; //on met dans TDR la valeur 21 / 0x15, should clear TXE
  //
  //   while (!((*usart1_SR_p >> TXE_POS) & 1)){ //wait until TXE=1, data as been copied in shift register
  //     asm("wfi"); //wait for interrupt, easy way
  //   }
  // }
  //
  // while (!((*usart1_SR_p >> TC_POS) &1)); //wait until TC=1
  //
  // *usart1_CR1_p = *usart1_CR1_p & ~(1<<TE_POS); //remise à 0 de TE, fin de transmission
  //
  // *usart1_TDR_p = 0x12; //on met dans TDR la valeur 21 / 0x15, should clear TXE
  // *usart1_CR1_p = *usart1_CR1_p | 1<<TE_POS; //mise à 1 de TE, declanche une frame idle
  // while (!((*usart1_SR_p >> TC_POS) &1)); //wait until TC=1
  // *usart1_CR1_p = *usart1_CR1_p & ~(1<<TE_POS); //remise à 0 de TE, fin de transmission
  // *usart1_CR1_p = *usart1_CR1_p |  (1<<RE_POS); //remise à 0 de TE, fin de transmission
  //
  //
  //   //Envoi de 0x7 depuis usart2
  //
  // *usart2_TDR_p = (uint32_t) 0b111; //on met dans TDR la valeur 7 / 0x7
  //
  // *usart2_CR1_p = *usart2_CR1_p | 1<<TE_POS; //mise à 1 de TE, declanche une transmission
  //
  // *usart2_CR1_p = *usart2_CR1_p & ~(1<<TE_POS); //remise à 0 de TE, fin de transmission


  //Envoi de 0x15 depuis usart1
  //
  // *usart1_TDR_p = (uint32_t) 0b1010101; //on met dans TDR la valeur 21 / 0x15
  //
  // *usart1_CR1_p = *usart1_CR1_p | 1<<TE_POS; //mise à 1 de TE, declanche une transmission
  //
  // *usart1_CR1_p = *usart1_CR1_p & ~(1<<TE_POS); //remise à 0 de TE, fin de transmission
  //
  // //for(i; i< 0xFFFF ; i++);    //petite attente ~12ms
  //
  // *usart1_CR1_p |=  1<<M_POS
  //                 | 1<<PCE_POS; //mise à 1 de M, mode 9 bits
  //

  //  *addr = 0x0;



  //  /* Zeroes bss the bad old way */
  //  for (addr = &edata; addr < &end; addr++)
  //     *addr = 0;
  //
  //  /* Go thru SRAM, between the end of bss and the stack bottom, and poke a value */
  //  register uint32_t *sp;
  //  __asm__ volatile ("mrs %0, msp" : "=r"(sp));
  //
  //  for (addr = &end; addr < sp; addr++)
  //     *addr = 0xdeadbeef;
  //
  //  addr = (uint32_t *)0xdeadcell;
  //  *addr++ = 0xbaaaaaad;
  //  *addr++ = 0xbaaaaaad;
}






                            // cpsid i
                            //
                            // push {R1,R2,R3,R4}
                            //
                            // @movw R1, #0x1000          @ LSB address of SR register of USART1
                            // @movt R1, #0x4001          @ MSB address of SR register of USART1
                            // @ldr R2, [R1,#0]
                            // @mov R3, #0b10000000
                            // @mvn R3, R3
                            // @and R2, R2, R3
                            // @str R2, [R1,#0]           @ Reset the TXE flags
                            //
                            //
                            // movw R4, #0x1000          @ LSB address of DR register of USART1
                            // movt R4, #0x2000          @ LSB address of DR register of USART1
                            //
                            // movw R1, #0x1004          @ LSB address of DR register of USART1
                            // movt R1, #0x4001          @ MSB address of DR register of USART1
                            // ldr R2, [R1,#0]
                            // ldr R3, [R4,#0]
                            // add R2, R3, #1
                            // mov R3, R2
                            // str R2 ,[R1,#0]                   @ at the end DR=DR+1
                            // str R3 ,[R4,#0]                   @ at the end DR=DR+1
                            // pop  {R1,R2,R3,R4}
                            // cpsie i
                            // bx R14
