
#include <hal/pin.h>

#define LED	PA8	// dependent on board

int main(void)
{
	pin_clock_enable(LED);
	pin_set(LED, false);
	pin_output_pushpull(LED);
	
	while (true) {
		pin_toggle(LED);
	}
}
