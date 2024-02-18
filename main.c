#include "ft_printf.h"

int main(void)
{
	int val1;
	int val2;

	val1 = ft_printf("|%3c|", 'a');
	printf("\n");
	val2 = printf("|%3c|", 'a');
	printf("\n");
	printf("val1: %d || val2: %d ", val1, val2);
}