
#include <hal/pin.h>

#if BOARD_VERSION==1
# define LED		PA8

/* the RMII peripheral */
# define PHY_CRSDV	PC5
# define PHY_RXD0	PC1
# define PHY_RXD1	PC2
# define PHY_TXEN	PC6
# define PHY_TXD0	PC3
# define PHY_TXD1	PC4
# define PHY_REFCLK	PC5
# define PHY_MDIO	PD4
# define PHY_MDC	PD5
/* bit banging pins */
# define PHY_RST	PA6
# define PHY_INTRP	PA7

/* the usart peripheral */
# define USART_TXD	PA3
# define USART_RXD	PA4

#else
# error "unsupported board"
#endif

/* Initialize pins in complex peripheral */
void init_eth(void)
{
	int phy_pins[] = {
		PHY_CRSDV,	PHY_RXD0,	PHY_RXD1,	PHY_REFCLK,
		PHY_TXEN,	PHY_TXD0,	PHY_TXD1,	PHY_MDIO,
		PHY_MDC
	};
	
	/* Initialize all pins that belongs to RMII */
	for (int i = 0; i < sizeof(phy_pins) / sizeof(phy_pins[0]); i++) {
		pin_clock_enable(phy_pins[i]);
		pin_af_pushpull(phy_pins[i]);
		pin_speed_high(phy_pins[i]);
		pin_af_map(phy_pins[i], GPIO_AF_ETH);
	}

	pin_input(PHY_INTRP);
	pin_pull_up(PHY_INTRP);
	pin_set(PHY_RST, true);
	pin_output_pushpull(PHY_RST);


	/* Reset the connected PHY by signal */
	pin_set(PHY_RST, false);
	for (int i = 0; i < 10000; i++) {
		__asm volatile ("nop");
	}
	pin_set(PHY_RST, true);
	for (int i = 0; i < 10000; i++) {
		__asm volatile ("nop");
	}
	
	/* Initialize phy over SNI */
	phy_reset(1);			/* out of scope of this example */
	
	/* Initialize ethernet MAC */
	eth_init();			/* out of scope of this example */
}

/* Initialize pins in simple peripheral */
void init_usart(void)
{
	pin_clock_enable(USART_TXD);
	pin_clock_enable(USART_RXD);
	
	pin_af_pushpull(USART_TXD);
	pin_af_pushpull(USART_RXD);
	
	pin_af_map(USART_RXD, GPIO_AF_USART6);
	pin_af_map(USART_TXD, GPIO_AF_USART6);
	
	usart_init(USART6);		/* out of scope of this example */
}

/* Initialize pins for general purpose bit-banging */
void init_led(void)
{
	/* Enable the clocks for pins */
	pin_clock_enable(LED);
	
	/* Configure LED */
	pin_set(LED, false);
	pin_output_pushpull(LED);
	pin_speed_fast(LED);
}

int main(void)
{
	init_led();
	init_usart();
	init_led();
	
	while (true) {
		eth_poll();		/* out of scope of this example */
		
		pin_toggle(LED);
	}
}
