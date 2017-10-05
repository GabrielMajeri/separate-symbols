#include <stdint.h>
#include <stdio.h>

static uint32_t fibonacci(uint8_t i)
{
	if (i == 0)
		return 0;

	uint32_t a = 1, b = 1;

	while (i-- > 0) {
		uint32_t tmp = b;
		b = a + b;
		a = tmp;
	}

	return a;
}

int main()
{
	const uint8_t i = 15;
	printf("The %uth fibonacci number is %u\n", i, fibonacci(i));
}
