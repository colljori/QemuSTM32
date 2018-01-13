#define USART1_BASE     0x40011000
#define USART2_BASE     0x40004400
#define USART6_BASE     0x40011400


#define USART_SR_OFS    0x00
#define USART_DR_OFS    0x04
#define USART_BRR_OFS   0x08
#define USART_CR1_OFS   0x0C
#define USART_CR2_OFS   0x10
#define USART_CR3_OFS   0x14
#define USART_GTPR_OFS  0x18

#define RXNE_POS        5


///////////////////////////////////////////USART_SR bit access
// bit num USART_SR
#define CTS_POS                 9
#define LBD_POS                 8
#define TXE_POS                 7
#define TC_POS                  6
#define RXNE_POS                5
#define IDLE_POS                4
#define ORE_POS                 3
#define NF_POS                  2
#define FE_POS                  1
#define PE_POS                  0

///////////////////////////////////////////USART_CR1 bit access
// bit num USART_CR1
#define OVER8_POS               15
#define UE_POS                  13
#define M_POS                   12
#define WAKE_POS                11
#define PCE_POS                 10
#define PS_POS                  9
#define PEIE_POS                8
#define TXIE_POS                7
#define TCIE_POS                6
#define RXNEIE_POS              5
#define IDLEIE_POS              4
#define TE_POS                  3
#define RE_POS                  2
#define RWU_POS                 1
#define SBK_POS                 0

///////////////////////////////////////////USART_CR2 bit access
// bit num USART_CR2
#define LINEN_POS               14
#define STOP1_POS               13
#define STOP0_POS               12
#define CLKEN_POS               11
#define CPOL_POS                10
#define CPHA_POS                9
#define LBCL_POS                8
#define LBDIE_POS               6
#define LBLD_POS                5
#define ADD3_POS                3
#define ADD2_POS                2
#define ADD1_POS                1
#define ADD0_POS                0

///////////////////////////////////////////USART_CR3 bit access
// bit num USART_CR3
#define ONEBIT_POS              11
#define CTSIE_POS               10
#define CTSE_POS                9
#define RTSE_POS                8
#define DMAT_POS                7
#define DMAR_POS                6
#define SCEN_POS                5
#define NACK_POS                4
#define HDSEL_POS               3
#define IRLP_POS                2
#define IREN_POS                1
#define EIE_POS                 0
