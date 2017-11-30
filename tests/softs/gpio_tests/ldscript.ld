MEMORY
{ 
  /* As defined in the data-sheet, assuming remapping of flash */
  FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 512K
  SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 96K
}

SECTIONS
{
    . = 0x0;
    .text :
    {
        *(.isr_vector_table)
        vectors.o(.text*)
        *(.text*)
        etext = .;
    } > FLASH

    .data :
    {
        *(.data*)
    } > SRAM

    /* End of data */

    /* Blank static storage to be cleared on startup */
    .bss :
    {
        . = ALIGN(4);
        edata = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        end = .;
    } > SRAM


    /* Compute stack address as a function of SRAM */
    sram_base_addr = ORIGIN(SRAM);
    sram_length = LENGTH(SRAM);
    stack_top = sram_base_addr + sram_length;
}
