 #ifndef REG_H
 #define REG_H

#define F_CPU 16000000UL

#define DIO_PORTA_REG *((volatile u8 *)(0x3B))
#define DIO_DDRA_REG  *((volatile u8 *)(0x3A))
#define DIO_PINA_REG  *((volatile u8 *)(0x39))

/* I/O regsters for Port B */
#define DIO_PORTB_REG *((volatile u8 *)(0x38))
#define DIO_DDRB_REG  *((volatile u8 *)(0x37))  
#define DIO_PINB_REG  *((volatile u8 *)(0x36))

/* I/O regsters for Port C */
#define DIO_PORTC_REG *((volatile u8 *)(0x35))
#define DIO_DDRC_REG  *((volatile u8 *)(0x34))
#define DIO_PINC_REG  *((volatile u8 *)(0x33))

/* I/O regsters for Port D */
#define DIO_PORTD_REG *((volatile u8 *)(0x32))
#define DIO_DDRD_REG  *((volatile u8 *)(0x31))
#define DIO_PIND_REG  *((volatile u8 *)(0x30))

//$3F ($5F) SREG

#define SREG_REG    *((volatile u8* )(0x5F))
#define GIE_BIT     7
#define EXTI_GICR_REG        *((volatile u8* )(0x5B))
#define EXTI_GICR_INT1       7
#define EXTI_GICR_INT0       6
#define EXTI_GICR_INT2       5
#define EXTI_GIFR_REG        *((volatile u8* )(0x5A))
#define EXTI_GIFR_INTF1      7
#define EXTI_GIFR_INTF0      6
#define EXTI_GIFR_INTF2      5
#define EXTI_MCUCR_REG       *((volatile u8* )(0x55))
#define EXTI_MCUCR_ISC00     0
#define EXTI_MCUCR_ISC01     1
#define EXTI_MCUCR_ISC10     2
#define EXTI_MCUCR_ISC11     3
#define EXTI_MCUCSR_REG      *((volatile u8* )(0x54))
#define EXTI_MCUCSR_ISC2     6

/**************************ADC Reg ***************************/


/*ADC Multiplexer Register */
#define ADC_ADMUX_REG        *((volatile u8* )(0x27))
#define ADC_ADMUX_REFS1      7
#define ADC_ADMUX_REFS0      6
#define ADC_ADMUX_ADLAR      5

/*ADC Control Register */

#define ADC_ADCSRA_REG       *((volatile u8* )(0x26))
#define ADC_ADCSRA_ADEN      7
#define ADC_ADCSRA_ADSC      6
#define ADC_ADCSRA_ADATE     5
#define ADC_ADCSRA_ADIF      4
#define ADC_ADCSRA_ADIE      3
#define ADC_ADCSRA_ADPS2     2
#define ADC_ADCSRA_ADPS1     1
#define ADC_ADCSRA_ADPS0     0

/*ADC Data Register */

#define ADC_ADC_REG          *((volatile u16*)(0x24))
#define ADC_ADCL_REG         *((volatile u8* )(0x24))
#define ADC_ADCH_REG         *((volatile u8* )(0x25))

/* ADC Reference Voltage Options */

#define ADC_REF_AREF        0
#define ADC_REF_AVCC (1 << ADC_ADMUX_REFS0)
#define ADC_REF_INTERNAL  ((1<<ADC_ADMUX_REFS1)|(1<<ADC_ADMUX_REFS0))

/*******TIMER 0 Registers ****/

#define TIMER0_OCR0_REG            *((volatile u8* )(0x5C))
#define TIMER0_TIMSK_REG           *((volatile u8* )(0x59))
#define TIMER0_TIMSK_TOIE0         0
#define TIMER0_TIMSK_OCIE0         1
#define TIMER0_TIFR_REG            *((volatile u8* )(0x58))
#define TIMER0_TIFR_TOV0           0
#define TIMER0_TCCR0_REG          *((volatile u8* )(0x53))
#define TIMER0_TCCR0_FOC0          7
#define TIMER0_TCCR0_WGM00         6
#define TIMER0_TCCR0_COM01         5
#define TIMER0_TCCR0_COM00         4
#define TIMER0_TCCR0_WGM01         3
#define TIMER0_TCNT0_REG          *((volatile u8* )(0x52))
#define TIMER0_TIFR_TOV0       0
#define TIMER0_TIFR_OCF0       1

/*******TIMER 1 Registers ****/
#define TIMER1_TCCR1A_REG       *((volatile u8* )(0x4F))
#define TIMER1_TCCR1B_REG       *((volatile u8* )(0x4E))
#define TIMER1_TCNT1_REG        *((volatile u16*)(0x4C))
#define TIMER1_OCR1A_REG        *((volatile u16*)(0x4A))
#define TIMER1_OCR1B_REG        *((volatile u16*)(0x48))
#define TIMER1_ICR1_REG         *((volatile u16*)(0x46))

/************************* SPI Registers **************/

#define SPI_DATA_REG          *((volatile u8* )(0x2f))   /*spi data Register */
#define SPI_CTRL_REG          *((volatile u8* )(0x2D))   /*spi Control Register*/
#define SPI_CTRL_SPIE          7
#define SPI_CTRL_SPE           6
#define SPI_CTRL_DORD          5
#define SPI_CTRL_MSTR          4
#define SPI_CTRL_CPOL          3
#define SPI_CTRL_CPHA          2
#define SPI_CTRL_SPR1          1
#define SPI_CTRL_SPR0          0
#define SPI_STAT_REG          *((volatile u8* )(0x2E))  /*Spi Status Register */
#define SPI_STAT_SPIF         7
#define SPI_STAT_WCOL         6
#define SPI_STAT_SPI2X        0

/**************************************USART *******************/

#define UART_UDR_REG          *((volatile u8 *)(0x2c))
#define UART_UCSRA_REG        *((volatile u8 *)(0x2B))
#define UART_UCSRB_REG        *((volatile u8 *)(0x2A))
#define UART_UCSRC_REG        *((volatile u8 *)(0x40))
#define UART_UBRRH_REG        *((volatile u8 *)(0x40))
#define UART_UBRRL_REG        *((volatile u8 *)(0x29))
#define UART_RXC  7
#define UART_TXC  6
#define UART_UDRE 5
#define UART_FE   4
#define UART_DOR  3
#define UART_PE   2
#define UART_U2X  1
#define UART_MPCM 0
#define UART_RXCIE   7
#define UART_TXCIE   6
#define UART_UDRIE   5
#define UART_RXEN    4
#define UART_TXEN    3
#define UART_UCSZ2   2
#define UART_RXB8    1
#define UART_TXB8    0
#define UART_URSEL   7
#define UART_UMSEL   6
#define UART_UPM1    5
#define UART_UPM0    4
#define UART_USBS    3
#define UART_UCSZ1   2
#define UART_UCSZ0   1
#define UART_UCPOL   0

/*********************************** TWI Registers *************************/

#define TWI_STATUS_REG             *((volatile u8* )(0x21))
#define TWI_STATUS_TWPS0           0
#define TWI_STATUS_TWPS1           1
#define TWI_ADDRESS_REG            *((volatile u8* )(0x22))
#define TWI_ADDRESS_TWGCE          0
#define TWI_BIT_RATE_REG           *((volatile u8* )(0x20))
#define TWI_Data_REG               *((volatile u8* )(0x23))
#define TWI_CTRL_REG               *((volatile u8* )(0x56))
#define TWI_CTRL_TWINT              7
#define TWI_CTRL_TWEA               6
#define TWI_CTRL_TWSTA              5
#define TWI_CTRL_TWSTO              4
#define TWI_CTRL_TWWC               3
#define TWI_CTRL_TWEN               2
#define TWI_CTRL_TWIE               0

/************************** Begin internal EEprom Registers ****************/

#define IN_EEPROM_DATA_REG              *((volatile u8* )(0x3D))
#define IN_EEPROM_EARL_REG *((volatile u8*)(0x3E))
#define IN_EEPROM_EARH_REG *((volatile u8*)(0x3F))
#define IN_EEPROM_CTRL_REG              *((volatile u8* )(0x3C))
#define IN_EEPROM_CTRL_EERE              0
#define IN_EEPROM_CTRL_EEWE              1
#define IN_EEPROM_CTRL_EEMWE             2
#define IN_EEPROM_CTRL_EERIE             3

/************************** End internal EEprom Registers ****************/
#endif
