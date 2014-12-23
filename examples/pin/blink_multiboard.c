
#include <hal/pin.h>

#if BOARD_VERSION==1
# define LED		PA8
# define BUTTON		PC1
# define BUTTON_LEVEL	false
#elsif BOARD_VERSION==2
# define LED		PC3
# define BUTTON		PC1
# define BUTTON_LEVEL	false
#elsif BOARD_VERSION==3
# define LED		PA1
# define BUTTON		PB6
# define BUTTON_LEVEL	true
#else
# error "unsupported board"
#endif

int main(void)
{
	/* Enable the clocks for pins */
	pin_clock_enable(LED);
	pin_clock_enable(BUTTON);
	
	/* Configure LED */
	pin_set(LED, false);
	pin_output_pushpull(LED);
	pin_speed_fast(LED);
	
	/* Configure button */
	pin_input(BUTTON);
	if (BUTTON_LEVEL) {
		pin_pull_down(BUTTON);
	} else {
		pin_pull_up(BUTTON);
	}
	
	while (true) {
		pin_toggle(LED);
		if (pin_get(BUTTON) == BUTTON_LEVEL) {
			/* when button was pressed, slow down blinking */
			
			/* TODO: This should be HAL delay function call */
			for (int i=0; i<10000;i++) {
				__asm volatile ("nop");
			}
		}
	}
}
