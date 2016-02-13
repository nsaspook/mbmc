#include "hwconf.h"

void config_pic(uint16_t hw_config)
{
	static int8_t z;
	if (hw_config == 8722u) {
		_asm nop _endasm // asm code to disable compiler optimizations
		/* set these boot bits so we can check for rests later */
		RCONbits.BOR = 1;
		RCONbits.POR = 1;
		if (RCONbits.TO == (uint8_t) LOW) WDT_TO = TRUE;
		if (EECON1bits.WRERR && (EECON1bits.EEPGD == (uint8_t) LOW)) EEP_ER = TRUE;
		/* Configure all PORT  pins  */

		ADCON1 = 0x03; // adc [0..11] enable

		TRISAbits.TRISA4 = LOW; // output, SD card power enable
		TRISAbits.TRISA0 = HIGH; // an0
		TRISAbits.TRISA1 = HIGH; // an1
		TRISAbits.TRISA2 = HIGH; // an2
		TRISAbits.TRISA3 = HIGH; // an3, this is now the VREF
		TRISAbits.TRISA5 = HIGH; // an4

		TRISB = 0x00; // all outputs first
		LATB = 0xFF;
		TRISBbits.TRISB0 = LOW; // HID lamp
		TRISBbits.TRISB1 = HIGH; // AC_OFF_U input
		TRISBbits.TRISB2 = LOW; // test pin out
		TRISBbits.TRISB3 = HIGH; // AC_OFF_I input
		TRISBbits.TRISB4 = HIGH; // mode N/O input
		TRISBbits.TRISB5 = HIGH; // PERKO input for ISR
		TRISBbits.TRISB6 = HIGH; // mode N/C input
		TRISBbits.TRISB7 = HIGH; // alarm ack switch input

		TRISC = 0;
		LATC = 0xff;
		TRISCbits.TRISC0 = HIGH; // CC led data input
		TRISCbits.TRISC1 = LOW; // SD card status LED
		TRISCbits.TRISC5 = LOW; // SPI serial data out
		TRISCbits.TRISC4 = HIGH; // SPI serial data in
		TRISCbits.TRISC3 = LOW; // SPI serial clock out
		TRISCbits.TRISC2 = LOW; // SD card select

		TRISD = 0xff; // dip switch inputs

		TRISE = LOW; // relay output 1
		LATE = 0xff;
		TRISFbits.TRISF0 = HIGH; // an5
		TRISFbits.TRISF1 = HIGH; // an6
		TRISFbits.TRISF2 = HIGH; // an7
		TRISFbits.TRISF3 = HIGH; // an8
		TRISFbits.TRISF4 = HIGH; // an9
		TRISFbits.TRISF5 = HIGH; // an10
		TRISFbits.TRISF6 = HIGH; // an11

		LATGbits.LATG3 = LOW; // output latch to zero
		TRISG = 0; // tx2/rx2, pwm channels
		LATG = 0xff;
		TRISGbits.TRISG4 = LOW; // output for high current load relay
		TRISGbits.TRISG3 = LOW; // output diversion pwm signal

		TRISH = 0; // mpuled and LCD
		LATH = 0xff;

		TRISJ = 0; // control relays
		LATJ = 0xff;

		/*
		 * Open the USART configured as
		 * 9N1, 38400,38400 baud, in send and receive INT mode
		 */
		BAUDCON1 |= 0x08; // 16 bit mode speed register
		BAUDCON2 |= 0x08; // 16 bit mode speed register

		Open1USART(USART_TX_INT_ON & USART_RX_INT_ON & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_LOW, 64); // 40mhz osc HS         38.4 kbaud, 16bit divider
		USART1_Status.TX_NINE = HIGH; // clear bit 8 for data, set bit 8 for commands
		TXSTA1bits.TX9D = HIGH; // same in uC
		RCSTA1bits.ADDEN = LOW; // receive all data
		TXSTA1bits.TX9 = HIGH;
		RCSTA1bits.RX9 = HIGH;
		SPBRGH1 = 0x00; // 0x01	9600
		SPBRG1 = 0x40; // 0x03	9600

		/*
		 * Open the USART configured as
		 * 8N1, 38400,38400 baud, transmit/receive INT mode
		 */
		Open2USART(USART_TX_INT_ON & USART_RX_INT_ON & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_LOW, 64); // 40mhz osc HS         38.4 kbaud, 16bit divider
		SPBRGH2 = 0x00;
		SPBRG2 = 0x40;

		while (DataRdy1USART()) { // dump 1 rx data`
			z = Read1USART();
		};
		while (DataRdy2USART()) { // dump 2 rx data
			z = Read2USART();
		};

		ALARMOUT = R_OFF;
		ansidraw(TRUE); // Clear and home screen
		solarup_delay = NULL;

		OpenADC(ADC_FOSC_32 & ADC_RIGHT_JUST & ADC_12_TAD, ADC_CH0 & ADC_REF_VREFPLUS_VSS & ADC_INT_OFF, ADC_12ANA); // open ADC channel for current and voltage readings
		PIE1bits.ADIE = LOW; // the ADC interrupt enable bit
		IPR1bits.ADIP = HIGH; // ADC use high pri

		OpenTimer0(TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_PS_1_256);
		OpenTimer3(TIMER_INT_ON & T1_16BIT_RW & T1_SOURCE_INT & T1_PS_1_8 &
			T1_OSC1EN_OFF & T1_SYNC_EXT_OFF);
		PR4 = 0xFF;
		OpenTimer4(TIMER_INT_OFF & T4_PS_1_16 & T4_POST_1_16); // no int, only for pwm
		OpenPWM4(0xFF);
		T3CONbits.T3CCP1 = 1; // Bits for Timer4 for PWM
		T3CONbits.T3CCP2 = 1; // same
		PIE3bits.TMR4IE = LOW; // TIMER4 int enable bit
		SetDCPWM4(1); // 0.1% power

		INTCONbits.RBIE = HIGH; // enable PORTB interrupts 1=enable
		INTCON2bits.RBIP = HIGH; // Set the PORTB interrupt-on-change as a high priority interrupt
		INTCON3bits.INT1IE = HIGH; // use external int for AC status signals
		INTCON2bits.INTEDG1 = HIGH; // rising edge
		INTCON3bits.INT1IF = LOW; // clean possible flag
		INTCON3bits.INT3IE = HIGH; // use external int for AC status signals
		INTCON2bits.INTEDG3 = HIGH; // rising edge
		INTCON3bits.INT3IF = LOW; // clean possible flag
		z = PORTB; // dummy read to clear possible b irq
		PERKOSW_R = PERKOSWI; // read the PERKO position switch
		INTCONbits.RBIF = LOW; // reset B flag
		INTCON2bits.RBPU = LOW; // enable input pullup. 0=on

		WriteTimer0(TIMEROFFSET); //      start timer0 at 1 second ticks
		WriteTimer3(TIMER3REG); //  low int worker thread timer  about 20hz                                                           //

		/*      work int thread setup */
		PIE2bits.TMR3IE = HIGH; // enable int
		IPR2bits.TMR3IP = LOW; // make it low level

		/* EEPROM write int enable */
		PIE2bits.EEIE = HIGH;

		/* Enable interrupt priority */
		RCONbits.IPEN = HIGH;
		PIR1 = LOW; // clear int flags
		PIR2 = LOW;
		PIR3 = LOW;

		/* Make receive interrupt high priority */
		IPR1bits.RC1IP = HIGH;
		IPR1bits.TX1IP = HIGH;
		IPR3bits.RC2IP = HIGH;

		/* Enable all high/low priority interrupts */
		INTCONbits.GIEH = HIGH;
		INTCONbits.GIEL = HIGH;
		max_eeprom_data = 1024;
	}
}

void start_pic(uint16_t hw_config)
{
	if (hw_config == 8722u) {
		IORELAYS = 0xff; // set control relays to off at powerup/reset
		CCOUTOPENSW = R_OFF; // charge voltage isolation relay/on
		SOLAROFF = R_OFF; // connect PV power
		BATLOAD = R_OFF; // battery load test relay/off
		BATLOAD_HI = R_OFF;
		BCRELAYS = 0xFF; // turn off relay 0-3   battery power
	}
}

void start_workerthread(void)
{
	/*      Work thread start */
	T2CONbits.TMR2ON = HIGH;
}