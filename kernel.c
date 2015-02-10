#include <stddef.h>
#include <stdint.h>

#define GPIO_BASE 0x20200000

extern void halt();

volatile unsigned int* gpio_fs4 = (unsigned int*)(GPIO_BASE+16);
volatile unsigned int* gpio_ok  = (unsigned int*)(GPIO_BASE+32);

void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags)
{
	(void) r0;
	(void) r1;
	(void) atags;

  // enable output to OK led
  *gpio_fs4 |= (1 << 21);

  // turn on the OK led
  *gpio_ok |= (1 << 15);

  halt();
}
