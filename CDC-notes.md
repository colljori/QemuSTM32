# Notes pour le cahier des charges 

## Architecture
page 14

Multi-AHB bus matrix: 32bits. Connects Master ( CPUs, DMAS) to slaves ( flash, SRAM, AHB, APB perif)
 * Connexions entre slaves master page 17

DMA -> acces à la mémoire et préf sans passer par CPU ( pas prioritaire ) 

## Memory 

**Flash**
 * 512 Kbytes ( storing programs and data )
 * Connected with accel/cache ( 2 entrèes AHB Bus-matrix 7S4M)
   - 64 cache lines of 128 bits on I-Code
   - 8 cache lines of 128 bits on D-Code
 * Adaptative Real Time Accelerator 
  - Instruction fetch ....

**SRAM**
 * 96 Kbytes 
 * access (read/write) CPU clock speed with 0 wait states


Mappage page 51 datasheet
 
## Reset 
A system reset is generated when one of the following events occurs:
1. A low level on the NRST pin (external reset)
2. Window watchdog end of count condition (WWDG reset)
3. Independent watchdog end of count condition (IWDG reset)
4. A software reset (SW reset) (see Software reset)
5. Low-power management reset (see Low-power management reset)
 
## Interruptions 

* 16 lvl de priorité
* 62 interrup maskable + 16 interrupt lines du CPU ( kesako ? )
* vector table

## Clock 
  * 2 types de clocks : RC oscillator interne à 16 MHz ou clock extern 4-26 MHz
  * Si fail de clock externe :  interrupt puis passage à clock interne

## Boot mode 
 * boot pins pour select modes : user Flash / system memory / embedded SRAM
 * boot loader ds system memory 


## Software 

### Bootloader

Pattern 1: Boot0(pin) = 1 and Boot1(pin) = 0
Create DFU ? 

### LEDs

LD2: activer avec le pin D13 du core = pin stm PA5 avec function SPI1_SCK  function ????? 


TODO: trouver le set d'instruction basique et faire qq programs
