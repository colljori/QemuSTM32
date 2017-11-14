# This file is part of not much, if not nothing
# Copyright (C) 2017  Frédéric Pétrot
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

# Vector table copied from ST Microelectronic RM0368 Reference manual
# "DocID025350 Rev 4", pages 201-204
#

.section ".isr_vector_table", "x" 
/* At boot time, sp and pc are assumed to be there */
.word stack_top                  @ 0x00000000
.word Reset_handler              @ 0x00000004
.word NMI_handler                @ 0x00000008
.word HardFault_handler          @ 0x0000000C
.word MemManage_handler          @ 0x00000010
.word BusFault_handler           @ 0x00000014
.word UsageFault_handler         @ 0x00000018
.word Reserved1_handler          @ 0x0000001C
.word Reserved2_handler          @ 0x00000020
.word Reserved3_handler          @ 0x00000024
.word Reserved4_handler          @ 0x00000028
.word SVCall_handler             @ 0x0000002C
.word Monitor_handler            @ 0x00000030
.word Reserved5_handler          @ 0x00000034
.word PendSV_handler             @ 0x00000038
.word Systick_handler            @ 0x0000003C
.word WWDG_handler               @ 0x00000040
.word EXTI16_PVD_handler         @ 0x00000044
.word EXTI21_TAMP_STAMP_handler  @ 0x00000048
.word EXTI22_RTC_WKUP_handler    @ 0x0000004C
.word FLASH_handler              @ 0x00000050
.word RCC_handler                @ 0x00000054
.word EXTI0_handler              @ 0x00000058
.word EXTI1_handler              @ 0x0000005C
.word EXTI2_handler              @ 0x00000060
.word EXTI3_handler              @ 0x00000064
.word EXTI4_handler              @ 0x00000068
.word DMA1_Stream0_handler       @ 0x0000006C
.word DMA1_Stream1_handler       @ 0x00000070
.word DMA1_Stream2_handler       @ 0x00000074
.word DMA1_Stream3_handler       @ 0x00000078
.word DMA1_Stream4_handler       @ 0x0000007C
.word DMA1_Stream5_handler       @ 0x00000080
.word DMA1_Stream6_handler       @ 0x00000084
.word ADC_handler                @ 0x00000088
.word Reserved6_handler          @ 0x0000008C
.word Reserved7_handler          @ 0x00000090
.word Reserved8_handler          @ 0x00000094
.word Reserved9_handler          @ 0x00000098
.word EXTI9_5_handler            @ 0x0000009C
.word TIM1_BRK_TIM9_handler      @ 0x000000A0
.word TIM1_UP_TIM10_handler      @ 0x000000A4
.word TIM1_TRG_COM_TIM11_handler @ 0x000000A8
.word TIM1_CC_handler            @ 0x000000AC
.word TIM2_handler               @ 0x000000B0
.word TIM3_handler               @ 0x000000B4
.word TIM4_handler               @ 0x000000B8
.word I2C1_EV_handler            @ 0x000000BC
.word I2C1_ER_handler            @ 0x000000C0
.word I2C2_EV_handler            @ 0x000000C4
.word I2C2_ER_handler            @ 0x000000C8
.word SPI1_handler               @ 0x000000CC
.word SPI2_handler               @ 0x000000D0
.word USART1_handler             @ 0x000000D4
.word USART2_handler             @ 0x000000D8
.word Reserved10_handler         @ 0x000000DC
.word EXTI15_10_handler          @ 0x000000E0
.word EXTI17_RTC_Alarm_handler   @ 0x000000E4
.word EXTI18_OTG_FS_WKUP_handler @ 0x000000E8
.word Reserved11_handler         @ 0x000000EC
.word Reserved12_handler         @ 0x000000F0
.word Reserved13_handler         @ 0x000000F4
.word Reserved14_handler         @ 0x000000F8
.word DMA1_Stream7_handler       @ 0x000000FC
.word Reserved15_handler         @ 0x00000100
.word SDIO_handler               @ 0x00000104
.word TIM5_handler               @ 0x00000108
.word SPI3_handler               @ 0x0000010C
.word Reserved16_handler         @ 0x00000110
.word Reserved17_handler         @ 0x00000114
.word Reserved18_handler         @ 0x00000118
.word Reserved19_handler         @ 0x0000011C
.word DMA2_Stream0_handler       @ 0x00000120
.word DMA2_Stream1_handler       @ 0x00000124
.word DMA2_Stream2_handler       @ 0x00000128
.word DMA2_Stream3_handler       @ 0x0000012C
.word DMA2_Stream4_handler       @ 0x00000130
.word Reserved20_handler         @ 0x00000134
.word Reserved21_handler         @ 0x00000138
.word Reserved22_handler         @ 0x0000013C
.word Reserved23_handler         @ 0x00000140
.word Reserved24_handler         @ 0x00000144
.word Reserved25_handler         @ 0x00000148
.word OTG_FS_handler             @ 0x0000014C
.word DMA2_Stream5_handler       @ 0x00000150
.word DMA2_Stream6_handler       @ 0x00000154
.word DMA2_Stream7_handler       @ 0x00000158
.word USART6_handler             @ 0x0000015C
.word I2C3_EV_handler            @ 0x00000160
.word I2C3_ER_handler            @ 0x00000164
.word Reserved26_handler         @ 0x00000168
.word Reserved27_handler         @ 0x0000016C
.word Reserved28_handler         @ 0x00000170
.word Reserved29_handler         @ 0x00000174
.word Reserved30_handler         @ 0x00000178
.word Reserved31_handler         @ 0x0000017C
.word Reserved32_handler         @ 0x00000180
.word FPU_handler                @ 0x00000184
.word Reserved33_handler         @ 0x00000188
.word Reserved34_handler         @ 0x0000018C
.word SPI4_handler               @ 0x00000190

.text
/* All these *must* be thumb code */
.thumb_func
NMI_handler:                b NMI_handler                @ self loop for now
.thumb_func
HardFault_handler:          b HardFault_handler          @ self loop for now
.thumb_func
MemManage_handler:          b MemManage_handler          @ self loop for now
.thumb_func
BusFault_handler:           b BusFault_handler           @ self loop for now
.thumb_func
UsageFault_handler:         b UsageFault_handler         @ self loop for now
.thumb_func
Reserved1_handler:          b Reserved1_handler          @ self loop for now
.thumb_func
Reserved2_handler:          b Reserved2_handler          @ self loop for now
.thumb_func
Reserved3_handler:          b Reserved3_handler          @ self loop for now
.thumb_func
Reserved4_handler:          b Reserved4_handler          @ self loop for now
.thumb_func
SVCall_handler:             b SVCall_handler             @ self loop for now
.thumb_func
Monitor_handler:            b Monitor_handler            @ self loop for now
.thumb_func
Reserved5_handler:          b Reserved5_handler          @ self loop for now
.thumb_func
PendSV_handler:             b PendSV_handler             @ self loop for now
.thumb_func
Systick_handler:            b Systick_handler            @ self loop for now
.thumb_func
WWDG_handler:               b WWDG_handler               @ self loop for now
.thumb_func
EXTI16_PVD_handler:         b EXTI16_PVD_handler         @ self loop for now
.thumb_func
EXTI21_TAMP_STAMP_handler:  b EXTI21_TAMP_STAMP_handler  @ self loop for now
.thumb_func
EXTI22_RTC_WKUP_handler:    b EXTI22_RTC_WKUP_handler    @ self loop for now
.thumb_func
FLASH_handler:              b FLASH_handler              @ self loop for now
.thumb_func
RCC_handler:                b RCC_handler                @ self loop for now
.thumb_func
EXTI0_handler:              b EXTI0_handler              @ self loop for now
.thumb_func
EXTI1_handler:              b EXTI1_handler              @ self loop for now
.thumb_func
EXTI2_handler:              b EXTI2_handler              @ self loop for now
.thumb_func
EXTI3_handler:              b EXTI3_handler              @ self loop for now
.thumb_func
EXTI4_handler:              b EXTI4_handler              @ self loop for now
.thumb_func
DMA1_Stream0_handler:       b DMA1_Stream0_handler       @ self loop for now
.thumb_func
DMA1_Stream1_handler:       b DMA1_Stream1_handler       @ self loop for now
.thumb_func
DMA1_Stream2_handler:       b DMA1_Stream2_handler       @ self loop for now
.thumb_func
DMA1_Stream3_handler:       b DMA1_Stream3_handler       @ self loop for now
.thumb_func
DMA1_Stream4_handler:       b DMA1_Stream4_handler       @ self loop for now
.thumb_func
DMA1_Stream5_handler:       b DMA1_Stream5_handler       @ self loop for now
.thumb_func
DMA1_Stream6_handler:       b DMA1_Stream6_handler       @ self loop for now
.thumb_func
ADC_handler:                b ADC_handler                @ self loop for now
.thumb_func
Reserved6_handler:          b Reserved6_handler          @ self loop for now
.thumb_func
Reserved7_handler:          b Reserved7_handler          @ self loop for now
.thumb_func
Reserved8_handler:          b Reserved8_handler          @ self loop for now
.thumb_func
Reserved9_handler:          b Reserved9_handler          @ self loop for now
.thumb_func
EXTI9_5_handler:            b EXTI9_5_handler            @ self loop for now
.thumb_func
TIM1_BRK_TIM9_handler:      b TIM1_BRK_TIM9_handler      @ self loop for now
.thumb_func
TIM1_UP_TIM10_handler:      b TIM1_UP_TIM10_handler      @ self loop for now
.thumb_func
TIM1_TRG_COM_TIM11_handler: b TIM1_TRG_COM_TIM11_handler @ self loop for now
.thumb_func
TIM1_CC_handler:            b TIM1_CC_handler            @ self loop for now
.thumb_func
TIM2_handler:               b TIM2_handler               @ self loop for now
.thumb_func
TIM3_handler:               b TIM3_handler               @ self loop for now
.thumb_func
TIM4_handler:               b TIM4_handler               @ self loop for now
.thumb_func
I2C1_EV_handler:            b I2C1_EV_handler            @ self loop for now
.thumb_func
I2C1_ER_handler:            b I2C1_ER_handler            @ self loop for now
.thumb_func
I2C2_EV_handler:            b I2C2_EV_handler            @ self loop for now
.thumb_func
I2C2_ER_handler:            b I2C2_ER_handler            @ self loop for now
.thumb_func
SPI1_handler:               b SPI1_handler               @ self loop for now
.thumb_func
SPI2_handler:               b SPI2_handler               @ self loop for now
.thumb_func
USART1_handler:             b USART1_handler             @ self loop for now
.thumb_func
USART2_handler:             b USART2_handler             @ self loop for now
.thumb_func
Reserved10_handler:         b Reserved10_handler         @ self loop for now
.thumb_func
EXTI15_10_handler:          b EXTI15_10_handler          @ self loop for now
.thumb_func
EXTI17_RTC_Alarm_handler:   b EXTI17_RTC_Alarm_handler   @ self loop for now
.thumb_func
EXTI18_OTG_FS_WKUP_handler: b EXTI18_OTG_FS_WKUP_handler @ self loop for now
.thumb_func
Reserved11_handler:         b Reserved11_handler         @ self loop for now
.thumb_func
Reserved12_handler:         b Reserved12_handler         @ self loop for now
.thumb_func
Reserved13_handler:         b Reserved13_handler         @ self loop for now
.thumb_func
Reserved14_handler:         b Reserved14_handler         @ self loop for now
.thumb_func
DMA1_Stream7_handler:       b DMA1_Stream7_handler       @ self loop for now
.thumb_func
Reserved15_handler:         b Reserved15_handler         @ self loop for now
.thumb_func
SDIO_handler:               b SDIO_handler               @ self loop for now
.thumb_func
TIM5_handler:               b TIM5_handler               @ self loop for now
.thumb_func
SPI3_handler:               b SPI3_handler               @ self loop for now
.thumb_func
Reserved16_handler:         b Reserved16_handler         @ self loop for now
.thumb_func
Reserved17_handler:         b Reserved17_handler         @ self loop for now
.thumb_func
Reserved18_handler:         b Reserved18_handler         @ self loop for now
.thumb_func
Reserved19_handler:         b Reserved19_handler         @ self loop for now
.thumb_func
DMA2_Stream0_handler:       b DMA2_Stream0_handler       @ self loop for now
.thumb_func
DMA2_Stream1_handler:       b DMA2_Stream1_handler       @ self loop for now
.thumb_func
DMA2_Stream2_handler:       b DMA2_Stream2_handler       @ self loop for now
.thumb_func
DMA2_Stream3_handler:       b DMA2_Stream3_handler       @ self loop for now
.thumb_func
DMA2_Stream4_handler:       b DMA2_Stream4_handler       @ self loop for now
.thumb_func
Reserved20_handler:         b Reserved20_handler         @ self loop for now
.thumb_func
Reserved21_handler:         b Reserved21_handler         @ self loop for now
.thumb_func
Reserved22_handler:         b Reserved22_handler         @ self loop for now
.thumb_func
Reserved23_handler:         b Reserved23_handler         @ self loop for now
.thumb_func
Reserved24_handler:         b Reserved24_handler         @ self loop for now
.thumb_func
Reserved25_handler:         b Reserved25_handler         @ self loop for now
.thumb_func
OTG_FS_handler:             b OTG_FS_handler             @ self loop for now
.thumb_func
DMA2_Stream5_handler:       b DMA2_Stream5_handler       @ self loop for now
.thumb_func
DMA2_Stream6_handler:       b DMA2_Stream6_handler       @ self loop for now
.thumb_func
DMA2_Stream7_handler:       b DMA2_Stream7_handler       @ self loop for now
.thumb_func
USART6_handler:             b USART6_handler             @ self loop for now
.thumb_func
I2C3_EV_handler:            b I2C3_EV_handler            @ self loop for now
.thumb_func
I2C3_ER_handler:            b I2C3_ER_handler            @ self loop for now
.thumb_func
Reserved26_handler:         b Reserved26_handler         @ self loop for now
.thumb_func
Reserved27_handler:         b Reserved27_handler         @ self loop for now
.thumb_func
Reserved28_handler:         b Reserved28_handler         @ self loop for now
.thumb_func
Reserved29_handler:         b Reserved29_handler         @ self loop for now
.thumb_func
Reserved30_handler:         b Reserved30_handler         @ self loop for now
.thumb_func
Reserved31_handler:         b Reserved31_handler         @ self loop for now
.thumb_func
Reserved32_handler:         b Reserved32_handler         @ self loop for now
.thumb_func
FPU_handler:                b FPU_handler                @ self loop for now
.thumb_func
Reserved33_handler:         b Reserved33_handler         @ self loop for now
.thumb_func
Reserved34_handler:         b Reserved34_handler         @ self loop for now
.thumb_func
SPI4_handler:               b SPI4_handler               @ self loop for now
.thumb_func
/* Let's go for the real stuff now */
.thumb_func
Reset_handler:              bl __start
1:                          b 1
