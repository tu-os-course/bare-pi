#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define GPIO_BASE 0x20200000

extern void halt();

volatile unsigned int* gpio_fs4 = (unsigned int*)(GPIO_BASE+0x10);
volatile unsigned int* gpio_set_1  = (unsigned int*)(GPIO_BASE+0x20);
volatile unsigned int* gpio_clr_1  = (unsigned int*)(GPIO_BASE+0x2C);

/**
 * Loop <delay> times in a way that the compiler won't optimize away
 */
static inline void delay(int32_t count)
{
	asm volatile(
	  "__delay_%=:\n"
	  "subs %0, %[count], #1 \n"
	  "bne __delay_%=\n"
		: "=r"(count)
		: [count]"0"(count)
		: "cc"
	);
}

void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags)
{
	(void) r0;
	(void) r1;
	(void) atags;

  // enable output to OK led
  *gpio_fs4 |= (1 << 21);

  // blink
  while(true) {
    *gpio_set_1 |= (1 << 15);
    delay(0x3f0000);
    *gpio_clr_1 |= (1 << 15);
    delay(0x3f0000);
  }

  halt();
}
